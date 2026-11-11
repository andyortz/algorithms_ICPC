// Tema: 06_Matematicas/Polinomios_y_transformadas
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Adaptación: Nombres que chocan con macros renombrados con prefijo nb_: S.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_662AF11D3967C4D0
#define NOTEBOOK_GENERADO_662AF11D3967C4D0
#include "../../_base/template-simple.hpp"

typedef int tp; // type of polynomial
template<class T=tp>
struct poly {  // poly<> : 1 variable, poly<poly<>>: 2 variables, etc.
	vector<T> c;
	T& operator[](int k){return c[k];}
	poly(vector<T>& c):c(c){}
	poly(initializer_list<T> c):c(c){}
	poly(int k):c(k){}
	poly(){}
	poly operator+(poly<T> o){
		int m=c.size(),n=o.c.size();
		poly res(max(m,n));
		for (int i=(0), nb_fin_1=(m); i<nb_fin_1; ++i)res[i]=res[i]+c[i];
		for (int i=(0), nb_fin_3=(n); i<nb_fin_3; ++i)res[i]=res[i]+o.c[i];
		return res;
	}
	poly operator*(tp k){
		poly res(c.size());
		for (int i=(0), nb_fin_5=(c.size()); i<nb_fin_5; ++i)res[i]=c[i]*k;
		return res;
	}
	poly operator*(poly o){
		int m=c.size(),n=o.c.size();
		poly res(m+n-1);
		for (int i=(0), nb_fin_7=(m); i<nb_fin_7; ++i)for (int j=(0), nb_fin_9=(n); j<nb_fin_9; ++j)res[i+j]=res[i+j]+c[i]*o.c[j];
		return res;
	}
	poly operator-(poly<T> o){return *this+(o*-1);}
	T operator()(tp v){
		T sum(0);
		for(int i=c.size()-1;i>=0;--i)sum=sum*v+c[i];
		return sum;
	}
};
// example: p(x,y)=2*x^2+3*x*y-y+4
// poly<poly<>> p={{4,-1},{0,3},{2}}
// printf("%d\n",p(2)(3)) // 27 (p(2,3))
set<tp> roots(poly<> p){ // only for integer polynomials
	set<tp> r;
	while(!p.c.empty()&&!p.c.back())p.c.pop_back();
	if(!p(0))r.insert(0);
	if(p.c.empty())return r;
	tp a0=0,an=abs(p[p.c.size()-1]);
	for(int k=0;!a0;a0=abs(p[k++]));
	vector<tp> ps,qs;
	for (int i=(1), nb_fin_11=(sqrt(a0)+1); i<nb_fin_11; ++i)if(a0%i==0)ps.pb(i),ps.pb(a0/i);
	for (int i=(1), nb_fin_13=(sqrt(an)+1); i<nb_fin_13; ++i)if(an%i==0)qs.pb(i),qs.pb(an/i);
	for(auto pt:ps)for(auto qt:qs)if(pt%qt==0){
		tp x=pt/qt;
		if(!p(x))r.insert(x);
		if(!p(-x))r.insert(-x);
	}
	return r;
}
pair<poly<>,tp> ruffini(poly<> p, tp r){ // returns pair (result,rem)
	int n=p.c.size()-1;
	vector<tp> b(n);
	b[n-1]=p[n];
	for(int k=n-2;k>=0;--k)b[k]=p[k+1]+r*b[k+1];
	return {poly<>(b),p[0]+r*b[0]};
}
// only for double polynomials
pair<poly<>,poly<> > polydiv(poly<> p, poly<> q){ // returns pair (result,rem)
	int n=p.c.size()-q.c.size()+1;
	vector<tp> b(n);
	for(int k=n-1;k>=0;--k){
		b[k]=p.c.back()/q.c.back();
		for (int i=(0), nb_fin_15=(q.c.size()); i<nb_fin_15; ++i)p[i+k]-=b[k]*q[i];
		p.c.pop_back();
	}
	while(!p.c.empty()&&abs(p.c.back())<EPS)p.c.pop_back();
	return {poly<>(b),p};
}
// only for double polynomials
poly<> interpolate(vector<tp> x, vector<tp> y){ //TODO TEST
	poly<> q={1},nb_S={0};
	for(tp a:x)q=poly<>({-a,1})*q;
	for (int i=(0), nb_fin_17=(x.size()); i<nb_fin_17; ++i){
		poly<> Li=ruffini(q,x[i]).first;
		Li=Li*(1.0/Li(x[i])); // change for int polynomials
		nb_S=nb_S+Li*y[i];
	}
	return nb_S;
}
#endif
