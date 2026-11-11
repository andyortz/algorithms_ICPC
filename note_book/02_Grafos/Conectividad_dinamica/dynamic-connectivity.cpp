// Tema: 02_Grafos/Conectividad_dinamica
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_512BF878911B0770
#define NOTEBOOK_GENERADO_512BF878911B0770
#include "../../_base/template-simple.hpp"
using ll = long long;
struct union_find {
    struct uf_save { ll a, rnka, b, rnkb; };
    vector<uf_save> saves;

    vector<ll> p, rnk;
    ll n, comps;

    union_find(ll _n) : n(_n), p(_n), rnk(_n) {
        for (int i = 0;i<n;i++) p[i] = i;
        comps = n;
    };

    ll find(ll x) { return p[x] == x ? x : find(p[x]); }

    int merge(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a == b) return 0;

        if (rnk[b] > rnk[a]) swap(a,b);

        comps--;
        saves.pb({a, rnk[a], b, rnk[b]});
        p[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return 1;
    };

    void rollback() {
        if (saves.empty()) return;
        uf_save lst = saves.back();
        saves.pop_back();
        comps++;
        p[lst.a] = lst.a, rnk[lst.a] = lst.rnka;
        p[lst.b] = lst.b, rnk[lst.b] = lst.rnkb;
    }
};

struct query { ll a, b; };
struct segtree {
    int n; // size of queries!!!
    vector<vector<query>> t; // node si a vector<query>

    segtree(int queries_n) : n(queries_n), t(2*n) {}

    void addQuery(int l, int r, const query &q) {
        l += n, r += n+1;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l&1) t[l++].pb(q);
            if (r&1) t[--r].pb(q);
        }
    }

    void dfs(int id, vector<ll> &ans, union_find &uf) {
        ll cnt = 0;
        for (auto & q : t[id]) cnt += uf.merge(q.a, q.b);

        if (id < n) dfs(id*2, ans, uf), dfs(id*2+1,ans,uf);
        else ans[id-n] = uf.comps;
     
        for (int i =0;i<cnt;i++) uf.rollback();
    }

    vector<ll> solve(union_find &uf) {
        vector<ll> ans(n);
        dfs(1, ans, uf);
        return ans;
    }
};

void test_case() {
    ll n, m, q; cin >> n >> m >> q;

    segtree tree(q+1);
    vector<map<int,int>> lst(n); // to manage living time!

    auto addEdge = [&](int x, int y, int time) {
        if (y<x) swap(x,y);
        lst[x][y] = time;
    };

    auto erEdge = [&](int x, int y, int time) {
        if (y<x) swap(x,y); 
        tree.addQuery(lst[x][y], time-1, {x,y});
        lst[x].erase(y);
    };

    for (int i = 0;i<m;i++) {
        ll x, y; cin >> x >> y; x--,y--;
        addEdge(x,y,0);
    }

    for (int time =1;time<=q;time++) {
        ll t, x, y; cin >> t >> x >> y;
        x--,y--;
        if (t==1) addEdge(x,y,time);
        else erEdge(x,y,time);
    }

    for (int i = 0;i < n;i++)
        for (auto &[j,v] : lst[i]) // be carefull with it and erasing
            tree.addQuery(v,q,{i,j});
 
    union_find uf(n);
    auto ans = tree.solve(uf);

    for (int i = 0;i < ans.size(); i++) {
        cout << ans[i] << " \n" [i+1 == ans.size()];
    }
} // https://cses.fi/problemset/task/2133/
#endif
