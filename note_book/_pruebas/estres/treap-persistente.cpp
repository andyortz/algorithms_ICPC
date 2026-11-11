// prueba: 01_Estructuras/Treap/persistent-treap.cpp
// splitat(newT, t, l, r, k): l = primeras k+1 posiciones. query(t, 0, cnt-1, L, R) = suma en [L, R].
// Cada operación crea una versión nueva a partir de una versión vieja al azar.
#include "../../01_Estructuras/Treap/persistent-treap.cpp"
#include "comun.hpp"
ll sumaRango(pitem t, int L, int R) { return query(t, 0, cnt(t) - 1, L, R); }
signed main() {
    for (int it = 0; it < 300; it++) {
        vector<pitem> ver = {nullptr}; vector<vector<ll>> hist = {{}};
        for (int k = 0; k < 150; k++) {
            int v = rnd(0, ver.size() - 1); auto cur = hist[v];
            int ty = cur.empty() ? 0 : rnd(0, 2);
            if (ty == 0) {   // insertar x en la posición p
                int p = rnd(0, cur.size()); ll x = rnd(-1e6, 1e6);
                pitem L = nullptr, R = nullptr;
                if (p > 0) splitat(new item(), ver[v], L, R, p - 1); else R = ver[v];
                pitem LM = new item(); merge(LM, L, new item(x));
                pitem T = new item(); merge(T, LM, R);
                ver.pb(T); cur.insert(cur.begin() + p, x); hist.pb(cur);
            } else if (ty == 1) {   // borrar la posición p
                int p = rnd(0, cur.size() - 1);
                pitem L = nullptr, R = nullptr, M = nullptr, R2 = nullptr;
                if (p > 0) splitat(new item(), ver[v], L, R, p - 1); else R = ver[v];
                splitat(new item(), R, M, R2, 0);
                pitem T = new item(); merge(T, L, R2);
                ver.pb(T); cur.erase(cur.begin() + p); hist.pb(cur);
            } else {   // consulta de suma en una versión
                int L = rnd(0, cur.size() - 1), R = rnd(L, cur.size() - 1);
                ll sm = 0; for (int i = L; i <= R; i++) sm += cur[i];
                CHECK(sumaRango(ver[v], L, R) == sm);
            }
            int w = rnd(0, ver.size() - 1);      // las versiones viejas no cambian
            CHECK(cnt(ver[w]) == (ll)hist[w].size());
            if (!hist[w].empty()) { ll sm = 0; for (ll x : hist[w]) sm += x; CHECK(gtot(ver[w]) == sm); }
        }
    }
    FIN("persistent-treap");
}
