// yosupo: ordered_set
// prueba: 01_Estructuras/Ordered_Set_PBDS/orderedset.cpp
#include "../../01_Estructuras/Ordered_Set_PBDS/orderedset.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    oset s;
    for (int i = 0; i < n; i++) { ll a; cin >> a; s.insert(a); }
    while (q--) {
        int t; ll x; cin >> t >> x;
        if (t == 0) s.insert(x);
        else if (t == 1) s.erase(x);
        else if (t == 2) cout << ((ll)s.size() < x ? -1 : *s.find_by_order(x - 1)) << '\n';
        else if (t == 3) cout << (ll)s.order_of_key(x + 1) << '\n';
        else if (t == 4) { ll k = s.order_of_key(x + 1); cout << (k == 0 ? -1 : *s.find_by_order(k - 1)) << '\n'; }
        else { auto it = s.lower_bound(x); cout << (it == s.end() ? -1 : *it) << '\n'; }
    }
}
