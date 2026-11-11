// Tema: 07_Geometria/Minkowski
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_AB4B12ED7530CE09
#define NOTEBOOK_GENERADO_AB4B12ED7530CE09
#include "../../_base/template-simple.hpp"
using ll = long long;
typedef vector<point> poly;
void norm(poly &pol) {
	int pos = 0;
	for (int i=(0), nb_fin_1=(pol.size()); i<nb_fin_1; ++i) {
		if(pol[i] < pol[pos])
			pos = i;
	}
	rotate(pol.begin(), pol.begin() + pos, pol.end());
}
poly minkos(poly &a, poly &b) {
	norm(a);
	norm(b);
	int posa = 0, posb = 0, ta = a.size(), tb = b.size();
	poly res;
	ll cro;
	while(posa < ta || posb < tb) {
		res.pb(a[(posa) % ta] + b[(posb) % tb]);
		cro = (a[(posa + 1) % ta] - a[posa % ta]) ^ (b[(posb + 1) % tb] - b[posb % tb]);
		if(cro == 0)
			posa++, posb++;
		else if(cro < 0)
			posb++;
		else posa++;
	}
	return res;
}
#endif
