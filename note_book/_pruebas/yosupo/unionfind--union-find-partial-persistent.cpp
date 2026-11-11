// yosupo: unionfind
// prueba: 01_Estructuras/DSU/union-find-partial-persistent.cpp
// Se responde con el tiempo actual t (la estructura también permite consultar tiempos pasados).
#include "../../_base/template-simple.hpp"
const int N = 200005;
#include "../../01_Estructuras/DSU/union-find-partial-persistent.cpp"
signed main() {
    fast;
    int n, q; cin >> n >> q;
    initDSU();
    while (q--) {
        int ty, u, v; cin >> ty >> u >> v;
        if (ty == 0) unite(u, v);
        else cout << (find(u, t) == find(v, t)) << '\n';
    }
}
