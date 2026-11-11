// prueba: 01_Estructuras/Treap/treap-implicit-vasito.cpp
// Secuencia con split/merge por tamaño: insertar, borrar y mover bloques; se compara con vector.
#include "../../01_Estructuras/Treap/treap-implicit-vasito.cpp"
#include "comun.hpp"
void dump(pitem t, vector<ll>& out) { if (!t) return; push(t); dump(t->l, out); out.pb(t->val); dump(t->r, out); }
signed main() {
    for (int it = 0; it < 500; it++) {
        pitem root = nullptr; vector<ll> v;
        for (int k = 0; k < 200; k++) {
            int ty = v.empty() ? 0 : rnd(0, 2);
            if (ty == 0) {
                int p = rnd(0, v.size()); ll x = rnd(-1e9, 1e9);
                pitem L, R; split(root, L, R, p); merge(L, L, new item(x)); merge(root, L, R);
                v.insert(v.begin() + p, x);
            } else if (ty == 1) {
                int p = rnd(0, v.size() - 1);
                pitem L, M, R; split(root, L, R, p); split(R, M, R, 1); merge(root, L, R); delete M;
                v.erase(v.begin() + p);
            } else {   // cortar [l, r) y pegarlo al principio
                int l = rnd(0, v.size() - 1), r = rnd(l + 1, v.size());
                pitem A, B, C; split(root, A, B, l); split(B, B, C, r - l); merge(root, B, A); merge(root, root, C);
                vector<ll> w(v.begin() + l, v.begin() + r); w.insert(w.end(), v.begin(), v.begin() + l); w.insert(w.end(), v.begin() + r, v.end()); v = w;
            }
            CHECK(cnt(root) == (ll)v.size());
            if (k % 10 == 0) { vector<ll> out; dump(root, out); CHECK(out == v); }
        }
    }
    FIN("treap-implicit");
}
