// Tema: 01_Estructuras/DSU
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: pii.
// Requisito: Contiene main de ejemplo/prueba: usar su main o el de simple.cpp, nunca ambos.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_7EA4CF747FE896AC
#define NOTEBOOK_GENERADO_7EA4CF747FE896AC
#include "../../_base/template-simple.hpp"
using pii = pair<int, int>;
// DSU con rollback: unite y find O(log n) (sin compresión de caminos), rollback O(1).
// par = padre, sz[find(x)] = tamaño; sp/ss = pilas (nodo, valor previo) para deshacer.

int par[N], sz[N];
stack <pii> sp, ss;

int find (int a) { return par[a] == a ? a : find(par[a]); }

void unite (int a, int b) {
    if ((a = find(a)) == (b = find(b))) return;
    if (sz[a] < sz[b]) swap(a, b);
    ss.push({a, sz[a]});
    sp.push({b, par[b]});
    sz[a] += sz[b];
    par[b] = a;
}

void rollback() {
    par[sp.top().st] = sp.top().nd; sp.pop();
    sz[ss.top().st]  = ss.top().nd; ss.pop();
}

signed main(){
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;
    return 0;
}
#endif
