// Pruebas de estrés del notebook contra fuerza bruta.
// Uso (desde note_book):  node _pruebas/estres/correr.mjs [filtro ...]
// Compila cada prueba con -D_GLIBCXX_ASSERTIONS (accesos fuera de rango en vector abortan) y
// pila de 256 MB; la ejecuta y registra el resultado en resultados.md (solo sin filtros).
import { spawnSync } from 'node:child_process';
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const here = path.dirname(fileURLToPath(import.meta.url));
const filters = process.argv.slice(2);
const exe = process.platform === 'win32' ? '.exe' : '';
const bin = path.join(here, '.bin');
fs.mkdirSync(bin, { recursive: true });
// g++ de MinGW recibe argv en ANSI: se usan rutas relativas (sin "ó") con cwd = esta carpeta.
const flags = ['-std=gnu++20', '-O2', '-D_GLIBCXX_ASSERTIONS', ...(process.platform === 'win32' ? ['-Wl,--stack,268435456'] : [])];

const tests = fs.readdirSync(here).filter((f) => f.endsWith('.cpp')).sort()
  .filter((f) => !filters.length || filters.some((x) => f.includes(x)));
const rows = [];
for (const f of tests) {
  const src = fs.readFileSync(path.join(here, f), 'utf8');
  const target = (src.match(/\/\/\s*prueba:\s*(.+)/) || [])[1]?.trim() ?? '?';
  const out = `.bin/${path.parse(f).name}${exe}`;
  let status, detail = '', ms = 0;
  const c = spawnSync('g++', [...flags, '-o', out, f], { cwd: here, encoding: 'utf8' });
  if (c.status !== 0) {
    status = 'CE';
    detail = (c.stderr || '').split('\n').filter((l) => /error/.test(l)).slice(0, 2).join(' ').slice(0, 300);
  } else {
    const t0 = Date.now();
    const r = spawnSync(path.join(here, out), [], { cwd: here, encoding: 'utf8', timeout: 120000, maxBuffer: 1 << 26 });
    ms = Date.now() - t0;
    const text = ((r.stdout || '') + (r.stderr || '')).trim().split('\n');
    detail = text[text.length - 1] || '';
    status = r.status === 0 ? 'OK' : (r.error && r.error.code === 'ETIMEDOUT') ? 'TLE' : 'FALLO';
    if (status === 'FALLO' && r.status !== 1) detail = `código ${r.status} (acceso inválido / assert) ${detail}`;
  }
  console.log(`  ${status.padEnd(6)} ${f.padEnd(44)} ${(ms / 1000).toFixed(2)}s  ${detail}`);
  rows.push({ f, target, status, detail, ms });
}
if (!filters.length) {
  const lines = ['# Pruebas de estrés contra fuerza bruta', '',
    `Generado por \`node _pruebas/estres/correr.mjs\` el ${new Date().toISOString().slice(0, 10)}. ` +
    'Cada prueba ejecuta miles de operaciones aleatorias pequeñas y compara cada respuesta con una implementación ingenua. ' +
    'Compilado con `-D_GLIBCXX_ASSERTIONS` (un acceso fuera de rango en `vector` aborta).', '',
    '| Estado | Prueba | Archivo del notebook | Tiempo | Detalle |', '| --- | --- | --- | --- | --- |'];
  for (const r of rows) lines.push(`| ${r.status} | [${r.f}](${r.f}) | [${r.target}](../../${r.target}) | ${(r.ms / 1000).toFixed(2)} s | ${r.detail.replace(/\|/g, '\\|')} |`);
  fs.writeFileSync(path.join(here, 'resultados.md'), lines.join('\n') + '\n');
  console.log('\nResumen escrito en _pruebas/estres/resultados.md');
}
