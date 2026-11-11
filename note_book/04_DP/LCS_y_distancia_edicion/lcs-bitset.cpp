// Implementación añadida al notebook; base: 00_Template/simple.cpp.
// Longitud de LCS para strings, incluidos caracteres repetidos y bytes 0..255.
// Referencia: https://allisons.org/ll/Publications/1986IPL/
// n = mayor longitud, m = menor longitud, W = ceil(m/64).
// Tiempo O(m + (n+256)*W); memoria O(256*W) palabras de 64 bits.
// No es O(N log N) general. No reconstruye la subsecuencia.
// Usa bytes: para Unicode, string representa bytes UTF-8, no puntos de código.
// uint64_t es intencional: NO sustituir por int (long long signed en la plantilla).
// Ejemplo: cout << lcs_bitset("abcde", "ace"); // 3

#ifndef NOTEBOOK_LCS_BITSET
#define NOTEBOOK_LCS_BITSET
#include "../../_base/template-simple.hpp"

int lcs_bitset(string_view a, string_view b) {
    if (a.size() < b.size()) swap(a, b);
    if (b.empty()) return 0;
    const int palabras = ((int)b.size() + 63) / 64;
    array<vector<uint64_t>, 256> mascara;
    for (auto& bits : mascara) bits.assign(palabras, 0);
    for (int j = 0; j < (int)b.size(); ++j)
        mascara[static_cast<unsigned char>(b[j])][j / 64] |= uint64_t(1) << (j % 64);

    vector<uint64_t> fila(palabras, 0);
    for (unsigned char c : a) {
        uint64_t acarreo = 1, prestamo = 0;
        for (int j = 0; j < palabras; ++j) {
            const uint64_t anterior = fila[j];
            const uint64_t x = anterior | mascara[c][j];
            const uint64_t y = (anterior << 1) | acarreo;
            acarreo = anterior >> 63;
            // Resta multipalabra x - y - prestamo, sin overflow signed.
            const uint64_t parcial = x - y;
            const uint64_t resta = parcial - prestamo;
            prestamo = (x < y) || (parcial < prestamo);
            fila[j] = x & ~resta;
        }
    }
    // Los bits fuera de b siguen en cero: fila siempre es un subconjunto de x.
    int respuesta = 0;
    for (uint64_t palabra : fila) respuesta += __builtin_popcountll(palabra);
    return respuesta;
}
#endif
