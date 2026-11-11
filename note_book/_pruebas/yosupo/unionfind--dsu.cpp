// yosupo: unionfind
// prueba: 01_Estructuras/DSU/dsu.cpp
#include "../../01_Estructuras/DSU/dsu.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    DSU d(n);
    while (q--) {
        int t, u, v; cin >> t >> u >> v;
        if (t == 0) d.merge(u, v);
        else cout << (d.find(u) == d.find(v)) << '\n';
    }
}
