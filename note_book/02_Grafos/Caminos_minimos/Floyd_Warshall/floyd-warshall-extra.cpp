// Tema: 02_Grafos/Caminos_minimos/Floyd_Warshall
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_DACAB54C9DC3BB87
#define NOTEBOOK_GENERADO_DACAB54C9DC3BB87
#include "../../../_base/template-simple.hpp"

// Dado un grafo halla la distancia minima entre cualquier par de nodos. g[i][j] guardara la distancia minima entre el nodo i y el j.

const int inf = 1e9;
const int MX = 505; // Cantidad maxima de nodos
int g[MX][MX]; // Matriz de adyacencia
int n, m; // Cantidad de nodos y aristas

void floydWarshall() {
    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

void init() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            g[i][j] = (i == j ? 0 : inf);
        }
    }
}
#endif
