// yosupo: ordered_set
// prueba: 01_Estructuras/Treap/treap.cpp
// split(t,l,r,x): l = claves < x, r = claves >= x. Las consultas recorren el árbol con siz.
#include "../../01_Estructuras/Treap/treap.cpp"
using ll = long long;
pitem root = nullptr;
bool contains(ll x) { pitem t = root; while (t) { if (t->key == x) return true; t = x < t->key ? t->l : t->r; } return false; }
void ins(ll x) { if (contains(x)) return; pitem l, r; split(root, l, r, x); merge(l, l, new item(x)); merge(root, l, r); }
void del(ll x) { if (!contains(x)) return; pitem l, m, r; split(root, l, r, x); split(r, m, r, x + 1); merge(root, l, r); delete m; }
ll kth(ll k) { pitem t = root; while (t) { ll s = sz(t->l); if (k < s) t = t->l; else if (k == s) return t->key; else k -= s + 1, t = t->r; } return -1; }
ll countLE(ll x) { ll c = 0; pitem t = root; while (t) { if (t->key <= x) c += sz(t->l) + 1, t = t->r; else t = t->l; } return c; }
signed main() {
    fast;
    srand(12345);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) { ll a; cin >> a; merge(root, root, new item(a)); }   // a llega ordenado
    while (q--) {
        int t; ll x; cin >> t >> x;
        if (t == 0) ins(x);
        else if (t == 1) del(x);
        else if (t == 2) cout << (sz(root) < x ? -1 : kth(x - 1)) << '\n';
        else if (t == 3) cout << countLE(x) << '\n';
        else if (t == 4) { ll c = countLE(x); cout << (c == 0 ? -1 : kth(c - 1)) << '\n'; }
        else { ll c = countLE(x - 1); cout << (c == sz(root) ? -1 : kth(c)) << '\n'; }
    }
}
