// prueba: 01_Estructuras/Rope/rope.cpp  (salida de ropeExample y operaciones contra vector)
#include "../../01_Estructuras/Rope/rope.cpp"
#include "comun.hpp"
signed main() {
    ostringstream os; auto* old = cout.rdbuf(os.rdbuf()); ropeExample(); cout.rdbuf(old);
    CHECK(os.str() == "1 5 1 2 3 4 5 \n1 5 2 3 1 2 3 4 5 2 3 \n");
    for (int it = 0; it < 300; it++) {
        rope<int> r; vector<ll> v;
        for (int k = 0; k < 200; k++) {
            int ty = v.empty() ? 0 : rnd(0, 2);
            if (ty == 0) { int p = rnd(0, v.size()); ll x = rnd(-1e9, 1e9); r.insert(p, x); v.insert(v.begin() + p, x); }
            else if (ty == 1) { int p = rnd(0, v.size() - 1), c = rnd(1, v.size() - p); r.erase(p, c); v.erase(v.begin() + p, v.begin() + p + c); }
            else { int p = rnd(0, v.size() - 1), c = rnd(1, v.size() - p); rope<int> sub = r.substr(p, c); r.erase(p, c); r.insert(0, sub);
                   vector<ll> w(v.begin() + p, v.begin() + p + c); w.insert(w.end(), v.begin(), v.begin() + p); w.insert(w.end(), v.begin() + p + c, v.end()); v = w; }
            CHECK((ll)r.size() == (ll)v.size());
            for (size_t i = 0; i < v.size(); i++) CHECK(r[i] == v[i]);
        }
    }
    FIN("rope");
}
