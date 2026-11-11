// Tema: 02_Grafos/Recorridos_y_conectividad
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (2 líneas).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_7663AB7D8B460390
#define NOTEBOOK_GENERADO_7663AB7D8B460390
#include "../../_base/template-simple.hpp"

// Busqueda en profundidad sobre grafos. Recibe un nodo inicial u y visita todos los nodos alcanzables desde u.
// DFS puede ser usado para contar la cantidad de componentes conexas en un grafo y puede ser modificado para que retorne informacion de los nodos dependiendo del problema.

const int MX = 1e5+5; // Cantidad maxima de nodos
vector<int> g[MX]; // Lista de adyacencia
vector<bool> vis; // Marca los nodos ya visitados
int n, m; // Cantidad de nodos y aristas

void dfs(int u) {
    vis[u] = true;
    for (auto &v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}

void init() {
    vis.assign(n, false);
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}
#endif
