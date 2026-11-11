// Tema: 08_Strings/KMP
// Base: Template/simple.cpp (int = long long).
// Adaptación: Formatos de scanf/printf ajustados al tipo real diagnosticado por GCC bajo int = long long.
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Requisito: E/S C: revisar formatos contra los tipos de 64 bits; ver diagnóstico -Wformat. No activar fast si se mezcla con cin/cout.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_35D3F1090D7D7BC6
#define NOTEBOOK_GENERADO_35D3F1090D7D7BC6
#include "../../_base/template-simple.hpp"

vector<int> kmppre(string& t){ // r[i]: longest border of t[0,i)
	vector<int> r(t.size()+1);r[0]=-1;
	int j=-1;
	for (int i=(0), nb_fin_1=(t.size()); i<nb_fin_1; ++i){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}
void kmp(string& s, string& t){ // find t in s
	int j=0;vector<int> b=kmppre(t);
	for (int i=(0), nb_fin_3=(s.size()); i<nb_fin_3; ++i){
		while(j>=0&&s[i]!=t[j])j=b[j];
		if(++j==t.size())printf("Match at %lld\n",i-j+1),j=b[j];
	}
}
#endif
