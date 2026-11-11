// prueba: 01_Estructuras/Segment_Tree/Lazy/segment-tree-lazy-vasito.cpp
#include "../../01_Estructuras/Segment_Tree/Lazy/segment-tree-lazy-vasito.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        int n = rnd(1, 50);
        vector<ll> a(n);
        for (auto& x : a) x = rnd(-1e9, 1e9);
        STree st(n); st.init(a.data());
        for (int k = 0; k < 300; k++) {
            int l = rnd(0, n - 1), r = rnd(l + 1, n);
            if (rnd(0, 1)) { ll v = rnd(-1e6, 1e6); st.upd(l, r, v); for (int i = l; i < r; i++) a[i] += v; }
            else { ll s = 0; for (int i = l; i < r; i++) s += a[i]; CHECK(st.query(l, r) == s); }
        }
    }
    FIN("segment-tree-lazy-vasito");
}
