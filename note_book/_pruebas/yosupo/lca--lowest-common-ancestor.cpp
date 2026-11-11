// yosupo: lca
// prueba: 03_Arboles/LCA_y_binary_lifting/lowest-common-ancestor.cpp
// Se usa tal cual (LOG = 18). Library Checker tiene N hasta 5e5 y árboles en camino.
#include "../../03_Arboles/LCA_y_binary_lifting/lowest-common-ancestor.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    vvl children(n);
    for (int i = 1; i < n; i++) { ll p; cin >> p; children[p].pb(i); }
    init(children, n);
    while (q--) { ll u, v; cin >> u >> v; cout << query(u, v) << '\n'; }
}
