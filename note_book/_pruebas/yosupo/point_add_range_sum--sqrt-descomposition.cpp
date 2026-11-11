// yosupo: point_add_range_sum
// prueba: 01_Estructuras/Descomposicion_SQRT/sqrt-descomposition.cpp
// sqrt_() no se puede usar: lee "l r" sin tipo de consulta y su "if (query)" evalúa el
// puntero a la función (siempre verdadero). Se usan sus globales y query(i); la
// inicialización de bloques replica las primeras líneas de sqrt_().
#include "../../01_Estructuras/Descomposicion_SQRT/sqrt-descomposition.cpp"
using ll = long long;
signed main() {
    fast;
    cin >> n >> q;
    v.assign(n, 0); for (auto& x : v) cin >> x;
    block = sqrt(n) + 2;
    p.assign(block, 0);
    for (int i = 0; i < n; i++) p[i / block] += v[i];
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 0) { p[x / block] += y; v[x] += y; }
        else cout << query(y - 1) - query(x - 1) << '\n';
    }
}
