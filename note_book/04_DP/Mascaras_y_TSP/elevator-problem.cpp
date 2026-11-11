// Tema: 04_DP/Mascaras_y_TSP
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_79E9E8C67B7FDFC9
#define NOTEBOOK_GENERADO_79E9E8C67B7FDFC9
#include "../../_base/template-simple.hpp"
using ll = long long;
using vl = vector<long long>;
// Given n <= 20 persons, print the minimum number of travels
// to move everyone in a elevator with capacity k.

ll n, k;
vl nums;
vector<pair<ll,ll>> dp;
 
// minimum travels, last travel with minimum weight. 
// use  f((1 << n) - 1).F 
pair<ll,ll> f(ll mask) {
    if (dp[mask] != make_pair(-1ll, -1ll)) {
        return dp[mask];
    }
    if (mask == 0) {
        return dp[mask] = {0, k};
    }
    dp[mask] = {n + 1, 0}; // one person in a travel, or use popcount.
    for (int i = 0; i < n; i++) {
        // person i is the last to enter to elevator.
        if ((mask >> i) & 1) {
            auto actual = f(mask ^ (1 << i)); // best option without this last person.
            if (actual.second + nums[i] <= k) {
                actual.second += nums[i];
                // what happened if there are a better minimum.
                // well in that case the last person should be other one.
                // so we are trying all options that last person will be better.
            } else {
                actual.second = nums[i];
                actual.first++;
            }
            dp[mask] = min(dp[mask], actual);
        }
    }
    return dp[mask];
}


// Iterative
void test_case() {
    ll n, k;
    cin >> n >> k;
    vl nums(n);
    vector<pair<ll,ll>> dp(1 << n, {n+1, 0});
    for (int i =0; i < n; i++) cin >> nums[i];
    dp[0] = {0, k};
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i& (1 << j)) {
                auto actual = dp[i ^ (1 << j)];
                if (actual.second + nums[j] <= k) {
                    actual.second += nums[j];
                } else {
                    actual.first++;
                    actual.second = nums[j];
                }
                dp[i] = min(dp[i], actual);
            }
        }
    }
    cout << dp[(1 << n) -1].first << "\n";
}
#endif
