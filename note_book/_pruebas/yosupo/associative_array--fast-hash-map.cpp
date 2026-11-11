// yosupo: associative_array
// prueba: 01_Estructuras/Hash_maps/fast-hash-map.cpp
#include "../../01_Estructuras/Hash_maps/fast-hash-map.cpp"
using ll = long long;
signed main() {
    fast;
    int q; cin >> q;
    while (q--) {
        int t; ll k; cin >> t >> k;
        if (t == 0) { ll v; cin >> v; mp[k] = v; }
        else { auto it = mp.find(k); cout << (it == mp.end() ? 0 : it->second) << '\n'; }
    }
}
