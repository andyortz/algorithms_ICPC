// prueba: 03_Arboles/Euler_Tour/euler-tour-sum.cpp  (test_case con el formato de CSES 1138)
// "1 s x": valor de s = x; "2 s": suma del camino raíz(1) -> s.
#include "../../03_Arboles/Euler_Tour/euler-tour-sum.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 50), m = rnd(1, 100);
        vector<ll> v(n + 1), par(n + 1, 0);
        string in = to_string(n) + " " + to_string(m) + "\n";
        for (int i = 1; i <= n; i++) v[i] = rnd(0, 1e9), in += to_string(v[i]) + " ";
        in += "\n";
        for (int i = 2; i <= n; i++) { par[i] = it % 4 == 0 ? i - 1 : rnd(1, i - 1); in += to_string(par[i]) + " " + to_string(i) + "\n"; }
        string exp;
        for (int k = 0; k < m; k++) {
            int s = rnd(1, n);
            if (rnd(0, 1)) { ll x = rnd(0, 1e9); v[s] = x; in += "1 " + to_string(s) + " " + to_string(x) + "\n"; }
            else { ll sum = 0; for (int z = s; z; z = par[z]) sum += v[z]; in += "2 " + to_string(s) + "\n"; exp += to_string(sum) + "\n"; }
        }
        istringstream is(in); ostringstream os;
        auto *ci = cin.rdbuf(is.rdbuf()), *co = cout.rdbuf(os.rdbuf());
        test_case();
        cin.rdbuf(ci); cout.rdbuf(co);
        CHECK(os.str() == exp);
    }
    FIN("euler-tour-sum");
}
