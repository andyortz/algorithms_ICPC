// prueba: 01_Estructuras/Heaps/heap-sort.cpp
// Max-heap en vector: insert (tras push_back), del(i) y find(x), con valores negativos.

#include "../../01_Estructuras/Heaps/heap-sort.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        vi h; multiset<ll> ms;
        for (int k = 0; k < 200; k++) {
            int ty = h.empty() ? 0 : rnd(0, 2);
            if (ty == 0) { ll x = rnd(-30, 30); h.pb(x); insert(h); ms.insert(x); }
            else if (ty == 1) { int i = rnd(0, h.size() - 1); ms.erase(ms.find(h[i])); del(h, i); }
            else { ll x = rnd(-31, 31); int i = find(h, x, 0); CHECK(ms.count(x) ? (i >= 0 && h[i] == x) : i == -1); }
            for (size_t i = 1; i < h.size(); i++) CHECK(h[(i - 1) / 2] >= h[i]);    // propiedad de heap
            CHECK(multiset<ll>(h.begin(), h.end()) == ms);
        }
    }
    FIN("heap-sort");
}
