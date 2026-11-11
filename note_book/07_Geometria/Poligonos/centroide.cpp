// Tema: 07_Geometria/Poligonos
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_B824BE1EF7996823
#define NOTEBOOK_GENERADO_B824BE1EF7996823
#include "../../_base/template-simple.hpp"

// calcula el centro de masa de un poligono antihorario
point cen(vector<point> p) {
	double x = 0, y = 0, area = 0, ax;
	int n = p.size()-1;
	for (int i=(0), nb_fin_1=(n); i<nb_fin_1; ++i) {
		ax = (p[i] ^ p[i+1]) / 2;
		area += ax;
		x += ax * (p[i].x + p[i+1].x) / 3;
		y += ax * (p[i].y + p[i+1].y) / 3;
	}
	return point(x / area, y / area);
}
#endif
