// yosupo: point_add_range_sum
// prueba: 01_Estructuras/Segment_Tree/Lazy/lazy-st1.cpp
// Árbol dinámico; upd/query usan [i,j) semiabierto dentro de [l,r).
#include "../../01_Estructuras/Segment_Tree/Lazy/lazy-st1.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    ST st;
    for (int i = 0; i < n; i++) { int a; cin >> a; st.upd(0, n, i, i + 1, a); }
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 0) st.upd(0, n, x, x + 1, y);
        else cout << st.query(0, n, x, y) << '\n';
    }
}
