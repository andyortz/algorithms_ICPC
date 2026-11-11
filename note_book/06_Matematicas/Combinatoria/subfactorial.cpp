// Tema: 06_Matematicas/Combinatoria
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_4C393130B1F1CF3F
#define NOTEBOOK_GENERADO_4C393130B1F1CF3F
#include "../../_base/template-simple.hpp"
using ll = long long;
using vl = vector<long long>;
/* Denote as !n or derangement numbers
  Count the number of permutations where no element is in
  the originial position, formally p[i] != i
  
  it can be seen as f(n) = n!-sum_i=1_to_n { cnk(n,i)*f(n-i) } 
  f(0)=1, f(1) = 1
  
  1 0 1	2 9 44 265 1,854 14,833 133,496	
  
  n! = sumi=0,i<=n,{cnk(n,i)!i}
  d[i] = (d[i-1]+d[i-2])*(i-1)
*/
const int mxN = 2e6 + 10; // max number
ll add(ll x, ll y) { return (x+y)%MOD; }
ll mul(ll x, ll y) { return (x*y)%MOD; }
vl subFact(mxN);
void init() {
    subFact[0] = 1;
    subFact[1] = 0;
    for (int i = 2;i<mxN;i++) {
        subFact[i] = mul(add(subFact[i-1],subFact[i-2]),i-1);
    }
}
#endif
