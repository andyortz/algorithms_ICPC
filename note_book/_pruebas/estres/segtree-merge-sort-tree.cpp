// prueba: 01_Estructuras/Segment_Tree/Merge_Sort_Tree/merge-sort-tree.cpp
// Por nodo: cantidad de valores <= x (upper_bound) y su suma (prefix); incluye n = 0.
#include "../../01_Estructuras/Segment_Tree/Merge_Sort_Tree/merge-sort-tree.cpp"
#include "comun.hpp"
signed main() {
    { segtree st; vl vacio; st.init(0, vacio); vector<node*> nd; st.query(0, -1, nd); CHECK(nd.empty()); }
    for (int it = 0; it < 500; it++) {
        int n = rnd(1, 50);
        vl a(n);
        for (auto& x : a) x = rnd(-20, 20);
        segtree st; st.init(n, a);
        for (int k = 0; k < 200; k++) {
            int l = rnd(0, n - 1), r = rnd(l, n - 1); ll x = rnd(-25, 25);
            vector<node*> nd; st.query(l, r, nd);
            ll c = 0, s = 0, total = 0;
            for (node* p : nd) {
                total += p->nums.size();
                CHECK(is_sorted(p->nums.begin(), p->nums.end()));
                ll j = upper_bound(p->nums.begin(), p->nums.end(), x) - p->nums.begin();
                c += j; if (j) s += p->prefix[j - 1];
            }
            ll bc = 0, bs = 0;
            for (int i = l; i <= r; i++) if (a[i] <= x) bc++, bs += a[i];
            CHECK(total == r - l + 1 && c == bc && s == bs);
        }
    }
    FIN("merge-sort-tree");
}
