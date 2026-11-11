// Tema: 06_Matematicas/Teoria_de_numeros/Diofanticas
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (2 líneas).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Adaptación: Dependencias del mismo origen incluidas explícitamente: extra/Math/Extended Euclides.cpp.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_5E51719C0F2B3DDA
#define NOTEBOOK_GENERADO_5E51719C0F2B3DDA
#include "../../../_base/template-simple.hpp"
#include "../Euclides/extended-euclides-extra.cpp"
using ll = long long;
// Encuentra x, y en la ecuación de la forma ax + by = c
// Agregar Extended Euclides.

ll g;
bool diophantine(ll a, ll b, ll c) {
    x = y = 0;
    if (!a && !b) return (!c); // sólo hay solución con c = 0
    g = euclid(abs(a), abs(b));
    if (c % g) return false;
    a /= g; b /= g; c /= g;
    if (a < 0) x *= -1;
    x = (x % b) * (c % b) % b;
    if (x < 0) x += b;
    y = (c - a*x) / b;
    return true;
}
#endif
