// Tema: 04_DP/Mascaras_y_SOS
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: n, M y vectores; pegar el bloque dentro de solve().
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_5BFAA466007AB3FA
#define NOTEBOOK_GENERADO_5BFAA466007AB3FA
#include "../../_base/template-simple.hpp"
using ll = long long;
// Useful to calculate reverse sos DP. 
// DP[x] = op(DP[y_1], DP[y_2], ...), where x is submask of y_i 
 
    vector<ll> nums(n);
    for (int i =0;i<n;i++) {
        nums[i] = rd(); // read submask, and set init state
        dp[nums[i]] = min(dp[nums[i]], {0, i});
    }

    
    for (int mask = (1<<m)-1; mask >= 0; mask--) { // You can switch fors depends of the problem
        if (dp[mask].first > 0) continue; // Don't propagate

        for (int i =0;i<m;i++) {
            if ((mask>>i)&1) { // Propagate to all submasks
                auto nxt = dp[mask]; nxt.first--; 
                dp[mask^(1ll<<i)] = min(dp[mask^(1ll<<i)], nxt);
            }
        }
    }
#endif
