// prueba: 01_Estructuras/Fenwick/fenwick-tree-2d.cpp  (1-indexado)
#include "../../01_Estructuras/Fenwick/fenwick-tree-2d.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 15), m = rnd(1, 15);
        vector<vector<ll>> a(n + 1, vector<ll>(m + 1, 0));
        BIT2D bt(n, m);
        for (int k = 0; k < 300; k++) {
            int ty = rnd(0, 2), x1 = rnd(1, n), x2 = rnd(x1, n), y1 = rnd(1, m), y2 = rnd(y1, m);
            if (ty == 0) { ll v = rnd(-1e9, 1e9); bt.add(x1, y1, v); a[x1][y1] += v; }
            else if (ty == 1) { ll v = rnd(-1e9, 1e9); bt.set(x1, y1, v); a[x1][y1] = v; }
            else { ll s = 0; for (int i = x1; i <= x2; i++) for (int j = y1; j <= y2; j++) s += a[i][j]; CHECK(bt.sum(x1, y1, x2, y2) == s); }
        }
    }
    FIN("fenwick-2d");
}
