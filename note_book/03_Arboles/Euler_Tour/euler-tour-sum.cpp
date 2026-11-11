// Tema: 03_Arboles/Euler_Tour
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl.
// Adaptación: Dependencias del mismo origen incluidas explícitamente: Nicolas/3 Data Structures/Fenwick Tree.cpp.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_D838D4B561A7127A
#define NOTEBOOK_GENERADO_D838D4B561A7127A
#include "../../_base/template-simple.hpp"
#include "../../01_Estructuras/Fenwick/fenwick-tree.cpp"
using ll = long long;
using vl = vector<long long>;
/* Euler Tour Sum Path O(n log n)
Given a Tree, and values in each node, process this queries:
 - Calculate the sum of values in the Path 1 to a 'given node'.
 - Update value of a node

Also you can extend this to sum path from A to B with updates.
Just add LCA and sum(0,A) + sum(0,B) - 2*(sum(0,lca)-values[lca])

Tested: https://cses.fi/problemset/task/1138/
*/
void test_case() {
    ll n, m; cin >> n >> m;
    vector<vl> adj(n+1); // 1-indexed
    vl nums(n+1), tin(n+1), tout(n+1);
    FenwickTree tree(2*n+2); // Add Fenwick Tree 0-indexed

    for (int i = 1; i <= n; i++) cin >> nums[i];
    for (int i = 0; i < n-1; i++) {
        ll x, y; cin >> x >> y;
        adj[x].pb(y); adj[y].pb(x);
    }
    
    ll time = 0;
    function<void(int,int)> dfs =[&](int x, int p) {
        tin[x] = time++;
        for (auto y : adj[x]) if (y != p) dfs(y, x);
        tout[x] = time++;
        tree.add(tin[x], nums[x]);
        tree.add(tout[x], -nums[x]);
    };
    dfs(1, 0);
    for (int i =0; i < m; i++) {
        ll t, x;
        cin >> t >> x;
        if (t == 1) { // update
            ll y; cin >> y;
            ll diff = y - nums[x];
            nums[x] = y;
            tree.add(tin[x], diff);
            tree.add(tout[x], -diff);
        } else { // query
            cout << tree.sum(0, tin[x]) << "\n";
        }
    }
}
#endif
