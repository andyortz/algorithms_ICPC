// Genera el PDF del notebook: A4 a 2 columnas, código resaltado, índice con números de página.
// Uso (desde note_book/_pdf):  npm install   (una vez)   y luego   node generar.mjs
// Requiere Microsoft Edge o Google Chrome instalado (se usa con puppeteer-core, sin descargar nada).
// Configuración: config.json (título, papel, tamaños, exclusiones).
//
// Orden: carpetas numeradas (00_, 01_, ...) = capítulos; subcarpetas = secciones; archivos = entradas.
// El índice se calcula en dos pasadas: se genera el PDF, se busca en qué página quedó cada
// encabezado (marcas "§n.n.n") con pdfjs y se vuelve a generar con los números reales.

import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import { spawn } from 'node:child_process';
import { fileURLToPath, pathToFileURL } from 'node:url';
import puppeteer from 'puppeteer-core';
import hljs from 'highlight.js';
import { marked } from 'marked';
import katex from 'katex';
import { getDocument } from 'pdfjs-dist/legacy/build/pdf.mjs';

const here = path.dirname(fileURLToPath(import.meta.url));
const root = path.resolve(here, '..');
const cfgFile = path.resolve(here, process.argv[2] ?? 'config.json');   // node generar.mjs [otra-config.json]
const cfg = JSON.parse(fs.readFileSync(cfgFile, 'utf8'));
const horizontal = (cfg.orientacion ?? 'horizontal') !== 'vertical';   // los teambooks se imprimen en horizontal
const bn = cfg.blancoYNegro ?? false;    // estilo pensado para impresora monocroma
const coll = new Intl.Collator('es', { numeric: true, sensitivity: 'base' });

// ---------------------------------------------------------------- recolección
const excluir = cfg.excluir.map((p) => p.replace(/\\/g, '/').replace(/\/+$/, ''));
const excluido = (r) => excluir.some((p) => r === p || r.startsWith(p + '/'));   // archivo o carpeta completa
function walk(rel) {
  const dir = path.join(root, rel);
  let out = [];
  for (const e of fs.readdirSync(dir, { withFileTypes: true }).sort((a, b) => coll.compare(a.name, b.name))) {
    if (e.name.startsWith('_') || e.name.startsWith('.') || e.name === 'node_modules') continue;
    const r = rel ? `${rel}/${e.name}` : e.name;
    if (excluido(r)) continue;
    if (e.isDirectory()) out = out.concat(walk(r));
    else if (rel && cfg.extensiones.includes(path.extname(e.name).slice(1))) out.push(r);
  }
  return out;
}

const ACENTOS = {
  Algebra: 'Álgebra', Arbol: 'Árbol', Arboles: 'Árboles', arboles: 'árboles', Aritmetica: 'Aritmética', Basico: 'Básico',
  Busqueda: 'Búsqueda', Circulos: 'Círculos', Descomposicion: 'Descomposición', Dinamico: 'Dinámico', Diofanticas: 'Diofánticas',
  Geometria: 'Geometría', Hungaro: 'Húngaro', Mascaras: 'Máscaras', Matematicas: 'Matemáticas', Metodos: 'Métodos',
  Poligonos: 'Polígonos', Programacion: 'Programación', Raices: 'Raíces', Rotacion: 'Rotación', Separacion: 'Separación',
  Teoria: 'Teoría', dinamica: 'dinámica', edicion: 'edición', expansion: 'expansión', factorizacion: 'factorización',
  formulas: 'fórmulas', maximo: 'máximo', minima: 'mínima', minimo: 'mínimo', minimos: 'mínimos', monotonas: 'monótonas',
  numericos: 'numéricos', numeros: 'números', topologico: 'topológico', triangulos: 'triángulos',
};
const bonito = (nombre) => nombre.replace(/^\d+_/, '').split('_').map((w) => ACENTOS[w] ?? w).join(' ');
const esc = (s) => s.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;');

