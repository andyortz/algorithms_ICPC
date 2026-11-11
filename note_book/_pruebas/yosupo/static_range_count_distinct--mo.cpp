// yosupo: static_range_count_distinct
// prueba: 01_Estructuras/Mo/mo-s.cpp
// Consultas vacías (l == r) se responden con 0 sin pasar por Mo.
#include "../../01_Estructuras/Mo/mo-s.cpp"
signed main() {
    fast;
    int n, q; cin >> n >> q;
    vi a(n); for (auto& x : a) cin >> x;
    vi vals = a; sort(vals.begin(), vals.end()); vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (auto& x : a) x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    vector<query> qs; vi orig;                    // idx de Mo = posición en qs (0..k-1)
    for (int i = 0; i < q; i++) { int l, r; cin >> l >> r; if (l < r) qs.pb({l, r - 1, (int)qs.size()}), orig.pb(i); }
    vi cnt(max<int>(n, 1), 0);
    ll distintos = 0;
    auto add = [&](int i) { if (cnt[a[i]]++ == 0) distintos++; };
    auto rem = [&](int i) { if (--cnt[a[i]] == 0) distintos--; };
    vector<ll> res = mo(qs, n, add, rem, [&]() { return distintos; });
    vector<ll> ans(q, 0);
    for (size_t k = 0; k < qs.size(); k++) ans[orig[k]] = res[k];
    for (ll x : ans) cout << x << '\n';
}
