// yosupo: dynamic_tree_vertex_add_path_sum
// prueba: 03_Arboles/Link_Cut_Tree/link-cut.cpp
#include "../../03_Arboles/Link_Cut_Tree/link-cut.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    vector<Node> nd(n);
    for (int i = 0; i < n; i++) { int a; cin >> a; nd[i] = new Node_t(a); }
    for (int i = 0; i + 1 < n; i++) { int u, v; cin >> u >> v; link(nd[u], nd[v]); }
    while (q--) {
        int t; cin >> t;
        if (t == 0) { int u, v, w, x; cin >> u >> v >> w >> x; cut(nd[u], nd[v]); link(nd[w], nd[x]); }
        else if (t == 1) { int p, x; cin >> p >> x; modify(nd[p], nd[p], x); }
        else { int u, v; cin >> u >> v; cout << query(nd[u], nd[v]) << '\n'; }
    }
}
