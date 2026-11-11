// prueba: 01_Estructuras/Intervalos_y_dominancia/disjoint-intervals.cpp
// Tras cada insert, s debe ser la lista de intervalos [a, b) maximales de la unión.
#include "../../01_Estructuras/Intervalos_y_dominancia/disjoint-intervals.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 1000; it++) {
        disjoint_intervals di; vector<int> cov(62, 0);
        for (int k = 0; k < 40; k++) {
            int a = rnd(0, 60), b = rnd(0, 60);
            di.insert({a, b});
            for (int i = a; i < b; i++) cov[i] = 1;
            set<pair<ll, ll>> exp;
            for (int i = 0; i < 61; i++) if (cov[i] && (i == 0 || !cov[i - 1])) { int j = i; while (cov[j]) j++; exp.insert({i, j}); }
            CHECK((set<pair<ll, ll>>(di.s.begin(), di.s.end()) == exp));
        }
    }
    FIN("disjoint-intervals");
}
