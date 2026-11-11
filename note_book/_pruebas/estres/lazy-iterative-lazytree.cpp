// prueba: 01_Estructuras/Segment_Tree/Lazy/iterative-lazytree.cpp
// SET y ADD en rango, asignación puntual, suma en rango; max_right/min_left con n potencia de 2.
#include "../../01_Estructuras/Segment_Tree/Lazy/iterative-lazytree.cpp"
#include "comun.hpp"
signed main() {
    for (int it = 0; it < 600; it++) {
        bool pot2 = it % 2;
        int n = pot2 ? (1 << rnd(0, 6)) : rnd(1, 50);
        bool neg = it % 3 == 0;                       // con negativos no se usan max_right/min_left
        vector<ll> a(n);
        lazyseg st(n);
        for (int i = 0; i < n; i++) { a[i] = rnd(neg ? -100 : 0, 100); st.update(i, {a[i]}); }
        for (int k = 0; k < 300; k++) {
            int ty = rnd(0, 5), l = rnd(0, n - 1), r = rnd(l, n - 1);
            if (ty == 0) { ll v = rnd(neg ? -50 : 0, 50); st.apply(l, r, {SET, v}); for (int i = l; i <= r; i++) a[i] = v; }
            else if (ty == 1) { ll v = rnd(neg ? -50 : 0, 50); st.apply(l, r, {ADD, v}); for (int i = l; i <= r; i++) a[i] += v; }
            else if (ty == 2) { ll v = rnd(neg ? -50 : 0, 50); st.update(l, {v}); a[l] = v; }
            else if (ty == 3) { ll s = 0; for (int i = l; i <= r; i++) s += a[i]; CHECK(st.query(l, r).x == s); }
            else if (pot2 && !neg) {
                ll K = rnd(0, 60 * n);
                auto g = [&](Node x) { return x.x <= K; };
                if (ty == 4) {   // mayor r con suma(a[l..r-1]) <= K
                    int L = rnd(0, n), R = L; ll s = 0;
                    while (R < n && s + a[R] <= K) s += a[R++];
                    CHECK(st.max_right(L, g) == R);
                } else {         // menor l con suma(a[l..r-1]) <= K
                    int R = rnd(0, n), L = R; ll s = 0;
                    while (L > 0 && s + a[L - 1] <= K) s += a[--L];
                    CHECK(st.min_left(R, g) == L);
                }
            }
        }
    }
    FIN("iterative-lazytree");
}
