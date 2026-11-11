// yosupo: point_add_range_sum
// prueba: 01_Estructuras/Fenwick/fenwick-tree.cpp
#include "../../01_Estructuras/Fenwick/fenwick-tree.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    vector<int> a(n); for (auto& x : a) cin >> x;
    FenwickTree ft(a);
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 0) ft.add(x, y); else cout << ft.sum(x, y - 1) << '\n';
    }
}
