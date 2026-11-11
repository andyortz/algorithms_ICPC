// yosupo: static_range_frequency
// prueba: 01_Estructuras/Segment_Tree/Merge_Sort_Tree/merge-sort-tree.cpp
// Sin protecciones en el adaptador: init y query manejan n = 0 y rangos vacíos (l == r).
#include "../../01_Estructuras/Segment_Tree/Merge_Sort_Tree/merge-sort-tree.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    vl a(n); for (auto& x : a) cin >> x;
    segtree st; st.init(n, a);
    vector<node*> nodes;
    while (q--) {
        ll l, r, x; cin >> l >> r >> x;
        nodes.clear(); st.query(l, r - 1, nodes);
        ll c = 0;
        for (node* nd : nodes) { auto pr = equal_range(nd->nums.begin(), nd->nums.end(), x); c += pr.second - pr.first; }
        cout << c << '\n';
    }
}
