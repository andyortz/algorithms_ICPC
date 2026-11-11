// yosupo: point_add_range_sum
// prueba: 01_Estructuras/Segment_Tree/Lazy/polynomial-sum-lazy-segtree-problem.cpp
// Func{add, ops}: con ops = 0 es una suma constante.
#include "../../01_Estructuras/Segment_Tree/Lazy/polynomial-sum-lazy-segtree-problem.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    lazytree st; st.init(n);
    for (int i = 0; i < n; i++) { ll a; cin >> a; st.update(i, {a}); }
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 0) st.apply(x, x, {y, 0}); else cout << st.query(x, y - 1).sum << '\n';
    }
}
