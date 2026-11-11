// prueba: 01_Estructuras/Sparse_Table/sparse-table-2d.cpp  (MAX_N = MAX_M = 100)
#include "../../01_Estructuras/Sparse_Table/sparse-table-2d.cpp"
#include "comun.hpp"
signed main() {
    calc_log2();
    for (int it = 0; it < 300; it++) {
        n = it < 20 ? MAX_N - rnd(0, 3) : rnd(1, 20);
        m = it < 20 ? MAX_M - rnd(0, 3) : rnd(1, 20);
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) MAT[i][j] = rnd(-1e9, 1e9);
        build();
        for (int k = 0; k < 200; k++) {
            int x1 = rnd(0, n - 1), x2 = rnd(x1, n - 1), y1 = rnd(0, m - 1), y2 = rnd(y1, m - 1);
            ll mn = LLONG_MAX;
            for (int i = x1; i <= x2; i++) for (int j = y1; j <= y2; j++) mn = min(mn, (ll)MAT[i][j]);
            CHECK(rmq(x1, y1, x2, y2) == mn);
        }
    }
    FIN("sparse-table-2d");
}
