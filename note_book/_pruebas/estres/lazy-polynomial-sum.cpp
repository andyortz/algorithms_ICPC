// prueba: 01_Estructuras/Segment_Tree/Lazy/polynomial-sum-lazy-segtree-problem.cpp
// apply(l, r, {add, ops}) suma add + ops*(p-l+1) a cada posición p de [l, r].
#include "../../01_Estructuras/Segment_Tree/Lazy/polynomial-sum-lazy-segtree-problem.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        int n = rnd(1, 50);
        vector<ll> a(n);
        lazytree st; st.init(n);
        for (int i = 0; i < n; i++) { a[i] = rnd(-1e6, 1e6); st.update(i, {a[i]}); }
        for (int k = 0; k < 300; k++) {
            int ty = rnd(0, 2), l = rnd(0, n - 1), r = rnd(l, n - 1);
            if (ty == 0) {
                ll ad = rnd(0, 2) ? 0 : rnd(-1000, 1000), ops = rnd(0, 2) ? 1 : rnd(-1000, 1000);
                st.apply(l, r, {ad, ops});
                for (int p = l; p <= r; p++) a[p] += ad + ops * (p - l + 1);
            } else if (ty == 1) { ll v = rnd(-1e6, 1e6); st.update(l, {v}); a[l] = v; }
            else { ll s = 0; for (int i = l; i <= r; i++) s += a[i]; CHECK(st.query(l, r).sum == s); }
        }
    }
    FIN("polynomial-sum-lazy");
}
