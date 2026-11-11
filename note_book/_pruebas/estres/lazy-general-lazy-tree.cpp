// prueba: 01_Estructuras/Segment_Tree/Lazy/general-lazy-tree.cpp
// Suma en rango + mínimo en rango + asignación puntual (todas las posiciones se inicializan con update).
#include "../../01_Estructuras/Segment_Tree/Lazy/general-lazy-tree.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 400; it++) {
        int n = rnd(1, 40);
        vector<ll> a(n);
        lazytree st; st.init(n);
        for (int i = 0; i < n; i++) { a[i] = rnd(-1e9, 1e9); st.update(i, Node(a[i])); }
        for (int k = 0; k < 300; k++) {
            int ty = rnd(0, 2), l = rnd(0, n - 1), r = rnd(l, n - 1);
            if (ty == 0) { ll v = rnd(-1e6, 1e6); st.apply(l, r, Func{v}); for (int i = l; i <= r; i++) a[i] += v; }
            else if (ty == 1) { ll v = rnd(-1e9, 1e9); st.update(l, Node(v)); a[l] = v; }
            else CHECK(st.query(l, r).mn == *min_element(a.begin() + l, a.begin() + r + 1));
        }
    }
    FIN("general-lazy-tree");
}
