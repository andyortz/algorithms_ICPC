// Tema: 02_Grafos/Orden_topologico
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_C08AC565D4A030EB
#define NOTEBOOK_GENERADO_C08AC565D4A030EB
#include "../../_base/template-simple.hpp"
using ll = long long;
// Find the topological order of a graph in O(n)
const int N = 1e5;
vector<vector<ll>> adj(N + 10);
vector<ll> visited(N +10);
bool cycle = false; // reports if doesn't exists a topological sort
vector<ll> topo;

void dfs(ll x) {
    if (visited[x] == 2) {
        return;
    } else if (visited[x] == 1) {
        cycle = true;
        return;
    }
    visited[x] = 1;
    for (auto y : adj[x]) dfs(y);
    visited[x] = 2;
    topo.pb(x);
}

void test_case() {
    ll n, m; cin >> n >> m;
    for (int i =0; i < m; i++) {
        ll x, y; cin >> x >> y;
        adj[x].pb(y);
    }
    for (int i = 1; i <= n; i++) dfs(i);
    reverse(topo.begin(), topo.end());
    if (cycle) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i =0; i < n; i++) {
            cout << topo[i] << " \n" [i == n - 1];
        }
    }
}
#endif
