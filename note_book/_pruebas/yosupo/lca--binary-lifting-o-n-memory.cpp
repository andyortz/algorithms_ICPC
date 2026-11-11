// yosupo: lca
// prueba: 03_Arboles/LCA_y_binary_lifting/binary-lifting-o-n-memory.cpp
// Raíz: nodo con de = 0 y par = go = sí mismo. p_i < i: se agregan en orden.
#include "../../03_Arboles/LCA_y_binary_lifting/binary-lifting-o-n-memory.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    vector<pNode> nd(n);
    nd[0] = new Node(); nd[0]->de = 0; nd[0]->par = nd[0]->go = nd[0];
    for (int i = 1; i < n; i++) { int p; cin >> p; nd[i] = add(nd[p], i); }
    unordered_map<pNode, int> id; id.reserve(2 * n);
    for (int i = 0; i < n; i++) id[nd[i]] = i;
    while (q--) { int u, v; cin >> u >> v; cout << id[lca(nd[u], nd[v])] << '\n'; }
}
