// yosupo: associative_array
// prueba: 01_Estructuras/Hash_maps/custom-hash.cpp
#include "../../01_Estructuras/Hash_maps/custom-hash.cpp"
using ll = long long;
signed main() {
    fast;
    int q; cin >> q;
    unordered_map<ll, ll, custom_hash_splitmix64> mp;
    mp.reserve(1 << 20);
    while (q--) {
        int t; ll k; cin >> t >> k;
        if (t == 0) { ll v; cin >> v; mp[k] = v; }
        else { auto it = mp.find(k); cout << (it == mp.end() ? 0 : it->second) << '\n'; }
    }
}
