// prueba: 03_Arboles/Descomposicion_SQRT/block-tree.cpp
// update(lvl, v): suma v a todos los nodos de profundidad lvl; query(x): suma del subárbol de x.
#include "../../03_Arboles/Descomposicion_SQRT/block-tree.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 60; it++) {
        int n = it < 20 ? rnd(1, 40) : rnd(400, 1500);
        vector<vector<ll>> adj(n); vector<ll> par(n, -1), dep(n, 0), val(n, 0);
        for (int i = 1; i < n; i++) { par[i] = it % 4 == 0 ? i - 1 : rnd(max(0LL, (ll)i - rnd(1, 50)), i - 1); adj[i].pb(par[i]); adj[par[i]].pb(i); dep[i] = dep[par[i]] + 1; }
        BlockTree bt(n, adj);
        ll maxd = *max_element(dep.begin(), dep.end());
        for (int k = 0; k < 150; k++) {
            if (rnd(0, 1)) { ll lvl = rnd(0, maxd), v = rnd(-1000, 1000); bt.update(lvl, v); for (int i = 0; i < n; i++) if (dep[i] == lvl) val[i] += v; }
            else {
                int x = rnd(0, n - 1); ll s = 0;
                for (int z = 0; z < n; z++) { int y = z; while (y != -1 && y != x) y = par[y]; if (y == x) s += val[z]; }
                CHECK(bt.query(x) == s);
            }
        }
    }
    FIN("block-tree");
}
