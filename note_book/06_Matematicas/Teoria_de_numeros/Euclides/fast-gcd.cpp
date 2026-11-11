// Requisito de selección: Adaptación de 64 bits: __builtin_ctz debe ser __builtin_ctzll. Usar entradas no negativas y tratar el cero antes del builtin.
// Tema: 06_Matematicas/Teoria_de_numeros/Euclides
// Base: Template/simple.cpp (int = long long).
// Requisito: Revisar casos cero, productos y desplazamientos antes de usar en el rango completo de 64 bits.
// Requisito: Operaciones de bits/ensamblador: revisar ancho de palabra (32/64 bits) y el caso cero; preservar tipos explícitos cuando el algoritmo lo exige.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_833CE5E7214514B4
#define NOTEBOOK_GENERADO_833CE5E7214514B4
#include "../../../_base/template-simple.hpp"

int gcd(int a, int b) {
  if (!a || !b)
    return a | b;
  unsigned shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);
  do {
    b >>= __builtin_ctz(b);
    if (a > b)
      swap(a, b);
    b -= a;
  } while (b);
  return a << shift;
}
#endif
