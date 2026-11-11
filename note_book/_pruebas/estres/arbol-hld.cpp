// prueba: 03_Arboles/Heavy_Light/hld-lca-con-heavy-paths.cpp
// hldQuery = máximo en el camino (valores >= 0: res empieza en 0). segQuery se implementa aquí.
#include "../../03_Arboles/Heavy_Light/hld-lca-con-heavy-paths.cpp"
#include "comun.hpp"
vector<ll> base;
int segQuery(int l, int r) { ll m = 0; for (int i = l; i <= r; i++) m = max(m, base[i]); return m; }
signed main() {
    for (int it = 0; it < 500; it++) {
        int n = rnd(1, 80);
        G.assign(n, {}); vector<ll> par(n, -1), val(n);
        for (int i = 1; i < n; i++) { par[i] = it % 4 == 0 ? i - 1 : rnd(0, i - 1); G[i].pb(par[i]); G[par[i]].pb(i); }
        for (auto& x : val) x = rnd(0, 1e9);
        init(n);
        base.assign(n, 0); for (int v = 0; v < n; v++) base[pos[v]] = val[v];
        vector<ll> dep(n, 0); for (int i = 1; i < n; i++) dep[i] = dep[par[i]] + 1;
        for (int k = 0; k < 100; k++) {
            ll a = rnd(0, n - 1), b = rnd(0, n - 1), m = 0;
            ll x = a, y = b;
            while (x != y) { if (dep[x] < dep[y]) swap(x, y); m = max(m, val[x]); x = par[x]; }
            m = max(m, val[x]);
            CHECK(hldQuery(a, b) == m);
        }
    }
    FIN("hld");
}
