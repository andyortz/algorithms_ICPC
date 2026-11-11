// Tema: 04_DP/Cambio_de_monedas
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_64B4234D8C8E1986
#define NOTEBOOK_GENERADO_64B4234D8C8E1986
#include "../../_base/template-simple.hpp"
using ll = long long;
using vl = vector<long long>;
// infinite number of coins
// Get the minimum number of coins that sum a value.
void test_case() {
    ll n, x;
    cin >> n >> x;
    vl dp(x + 1, inf - 1);
    vl coin(n);
    for (int i=(0), nb_fin_1=(n); i<nb_fin_1; ++i) cin >> coin[i];
    dp[0] = 0;
    for (int i=(0), nb_fin_3=(x); i<nb_fin_3; ++i) {
        for (auto &c : coin) {
            if (c + i > x) continue;
            dp[i + c] = min(dp[i + c], dp[i] + 1);
        }
    }
    if (dp[x] + 1== inf) {
        cout << "-1\n";
    } else {
        cout << dp[x] << "\n";
    }
}
#endif
