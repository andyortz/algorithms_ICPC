// prueba: 03_Arboles/Descomposicion_centroide/centroid-decomposition-extra.cpp
// upd(u) marca u; query(u) = distancia mínima de u a un nodo marcado.
#include "../../03_Arboles/Descomposicion_centroide/centroid-decomposition-extra.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 60);
        for (int i = 0; i < n; i++) g[i].clear(), dep[i] = 0, dist[i].clear();
        for (int i = 1; i < n; i++) { int p = it % 4 == 0 ? i - 1 : rnd(0, i - 1); g[i].pb(p); g[p].pb(i); }
        c_ans.assign(n, N);
        build(0);
        vector<int> marked(n, 0);
        for (int k = 0; k < 100; k++) {
            int u = rnd(0, n - 1);
            if (rnd(0, 1)) { upd(u); marked[u] = 1; }
            else if (count(marked.begin(), marked.end(), 1)) {
                vector<int> d(n, -1); d[u] = 0; vector<int> q = {u}; int best = INT_MAX;
                for (size_t i = 0; i < q.size(); i++) { int x = q[i]; if (marked[x]) best = min<ll>(best, d[x]); for (int y : g[x]) if (d[y] < 0) d[y] = d[x] + 1, q.pb(y); }
                CHECK(query(u) == best);
            }
        }
    }
    FIN("centroid-decomposition");
}
