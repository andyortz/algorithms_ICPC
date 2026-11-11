// yosupo: point_add_range_sum
// prueba: 01_Estructuras/Segment_Tree/Dinamico/lazy-creation.cpp
#include "../../01_Estructuras/Segment_Tree/Dinamico/lazy-creation.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    pst root = nullptr;
    for (int i = 0; i < n; i++) { int a; cin >> a; update(root, 0, n - 1, i, a); }
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 0) update(root, 0, n - 1, x, y); else cout << query(root, 0, n - 1, x, y - 1) << '\n';
    }
}
