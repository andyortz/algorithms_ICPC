// yosupo: point_add_range_sum
// prueba: 01_Estructuras/Segment_Tree/Lazy/segment-tree-lazy-vasito.cpp
#include "../../01_Estructuras/Segment_Tree/Lazy/segment-tree-lazy-vasito.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    vector<int> a(n); for (auto& x : a) cin >> x;
    STree st(n); st.init(a.data());
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 0) st.upd(x, x + 1, y); else cout << st.query(x, y) << '\n';
    }
}
