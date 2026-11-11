// yosupo: range_kth_smallest
// prueba: 01_Estructuras/Segment_Tree/Persistente/persistantsegmenttree.cpp
// Versión i = conteos de a[0..i-1] por valor comprimido; se desciende por v->l / v->r.
#include "../../01_Estructuras/Segment_Tree/Persistente/persistantsegmenttree.cpp"
using ll = long long;
signed main() {
    fast;
    int n, q; cin >> n >> q;
    vi a(n); for (auto& x : a) cin >> x;
    vi vals = a; sort(vals.begin(), vals.end()); vals.erase(unique(vals.begin(), vals.end()), vals.end());
    ll m = vals.size();
    vector<ll> zero(m, 0);
    vector<Vertex*> ver = {build(zero)};
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
        ver.pb(update(ver.back(), m, pos, get_sum(ver.back(), m, pos, pos) + 1));
    }
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        Vertex *L = ver[l], *R = ver[r];
        int tl = 0, tr = m - 1;
        while (tl != tr) {
            int tm = (tl + tr) / 2;
            ll c = R->l->sum - L->l->sum;
            if (k < c) L = L->l, R = R->l, tr = tm;
            else k -= c, L = L->r, R = R->r, tl = tm + 1;
        }
        cout << vals[tl] << '\n';
    }
}
