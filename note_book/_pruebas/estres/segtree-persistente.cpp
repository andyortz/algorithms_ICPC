// prueba: 01_Estructuras/Segment_Tree/Persistente/persistantsegmenttree.cpp
// Cada update crea una versión; se consultan versiones viejas al azar.
#include "../../01_Estructuras/Segment_Tree/Persistente/persistantsegmenttree.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 40);
        vector<ll> a(n);
        for (auto& x : a) x = rnd(-1e9, 1e9);
        vector<Vertex*> ver = {build(a)};
        vector<vector<ll>> hist = {a};
        for (int k = 0; k < 200; k++) {
            int v = rnd(0, ver.size() - 1), l = rnd(0, n - 1), r = rnd(l, n - 1);
            if (rnd(0, 1)) {
                ll x = rnd(-1e9, 1e9);
                ver.pb(rnd(0, 3) ? update(ver[v], n, l, x) : copy(update(ver[v], n, l, x)));
                hist.pb(hist[v]); hist.back()[l] = x;
            } else { ll s = 0; for (int i = l; i <= r; i++) s += hist[v][i]; CHECK(get_sum(ver[v], n, l, r) == s); }
        }
    }
    FIN("persistent-segtree");
}
