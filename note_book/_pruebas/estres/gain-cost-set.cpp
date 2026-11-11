// prueba: 01_Estructuras/Intervalos_y_dominancia/gain-cost-set-vasito.cpp
// get(g) = costo mínimo entre los pares con beneficio >= g (INF si no hay).
#include "../../_base/template-simple.hpp"
const long long INF = 4e18;
#include "../../01_Estructuras/Intervalos_y_dominancia/gain-cost-set-vasito.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 1000; it++) {
        GCS s; vector<pair<ll, ll>> all;
        for (int k = 0; k < 60; k++) {
            if (rnd(0, 1)) { ll g = rnd(0, 30), c = rnd(0, 30); s.add(g, c); all.pb({g, c}); }
            else {
                ll g = rnd(-1, 31), best = INF;
                for (auto [gg, cc] : all) if (gg >= g) best = min(best, cc);
                CHECK(s.get(g) == best);
            }
        }
    }
    FIN("gain-cost-set");
}
