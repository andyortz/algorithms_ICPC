// Tema: 06_Matematicas/Metodos_numericos
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_C56870055A7EDDD2
#define NOTEBOOK_GENERADO_C56870055A7EDDD2
#include "../../_base/template-simple.hpp"

double simpson(double f(double), double a, double b) {
	int n = 100000;
	double s = f(a) + f(b);
	double h = (b - a) / n;
	for (int i=(1), nb_fin_1=(n); i<nb_fin_1; ++i)
		s += ((i & 1) ? 4  : 2) * f(a + h * i);
	return s * (h / 3);
}
#endif
