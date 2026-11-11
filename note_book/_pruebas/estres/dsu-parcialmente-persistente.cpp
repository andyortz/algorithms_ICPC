// prueba: 01_Estructuras/DSU/union-find-partial-persistent.cpp
// find(a, tiempo) responde sobre el estado tras `tiempo` uniones efectivas.
#include "../../_base/template-simple.hpp"
const int N = 105;
#include "../../01_Estructuras/DSU/union-find-partial-persistent.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        int n = rnd(1, 40);
        initDSU();
        vector<vector<int>> snap = {vector<int>(n)}; iota(snap[0].begin(), snap[0].end(), 0);
        for (int k = 0; k < 150; k++) {
            int a = rnd(0, n - 1), b = rnd(0, n - 1);
            if (rnd(0, 1)) {
                ll antes = t; unite(a, b);
                if (t != antes) { auto comp = snap.back(); int ca = comp[a], cb = comp[b]; for (auto& c : comp) if (c == cb) c = ca; snap.pb(comp); }
                CHECK(t == (ll)snap.size() - 1);
            } else {
                int tt = rnd(0, snap.size() - 1);
                CHECK((find(a, tt) == find(b, tt)) == (snap[tt][a] == snap[tt][b]));
            }
        }
    }
    FIN("union-find-partial-persistent");
}
