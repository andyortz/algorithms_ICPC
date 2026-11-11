// Tema: 03_Arboles/Isomorfismo_y_hashing
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (2 líneas).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_060F96EEBD6B142C
#define NOTEBOOK_GENERADO_060F96EEBD6B142C
#include "../../_base/template-simple.hpp"
using ll = long long;
using ull = unsigned long long;
// Hash de árboles enraizados: hash(u) = R[suma de hash(hijos)], R aleatoria de 64 bits.
// Subárboles isomorfos <=> mismo hash (colisión ~n^2/2^64). Iterativo; O(n log n).
// Tested https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification

mt19937_64 rngIso(chrono::steady_clock::now().time_since_epoch().count());
map<ull, ull> table;

ull get(ull x) {
    auto it = table.find(x);
    if (it != table.end()) return it->second;
    return table[x] = rngIso();
}

vector<ull> hashes, sum;

// g: lista de adyacencia (dirigida padre->hijos o no dirigida). Calcula hashes[u] del
// subárbol de u con raíz root. O(n log n) por el map.
void dfs(const vector<vector<int>> &g, int root) {
    int n = g.size();
    hashes.assign(n, 0); sum.assign(n, 0);
    vector<int> order = {root}, par(n, -1);
    for (size_t k = 0; k < order.size(); k++) {
        int u = order[k];
        for (int v : g[u]) if (v != par[u]) par[v] = u, order.pb(v);
    }
    for (int k = (int)order.size() - 1; k >= 0; k--) {   // hijos antes que padres
        int u = order[k];
        hashes[u] = get(sum[u]);
        if (par[u] >= 0) sum[par[u]] += hashes[u];
    }
}
#endif
