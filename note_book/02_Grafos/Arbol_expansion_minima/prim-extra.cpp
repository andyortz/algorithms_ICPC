// Tema: 02_Grafos/Arbol_expansion_minima
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_4672E08AD0B5DF2E
#define NOTEBOOK_GENERADO_4672E08AD0B5DF2E
#include "../../_base/template-simple.hpp"
using ll = long long;
// Dado un grafo halla el costo total de su arbol cobertor minimo.

struct edge {
    int v; ll w;

    bool operator < (const edge &o) const {
        return o.w < w; // invertidos para que la pq ordene de < a >
    }
};

const int MX = 1e5+5; // Cantidad maxima de nodos
vector<edge> g[MX]; // Lista de adyacencia
vector<bool> vis; // Marca los nodos ya visitados
ll ans; // Costo total del arbol cobertor minimo
int n, m; // Cantidad de nodos y aristas

void prim() {
    priority_queue<edge> pq;
    vis[0] = true;
    for (auto &ed : g[0]) {
        int v = ed.v;
        if (!vis[v]) pq.push({v, ed.w});
    }
    while (pq.size()) {
        int u = pq.top().v;
        ll w = pq.top().w;
        pq.pop();
        if (!vis[u]) {
            ans += w;
            vis[u] = true;
            for (auto &ed : g[u]) {
                int v = ed.v;
                if (!vis[v]) pq.push({v, ed.w});
            }
        }
    }
}

void init() {
    ans = 0;
    vis.assign(n, false);
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}
#endif