function estructura() {
  const caps = [];
  for (const f of walk('')) {
    const parts = f.split('/');
    let cap = caps.find((c) => c.dir === parts[0]);
    if (!cap) caps.push(cap = { dir: parts[0], nombre: bonito(parts[0]), secciones: [] });
    const sub = parts.slice(1, -1);
    const key = sub.join('/');
    let sec = cap.secciones.find((s) => s.key === key);
    if (!sec) cap.secciones.push(sec = { key, nombre: sub.map(bonito).join(' › '), archivos: [] });
    sec.archivos.push({ ruta: f, nombre: parts[parts.length - 1] });
  }
  caps.forEach((c, i) => {
    c.num = String(i);
    // archivos sueltos del capítulo primero; después las subcarpetas en orden
    c.secciones.sort((a, b) => (a.key === '' ? -1 : b.key === '' ? 1 : coll.compare(a.key, b.key)));
    let si = 0;
    for (const s of c.secciones) {
      if (s.key === '') { s.num = null; s.archivos.forEach((a, k) => (a.num = `${c.num}.${++si}`)); }
      else { s.num = `${c.num}.${++si}`; s.archivos.forEach((a, k) => (a.num = `${s.num}.${k + 1}`)); }
    }
  });
  return caps;
}

// ---------------------------------------------------------------- contenido de cada archivo
function limpiarCpp(src) {
  const quitar = cfg.quitarLineasQueEmpiezanCon;
  let lines = src.replace(/\r\n/g, '\n').split('\n');
  let guard = null;
  lines = lines.filter((l) => {
    const t = l.trim();
    if (quitar.some((p) => t.startsWith(p))) return false;
    if (/^#pragma (push|pop)_macro\("\w+"\)$/.test(t)) return false;
    if (/^#undef (int|fast|pb|F|S|all|sortt|sortn|pi|vi|vb|vpi|vs|endl)$/.test(t)) return false;
    let m = t.match(/^#ifndef (NOTEBOOK_GENERADO_\w+|GEO3D_\w+)$/);
    if (m) { guard = m[1]; return false; }
    if (guard && t === `#define ${guard}`) return false;
    if (/^#include\s+"(\.\.\/)*_base\/template-simple\.hpp"$/.test(t)) return false;
    return true;
  });
  if (guard) {                                   // quitar el #endif que cierra la guarda
    for (let i = lines.length - 1; i >= 0; i--) {
      if (lines[i].trim() === '') continue;
      if (lines[i].trim() === '#endif') lines.splice(i, 1);
      break;
    }
  }
  return compactar(compactarCajas(lines), '//');
}

// Solo presentación: las "cajas" de comentarios (/***...***/, "* texto      *") ocupan una
// línea completa del archivo pero 2 o 3 líneas en una columna del PDF.
function compactarCajas(lines) {
  return lines.map((l) => {
    const m = l.match(/^(\s*\/?)([*=\-#~])\2{20,}(\/?)\s*$/);
    if (m) return m[1] + m[2].repeat(24) + m[3];
    if (/^\s*\*.*\S\s{2,}\*\s*$/.test(l)) return l.replace(/\s+\*\s*$/, '');
    return l;
  });
}

// Solo presentación (config.quitarLineasVacias): sin líneas vacías, sin separadores que solo
// dibujan una raya (// ====, # ----) y sin comentarios vacíos (//, #, *).
function compactar(lines, com) {
  if (!cfg.quitarLineasVacias) return lines.join('\n').replace(/\n{3,}/g, '\n\n').trim();
  const c = com === '//' ? '\\/\\/' : '#';
  const raya = new RegExp(`^\\s*${c}\\s*[=\\-*#~_]{4,}\\s*$`), vacio = new RegExp(`^\\s*(${c}|\\*)\\s*$`);
  return lines.filter((l) => l.trim() !== '' && !raya.test(l) && !vacio.test(l)).join('\n').trim();
}

function codigo(src, lang) {
  const html = hljs.highlight(src, { language: lang, ignoreIllegals: true }).value;
  return `<pre class="code"><code class="hljs">${html}</code></pre>`;
}

function mathToHtml(tex, display) {
  try { return katex.renderToString(tex, { displayMode: display, throwOnError: false, strict: 'ignore' }); }
  catch { return `<code>${esc(tex)}</code>`; }
}

// Conversor mínimo LaTeX -> HTML para los apuntes de fórmulas (.tex del notebook).
function texToHtml(src) {
  const ph = [];
  const keep = (html) => `\u0000${ph.push(html) - 1}\u0000`;
  let s = src.replace(/\r\n/g, '\n');
  s = s.replace(/\\begin\{lstlisting\}(\[[^\]]*\])?([\s\S]*?)\\end\{lstlisting\}/g, (_, o, c) => keep(codigo(c.replace(/^\n|\n$/g, ''), 'cpp')));
  s = s.replace(/\$\$([\s\S]+?)\$\$/g, (_, m) => keep(mathToHtml(m, true)));
  s = s.replace(/\\\[([\s\S]+?)\\\]/g, (_, m) => keep(mathToHtml(m, true)));
  s = s.replace(/\\\(([\s\S]+?)\\\)/g, (_, m) => keep(mathToHtml(m, false)));
  s = s.replace(/(?<!\\)\$([^$]+?)(?<!\\)\$/g, (_, m) => keep(mathToHtml(m, false)));
  // Grupo {...} con hasta 3 niveles de llaves anidadas (p. ej. {|p{12cm}|}).
  const B = '\\{(?:[^{}]|\\{(?:[^{}]|\\{[^{}]*\\})*\\})*\\}';
  const reMulti = new RegExp(`\\\\multi(?:column|row)\\{\\d+\\}${B}(${B})`, 'g');
  const inline = (t) => {
    let x = t.replace(/\\cline\{[^}]*\}/g, '');
    for (let k = 0; k < 3; k++) {
      x = x.replace(reMulti, (_, c) => c.slice(1, -1))
        .replace(/\\(textbf|mathbf)\{((?:[^{}]|\{[^{}]*\})*)\}/g, '<b>$2</b>')
        .replace(/\\(textit|emph)\{((?:[^{}]|\{[^{}]*\})*)\}/g, '<i>$2</i>')
        .replace(/\\texttt\{((?:[^{}]|\{[^{}]*\})*)\}/g, '<code>$1</code>');
    }
    return x.replace(/\\(hspace|vspace)\*?\{[^}]*\}/g, ' ')
      .replace(/\\(noindent|centering|small|footnotesize|scriptsize|hline|midrule|toprule|bottomrule|newline|par)\b/g, ' ')
      .replace(/\\\\/g, '<br>').replace(/\\([%&_#$])/g, '$1').replace(/~/g, '&nbsp;')
      .replace(/``|''/g, '"').replace(/\\[a-zA-Z]+\*?(\[[^\]]*\])?/g, '').replace(/[{}]/g, '');
  };
  const tabla = (body, sep) => {
    const rows = body.split(/\\\\/).map((r) => r.replace(/\\hline|\\midrule|\\cline\{[^}]*\}/g, '').trim()).filter((r) => r);
    return keep('<table class="tex">' + rows.map((r, i) => '<tr>' + r.split(sep).map((c) => {
      const span = c.match(/\\multicolumn\{(\d+)\}/);
      const cell = inline(c.trim());
      return span ? `<td colspan="${span[1]}" class="c">${cell}</td>` : `<td>${cell}</td>`;
    }).join('') + '</tr>').join('') + '</table>');
  };
  s = s.replace(/\\begin\{tabbing\}([\s\S]*?)\\end\{tabbing\}/g, (_, b) => tabla(b, /\\[=>]/));
  s = s.replace(new RegExp(`\\\\begin\\{(supertabular|tabular)\\}${B}([\\s\\S]*?)\\\\end\\{\\1\\}`, 'g'), (_, e, b) => tabla(b, /(?<!\\)&/));
  s = s.replace(/\\(tablefirsthead|tablehead|tabletail|tablelasttail)\{((?:[^{}]|\{(?:[^{}]|\{[^{}]*\})*\})*)\}/g, '');
  s = s.replace(/\\renewcommand\{[^}]*\}\{[^}]*\}/g, '');
  s = s.replace(/\\begin\{(itemize|enumerate)\}([\s\S]*?)\\end\{\1\}/g, (_, e, b) => {
    const items = b.split(/\\item\b/).slice(1).map((it) => `<li>${inline(it.trim())}</li>`).join('');
    return keep(e === 'itemize' ? `<ul>${items}</ul>` : `<ol>${items}</ol>`);
  });
  s = s.replace(/\\(begin|end)\{(center|flushleft|flushright|minipage)\}(\{[^}]*\})?/g, '');
  s = s.replace(/\\(sub)*section\*?\{([^}]*)\}/g, (_, sub, t) => keep(`<h5>${inline(t)}</h5>`));
  const html = s.split(/\n\s*\n/).map((p) => p.trim()).filter((p) => p)
    .map((p) => (/^\u0000\d+\u0000$/.test(p) ? p : `<p>${inline(p)}</p>`)).join('\n');
  return html.replace(/\u0000(\d+)\u0000/g, (_, i) => ph[i]).replace(/\u0000(\d+)\u0000/g, (_, i) => ph[i]);
}

marked.use({
  renderer: {
    code({ text, lang }) { return codigo(text, hljs.getLanguage(lang || '') ? lang : 'plaintext'); },
    link({ tokens }) { return this.parser.parseInline(tokens); },
  },
});
function mdToHtml(src) {
  let s = src.replace(/\r\n/g, '\n');
  const ph = [];
  s = s.replace(/(?<!\\)\$\$([\s\S]+?)\$\$/g, (_, m) => `MATHPH${ph.push(mathToHtml(m, true)) - 1}X`);
  return marked.parse(s).replace(/MATHPH(\d+)X/g, (_, i) => ph[i]);
}

function contenido(ruta) {
  const src = fs.readFileSync(path.join(root, ruta), 'utf8');
  const ext = path.extname(ruta).slice(1);
  if (ext === 'cpp' || ext === 'hpp') return codigo(limpiarCpp(src), 'cpp');
  if (ext === 'py') return codigo(compactar(src.replace(/\r\n/g, '\n').split('\n'), '#'), 'python');
  if (ext === 'tex') return `<div class="tex">${texToHtml(src)}</div>`;
  if (ext === 'md') return `<div class="md">${mdToHtml(src)}</div>`;
  return `<pre class="code plain">${esc(src.replace(/\r\n/g, '\n').trim())}</pre>`;
}

// ---------------------------------------------------------------- HTML
function html(caps, paginas) {
  const pg = (num) => `<span class="pg">${paginas.get(num) ?? '00'}</span>`;
  let toc = '', body = '';
  for (const c of caps) {
    toc += `<div class="toc-cap"><span class="n">${c.num}</span><span class="t">${esc(c.nombre)}</span>${pg(c.num)}</div>`;
    body += `<h1 class="cap"><span class="mark">§${c.num}</span> ${esc(c.nombre)}</h1>`;
    for (const s of c.secciones) {
      if (s.num) {
        toc += `<div class="toc-sec"><span class="n">${s.num}</span><span class="t">${esc(s.nombre)}</span>${pg(s.num)}</div>`;
        body += `<h2 class="sec"><span class="mark">§${s.num}</span> ${esc(s.nombre)}</h2>`;
      }
      for (const a of s.archivos) {
        toc += `<div class="toc-arc"><span class="n">${a.num}</span><span class="t">${esc(a.nombre)}</span>${pg(a.num)}</div>`;
        body += `<section class="arc"><h3><span class="mark">§${a.num}</span><span class="nom">${esc(a.nombre)}</span><span class="ruta"><bdi>${esc(path.posix.dirname(a.ruta))}</bdi></span></h3>${contenido(a.ruta)}</section>`;
      }
    }
  }
  const katexCss = pathToFileURL(path.join(here, 'node_modules', 'katex', 'dist', 'katex.min.css')).href;
  const hljsCss = fs.readFileSync(path.join(here, 'node_modules', 'highlight.js', 'styles', 'github.css'), 'utf8');
  const fecha = new Date().toLocaleDateString('es', { year: 'numeric', month: 'long', day: 'numeric' });
  return `<!DOCTYPE html><html lang="es"><head><meta charset="utf-8"><title>${esc(cfg.titulo)}</title>
<link rel="stylesheet" href="${katexCss}">
<style>
${hljsCss}
@page { size: ${cfg.papel} ${horizontal ? 'landscape' : 'portrait'}; }
html { -webkit-print-color-adjust: exact; print-color-adjust: exact; }
body { margin: 0; font-family: "Segoe UI", Calibri, Arial, sans-serif; font-size: ${cfg.tamTexto}; line-height: 1.25; color: #000; }
.portada { text-align: center; border-bottom: 1.2pt solid #000; padding-bottom: 2mm; margin-bottom: 2mm; }
.portada h1 { font-size: 20pt; margin: 0; } .portada div { font-size: 9pt; color: #333; }
.toc { columns: ${cfg.columnas}; column-gap: 6mm; column-rule: 0.4pt solid #bbb; font-size: 7.4pt; }
.toc div { display: flex; align-items: baseline; gap: 1.2mm; break-inside: avoid; }
.toc .t { flex: 1; overflow: hidden; white-space: nowrap; }
.toc .t::after { content: " ................................................................................................................................"; color: #999; }
.toc .n { min-width: 7mm; color: #444; } .toc .pg { min-width: 5mm; text-align: right; font-variant-numeric: tabular-nums; }
.toc-cap { font-weight: 700; font-size: 8.4pt; margin-top: 1.6mm; break-after: avoid; }
.toc-sec { font-weight: 600; padding-left: 2mm; } .toc-arc { padding-left: 5mm; color: #222; }
.contenido { columns: ${cfg.columnas}; column-gap: 5mm; column-rule: 0.4pt solid #999; margin-top: 2mm; border-top: 1.2pt solid #000; padding-top: 1mm; }
h1.cap { font-size: 11pt; margin: 2mm 0 1mm; padding: 0.4mm 0; border-top: 1.6pt solid #000; border-bottom: 0.6pt solid #000; break-after: avoid; }
h2.sec { font-size: 8.6pt; margin: 1.8mm 0 0.6mm; padding-bottom: 0.3mm; border-bottom: 0.8pt solid #000; break-after: avoid; }
h3 { font-size: 7.6pt; margin: 1.2mm 0 0.3mm; padding: 0.3mm 1mm; ${bn ? 'border-top: 0.4pt solid #000; border-bottom: 0.4pt solid #000;' : 'background: #e6e6e6;'} break-after: avoid; display: flex; gap: 2mm; align-items: baseline; }
h3 .nom { white-space: nowrap; }
h3 .ruta bdi { direction: ltr; unicode-bidi: isolate; }
h3 .ruta { flex: 1; min-width: 0; text-align: right; font-weight: 400; font-size: 5.6pt; color: #555; white-space: nowrap; overflow: hidden; text-overflow: ellipsis; direction: rtl; }
.mark { font-variant-numeric: tabular-nums; }
pre.code { margin: 0 0 0.8mm; font-family: Consolas, "Cascadia Mono", "Courier New", monospace; font-size: ${cfg.tamCodigo}; line-height: 1.16;
  white-space: pre-wrap; overflow-wrap: anywhere; tab-size: 4; }
pre.code code.hljs { padding: 0; background: none; display: inline; }
${bn ? `/* Blanco y negro: todo negro; palabras clave en negrita, comentarios en gris oscuro cursiva. */
pre.code .hljs, pre.code .hljs * { color: #000 !important; }
pre.code .hljs-comment, pre.code .hljs-comment * { color: #3a3a3a !important; font-style: italic; }
.hljs-keyword, .hljs-type, .hljs-built_in, .hljs-meta .hljs-keyword { font-weight: 700; }
.hljs-title, .hljs-section { font-weight: 400; }`
  : `.hljs-comment { color: #555; font-style: italic; } .hljs-keyword, .hljs-type, .hljs-built_in { color: #0033a0; }
.hljs-string { color: #8a1c00; } .hljs-meta { color: #6a2a8a; } .hljs-number, .hljs-literal { color: #006a4e; }`}
.tex, .md { font-size: ${cfg.tamTexto}; } .tex p, .md p { margin: 0.6mm 0; } .tex h5, .md h1, .md h2, .md h3 { font-size: 7.8pt; margin: 1.2mm 0 0.4mm; }
.md h1 { font-size: 8.4pt; }
.md h1, .md h2, .md h3, .md h4 { background: none; display: block; padding: 0; border-bottom: 0.4pt solid #888; } table { border-collapse: collapse; width: 100%; margin: 0.6mm 0; font-size: 6.4pt; }
td, th { border: 0.3pt solid #999; padding: 0.3mm 0.8mm; vertical-align: top; } td.c { text-align: center; font-weight: 600; }
ul, ol { margin: 0.4mm 0; padding-left: 4mm; } code { font-family: Consolas, monospace; font-size: 0.95em; }
.katex { font-size: 1.05em; } .katex-display { margin: 0.6mm 0; }
</style></head><body>
<div class="portada"><h1>${esc(cfg.titulo)}</h1><div>${esc(cfg.subtitulo)} · ${fecha}</div></div>
<div class="toc">${toc}</div>
<div class="contenido">${body}</div>
</body></html>`;
}

// ---------------------------------------------------------------- PDF
function navegador() {
  const c = [process.env.CHROME_PATH,
    'C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe', 'C:/Program Files/Microsoft/Edge/Application/msedge.exe',
    'C:/Program Files/Google/Chrome/Application/chrome.exe', 'C:/Program Files (x86)/Google/Chrome/Application/chrome.exe',
    '/usr/bin/google-chrome', '/usr/bin/chromium', '/Applications/Google Chrome.app/Contents/MacOS/Google Chrome'];
  const p = c.find((x) => x && fs.existsSync(x));
  if (!p) throw new Error('No se encontró Edge ni Chrome. Definir CHROME_PATH con la ruta del navegador.');
  return p;
}

async function render(browser, htmlStr) {
  const file = path.join(here, 'build', 'notebook.html');
  fs.mkdirSync(path.dirname(file), { recursive: true });
  fs.writeFileSync(file, htmlStr);
  const page = await browser.newPage();
  await page.goto(pathToFileURL(file).href, { waitUntil: 'networkidle0', timeout: 0 });
  await page.evaluate(() => document.fonts.ready);
  const pdf = await page.pdf({
    format: cfg.papel, landscape: horizontal, printBackground: true, margin: cfg.margenes, displayHeaderFooter: true,
    headerTemplate: '<div></div>',
    footerTemplate: `<div style="width:100%;font-size:6.5pt;font-family:Segoe UI,Arial;color:#444;padding:0 7mm;display:flex;justify-content:space-between"><span>${esc(cfg.titulo)}</span><span><span class="pageNumber"></span> / <span class="totalPages"></span></span></div>`,
    timeout: 0,
  });
  await page.close();
  return Buffer.from(pdf);
}

async function paginasDeMarcas(pdfBuf) {
  const doc = await getDocument({ data: new Uint8Array(pdfBuf), disableFontFace: true, useSystemFonts: false, verbosity: 0 }).promise;
  const m = new Map();
  for (let p = 1; p <= doc.numPages; p++) {
    const tc = await (await doc.getPage(p)).getTextContent();
    const text = tc.items.map((it) => it.str).join(' ');
    for (const x of text.matchAll(/§\s*(\d+(?:\.\d+)*)/g)) if (!m.has(x[1])) m.set(x[1], p);
  }
  return { mapa: m, total: doc.numPages };
}

const t0 = Date.now();
const caps = estructura();
const nArchivos = caps.reduce((s, c) => s + c.secciones.reduce((t, x) => t + x.archivos.length, 0), 0);
console.log(`${caps.length} capítulos, ${nArchivos} archivos`);
// Edge/Chrome se lanzan a mano y puppeteer se conecta por DevToolsActivePort: si el navegador se
// relanza a sí mismo (p. ej. con una actualización pendiente, el proceso inicial sale con código 0)
// puppeteer.launch falla aunque el navegador quede abierto; este método sigue funcionando.
async function abrirNavegador() {
  const perfil = fs.mkdtempSync(path.join(os.tmpdir(), 'notebook-pdf-'));
  const proc = spawn(navegador(), ['--headless=new', '--disable-gpu', '--no-first-run', '--no-default-browser-check',
    '--remote-debugging-port=0', `--user-data-dir=${perfil}`, 'about:blank'], { stdio: 'ignore' });
  const archivo = path.join(perfil, 'DevToolsActivePort');
  for (let t = 0; !fs.existsSync(archivo) || fs.readFileSync(archivo, 'utf8').split('\n').length < 2; t++) {
    if (t > 300) throw new Error('El navegador no abrió el puerto de depuración en 30 s.');
    await new Promise((r) => setTimeout(r, 100));
  }
  const [puerto, ruta] = fs.readFileSync(archivo, 'utf8').split('\n');
  const b = await puppeteer.connect({ browserWSEndpoint: `ws://127.0.0.1:${puerto.trim()}${ruta.trim()}`, defaultViewport: null });
  b.cerrarTodo = async () => {
    try { await b.close(); } catch { try { proc.kill(); } catch {} }
    for (let i = 0; i < 20; i++) { try { fs.rmSync(perfil, { recursive: true, force: true }); break; } catch { await new Promise((r) => setTimeout(r, 250)); } }
  };
  return b;
}
const browser = await abrirNavegador();
// "columnas" puede ser un número o una lista (p. ej. [2, 3]): se genera un PDF por valor.
// En "salida", {columnas} se reemplaza por ese número.
const variantes = Array.isArray(cfg.columnas) ? cfg.columnas : [cfg.columnas];
try {
  for (const cols of variantes) {
    cfg.columnas = cols;
    let paginas = new Map(), pdf, info;
    for (let pasada = 1; pasada <= 4; pasada++) {
      pdf = await render(browser, html(caps, paginas));
      info = await paginasDeMarcas(pdf);
      const iguales = [...info.mapa].every(([k, v]) => paginas.get(k) === v) && paginas.size === info.mapa.size;
      console.log(`[${cols} columnas] pasada ${pasada}: ${info.total} páginas, ${info.mapa.size} marcas${iguales ? ' (índice estable)' : ''}`);
      if (iguales) break;
      paginas = info.mapa;
    }
    const faltan = caps.flatMap((c) => [c.num, ...c.secciones.flatMap((s) => [s.num, ...s.archivos.map((a) => a.num)])]).filter((n) => n && !info.mapa.has(n));
    if (faltan.length) console.warn(`Aviso: no se encontraron en el PDF las marcas ${faltan.slice(0, 10).join(', ')}${faltan.length > 10 ? '…' : ''}`);
    const salida = path.resolve(here, cfg.salida.replace('{columnas}', cols));
    fs.writeFileSync(salida, pdf);
    console.log(`Listo: ${path.relative(root, salida)} (${info.total} páginas, ${(pdf.length / 1024).toFixed(0)} KB)`);
  }
  console.log(`Total: ${((Date.now() - t0) / 1000).toFixed(1)} s`);
} finally {
  await browser.cerrarTodo();
}
