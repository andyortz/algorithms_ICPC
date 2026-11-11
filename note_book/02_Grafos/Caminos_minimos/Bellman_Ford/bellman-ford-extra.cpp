// Tema: 02_Grafos/Caminos_minimos/Bellman_Ford
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (2 líneas).
// Adaptación: Alias de tipos ausentes declarados localmente: ll, pii.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_ABFD96ED0B1DD5C3
#define NOTEBOOK_GENERADO_ABFD96ED0B1DD5C3
#include "../../../_base/template-simple.hpp"
using ll = long long;
using pii = pair<int, int>;
// Dado un grafo con pesos, positivos o negativos, halla la ruta de costo minimo entre un nodo inicial u y todos los demas nodos.
// Tambien halla ciclos negativos.

const ll inf = 1e18;
const int MX = 1e5+5; // Cantidad maxima de nodos
vector<pii> g[MX]; // Lista de adyacencia, u->[(v, cost)]
vector<ll> dist; // Almacena la distancia a cada nodo
// vector<int> cycle; // Para construir el ciclo negativo
int n, m; // Cantidad de nodos y aristas

// O(n*m)
void bellmanFord(int src) {
    dist.assign(n, inf);
    dist[src] = 0;
    for (int i = 0; i < n-1; i++) 
        for (int u = 0; u < n; u++) 
            if (dist[u] != inf) 
                for (auto &v : g[u]) {
                    dist[v.first] = min(dist[v.first], dist[u] + v.second);
                }
    // Encontrar ciclos negativos
    // cycle.clear();
    for (int u = 0; u < n; u++) 
        if (dist[u] != inf) 
            for (auto &v : g[u]) 
                if (dist[v.first] > dist[u] + v.second) { // Ciclo negativo
                    dist[v.first] = -inf;
                    // cycle.pb(v.F); // Para reconstruir
                }
}

void init() {
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}
#endif
