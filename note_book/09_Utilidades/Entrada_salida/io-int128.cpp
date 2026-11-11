// Selección: Una sola salida por cout y entrada por cin, evitando mezclar stdio con fast. Entrada válida dentro del rango signed de 128 bits.
// Tema: 09_Utilidades/Entrada_salida
// Base: Template/simple.cpp (int = long long).
// Requisito: Requiere compilador GNU con enteros de 128 bits.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_8EC047B3DE1B7F30
#define NOTEBOOK_GENERADO_8EC047B3DE1B7F30
#include "../../_base/template-simple.hpp"

// Lectura y escritura con cin/cout, compatibles con fast.
__int128 read() {
    string s; cin >> s;
    bool negative = !s.empty() && s[0] == '-';
    __uint128_t x = 0;
    for (int i = (!s.empty() && (s[0] == '-' || s[0] == '+')); i < (int)s.size(); ++i)
        x = x * 10 + (s[i] - '0');
    return negative && x ? -static_cast<__int128>(x - 1) - 1 : static_cast<__int128>(x);
}
void print_iostream(__int128 x) {
    __uint128_t magnitude = x < 0 ? __uint128_t(0) - __uint128_t(x) : __uint128_t(x);
    string digits;
    do { digits.pb(char('0' + magnitude % 10)); magnitude /= 10; } while (magnitude);
    if (x < 0) cout << '-';
    reverse(all(digits)); cout << digits;
}
#endif
