// Tema: 07_Geometria/Tres_dimensiones
// Base: Template/simple.cpp (int = long long).
// Requisito: Necesita una versión 3D de pt con z y producto cruzado; point.cpp del origen es 2D por defecto.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_FEDCE77DA8F2C818
#define NOTEBOOK_GENERADO_FEDCE77DA8F2C818
#include "../../_base/template-simple.hpp"

struct plane {
	pt a,n; // n: normal unit vector
	plane(pt a, pt b, pt c):a(a),n(((b-a)^(c-a)).unit()){}
	plane(){}
	bool has(pt p){return abs((p-a)*n)<=EPS;}
	double angle(plane w){return acos(n*w.n);}
	double dist(pt p){return abs((p-a)*n);}
	pt proj(pt p){inter(ln(p,p+n),p);return p;}
	bool inter(ln l, pt& r){
		double x=n*(l.p+l.pq-a),y=n*(l.p-a);
		if(abs(x-y)<=EPS)return false;
		r=(l.p*x-(l.p+l.pq)*y)/(x-y);
		return true;
	}
	bool inter(plane w, ln& r){
		pt nn=n^w.n;pt v=n^nn;double d=w.n*v;
		if(abs(d)<=EPS)return false;
		pt p=a+v*(w.n*(w.a-a)/d);
		r=ln(p,p+nn);
		return true;
	}
};
#endif
