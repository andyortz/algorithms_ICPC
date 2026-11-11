// prueba: 01_Estructuras/DSU/dsu.cpp  (find, merge y siz)
#include "../../01_Estructuras/DSU/dsu.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        int n = rnd(1, 40); DSU d(n); vector<int> comp(n);
        iota(comp.begin(), comp.end(), 0);
        for (int k = 0; k < 100; k++) {
            int a = rnd(0, n - 1), b = rnd(0, n - 1);
            if (rnd(0, 1)) { d.merge(a, b); int ca = comp[a], cb = comp[b]; for (auto& c : comp) if (c == cb) c = ca; }
            else { CHECK((d.find(a) == d.find(b)) == (comp[a] == comp[b])); CHECK(d.siz(a) == count(comp.begin(), comp.end(), comp[a])); }
        }
    }
    FIN("dsu");
}
