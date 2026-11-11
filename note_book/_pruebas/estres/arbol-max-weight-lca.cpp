// prueba: 03_Arboles/LCA_y_binary_lifting/max-weight-lca.cpp  (1-indexado, pesos >= 0)
#include "../../03_Arboles/LCA_y_binary_lifting/max-weight-lca.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        n = rnd(1, 80);
        for (int i = 1; i <= n; i++) adj[i].clear(), vis[i] = 0;
        vector<ll> par(n + 1, 0), w(n + 1, 0), dep(n + 1, 0);
        for (int i = 2; i <= n; i++) { par[i] = it % 4 == 0 ? i - 1 : rnd(1, i - 1); w[i] = rnd(0, 1e9); dep[i] = dep[par[i]] + 1; adj[i].pb({par[i], w[i]}); adj[par[i]].pb({i, w[i]}); }
        build();
        for (int k = 0; k < 100; k++) {
            ll a = rnd(1, n), b = rnd(1, n), x = a, y = b, m = 0;
            while (x != y) { if (dep[x] < dep[y]) swap(x, y); m = max(m, w[x]); x = par[x]; }
            CHECK(mxedge(a, b) == m);
        }
    }
    FIN("max-weight-lca");
}
