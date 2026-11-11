// prueba: 03_Arboles/Mo_en_arboles/mo-s-in-tree-s.cpp  (programa completo: distintos en un camino)
// Su main lee con scanf: se redirige stdin a un archivo temporal y se leen las respuestas de res[].
#include "../../_base/template-simple.hpp"
#define main mo_tree_main
#include "../../03_Arboles/Mo_en_arboles/mo-s-in-tree-s.cpp"
#undef main
#include "comun.hpp"
signed main() {
    freopen("NUL", "w", stdout);
    for (int it = 0; it < 300; it++) {
        int nn = rnd(1, 60), qq = rnd(1, 60);
        vector<ll> val(nn + 1), par(nn + 1, 0), dep(nn + 1, 0);
        string in = to_string(nn) + " " + to_string(qq) + "\n";
        for (int i = 1; i <= nn; i++) val[i] = rnd(-3, 3) * 1000000007LL, in += to_string(val[i]) + " ";
        in += "\n";
        for (int i = 2; i <= nn; i++) { par[i] = it % 4 == 0 ? i - 1 : rnd(1, i - 1); dep[i] = dep[par[i]] + 1; in += to_string(par[i]) + " " + to_string(i) + "\n"; }
        vector<ll> exp;
        for (int k = 0; k < qq; k++) {
            ll u = rnd(1, nn), v = rnd(1, nn); in += to_string(u) + " " + to_string(v) + "\n";
            set<ll> s; ll a = u, b = v;
            while (a != b) { if (dep[a] < dep[b]) swap(a, b); s.insert(val[a]); a = par[a]; }
            s.insert(val[a]); exp.pb(s.size());
        }
        { FILE* f = fopen("tmp_mo_arbol.txt", "w"); fputs(in.c_str(), f); fclose(f); }
        getID.clear(); memset(counter, 0, sizeof counter); memset(flag, 0, sizeof flag); memset(seen, 0, sizeof seen);
        memset(res, 0, sizeof res); memset(DP, 0, sizeof DP); memset(level, 0, sizeof level);
        freopen("tmp_mo_arbol.txt", "r", stdin);
        mo_tree_main();
        for (int k = 0; k < qq; k++) CHECK(res[k] == exp[k]);
    }
    remove("tmp_mo_arbol.txt");
    FIN("mo-in-tree");
}
