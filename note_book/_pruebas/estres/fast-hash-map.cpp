// prueba: 01_Estructuras/Hash_maps/fast-hash-map.cpp  (gp_hash_table global mp)
#include "../../01_Estructuras/Hash_maps/fast-hash-map.cpp"
#include "comun.hpp"
signed main() {
    map<ll, ll> ref;
    for (int k = 0; k < 300000; k++) {
        ll key = rnd(0, 2) ? rnd(-1000, 1000) : (rnd(1, 1000) << rnd(20, 40));
        int ty = rnd(0, 2);
        if (ty == 0) { mp[key] = k; ref[key] = k; }
        else if (ty == 1) { mp.erase(key); ref.erase(key); }
        else { auto it = mp.find(key); CHECK((it != mp.end()) == ref.count(key)); if (it != mp.end()) CHECK(it->second == ref[key]); }
    }
    CHECK(mp.size() == ref.size());
    FIN("fast-hash-map");
}
