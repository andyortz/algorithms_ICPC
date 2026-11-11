// yosupo: persistent_unionfind
// prueba: 01_Estructuras/DSU/union-find-rollback.cpp
// Offline: árbol de versiones + DFS; al volver de una versión se hace rollback.
// unite no devuelve si unió: se detecta comparando el tamaño de la pila sp.
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
    vector<int> T(q), U(q), V(q);
    vector<vector<int>> ch(q + 1), ask(q + 1);   // versión k -> nodo k+1 (0 = grafo vacío)
    for (int i = 0; i < q; i++) {
        int k; cin >> T[i] >> k >> U[i] >> V[i];
        if (T[i] == 0) ch[k + 1].pb(i + 1); else ask[k + 1].pb(i);
    }
    vector<int> ans(q, -1), did(q + 1, 0);
    vector<pair<int, int>> stk = {{0, 0}};         // (nodo, 0 = entrar / 1 = salir)
    while (!stk.empty()) {
        auto [x, s] = stk.back(); stk.pop_back();
        if (s == 0) {
            if (x > 0) { size_t b = sp.size(); unite(U[x - 1], V[x - 1]); did[x] = sp.size() != b; }
            for (int i : ask[x]) ans[i] = find(U[i]) == find(V[i]);
            stk.pb({x, 1});
            for (int c : ch[x]) stk.pb({c, 0});
        } else if (did[x]) rollback();
    }
    for (int i = 0; i < q; i++) if (T[i] == 1) cout << ans[i] << '\n';
}
