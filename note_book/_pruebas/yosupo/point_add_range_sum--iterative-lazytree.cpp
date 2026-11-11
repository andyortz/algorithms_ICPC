// yosupo: point_add_range_sum
// prueba: 01_Estructuras/Segment_Tree/Lazy/iterative-lazytree.cpp
#include "../../01_Estructuras/Segment_Tree/Lazy/iterative-lazytree.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    lazyseg st(n);
    for (int i = 0; i < n; i++) { ll a; cin >> a; st.update(i, {a}); }
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 0) st.apply(x, x, {ADD, y}); else cout << st.query(x, y - 1).x << '\n';
    }
}
