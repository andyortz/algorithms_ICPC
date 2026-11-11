// Juez local con los casos oficiales de Library Checker (https://judge.yosupo.jp).
// Reproduce generate.py de yosupo06/library-checker-problems sin Python: genera params.h,
// compila generadores, checker y solución oficial, crea los casos, verifica sus SHA-256 contra
// hash.json (los mismos datos que usa el juez en línea) y juzga cada adaptador de esta carpeta.
//
// Uso (desde note_book):
//   node _pruebas/yosupo/juez.mjs                 -> todos los adaptadores
//   node _pruebas/yosupo/juez.mjs unionfind lca   -> solo los adaptadores cuyo nombre contiene el filtro
// Opciones: --repo <ruta>  (por defecto ../../repos/library-checker-problems desde note_book)
//           --factor <x>   (multiplica el límite de tiempo; por defecto 1)
// Cada adaptador empieza con:  // yosupo: <problema>   y   // prueba: <archivo del notebook>
// Requisitos: Node.js, g++ y git en el PATH.

import { spawnSync, execFileSync } from 'node:child_process';
import fs from 'node:fs';
import path from 'node:path';
import crypto from 'node:crypto';
import { fileURLToPath } from 'node:url';

const here = path.dirname(fileURLToPath(import.meta.url));
const notebook = path.resolve(here, '..', '..');
const args = process.argv.slice(2);
const opt = (name, def) => { const i = args.indexOf(name); if (i < 0) return def; const v = args[i + 1]; args.splice(i, 2); return v; };
const repo = path.resolve(opt('--repo', path.resolve(notebook, '..', '..', 'repos', 'library-checker-problems')));
const factor = Number(opt('--factor', '1'));
const filters = args;
const exe = process.platform === 'win32' ? '.exe' : '';
const isWin = process.platform === 'win32';

if (!fs.existsSync(path.join(repo, 'common'))) {
  console.error(`No se encontró el repositorio en ${repo}.\n` +
    'Clonar con: git clone --depth 1 --filter=blob:none --sparse https://github.com/yosupo06/library-checker-problems');
  process.exit(1);
}

// ---------------- utilidades ----------------
const sha256 = (buf) => crypto.createHash('sha256').update(buf).digest('hex');
const toLF = (file) => { const b = fs.readFileSync(file); if (b.includes(13)) fs.writeFileSync(file, b.toString('latin1').replace(/\r\n/g, '\n'), 'latin1'); };
const mtime = (f) => (fs.existsSync(f) ? fs.statSync(f).mtimeMs : -1);
const STACK = isWin ? ['-Wl,--stack,268435456'] : [];

// MinGW (g++, ld y los checkers de testlib) recibe argv en la página de códigos ANSI: una ruta con
// acentos ("Programación") puede llegar corrupta. Por eso a los programas externos solo se les pasan
// rutas RELATIVAS al directorio de trabajo (que se fija con cwd y que Node maneja en Unicode).
const rel = (cwd, p) => (path.isAbsolute(p) ? path.relative(cwd, p) : p).split(path.sep).join('/');

function compile(src, out, flags) {
  if (mtime(out) > mtime(src) && flags.deps.every((d) => mtime(out) > mtime(d))) return;
  fs.mkdirSync(path.dirname(out), { recursive: true });
  const cwd = path.dirname(src);
  const r = spawnSync('g++', [...flags.args.map((a) => rel(cwd, a)), '-o', rel(cwd, out), rel(cwd, src)], { encoding: 'utf8', cwd });
  if (r.status !== 0) throw new Error(`Error al compilar ${src}:\n${(r.stderr || '').slice(0, 3000)}`);
}
const officialFlags = (dir, deps = []) => ({
  args: ['-O2', '-std=c++17', ...STACK, ...(isWin ? ['-D__USE_MINGW_ANSI_STDIO', '-static'] : []), '-I', path.join(repo, 'common')],
  deps: [path.join(dir, 'params.h'), ...deps],
});

