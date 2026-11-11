// Requisito de selección: El ejemplo original no lee/inicializa n ni m antes de reservar dist; completar la entrada antes de ejecutarlo.
// Tema: 02_Grafos/Caminos_minimos/Floyd_Warshall
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_FA68DE77C1F0CD8C
#define NOTEBOOK_GENERADO_FA68DE77C1F0CD8C
#include "../../../_base/template-simple.hpp"
using ll = long long;
// Distancia mínima de todo i a todo j con pesos negativos. dist = -inf: hay ciclo negativo en
// algún camino i->j; inf: no alcanzable. Todo camino real debe ser < inf.
const ll inf = INT32_MAX;
void test_case() {
    ll n, m; // nodes, edges
    vector<vector<ll>> dist(n, vector<ll>(n, inf));
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        ll a, b, w;
        cin >> a >> b >> w; // negative weights
        dist[a][b] = min(dist[a][b], w);
    }
    // floid warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] == inf || dist[k][j] == inf) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    // find negative cycles for a node
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) dist[i][i] = -inf;
    }
    // find negative cycles betweens a routes from i to j
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n ; j++) {
            for (int k = 0; k < n; k++) {
                if (dist[k][k] < 0 && dist[i][k] != inf && dist[k][j] != inf) {
                    dist[i][j] = -inf;
                }
            }
        }
    }
}
#endif
