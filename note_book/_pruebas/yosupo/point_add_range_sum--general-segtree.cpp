// yosupo: point_add_range_sum
// prueba: 01_Estructuras/Segment_Tree/Basico/general-segtree.cpp
#include "../../01_Estructuras/Segment_Tree/Basico/general-segtree.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    vector<Node> a(n); for (auto& x : a) cin >> x.x;
    segtree st; st.init(a);
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 0) { a[x].x += y; st.update(x, a[x]); }
        else cout << st.query(x, y - 1).x << '\n';
    }
}
