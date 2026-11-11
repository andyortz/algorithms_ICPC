// yosupo: range_kth_smallest
// prueba: 01_Estructuras/Wavelet_Tree/wavelet-tree-vasito.cpp
// Valores comprimidos a [0, n). WT ocupa 2^20 vectores: se declara global.
#include "../../01_Estructuras/Wavelet_Tree/wavelet-tree-vasito.cpp"
using ll = long long;
WT wt;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    vi a(n); for (auto& x : a) cin >> x;
    vi vals = a; sort(vals.begin(), vals.end()); vals.erase(unique(vals.begin(), vals.end()), vals.end());
    wt.init(max<int>(n, 2));
    for (int i = 0; i < n; i++) wt.add(lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin());
    while (q--) { int l, r, k; cin >> l >> r >> k; cout << vals[wt.query0(l, r, k)] << '\n'; }
}
