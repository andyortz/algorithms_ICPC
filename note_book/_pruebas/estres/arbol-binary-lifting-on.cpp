// prueba: 03_Arboles/LCA_y_binary_lifting/binary-lifting-o-n-memory.cpp  (find y lca)
#include "../../03_Arboles/LCA_y_binary_lifting/binary-lifting-o-n-memory.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        int n = rnd(1, 120); bool camino = it % 4 == 0;
        vector<ll> par(n, 0), dep(n, 0); vector<pNode> nd(n);
        nd[0] = new Node(); nd[0]->de = 0; nd[0]->par = nd[0]->go = nd[0];
        for (int i = 1; i < n; i++) { par[i] = camino ? i - 1 : rnd(0, i - 1); dep[i] = dep[par[i]] + 1; nd[i] = add(nd[par[i]], i); }
        map<pNode, ll> id; for (int i = 0; i < n; i++) id[nd[i]] = i;
        for (int k = 0; k < 100; k++) {
            ll x = rnd(0, n - 1), y = rnd(0, n - 1), a = x, b = y;
            while (dep[a] > dep[b]) a = par[a];
            while (dep[b] > dep[a]) b = par[b];
            while (a != b) a = par[a], b = par[b];
            CHECK(id[lca(nd[x], nd[y])] == a);
            ll d = rnd(0, dep[x]), z = x; while (dep[z] > d) z = par[z];
            CHECK(id[find(nd[x], d)] == z);
        }
    }
    FIN("binary-lifting-o-n-memory");
}
