// yosupo: staticrmq
// prueba: 01_Estructuras/Segment_Tree/Lazy/general-lazy-tree.cpp
#include "../../01_Estructuras/Segment_Tree/Lazy/general-lazy-tree.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    lazytree st; st.init(n);
    for (int i = 0; i < n; i++) { ll a; cin >> a; st.update(i, Node(a)); }
    while (q--) { int l, r; cin >> l >> r; cout << st.query(l, r - 1).mn << '\n'; }
}
