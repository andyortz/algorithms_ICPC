// prueba: 03_Arboles/Rerooting/re-rooting.cpp
// Tras dfs(0) y dfss(0), dp[i] = distancia máxima desde i (excentricidad). Requiere grafo,
// dp y maxi declarados y en cero.
#include "../../_base/template-simple.hpp"
vector<int> grafo[205];
int dp[205], maxi[205];
#include "../../03_Arboles/Rerooting/re-rooting.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 500; it++) {
        int n = rnd(1, 200);
        for (int i = 0; i < n; i++) grafo[i].clear(), dp[i] = maxi[i] = 0;
        for (int i = 1; i < n; i++) { int p = it % 4 == 0 ? i - 1 : rnd(0, i - 1); grafo[i].pb(p); grafo[p].pb(i); }
        dfs(0); dfss(0);
        for (int u = 0; u < n; u++) {
            vector<int> d(n, -1); d[u] = 0; vector<int> q = {u}; int e = 0;
            for (size_t i = 0; i < q.size(); i++) { e = max(e, d[q[i]]); for (int y : grafo[q[i]]) if (d[y] < 0) d[y] = d[q[i]] + 1, q.pb(y); }
            CHECK(dp[u] == e);
        }
    }
    FIN("re-rooting");
}
