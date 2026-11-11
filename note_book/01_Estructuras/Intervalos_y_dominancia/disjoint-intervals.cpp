// Tema: 01_Estructuras/Intervalos_y_dominancia
// Base: Template/simple.cpp (int = long long).
// Adaptación: Accesos abreviados a pair reemplazados por first/second, sin macros auxiliares.
// Adaptación: Corregido nombre del conjunto: s.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_55F9C353E1C915E7
#define NOTEBOOK_GENERADO_55F9C353E1C915E7
#include "../../_base/template-simple.hpp"

// stores disjoint intervals as [first, second)
struct disjoint_intervals {
	set<pair<int,int> > s;
	void insert(pair<int,int> v){
		if(v.first>=v.second) return;
		auto at=s.lower_bound(v);auto it=at;
		if(at!=s.begin()&&(--at)->second>=v.first)v.first=at->first,--it;
		for(;it!=s.end()&&it->first<=v.second;s.erase(it++))
			v.second=max(v.second,it->second);
		s.insert(v);
	}
};
#endif
