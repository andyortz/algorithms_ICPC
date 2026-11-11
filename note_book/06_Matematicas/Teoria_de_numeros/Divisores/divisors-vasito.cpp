// Tema: 06_Matematicas/Teoria_de_numeros/Divisores
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_F6E8F3CA247A215E
#define NOTEBOOK_GENERADO_F6E8F3CA247A215E
#include "../../../_base/template-simple.hpp"
using ll = long long;
void div_rec(vector<ll>& r, vector<pair<ll,int> >& f, int k, ll c){
	if(k==f.size()){r.pb(c);return;}
	for (int i=(0), nb_fin_1=(f[k].second+1); i<nb_fin_1; ++i)div_rec(r,f,k+1,c),c*=f[k].first;
}
vector<ll> divisors(vector<pair<ll,int> > f){
	vector<ll> r; // returns divisors given factorization
	div_rec(r,f,0,1);
	return r;
}
#endif
