// prueba: 01_Estructuras/Sparse_Table/spare-table.cpp
#include "../../01_Estructuras/Sparse_Table/spare-table.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 1000; it++) {
        int n = rnd(1, 70);
        vi a(n);
        for (auto& x : a) x = rnd(-1e9, 1e9);
        rmq r(a);
        for (int k = 0; k < 100; k++) {
            int l = rnd(0, n - 1), rr = rnd(l, n - 1);
            CHECK(r.get(l, rr) == *min_element(a.begin() + l, a.begin() + rr + 1));
        }
    }
    FIN("sparse-table");
}
