// prueba: 01_Estructuras/Segment_Tree/Lazy/lazy-st1.cpp
// Árbol dinámico: suma en rango [i, j) y suma en rango, sobre [0, n) y sobre [0, 1e9).
#include "../../01_Estructuras/Segment_Tree/Lazy/lazy-st1.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        int n = rnd(1, 50);
        vector<ll> a(n, 0);
        ST st;
        for (int k = 0; k < 300; k++) {
            int l = rnd(0, n - 1), r = rnd(l + 1, n);
            if (rnd(0, 1)) { ll v = rnd(-1e6, 1e6); st.upd(0, n, l, r, v); for (int i = l; i < r; i++) a[i] += v; }
            else { ll s = 0; for (int i = l; i < r; i++) s += a[i]; CHECK(st.query(0, n, l, r) == s); }
        }
    }
    // Coordenadas grandes: se compara contra un mapa de intervalos elementales.
    for (int it = 0; it < 100; it++) {
        const ll M = 1000000000;
        ST st; vector<array<ll, 3>> ups;
        for (int k = 0; k < 200; k++) {
            ll l = rnd(0, M - 1), r = rnd(l + 1, min(M, l + rnd(1, M)));
            if (rnd(0, 1)) { ll v = rnd(-1000, 1000); st.upd(0, M, l, r, v); ups.pb({l, r, v}); }
            else { ll s = 0; for (auto& [a, b, v] : ups) s += v * max(0LL, min(b, r) - max(a, l)); CHECK(st.query(0, M, l, r) == s); }
        }
    }
    FIN("lazy-st1");
}
