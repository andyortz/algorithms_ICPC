// prueba: 01_Estructuras/Segment_Tree/Basico/general-segtree.cpp
#include "../../01_Estructuras/Segment_Tree/Basico/general-segtree.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        int n = rnd(1, 50);
        vector<ll> a(n);
        segtree st;
        if (it % 2) { vector<Node> b(n); for (int i = 0; i < n; i++) b[i].x = a[i] = rnd(-1e9, 1e9); st.init(b); }
        else { st.init(n); for (int i = 0; i < n; i++) { a[i] = rnd(-1e9, 1e9); st.update(i, {a[i]}); } }
        for (int k = 0; k < 300; k++) {
            int ty = rnd(0, 2), l = rnd(0, n - 1), r = rnd(l, n - 1);
            if (ty == 0) { ll v = rnd(-1e9, 1e9); st.update(l, {v}); a[l] = v; }
            else if (ty == 1) CHECK(st.get(l).x == a[l]);
            else { ll s = 0; for (int i = l; i <= r; i++) s += a[i]; CHECK(st.query(l, r).x == s); }
        }
    }
    FIN("general-segtree");
}
