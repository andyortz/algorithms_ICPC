// prueba: 01_Estructuras/Segment_Tree/Dos_dimensiones/segment-tree-2d.cpp  (0-indexado, inclusivo)
#include "../../01_Estructuras/Segment_Tree/Dos_dimensiones/segment-tree-2d.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 15), m = rnd(1, 15);
        vector<vector<Node>> a(n, vector<Node>(m));
        for (auto& row : a) for (auto& x : row) x.x = rnd(-1e9, 1e9);
        segtree2d st;
        if (it % 2) st.init(n, m, a);
        else { st.init(n, m); for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) st.update(i, j, a[i][j]); }
        for (int k = 0; k < 300; k++) {
            int ty = rnd(0, 2), x1 = rnd(0, n - 1), x2 = rnd(x1, n - 1), y1 = rnd(0, m - 1), y2 = rnd(y1, m - 1);
            if (ty == 0) { ll v = rnd(-1e9, 1e9); st.update(x1, y1, {v}); a[x1][y1].x = v; }
            else if (ty == 1) CHECK(st.get(x1, y1).x == a[x1][y1].x);
            else { ll s = 0; for (int i = x1; i <= x2; i++) for (int j = y1; j <= y2; j++) s += a[i][j].x; CHECK(st.query(x1, y1, x2, y2).x == s); }
        }
    }
    FIN("segment-tree-2d");
}
