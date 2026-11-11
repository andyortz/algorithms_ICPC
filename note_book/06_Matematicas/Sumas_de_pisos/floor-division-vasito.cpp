// Tema: 06_Matematicas/Sumas_de_pisos
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_5E955006BC7AFB51
#define NOTEBOOK_GENERADO_5E955006BC7AFB51
#include "../../_base/template-simple.hpp"
using ll = long long;
void floordiv(ll x, ll y, ll& q, ll& r) { // (for negative x)
	q=x/y;r=x%y;
	if((r!=0)&&((r<0)!=(y<0)))q--,r+=y;
}
#endif
