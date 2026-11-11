// Tema: 05_Flujos_y_matching/Corte_minimo
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_04D1DEBF647D9168
#define NOTEBOOK_GENERADO_04D1DEBF647D9168
#include "../../_base/template-simple.hpp"

// Halla el corte mínimo en un grafo no dirigido y con pesos O(V ^ 3)

struct stoer_wagner {
    int n;
    vector<vector<int>> g;

    stoer_wagner(int n) : n(n), g(n, vector<int>(n)) {}

    void add_edge(int a, int b, int w) {
        g[a][b] = g[b][a] = w;
    }

    pair<int, vector<int>> min_cut() {
        vector<int> used(n);
        vector<int> cut, best_cut;
        int best_weight = -1;
        for (int p = n-1; p >= 0; --p) {
            vector<int> w = g[0];
            vector<int> added = used;
            int prv, lst = 0;
            for (int i = 0; i < p; ++i) {
                prv = lst; lst = -1;
                for (int j = 1; j < n; ++j) {
                    if (!added[j] && (lst == -1 || w[j] > w[lst])) lst = j;
                }
                if (i == p-1) {
                    for (int j = 0; j < n; j++) 
                        g[prv][j] += g[lst][j];
                    for (int j = 0; j < n; j++) 
                        g[j][prv] = g[prv][j];
                    used[lst] = true;
                    cut.pb(lst);
                    if (best_weight == -1 || w[lst] < best_weight) {
                        best_cut = cut;
                        best_weight = w[lst];
                    }
                } else {
                    for (int j = 0; j < n; j++) 
                        w[j] += g[lst][j];
                    added[lst] = true;
                }
            }
        }
        return {best_weight, best_cut}; // best_cut contains all nodes in the same set
    }
};
#endif
