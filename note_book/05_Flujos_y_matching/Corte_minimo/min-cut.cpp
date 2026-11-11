// Tema: 05_Flujos_y_matching/Corte_minimo
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vvl.
// Adaptación: Dependencias del mismo origen incluidas explícitamente: Nicolas/5 Flow/Max Flow.cpp.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_0AB262A01AF71845
#define NOTEBOOK_GENERADO_0AB262A01AF71845
#include "../../_base/template-simple.hpp"
#include "../Flujo_maximo/max-flow.cpp"
using ll = long long;
using vvl = vector<vector<long long>>;
/*
Minimum Cut, need revision for general cases!!!

Tested in https://cses.fi/problemset/task/1695/ 
  with undirected graph with capacity 1

1. Run Max Flow Algorithm
2. Get reachable vertices from source in the residual graph!
   using BFS or DFS, call this reachable vertices = S
3. Iterate S, iterate edges of S in normal graph that not belongs to S,
   thats the mincut edges of the answer.
*/

void test_case() {
    ll n, m; cin >> n >> m;
    vvl g(n);
    Dinitz f(n,0,n-1); // add Dinitz for maxFlow!!
    for (int i =0;i<m;i++) {
        ll x, y;cin >>x >> y;x--,y--;
        g[x].pb(y); g[y].pb(x); //this example the graph is bidirectional
        f.addEdge(x,y,1); f.addEdge(y,x,1);
    }
    f.maxFlow(); // step 1

    vvl residual(n); // Step 2
    for (int i =0;i<n;i++) for (auto j:f.G[i]) 
        if ((j.f<0 && j.cap==0) || (j.f==0 && j.cap > 0))
            residual[i].pb(j.to); // residual graph

    set<ll> vis;
    function<void(int)> dfs = [&](int x) {
        vis.insert(x); // dfs on residual from source
        for (auto y : residual[x]) if (!vis.count(y)) dfs(y);  
    };
    dfs(0);

    vector<pair<ll,ll>> ans; // step 3
    for (auto x : vis) 
        for (auto y : g[x]) 
            if (!vis.count(y)) 
                ans.pb({x,y});

    cout << ans.size() << "\n";
    for (auto e : ans) {
        cout << e.first + 1 << " " << e.second + 1 << "\n";
    }
}
#endif
