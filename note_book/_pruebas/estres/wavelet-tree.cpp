// prueba: 01_Estructuras/Wavelet_Tree/wavelet-tree-vasito.cpp
// query0 (i-ésimo menor en [a, b)) y upd (intercambiar posiciones i, i+1). Valores en [0, n).
#include "../../01_Estructuras/Wavelet_Tree/wavelet-tree-vasito.cpp"
#include "comun.hpp"
WT wt;
signed main() {
    for (int it = 0; it < 500; it++) {
        int n = rnd(2, 40);
        vi a(n);
        wt.init(n);
        for (auto& x : a) { x = rnd(0, n - 1); wt.add(x); }
        for (int k = 0; k < 200; k++) {
            if (rnd(0, 2) == 0) { int i = rnd(0, n - 2); wt.upd(i); swap(a[i], a[i + 1]); }
            else {
                int l = rnd(0, n - 1), r = rnd(l + 1, n), i = rnd(0, r - l - 1);
                vi b(a.begin() + l, a.begin() + r); sort(b.begin(), b.end());
                CHECK(wt.query0(l, r, i) == b[i]);
            }
        }
    }
    FIN("wavelet-tree");
}
