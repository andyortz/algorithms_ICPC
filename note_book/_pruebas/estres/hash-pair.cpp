// prueba: 01_Estructuras/Hash_maps/custom-hash-pair.cpp  y  custom-hash.cpp
#include "../../01_Estructuras/Hash_maps/custom-hash-pair.cpp"
#include "../../01_Estructuras/Hash_maps/custom-hash.cpp"
#include "comun.hpp"
signed main() {
    unordered_set<pair<ll, ll>, chash> s; set<pair<ll, ll>> ref;
    unordered_map<ll, ll, custom_hash_splitmix64> m; map<ll, ll> mref;
    for (int k = 0; k < 200000; k++) {
        pair<ll, ll> p = {rnd(-50, 50) * (rnd(0, 1) ? (1LL << 32) : 1), rnd(-50, 50)};
        ll key = rnd(0, 3) ? rnd(-100, 100) : (1LL << rnd(0, 62));
        int ty = rnd(0, 2);
        if (ty == 0) { s.insert(p); ref.insert(p); m[key] += k; mref[key] += k; }
        else if (ty == 1) { s.erase(p); ref.erase(p); m.erase(key); mref.erase(key); }
        else { CHECK(s.count(p) == ref.count(p)); CHECK(m.count(key) == mref.count(key)); if (m.count(key)) CHECK(m[key] == mref[key]); }
    }
    CHECK(s.size() == ref.size() && m.size() == mref.size());
    FIN("custom-hash-pair / custom-hash");
}
