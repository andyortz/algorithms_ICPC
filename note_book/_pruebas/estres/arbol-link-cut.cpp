// prueba: 03_Arboles/Link_Cut_Tree/link-cut.cpp
// Bosque dinámico: link, cut(x,y), connected, modify (suma en camino), query (suma en camino);
// con raíz fijada por mkR(r): lca, father, depth, lift, getR y cut(x).
#include "../../03_Arboles/Link_Cut_Tree/link-cut.cpp"
#include "comun.hpp"
int n_; vector<set<int>> adj; vector<ll> val;
vector<int> parentFrom(int r, vector<int>& dep) {     // BFS desde r en la componente de r
    vector<int> p(n_, -2); dep.assign(n_, -1); p[r] = -1; dep[r] = 0; vector<int> q = {r};
    for (size_t i = 0; i < q.size(); i++) for (int y : adj[q[i]]) if (p[y] == -2) p[y] = q[i], dep[y] = dep[q[i]] + 1, q.pb(y);
    return p;
}
vector<int> path(int x, int y) {
    vector<int> dep; auto p = parentFrom(x, dep); vector<int> res;
    for (int z = y; z != -1; z = p[z]) res.pb(z);
    return res;
}
signed main() {
    for (int it = 0; it < 300; it++) {
        n_ = rnd(1, 30); adj.assign(n_, {}); val.assign(n_, 0);
        vector<Node> nd(n_);
        for (int i = 0; i < n_; i++) { val[i] = rnd(0, 1000); nd[i] = new Node_t(val[i]); }
        for (int k = 0; k < 300; k++) {
            int x = rnd(0, n_ - 1), y = rnd(0, n_ - 1), ty = rnd(0, 6);
            vector<int> dep; auto p = parentFrom(x, dep); bool con = p[y] != -2;
            CHECK(connected(nd[x], nd[y]) == con);
            if (ty == 0 && !con) { link(nd[x], nd[y]); adj[x].insert(y); adj[y].insert(x); }
            else if (ty == 1 && !adj[x].empty()) { int z = *adj[x].begin(); cut(nd[x], nd[z]); adj[x].erase(z); adj[z].erase(x); }
            else if (ty == 2 && con) { ll d = rnd(1, 100); modify(nd[x], nd[y], d); for (int z : path(x, y)) val[z] += d; }
            else if (ty == 3 && con) { ll s = 0; for (int z : path(x, y)) s += val[z]; CHECK(query(nd[x], nd[y]) == s); }
            else if (ty >= 4) {
                int r = x; mkR(nd[r]);
                vector<int> d2; auto pr = parentFrom(r, d2);
                vector<int> comp; for (int z = 0; z < n_; z++) if (pr[z] != -2) comp.pb(z);
                int u = comp[rnd(0, comp.size() - 1)], w = comp[rnd(0, comp.size() - 1)];
                if (ty == 4) {
                    int a = u, b = w; while (d2[a] > d2[b]) a = pr[a]; while (d2[b] > d2[a]) b = pr[b]; while (a != b) a = pr[a], b = pr[b];
                    CHECK(lca(nd[u], nd[w]) == nd[a]);
                } else if (ty == 5) {
                    Node f = father(nd[u]); CHECK(pr[u] == -1 ? f == nullptr : f == nd[pr[u]]);
                    CHECK(depth(nd[u]) == d2[u]);
                    int t = rnd(0, d2[u]), z = u; for (int j = 0; j < t; j++) z = pr[z];
                    CHECK(lift(nd[u], t) == nd[z] && getR(nd[u]) == nd[r]);
                } else if (u != r) { cut(nd[u]); adj[u].erase(pr[u]); adj[pr[u]].erase(u); }
            }
        }
    }
    FIN("link-cut");
}
