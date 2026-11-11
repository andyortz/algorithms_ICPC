// Compilar desde note_book: g++ -std=gnu++20 -O2 -Wall -Wextra _pruebas/sqrt-descomposition.cpp -o <ruta_temporal.exe>
// Prueba de sqrt_() (formato propio: "1 l r" suma, "2 i x" asignación, 1-indexado) contra fuerza bruta.
#include "../01_Estructuras/Descomposicion_SQRT/sqrt-descomposition.cpp"
using ll = long long;

signed main() {
    mt19937_64 rng(20261105);
    auto rnd = [&](ll l, ll r) { return l + (ll)(rng() % (unsigned long long)(r - l + 1)); };
    int casos = 0, consultas = 0;
    for (int it = 0; it < 500; it++) {
        int N = rnd(1, 80), Q = rnd(1, 300);
        vector<ll> b(N);
        for (auto& x : b) x = rnd(-1000, 1000);
        n = N; q = Q; v = vi(b.begin(), b.end());      // estado inicial de la estructura
        string in, esperado;
        for (int k = 0; k < Q; k++) {
            if (rng() % 2) {
                ll l = rnd(1, N), r = rnd(l, N), s = 0;
                for (ll i = l; i <= r; i++) s += b[i - 1];
                in += "1 " + to_string(l) + " " + to_string(r) + "\n";
                esperado += to_string(s) + "\n";
                consultas++;
            } else {
                ll i = rnd(1, N), x = rnd(-1000, 1000);
                b[i - 1] = x;
                in += "2 " + to_string(i) + " " + to_string(x) + "\n";
            }
        }
        istringstream iss(in); ostringstream oss;
        auto *cinBuf = cin.rdbuf(iss.rdbuf());
        auto *coutBuf = cout.rdbuf(oss.rdbuf());
        sqrt_();
        cin.rdbuf(cinBuf); cout.rdbuf(coutBuf);
        if (oss.str() != esperado) { cerr << "FALLO en el caso " << it << endl; return 1; }
        casos++;
    }
    cout << "sqrt-descomposition: " << casos << " casos, " << consultas << " sumas OK" << endl;
}
