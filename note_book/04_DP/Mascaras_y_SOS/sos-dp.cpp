// Tema: 04_DP/Mascaras_y_SOS
// Base: Template/simple.cpp (int = long long).
// Requisito: M y dp; pegar el bucle dentro de solve() o una función.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_459071506D2D089E
#define NOTEBOOK_GENERADO_459071506D2D089E
#include "../../_base/template-simple.hpp"

// F(mask) = op(F(x_1), F(x_2), ...) where x is submask of mask
// init sos[z] 
for (int i = 0; i < M; i++) {
  for (int mask = 0; mask < (1 << M); mask++) {
    if (mask & (1 << i)) { 
      sos[mask] += sos[mask ^ (1 << i)]; 
    }		}
}
#endif
