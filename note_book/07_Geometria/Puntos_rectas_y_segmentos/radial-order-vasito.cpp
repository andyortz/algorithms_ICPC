// Selección: Reutiliza extra/Geometry/Point.cpp como proveedor único.
// Selección: Orden radial compatible con pt de la base geométrica elegida.
// Tema: 07_Geometria/Puntos_rectas_y_segmentos
// Base: Template/simple.cpp (int = long long).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_E2C10BE355320261
#define NOTEBOOK_GENERADO_E2C10BE355320261
#include "../../_base/template-simple.hpp"
#include "point-extra.cpp"

struct Cmp { // Usa el pt de point-extra.cpp
	pt r;
	Cmp(pt r):r(r){}
	int cuad(const pt &a)const {
		if(a.x>0&&a.y>=0)return 0;
		if(a.x<=0&&a.y>0)return 1;
		if(a.x<0&&a.y<=0)return 2;
		if(a.x>=0&&a.y<0)return 3;
		assert(a.x==0&&a.y==0);
		return -1;
	}
	bool cmp(const pt& p1, const pt& p2)const {
		int c1=cuad(p1),c2=cuad(p2);
		if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
		return c1<c2;
	}
	bool operator()(const pt& p1, const pt& p2)const {
		return cmp(p1-r,p2-r);
	}
};
#endif
