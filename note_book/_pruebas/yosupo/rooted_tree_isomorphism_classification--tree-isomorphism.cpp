// yosupo: rooted_tree_isomorphism_classification
// prueba: 03_Arboles/Isomorfismo_y_hashing/tree-isomorphism-extra.cpp
#include "../../03_Arboles/Isomorfismo_y_hashing/tree-isomorphism-extra.cpp"
signed main() {
    fast;
    int n; cin >> n;
    vector<vi> g(n);
    for (int i = 1; i < n; i++) { int p; cin >> p; g[p].pb(i); }
    dfs(g, 0);
    map<ull, int> cls; vi ans(n);
    for (int i = 0; i < n; i++) {
        auto it = cls.find(hashes[i]);
        if (it == cls.end()) it = cls.emplace(hashes[i], cls.size()).first;
        ans[i] = it->second;
    }
    cout << cls.size() << '\n';
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
}
