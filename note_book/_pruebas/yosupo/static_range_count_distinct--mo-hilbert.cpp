// yosupo: static_range_count_distinct
// prueba: 01_Estructuras/Mo/mo-s-hilbert-curve.cpp
// El archivo aporta Query y el orden de Hilbert; add/remove se escriben aquí.
#include "../../01_Estructuras/Mo/mo-s-hilbert-curve.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    vi a(n); for (auto& x : a) cin >> x;
    vi vals = a; sort(vals.begin(), vals.end()); vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (auto& x : a) x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    vector<Query> qs(q);
    for (int i = 0; i < q; i++) { int l, r; cin >> l >> r; qs[i] = {l, r - 1, i, 0}; qs[i].calcOrder(); }
    sort(qs.begin(), qs.end());
    vi cnt(max<int>(n, 1), 0), ans(q, 0);
    int cur = 0, L = 0, R = -1;
    auto add = [&](int i) { if (cnt[a[i]]++ == 0) cur++; };
    auto rem = [&](int i) { if (--cnt[a[i]] == 0) cur--; };
    for (auto& Q : qs) {
        if (Q.l > Q.r) { ans[Q.idx] = 0; continue; }
        while (L > Q.l) add(--L);
        while (R < Q.r) add(++R);
        while (L < Q.l) rem(L++);
        while (R > Q.r) rem(R--);
        ans[Q.idx] = cur;
    }
    for (int x : ans) cout << x << '\n';
}
