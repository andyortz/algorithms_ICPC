// Tema: 07_Geometria/Circulos_y_triangulos
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ld.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_E4311EFCA0515A8D
#define NOTEBOOK_GENERADO_E4311EFCA0515A8D
#include "../../_base/template-simple.hpp"
using ld = long double;
ld triangle_area(ld a, ld b, ld c) {
    ld s = (a + b + c) / 2;
    return sqrtl(s * (s - a) * (s - b) * (s - c));
}
#endif
