// Tema: 04_DP/Mascaras_y_TSP
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl, vvl.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_B71725807FEA0AED
#define NOTEBOOK_GENERADO_B71725807FEA0AED
#include "../../_base/template-simple.hpp"
using vpl = vector<pair<long long, long long>>;
using ll = long long;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
// Given directed weighted graph, gets the minimun halmilton cycle. 
// Use dfs(0, 1<<(initial)), if 1e9 then it impossible, otherwise get the min.
const int MAX_SIZE = 15;
const ll IMPOSSIBLE = 1e9;
ll INITIAL = 0; // initial node
vpl adj[MAX_SIZE];
vvl dp(MAX_SIZE, vl(1 << MAX_SIZE, -1));
ll n, m;
ll target; // init as (1 << n) - 1, full visited

ll dfs(ll x, ll mask) {
    if (dp[x][mask] != -1) {
        return dp[x][mask];
    }
    if (mask == target) {
        for (auto &yy : adj[x]) {
            if (yy.first == INITIAL) {
                return yy.second;
            }
        }
        return dp[x][mask] = IMPOSSIBLE;
    }
    ll ans = IMPOSSIBLE;
    for (auto &yy : adj[x]) {
        ll y, d;
        tie(y, d) = yy;
        if ((mask >> y) & 1) continue;
        ll actual = dfs(y, mask | (1 << y)) + d;
        ans = min(ans, actual);
    }
    return dp[x][mask] = ans;
}
#endif
