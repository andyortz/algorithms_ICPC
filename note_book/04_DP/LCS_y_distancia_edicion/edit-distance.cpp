// Selección: Se conserva la DP O(n*m); eliminada la alternativa recursiva exponencial.
// Tema: 04_DP/LCS_y_distancia_edicion
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl, vvl.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_CF8094248A38B7ED
#define NOTEBOOK_GENERADO_CF8094248A38B7ED
#include "../../_base/template-simple.hpp"
using ll = long long;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
// My own
ll editDistance(string &s, string &t) {
    ll n = s.size();
    ll m = t.size();
    vvl dp(n+1, vl(m+1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (min(i, j) == 0) dp[i][j] = max(i, j);
            else if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
        }
    }
    return dp[n][m];
}
#endif