// Parser TOML mínimo para info.toml (timelimit, [[tests]], [params]).
function parseInfo(file) {
  const info = { timelimit: 5, tests: [], params: {} };
  let sec = null;
  for (let line of fs.readFileSync(file, 'utf8').split(/\r?\n/)) {
    line = line.replace(/#.*$/, '').trim();
    if (!line) continue;
    if (line === '[[tests]]') { sec = { }; info.tests.push(sec); continue; }
    if (line === '[params]') { sec = info.params; continue; }
    if (/^\[/.test(line)) { sec = {}; continue; }
    const m = line.match(/^([A-Za-z0-9_]+)\s*=\s*(.+)$/);
    if (!m) continue;
    let [, k, v] = m;
    let val;
    if (/^["']/.test(v)) val = { type: 'str', v: v.slice(1, -1) };
    else if (/^-?[\d_]+$/.test(v)) val = { type: 'int', v: v.replace(/_/g, '') };
    else if (/^-?[\d_.eE+-]+$/.test(v)) val = { type: 'float', v: v.replace(/_/g, '') };
    else val = { type: 'other', v };
    if (sec === null && k === 'timelimit') info.timelimit = Number(val.v);
    else if (sec === info.params) info.params[k] = val;
    else if (sec) sec[k] = val.type === 'int' ? Number(val.v) : val.v;
  }
  return info;
}

function findProblemDir(slug) {
  const list = execFileSync('git', ['-C', repo, 'ls-tree', '-d', '-r', '--name-only', 'HEAD'], { encoding: 'utf8' })
    .split('\n').filter((d) => d.split('/').pop() === slug);
  if (!list.length) throw new Error(`Problema desconocido: ${slug}`);
  const rel = list[0];
  if (!fs.existsSync(path.join(repo, rel, 'info.toml'))) {
    console.log(`  (sparse-checkout add ${rel})`);
    execFileSync('git', ['-C', repo, 'sparse-checkout', 'add', rel]);
  }
  return path.join(repo, rel);
}

// ---------------- preparación de un problema ----------------
const prepared = new Map();
function prepare(slug) {
  if (prepared.has(slug)) return prepared.get(slug);
  const dir = findProblemDir(slug);
  const info = parseInfo(path.join(dir, 'info.toml'));
  const bin = path.join(dir, '.local');
  // params.h igual que generate.py
  const ph = Object.entries(info.params).map(([k, v]) =>
    v.type === 'int' ? `#define ${k} (long long)${v.v}` : v.type === 'float' ? `#define ${k} ${v.v}` : `#define ${k} "${v.v}"`).join('\n') + (Object.keys(info.params).length ? '\n' : '');
  const phFile = path.join(dir, 'params.h');
  if (!fs.existsSync(phFile) || fs.readFileSync(phFile, 'utf8') !== ph) fs.writeFileSync(phFile, ph);
  const hashes = JSON.parse(fs.readFileSync(path.join(dir, 'hash.json'), 'utf8'));
  const cases = [];
  for (const t of info.tests) for (let i = 0; i < t.number; i++) cases.push({ gen: t.name, i, name: `${path.parse(t.name).name}_${String(i).padStart(2, '0')}` });
  const inDir = path.join(dir, 'in'), outDir = path.join(dir, 'out');
  fs.mkdirSync(inDir, { recursive: true }); fs.mkdirSync(outDir, { recursive: true });
  const ok = (f, key) => fs.existsSync(f) && sha256(fs.readFileSync(f)) === hashes[key];
  const t0 = Date.now();
  const checkerSrc = fs.existsSync(path.join(dir, 'checker.cpp')) ? path.join(dir, 'checker.cpp') : path.join(repo, 'common', 'checker.cpp');
  const checker = path.join(bin, 'checker' + exe);
  compile(checkerSrc, checker, officialFlags(dir));
  const correct = path.join(bin, 'correct' + exe);
  let mismatch = 0, generated = 0;
  for (const c of cases) {
    const inF = path.join(inDir, c.name + '.in'), outF = path.join(outDir, c.name + '.out');
    if (!ok(inF, c.name + '.in')) {
      if (c.gen.endsWith('.in')) fs.copyFileSync(path.join(dir, 'gen', c.name + '.in'), inF);
      else {
        const g = path.join(bin, path.parse(c.gen).name + exe);
        compile(path.join(dir, 'gen', c.gen), g, officialFlags(dir));
        const fd = fs.openSync(inF, 'w');
        const r = spawnSync(g, [String(c.i)], { stdio: ['ignore', fd, 'pipe'], cwd: repo });
        fs.closeSync(fd);
        if (r.status !== 0) throw new Error(`Generador falló: ${c.gen} ${c.i}`);
      }
      toLF(inF); generated++;
    }
    if (!ok(inF, c.name + '.in')) mismatch++;
    if (!ok(outF, c.name + '.out')) {
      compile(path.join(dir, 'sol', 'correct.cpp'), correct, officialFlags(dir));
      const fi = fs.openSync(inF, 'r'), fo = fs.openSync(outF, 'w');
      const r = spawnSync(correct, [], { stdio: [fi, fo, 'pipe'] });
      fs.closeSync(fi); fs.closeSync(fo);
      if (r.status !== 0) throw new Error(`Solución oficial falló en ${c.name}`);
      toLF(outF); generated++;
      if (!ok(outF, c.name + '.out')) mismatch++;
    }
  }
  const res = { slug, dir, info, cases, checker, mismatch };
  console.log(`[${slug}] ${cases.length} casos, límite ${info.timelimit}s` +
    (generated ? `, ${generated} archivos generados en ${((Date.now() - t0) / 1000).toFixed(1)}s` : ', casos en caché') +
    (mismatch ? `, ¡${mismatch} archivos NO coinciden con hash.json!` : ', SHA-256 = hash.json'));
  prepared.set(slug, res);
  return res;
}

// ---------------- juzgar un adaptador ----------------
function judge(adapterFile) {
  const src = fs.readFileSync(adapterFile, 'utf8');
  const slug = (src.match(/\/\/\s*yosupo:\s*(\S+)/) || [])[1];
  const target = (src.match(/\/\/\s*prueba:\s*(.+)/) || [])[1]?.trim() ?? '?';
  if (!slug) return null;
  const P = prepare(slug);
  const out = path.join(notebook, '_pruebas', 'yosupo', '.bin', path.parse(adapterFile).name + exe);
  const deps = [...src.matchAll(/#include\s+"([^"]+)"/g)].map((m) => path.resolve(path.dirname(adapterFile), m[1]));
  let compileError = null;
  try { compile(adapterFile, out, { args: ['-O2', '-std=gnu++20', ...STACK], deps: deps.filter((d) => fs.existsSync(d)) }); }
  catch (e) { compileError = e.message; }
  const row = { adapter: path.basename(adapterFile), slug, target, verdicts: {}, max: 0, worst: '', detail: '' };
  if (compileError) { row.verdicts.CE = P.cases.length; row.detail = compileError.split('\n').slice(1, 4).join(' ').slice(0, 300); return row; }
  const tl = P.info.timelimit * factor * 1000;
  const tmp = path.join(P.dir, '.local', 'salida.txt');
  for (const c of P.cases) {
    const inF = path.join(P.dir, 'in', c.name + '.in'), ans = path.join(P.dir, 'out', c.name + '.out');
    const fi = fs.openSync(inF, 'r'), fo = fs.openSync(tmp, 'w');
    const t0 = process.hrtime.bigint();
    const r = spawnSync(out, [], { stdio: [fi, fo, 'pipe'], timeout: tl + 2000, maxBuffer: 1 << 26 });
    const ms = Number(process.hrtime.bigint() - t0) / 1e6;
    fs.closeSync(fi); fs.closeSync(fo);
    let v;
    if (ms > tl || (r.error && r.error.code === 'ETIMEDOUT')) v = 'TLE';
    else if (r.status !== 0) v = 'RE';
    else {
      const ch = spawnSync(P.checker, [rel(P.dir, inF), rel(P.dir, tmp), rel(P.dir, ans)], { encoding: 'utf8', cwd: P.dir });
      v = ch.status === 0 ? 'AC' : 'WA';
      if (v === 'WA' && !row.detail) row.detail = `${c.name}: ${(ch.stdout + ch.stderr).trim().slice(0, 200)}`;
    }
    if (v === 'RE' && !row.detail) row.detail = `${c.name}: código ${r.status ?? r.signal} ${(r.stderr || '').toString().slice(0, 150)}`;
    if (v === 'TLE' && !row.detail) row.detail = `${c.name}: > ${(tl / 1000).toFixed(1)}s`;
    row.verdicts[v] = (row.verdicts[v] || 0) + 1;
    if (ms > row.max) { row.max = ms; row.worst = c.name; }
  }
  return row;
}

// ---------------- main ----------------
const adapters = fs.readdirSync(here).filter((f) => f.endsWith('.cpp')).sort()
  .filter((f) => !filters.length || filters.some((x) => f.includes(x)));
const rows = [];
for (const f of adapters) {
  const row = judge(path.join(here, f));
  if (!row) continue;
  const v = Object.entries(row.verdicts).map(([k, n]) => `${k}×${n}`).join(' ');
  const status = Object.keys(row.verdicts).length === 1 && row.verdicts.AC ? 'AC' : Object.keys(row.verdicts).filter((k) => k !== 'AC').join('/');
  row.status = status;
  console.log(`  ${status.padEnd(7)} ${f.padEnd(52)} ${v.padEnd(14)} máx ${(row.max / 1000).toFixed(2)}s (${row.worst})${row.detail ? '\n          ' + row.detail : ''}`);
  rows.push(row);
}
if (!filters.length) {
  const lines = ['# Resultados contra Library Checker (casos oficiales, juez local)', '',
    `Generado por \`node _pruebas/yosupo/juez.mjs\` el ${new Date().toISOString().slice(0, 10)}. ` +
    'Los casos se generaron con los generadores oficiales y coinciden byte a byte con `hash.json` del repositorio. ' +
    'Los tiempos son de esta máquina (g++ MinGW, -O2), no del servidor del juez.', '',
    '| Veredicto | Adaptador | Problema | Archivo del notebook | Casos | Máx. tiempo | Detalle |', '| --- | --- | --- | --- | --- | --- | --- |'];
  for (const r of rows) {
    const total = Object.values(r.verdicts).reduce((a, b) => a + b, 0);
    lines.push(`| ${r.status} | [${r.adapter}](${r.adapter}) | [${r.slug}](https://judge.yosupo.jp/problem/${r.slug}) | [${r.target}](../../${r.target}) | ${r.verdicts.AC || 0}/${total} | ${(r.max / 1000).toFixed(2)} s | ${(r.detail || '').replace(/\|/g, '\\|').replace(/\n/g, ' ')} |`);
  }
  fs.writeFileSync(path.join(here, 'resultados.md'), lines.join('\n') + '\n');
  console.log('\nResumen escrito en _pruebas/yosupo/resultados.md');
}
