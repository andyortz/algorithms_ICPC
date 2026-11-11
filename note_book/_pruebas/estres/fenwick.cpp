// prueba: 01_Estructuras/Fenwick/fenwick-tree.cpp
#include "../../01_Estructuras/Fenwick/fenwick-tree.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        int n = rnd(1, 50);
        vector<ll> a(n);
        for (auto& x : a) x = rnd(-1e9, 1e9);
        FenwickTree ft(a);
        for (int k = 0; k < 300; k++) {
            int l = rnd(0, n - 1), r = rnd(l, n - 1);
            if (rnd(0, 1)) { ll v = rnd(-1e9, 1e9); ft.add(l, v); a[l] += v; }
            else { ll s = 0; for (int i = l; i <= r; i++) s += a[i]; CHECK(ft.sum(l, r) == s && ft.sum(r) == accumulate(a.begin(), a.begin() + r + 1, 0LL)); }
        }
    }
    FIN("fenwick-tree");
}
