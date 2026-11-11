// Selección: Usa fast de simple.cpp en lugar de la macro hana.
// Tema: 03_Arboles/LCA_y_binary_lifting
// Base: Template/simple.cpp (int = long long).
// Requisito: Contiene main de ejemplo/prueba: usar su main o el de simple.cpp, nunca ambos.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_88E4197E892ABFE8
#define NOTEBOOK_GENERADO_88E4197E892ABFE8
#include "../../_base/template-simple.hpp"

using namespace std;

#define double long double






const int N = 1e5+10;
const int INF = 1e17+1;
const int mod = 1e9+7;
//const int mod = 998244353;
const double eps = 1e-6;
typedef pair<int,int> pii;
int n, q;
vi grafo[N+1], tin, tout;
vector<vi> dp;
int timer = 0, l;

struct node {
    vi v;
    void insert(int x) {
        auto it = lower_bound(v.begin(), v.end(), x);
        if (it != v.end() && *it == x ) return;
        v.insert(it, x);
        if (v.size() > 10) v.pop_back();
    }
};
node merge(node &a, node &b) {
    node res;
    for (int i = 0, j = 0; res.v.size() < 10; ) 
    if (i < a.v.size() && j < b.v.size()) {
        if (a.v[i] < b.v[j]) 
            res.insert(a.v[i++]);
        else 
            res.insert(b.v[j++]);
    } else if (i<a.v.size()) {
        res.insert(a.v[i++]);
    } else if (j<b.v.size()) {
        res.insert(b.v[j++]);
    } else break;
    return res;
}
vector<node> a;
vector<vector<node>> dpa;

void dfs(int i, int p = 1) {
    tin[i] = timer++;
    dp[i][0] = p;
    dpa[i][0] = merge(a[i], a[p]);
    for (int j = 1; j<=l; j++) 
        dp[i][j] = dp[dp[i][j-1]][j-1], 
        dpa[i][j] = merge(dpa[i][j-1], dpa[dp[i][j-1]][j-1]);
    
    for (auto &to: grafo[i]) 
        if (to!=p) dfs(to, i);

    tout[i] = timer++;
}
int is_ancestor(int i, int j) {
    return tin[i]<tin[j] && tout[i]>tout[j];
}
int lca(int i, int j) {
    // to append functions take in mind: fdp[i][k] = [i, p_k-1(i)) U [p_k-1(i), p_k(i)]
    if (i==j) return i;
    if (is_ancestor(i, j)) return i;
    if (is_ancestor(j, i)) return j;
    for (int k = l; k>-1; k--) 
        if (!is_ancestor(dp[i][k], j)) i = dp[i][k];
    return dp[i][0];
}
node fa(int i, int p) {
    node res;
    for (int k = l; k>-1; k--) 
    if (!is_ancestor(dp[i][k], p)) 
        res = merge(res, dpa[i][k]), i = dp[i][k];
    if (i==p) res = merge(res, a[i]);
    else res = merge(res, dpa[i][0]);
    return res;
}
void init() {
    for (int i = 1; i<=n; i++) grafo[i].clear();
    tin.resize(n+1), tout.resize(n+1);
    l = 0;
    while ((1<<l) < n) l++;
    dp.resize(n+1, vi(l+1, -1));
    dpa.resize(n+1, vector<node>(l+1));
    a.resize(n+1);
}
void solve() {
    int m; cin>>n>>m>>q;
    init();
    for (int i = 1; i<n; i++) {
        int a, b; cin>>a>>b;
        grafo[a].pb(b);
        grafo[b].pb(a);
    }

    for (int i = 1; i<=m; i++) {
        int x; cin>>x;
        a[x].insert(i);
    }
    dfs(1);
    while (q--) {
        int ax, bx, x; cin>>ax>>bx>>x;
        int p = lca(ax, bx);
        auto fia = fa(ax, p); auto fib = fa(bx, p);
        node res = merge(fia, fib);
        vi aux = res.v;

        cout<<min(x, (int)aux.size())<<' ';
        for (int i =0; i<min(x, (int)aux.size()); i++) cout<<aux[i]<<' ';
            cout<<endl;
    }
}
signed main() {
    fast;
    int T = 1; //cin>>T;
    while (T--) solve();
    //while (!cin.eof()) solve();
    return 0;
}
#endif
