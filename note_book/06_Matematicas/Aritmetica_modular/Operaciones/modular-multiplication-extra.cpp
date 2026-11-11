// Requisito de selección: La fórmula original usa overflow signed en a*b; requiere reemplazo por __int128 para aritmética definida en todo el rango positivo de int64.
// Tema: 06_Matematicas/Aritmetica_modular/Operaciones
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_3D679CF151D517CC
#define NOTEBOOK_GENERADO_3D679CF151D517CC
#include "../../../_base/template-simple.hpp"
using ll = long long;
// * Calcula (a*b) % m sin overflow cuando m es ll.
// O(1)
ll mulmod(ll a, ll b, ll m) {
    ll r = a*b-(ll)((long double)a*b/m+.5)*m;
    return r < 0 ? r+m : r;
}
#endif
