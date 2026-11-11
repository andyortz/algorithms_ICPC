// Selección: Una sola recurrencia de Josephus, posiciones desde 1; O(n) y pila O(n).
// Tema: 06_Matematicas/Josephus
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_F55D7FE5584AFCF4
#define NOTEBOOK_GENERADO_F55D7FE5584AFCF4
#include "../../_base/template-simple.hpp"
using ll = long long;
// UFMG
/* Josephus Problem - It returns the position to be, in order to not die. O(n)*/
/* With k=2, for instance, the game begins with 2 being killed and then n+2, n+4, ... */
ll josephus(ll n, ll k) {
  if(n==1) return 1;
  else return (josephus(n-1, k)+k-1)%n+1;
}

#endif
