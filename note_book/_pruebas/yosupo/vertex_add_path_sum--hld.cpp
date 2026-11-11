// yosupo: vertex_add_path_sum
// prueba: 03_Arboles/Heavy_Light/hld-lca-con-heavy-paths.cpp
// hldQuery del archivo combina con max, así que la suma por camino se escribe aquí con los
// arreglos de la descomposición (head, pos, parent, depth) y el Fenwick del notebook.
#include "../../03_Arboles/Heavy_Light/hld-lca-con-heavy-paths.cpp"
#include "../../01_Estructuras/Fenwick/fenwick-tree.cpp"
using ll = long long;
int segQuery(int, int) { return 0; }
signed main() {
    fast;
    int n, q; cin >> n >> q;
    vi a(n); for (auto& x : a) cin >> x;
    G.assign(n, {});
    for (int i = 0; i + 1 < n; i++) { int u, v; cin >> u >> v; G[u].pb(v); G[v].pb(u); }
    init(n);
    FenwickTree ft(n);
    for (int v = 0; v < n; v++) ft.add(pos[v], a[v]);
    auto path = [&](int x, int y) {
        ll res = 0;
        for (; head[x] != head[y]; y = parent[head[y]]) {
            if (depth[head[x]] > depth[head[y]]) swap(x, y);
            res += ft.sum(pos[head[y]], pos[y]);
        }
        if (depth[x] > depth[y]) swap(x, y);
        return res + ft.sum(pos[x], pos[y]);
    };
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 0) ft.add(pos[x], y); else cout << path(x, y) << '\n';
    }
}
