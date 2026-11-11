// prueba: 03_Arboles/LCA_y_binary_lifting/lowest-common-ancestor.cpp  (query y kParent)
#include "../../03_Arboles/LCA_y_binary_lifting/lowest-common-ancestor.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        int n = rnd(1, 80); bool camino = it % 4 == 0;
        vector<ll> par(n, -1), dep(n, 0); vvl ch(n);
        for (int i = 1; i < n; i++) { par[i] = camino ? i - 1 : rnd(0, i - 1); ch[par[i]].pb(i); dep[i] = dep[par[i]] + 1; }
        init(ch, n);
        for (int k = 0; k < 100; k++) {
            ll x = rnd(0, n - 1), y = rnd(0, n - 1), a = x, b = y;
            while (dep[a] > dep[b]) a = par[a];
            while (dep[b] > dep[a]) b = par[b];
            while (a != b) a = par[a], b = par[b];
            CHECK(query(x, y) == a);
            ll kk = rnd(0, dep[x]), z = x; for (int j = 0; j < kk; j++) z = par[z];
            CHECK(kParent(x, kk) == z);
        }
    }
    FIN("lowest-common-ancestor");
}
