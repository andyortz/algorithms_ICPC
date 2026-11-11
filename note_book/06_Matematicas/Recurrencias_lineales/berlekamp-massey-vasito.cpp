// Tema: 06_Matematicas/Recurrencias_lineales
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Adaptación: Alias de tipos ausentes declarados localmente: ll, ld.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_7BD645314E70B6D1
#define NOTEBOOK_GENERADO_7BD645314E70B6D1
#include "../../_base/template-simple.hpp"
using ll = long long;
using ld = long double;
vi BM(vi x){
	vi ls,cur;int lf,ld;
  for (int i=(0), nb_fin_1=(static_cast<long long>((x).size())); i<nb_fin_1; ++i){
		ll t=0;
    for (int j=(0), nb_fin_3=(static_cast<long long>((cur).size())); j<nb_fin_3; ++j)t=(t+x[i-j-1]*(ll)cur[j])%MOD;
		if((t-x[i])%MOD==0)continue;
    if(!static_cast<long long>((cur).size())){cur.resize(i+1);lf=i;ld=(t-x[i])%MOD;continue;}
		ll k=-(x[i]-t)*fast_pow(ld,MOD-2)%MOD;
		vi c(i-lf-1);c.pb(k);
    for (int j=(0), nb_fin_6=(static_cast<long long>((ls).size())); j<nb_fin_6; ++j)c.pb(-ls[j]*k%MOD);
    if(static_cast<long long>((c).size())<static_cast<long long>((cur).size()))c.resize(static_cast<long long>((cur).size()));
    for (int j=(0), nb_fin_11=(static_cast<long long>((cur).size())); j<nb_fin_11; ++j)c[j]=(c[j]+cur[j])%MOD;
    if(i-lf+static_cast<long long>((ls).size())>=static_cast<long long>((cur).size()))ls=cur,lf=i,ld=(t-x[i])%MOD;
		cur=c;
	}
  for (int i=(0), nb_fin_15=(static_cast<long long>((cur).size())); i<nb_fin_15; ++i)cur[i]=(cur[i]%MOD+MOD)%MOD;
	return cur;
}
#endif
