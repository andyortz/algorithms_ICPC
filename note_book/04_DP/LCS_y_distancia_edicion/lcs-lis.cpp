// Implementación añadida al notebook; base: 00_Template/simple.cpp.
// Longitud de LCS mediante posiciones + LIS (Hunt-Szymanski).
// Referencia: https://doi.org/10.1145/359581.359603
// n = a.size(), m = b.size(), r = número de pares (i,j) con a[i] == b[j].
// Tiempo O((n+m+r) * log(m+2)), memoria O(m). No materializa los r pares.
// Si b no tiene repetidos: r <= n, tiempo O((n+m) * log(m+2)).
// En particular, dos permutaciones de tamaño N: O(N log N).
// Con muchos repetidos puede ser O(n*m*log(m+2)): usar lcs_bitset para strings.
// Admite string y vector<int>; devuelve la longitud, no reconstruye la LCS.
// Ejemplo: vi a={3,1,2}, b={1,3,2}; cout << lcs_lis(a,b); // 2

#ifndef NOTEBOOK_LCS_LIS
#define NOTEBOOK_LCS_LIS
#include "../../_base/template-simple.hpp"

template<class Secuencia>
int lcs_lis(const Secuencia& a, const Secuencia& b) {
    using Valor = typename Secuencia::value_type;
    map<Valor, vi> posiciones;
    for (int j = 0; j < (int)b.size(); ++j) posiciones[b[j]].pb(j);

    vi mejores;
    mejores.reserve(min(a.size(), b.size()));
    for (const auto& valor : a) {
        auto encontrado = posiciones.find(valor);
        if (encontrado == posiciones.end()) continue;
        const vi& indices = encontrado->second;
        // Descendente: no usar dos coincidencias de un mismo a[i] en la LIS.
        for (auto it = indices.rbegin(); it != indices.rend(); ++it) {
            auto lugar = lower_bound(all(mejores), *it);
            if (lugar == mejores.end()) mejores.pb(*it);
            else *lugar = *it;
        }
    }
    return (int)mejores.size();
}
#endif
