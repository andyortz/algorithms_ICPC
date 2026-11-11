// prueba: 03_Arboles/LCA_y_binary_lifting/lca-multiplication-path.cpp  (solve() de CF 587C)
// "n m q", aristas, ciudad de cada persona 1..m, consultas "v u a": los min(a, k) menores ids
// de personas en el camino v-u (a <= 10).
#include "../../_base/template-simple.hpp"
#define main lca_mult_main
#include "../../03_Arboles/LCA_y_binary_lifting/lca-multiplication-path.cpp"
#undef main
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 300; it++) {
        int nn = rnd(1, 40), mm = rnd(1, 60), qq = rnd(1, 40);
        vector<ll> par(nn + 1, 0), dep(nn + 1, 0), city(mm + 1);
        string in = to_string(nn) + " " + to_string(mm) + " " + to_string(qq) + "\n";
        for (int i = 2; i <= nn; i++) { par[i] = it % 4 == 0 ? i - 1 : rnd(1, i - 1); dep[i] = dep[par[i]] + 1; in += to_string(par[i]) + " " + to_string(i) + "\n"; }
        for (int i = 1; i <= mm; i++) city[i] = rnd(1, nn), in += to_string(city[i]) + " ";
        in += "\n";
        string exp;
        for (int k = 0; k < qq; k++) {
            ll v = rnd(1, nn), u = rnd(1, nn), x = rnd(1, 10);
            in += to_string(v) + " " + to_string(u) + " " + to_string(x) + "\n";
            set<ll> onPath; ll a = v, b = u;
            while (a != b) { if (dep[a] < dep[b]) swap(a, b); onPath.insert(a); a = par[a]; }
            onPath.insert(a);
            vector<ll> ids; for (int i = 1; i <= mm; i++) if (onPath.count(city[i])) ids.pb(i);
            ll c = min<ll>(x, ids.size());
            exp += to_string(c) + " "; for (int i = 0; i < c; i++) exp += to_string(ids[i]) + " ";
            exp += "\n";
        }
        tin.clear(); tout.clear(); dp.clear(); dpa.clear(); a.clear(); timer = 0;
        istringstream is(in); ostringstream os;
        auto *ci = cin.rdbuf(is.rdbuf()), *co = cout.rdbuf(os.rdbuf());
        solve();
        cin.rdbuf(ci); cout.rdbuf(co);
        CHECK(os.str() == exp);
    }
    FIN("lca-multiplication-path");
}
