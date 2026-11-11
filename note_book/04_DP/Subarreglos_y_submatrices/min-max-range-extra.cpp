// Tema: 04_DP/Subarreglos_y_submatrices
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: El original carece de return ans, inicializa ans a -1 para minimizar y recurre con i+1 aunque el corte termina en j: revisar transición e inicialización antes de usar.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_76FFDA3300291449
#define NOTEBOOK_GENERADO_76FFDA3300291449
#include "../../_base/template-simple.hpp"
using ll = long long;
// Devuelve el el minimo de los maximos entre pares de rangos consecutivos haciendo cortes en el Array.

const int MAX = 1005;
ll dp[MAX][MAX];
ll sum_ran[MAX][MAX];
int N;

ll f(int i, int cuts) {
    if (cuts == 0) return sum_ran[i][N-1];
    if (i == N) return 0;
    ll &ans = dp[i][cuts];
    if (ans != - 1) return ans;
    for (int j = i; j < N; j++) {
        ans = min(ans, max(sum_ran[i][j], f(i + 1, cuts - 1)));
    }
}
#endif
