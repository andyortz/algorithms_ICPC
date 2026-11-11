// yosupo: staticrmq
// prueba: 01_Estructuras/Sparse_Table/spare-table.cpp
#include "../../01_Estructuras/Sparse_Table/spare-table.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    vi a(n); for (auto& x : a) cin >> x;
    rmq r(a);
    while (q--) { int l, rr; cin >> l >> rr; cout << r.get(l, rr - 1) << '\n'; }
}
