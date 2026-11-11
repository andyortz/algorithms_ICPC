// prueba: 01_Estructuras/Segment_Tree/Dinamico/lazy-creation.cpp
// Suma puntual y suma en rango sobre posiciones hasta 1e9 (nodos creados bajo demanda).
#include "../../01_Estructuras/Segment_Tree/Dinamico/lazy-creation.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 300; it++) {
        ll M = it % 2 ? 1000000000 : rnd(1, 40);
        pst root = nullptr; map<ll, ll> a;
        for (int k = 0; k < 300; k++) {
            if (rnd(0, 1)) { ll p = rnd(0, M - 1), v = rnd(-1e9, 1e9); update(root, 0, M - 1, p, v); a[p] += v; }
            else {
                ll l = rnd(0, M - 1), r = rnd(l, M - 1), s = 0;
                for (auto it2 = a.lower_bound(l); it2 != a.end() && it2->first <= r; ++it2) s += it2->second;
                CHECK(query(root, 0, M - 1, l, r) == s);
            }
        }
    }
    FIN("lazy-creation");
}
