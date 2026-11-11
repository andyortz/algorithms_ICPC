// prueba: 03_Arboles/DSU_on_Tree/dsu-on-tree-sack-extra.cpp
// Tras dfs(u, padre, true), cnt[c] = nodos del subárbol de u con color c.
#include "../../03_Arboles/DSU_on_Tree/dsu-on-tree-sack-extra.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 60);
        for (int i = 0; i < n; i++) g[i].clear(), col[i] = rnd(0, 5);
        vector<int> par(n, -1);
        for (int i = 1; i < n; i++) { par[i] = it % 4 == 0 ? i - 1 : rnd(0, i - 1); g[i].pb(par[i]); g[par[i]].pb(i); }
        for (int u = 0; u < n; u++) {
            pre(0, -1);
            for (int c = 0; c <= 5; c++) cnt[c] = 0;
            dfs(u, par[u], true);
            vector<int> exp(6, 0);
            for (int z = 0; z < n; z++) { int y = z; while (y != -1 && y != u) y = par[y]; if (y == u) exp[col[z]]++; }
            for (int c = 0; c <= 5; c++) CHECK(cnt[c] == exp[c]);
        }
    }
    FIN("dsu-on-tree");
}
