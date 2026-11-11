// Tema: 01_Estructuras/Heaps
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Max-heap en un vector: v.pb(x); insert(v) | del(v, i) borra la posición i | find(v, x, 0) índice de x o -1.
// Corregido: find comprobaba i>n (leía v[n]); del dejaba el último elemento sin subir (rompía
// el heap) y usaba -1 como centinela (fallaba con valores negativos).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_6C110EED854799A1
#define NOTEBOOK_GENERADO_6C110EED854799A1
#include "../../_base/template-simple.hpp"

int find(vi &v, int x, int i) {
	int n = v.size();
	//cout<<i<<endl;
	if (i>=n || v[i]<x) return -1;
	if (v[i]==x) return i;
	int a = i*2+1, b = i*2+2;
	return max(find(v,x,a),find(v,x,b));
}
void insert(vi &v) {
	int i = v.size()-1; 
	while (i>0) {
		int p = i; 
		if (!(p&1)) p--;
		p>>=1;
	       	if (v[p]>v[i]) break;
		swap(v[p], v[i]); 
		i = p;
	}
} 
void del(vi &v, int i) {
	v[i] = LLONG_MIN; // centinela menor que cualquier valor
	int a = i*2+1,b=i*2+2, n=v.size();
	int max = -1;
	if(a<n) max = a;
	if(b<n) 
	       if(v[max]<v[b])
		max = b;
	if(max!=-1)
		swap(v[i], v[max]), del(v,max);
	else {
		swap(v[i],v[n-1]);
		v.pop_back();
		// el elemento que llegó desde el final puede ser mayor que su nuevo padre: subirlo
		for (; i > 0 && i < (int)v.size() && v[(i-1)/2] < v[i]; i = (i-1)/2) swap(v[(i-1)/2], v[i]);
	}
}
void solve() {
	int n;
	vi v; cin>>n;
	for (int i=(0), nb_fin_1=(n); i<nb_fin_1; ++i) {
		int x; cin>>x;
		v.pb(x);
		insert(v);
	}
	del(v,3);
	n = v.size();
	for (int i=(0), nb_fin_3=(n); i<nb_fin_3; ++i)
		cout<<v[i]<<" \n"[i==n-1];
	cout<<find(v,2,0)<<endl;
}
#endif
