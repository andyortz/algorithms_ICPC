// prueba: 01_Estructuras/Ordered_Set_PBDS/multiorderedset.cpp
// Todas las operaciones contra un vector ordenado (multiconjunto).
#include "../../01_Estructuras/Ordered_Set_PBDS/multiorderedset.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        multiordered_set ms; vector<ll> v;
        for (int k = 0; k < 200; k++) {
            int ty = rnd(0, 7); ll x = rnd(-8, 8);
            auto lo = lower_bound(v.begin(), v.end(), x), hi = upper_bound(v.begin(), v.end(), x);
            bool ex = lo != hi;
            if (ty <= 1) { ms.insert(x); v.insert(hi, x); }
            else if (ty == 2) { ms.erase(x); if (ex) v.erase(lo); }
            else if (ty == 3) CHECK(ms.exists(x) == ex);
            else if (ty == 4) { if (!v.empty()) { int p = rnd(0, v.size() - 1); CHECK(ms.find_by_order(p) == v[p]); } }
            else if (ty == 5) { CHECK(ms.first_index(x) == (ex ? lo - v.begin() : -1)); CHECK(ms.last_index(x) == (ex ? hi - v.begin() - 1 : -1)); }
            else if (ty == 6) CHECK(ms.count(x) == (ex ? hi - lo : -1));
            else { ll y = rnd(x, 8); ll c = upper_bound(v.begin(), v.end(), y) - lower_bound(v.begin(), v.end(), x); CHECK(ms.count(x, y) == c); }
            CHECK(ms.size() == (ll)v.size());
        }
    }
    FIN("multiorderedset");
}
