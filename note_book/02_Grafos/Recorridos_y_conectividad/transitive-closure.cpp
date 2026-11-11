// Tema: 02_Grafos/Recorridos_y_conectividad
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_821CD411A085AE12
#define NOTEBOOK_GENERADO_821CD411A085AE12
#include "../../_base/template-simple.hpp"
using ll = long long;
/* Transitive Closure O(n^3)
Check if from A can reach B in an undirected graph.
*/
const int inf = 1e9;
vector<int> adj[n];
ll distance[n][n];

void floydWarshall() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			distance[i][j] = false;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int b : adj[i]) {
			distance[i][b] = true;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				distance[i][j] |= distance[i][k] & distance[k][j];
			}
		}
	}
}
#endif
