// prueba: 01_Estructuras/Treap/treap-implicit-father-vasito.cpp
// El archivo exige un item con puntero f (padre): se declara aquí junto con push/cnt/upd_cnt.
#include "../../_base/template-simple.hpp"
mt19937 rngItem(5);
typedef struct item *pitem;
struct item { long long pr, cnt, val; pitem l, r, f; item(long long v) : pr(rngItem()), cnt(1), val(v), l(0), r(0), f(0) {} };
void push(pitem) {}
long long cnt(pitem t) { return t ? t->cnt : 0; }
void upd_cnt(pitem t) { if (t) t->cnt = cnt(t->l) + cnt(t->r) + 1; }
#include "../../01_Estructuras/Treap/treap-implicit-father-vasito.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 400; it++) {
        int n = rnd(1, 60);
        vector<pitem> nodes(n); pitem root = nullptr; vector<int> order;   // order = secuencia de ids
        for (int i = 0; i < n; i++) { nodes[i] = new item(i); merge(root, root, nodes[i]); order.pb(i); }
        for (int k = 0; k < 200; k++) {
            int l = rnd(0, n - 1), r = rnd(l + 1, n);
            pitem A, B, C; split(root, A, B, l); split(B, B, C, r - l); merge(root, B, A); merge(root, root, C);
            vector<int> w(order.begin() + l, order.begin() + r); w.insert(w.end(), order.begin(), order.begin() + l); w.insert(w.end(), order.begin() + r, order.end()); order = w;
            for (int q = 0; q < 5; q++) {
                int id = rnd(0, n - 1), pos;
                pitem rt = ::root(nodes[id], pos);
                CHECK(rt == root && order[pos] == id);
            }
        }
    }
    FIN("treap-implicit-father");
}
