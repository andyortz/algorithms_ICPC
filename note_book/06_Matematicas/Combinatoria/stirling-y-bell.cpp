// Tema: 06_Matematicas/Combinatoria
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_F177B8B2424314A8
#define NOTEBOOK_GENERADO_F177B8B2424314A8
#include "../../_base/template-simple.hpp"
using ll = long long;
// stir[n][k] cantidad de formas de paritcionar un conjunto de n elementos en k conjuntos
// bell[n] cantidad de formas de particionar un conjunto
ll stir[tam][tam];
ll bell[tam];
void stirBell() {
  for (int i=(1), nb_fin_1=(tam); i<nb_fin_1; ++i) {
  stir[i][1] = 1;
  for (int j=(2), nb_fin_3=(1010); j<nb_fin_3; ++j)
    stir[i][j] = (j * stir[i - 1][j] % MOD + stir[i - 1][j - 1]) % MOD;
  }
  for (int i=(1), nb_fin_5=(tam); i<nb_fin_5; ++i)
  for (int j=(1), nb_fin_7=(i + 1); j<nb_fin_7; ++j)
    bell[i] = (bell[i] + stir[i][j]) % MOD;
}
#endif
