// yosupo: unionfind
// prueba: 01_Estructuras/DSU/union-find-rollback.cpp
// El archivo necesita N y los accesos .st/.nd, y trae un main de ejemplo (se renombra).
#include "../../_base/template-simple.hpp"
const int N = 200005;
#define st first
#define nd second
#define main main_ejemplo_notebook
#include "../../01_Estructuras/DSU/union-find-rollback.cpp"
#undef main
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
    while (q--) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 0) unite(u, v);
        else cout << (find(u) == find(v)) << '\n';
    }
}
