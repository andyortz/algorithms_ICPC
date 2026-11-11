// Tema: 06_Matematicas/Sumas_de_pisos
// Base: Template/simple.cpp (int = long long).
// Requisito: n y nums; el llenado de ch va dentro de solve().
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_5B5E1FDD8A1D030B
#define NOTEBOOK_GENERADO_5B5E1FDD8A1D030B
#include "../../_base/template-simple.hpp"

/*
Trick using SQRT for problems using de diferent floor values o a num.

A num has only around SQRT(n) possible values when it is floor divided, for 2e5 is around 890
e.g. floor(n/i)=j. j has around sqrt(n) values.
e.g. floor(10/i)=j. j only can be 1, 2, 3, 5, 10 for any i

The following function calculates when a n/i changes if you iterate over i increasing.
You can solve https://codeforces.com/gym/105009/problem/L using this.
*/

const int MXN = 2e5 + 10;
int nums[MXN];
vector<int> ch[MXN];
for (int i =0;i<n;i++) {
  for (int d = 1; d <= nums[i]; d = nums[i]/(nums[i]/d)+1) {
    ch[d].pb(i);
  }
  ch[nums[i]+1].pb(i);
}
#endif
