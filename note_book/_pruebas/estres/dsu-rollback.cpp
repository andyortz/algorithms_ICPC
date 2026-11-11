// prueba: 01_Estructuras/DSU/union-find-rollback.cpp
// rollback() deshace el último unite que sí unió (los que no unen no apilan nada).
#include "../../_base/template-simple.hpp"
const int N = 105;
#define st first
#define nd second
#define main main_ejemplo_notebook
#include "../../01_Estructuras/DSU/union-find-rollback.cpp"
#undef main
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        int n = rnd(1, 40);
        for (int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
        while (!sp.empty()) sp.pop(), ss.pop();
        vector<vector<int>> hist = {vector<int>(n)}; iota(hist[0].begin(), hist[0].end(), 0);
        for (int k = 0; k < 150; k++) {
            int ty = rnd(0, 2), a = rnd(0, n - 1), b = rnd(0, n - 1);
            auto comp = hist.back();
            if (ty == 0) {
                size_t antes = sp.size(); unite(a, b);
                if (sp.size() != antes) { int ca = comp[a], cb = comp[b]; for (auto& c : comp) if (c == cb) c = ca; hist.pb(comp); }
                else CHECK(comp[a] == comp[b]);
            } else if (ty == 1 && hist.size() > 1) { rollback(); hist.pop_back(); }
            else { CHECK((find(a) == find(b)) == (comp[a] == comp[b])); CHECK(sz[find(a)] == count(comp.begin(), comp.end(), comp[a])); }
        }
    }
    FIN("union-find-rollback");
}
