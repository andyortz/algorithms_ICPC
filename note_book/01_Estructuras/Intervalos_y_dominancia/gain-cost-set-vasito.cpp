// Tema: 01_Estructuras/Intervalos_y_dominancia
// Base: Template/simple.cpp (int = long long).
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_4C514CE35AE41E5B
#define NOTEBOOK_GENERADO_4C514CE35AE41E5B
#include "../../_base/template-simple.hpp"

// stores pairs (benefit,cost) (erases non-optimal pairs)
struct GCS {
	set<pair<int,int> > s;
	void add(int g, int c){
		pair<int,int> x={g,c};
		auto p=s.lower_bound(x);
		if(p!=s.end()&&p->second<=x.second)return;
		if(p!=s.begin()){ // erase pairs with less benefit
			--p;            // and more cost
			while(p->second>=x.second){
				if(p==s.begin()){s.erase(p);break;}
				s.erase(p--);
			}
		}
		s.insert(x);
	}
	int get(int gain){ // min cost for some benefit
		auto p=s.lower_bound((pair<int,int>){gain,-INF});
		int r=p==s.end()?INF:p->second;
		return r;
	}
};
#endif
