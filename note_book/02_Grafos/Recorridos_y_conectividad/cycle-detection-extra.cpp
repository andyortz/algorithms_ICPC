// Tema: 02_Grafos/Recorridos_y_conectividad
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_D4056D8C5CBA2412
#define NOTEBOOK_GENERADO_D4056D8C5CBA2412
#include "../../_base/template-simple.hpp"

// Determina si un grafo dirigido tiene o no ciclos (si es un DAG o no).

const int MX = 1e5+5; // Cantidad maxima de nodos
vector<int> g[MX]; // Lista de adyacencia
vector<int> vis; // Marca el estado de los nodos ya visitados
bool cycle; // true si el grafo tiene ciclos
int n, m; // Cantidad de nodos y aristas

void dfs(int u) {
    if (cycle) return;
    vis[u] = 1;
    for (auto &v : g[u]) {
        if (!vis[v]) dfs(v);
        else if (vis[v] == 1) {
            cycle = true;
            break;
        }
    }
    vis[u] = 2;
}

void init() {
    vis.assign(n, 0);
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}
#endif
