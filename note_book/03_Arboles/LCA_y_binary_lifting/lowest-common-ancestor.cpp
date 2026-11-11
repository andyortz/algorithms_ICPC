// Requisito de selección: Árbol dirigido de padre a hijos, raíz 0. LOG se calcula en init según n; kParent requiere k<=depth[x].
// Tema: 03_Arboles/LCA_y_binary_lifting
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vvl.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_6547E5980CE83B6B
#define NOTEBOOK_GENERADO_6547E5980CE83B6B
#include "../../_base/template-simple.hpp"
using ll = long long;
using vvl = vector<vector<long long>>;
// Give a rooted tree, find the Lowest Common Ancestor node
// of A and B.
// Tested https://cses.fi/problemset/task/1688/
// Tested https://judge.yosupo.jp/problem/lca (N = 5e5, árboles en camino)
vector<vector<ll>> up;
vector<ll> depth;
int LOG = 1; // se calcula en init: 2^LOG > n (antes fijo en 18: fallaba con profundidad >= 2^18)

void init(const vector<vector<ll>> &children, ll n) {
    LOG = 1;
    while ((1LL << LOG) <= n) LOG++;
    up.assign(LOG,vector<ll>(n,0));
    depth.assign(n,0);
    // Recorrido iterativo (BFS): una recursión de profundidad ~n puede desbordar la pila.
    vector<ll> order = {0}; // raíz 0
    for (size_t k = 0; k < order.size(); k++) {
        ll x = order[k];
        for (auto y : children[x]) {
            up[0][y] = x;
            depth[y] = depth[x] +1;
            order.pb(y);
        }
    }

    for (int i = 1; i < LOG; i++)
        for (int j = 0; j < n; j++) 
            up[i][j] = up[i-1][up[i-1][j]];
}
 
ll kParent(ll x, ll k) {
    ll i = 0;
    while (k) {
        if (k & 1) x = up[i][x];
        k >>= 1;
        i++;
    }
    return x;
}
 
ll query(ll x, ll y) {
    if (depth[x] < depth[y]) swap(x, y);
    x = kParent(x, depth[x] - depth[y]);
    if (x == y) {
        return x;
    }
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[i][x] != up[i][y]) {
            x = up[i][x];
            y = up[i][y];
        }
    }
    return up[0][x];
}

void test_case() {
    ll n, q; cin >> n >> q;
    vvl children(n);
    for (int i = 1; i < n; i++) {
        ll p; cin >> p; p--;
        children[p].pb(i);
    }
    init(children, n);
    
    for (int i = 0; i < q; i++) {
        ll x, y;cin >> x >> y;
        x--,y--;
        cout << query(x, y) + 1 << "\n";
    }
}
#endif
