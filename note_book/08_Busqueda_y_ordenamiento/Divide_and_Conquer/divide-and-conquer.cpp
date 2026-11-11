// Tema: 08_Busqueda_y_ordenamiento/Divide_and_Conquer
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_1C98F4A0A9476FD4
#define NOTEBOOK_GENERADO_1C98F4A0A9476FD4
#include "../../_base/template-simple.hpp"
using ll = long long;
vi dp(N+1, 0);
int bin(vi &v, int x) {
	int i = 0, j = v.size(), r = j;
	while (i<=j) {
		int mid = (i+j)>>1; 
		if (v[mid]>=x)
			r = mid, j = mid-1;
		else i = mid+1; 
	}
	return r; 
}
void dc(vcor &v, int i, int j) {
	if(j==i) 
		return;
	int mid = (i+j)>>1;
	dc(v, i, mid);
	dc(v, mid+1, j);
	vi aux;
	for (int k=(i), nb_fin_1=(mid+1); k<nb_fin_1; ++k)
		aux.pb(v[k].y);
	sort(aint(aux));
	for (int k=(mid+1), nb_fin_3=(j+1); k<nb_fin_3; ++k) {
		dp[k] = bin(aux, v[k].y);
	}
}
// use this option when the cut is not dividing the whole set:
// optimization from n ** 2 -> n * log n  
void dc(vector<int> &v, int i, int j) {
	if (i > j) return;
	if (i == j) return; 
	int ll = i, rr = j;
	while ( i <= j) {
		if (check(i,ll,rr)) {
			return dc(v,ll,i); // break instead of returning
		}
		if (check (j,ll,rr)) {
			return dc(v,j,rr);
		}
		i++, j--;
	}
	// check how can u combine everything
	return;
}
#endif
