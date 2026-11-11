// Tema: 02_Grafos/Dominadores
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_06481FCF5BBE3EB0
#define NOTEBOOK_GENERADO_06481FCF5BBE3EB0
#include "../../_base/template-simple.hpp"

//idom[i]=parent of i in dominator tree with root=rt, or -1 if not exists
int n,rnk[tam],pre[tam],anc[tam],idom[tam],semi[tam],low[tam];
vi g[tam],rev[tam],dom[tam],ord;
void dfspre(int pos){
	rnk[pos]=sz(ord); ord.pb(pos);
	for(auto x:g[pos]){
		rev[x].pb(pos);
		if(rnk[x]==n) pre[x]=pos,dfspre(x);
	}
}
int eval(int v){
	if(anc[v]<n&&anc[anc[v]]<n){
		int x=eval(anc[v]);
		if(rnk[semi[low[v]]]>rnk[semi[x]]) low[v]=x;
		anc[v]=anc[anc[v]];
	}
	return low[v];
}
void dominators(int rt){
	for (int i=(0), nb_fin_1=(n); i<nb_fin_1; ++i){
		dom[i].clear(); rev[i].clear();
		rnk[i]=pre[i]=anc[i]=idom[i]=n;
		semi[i]=low[i]=i;
	}
	ord.clear(); dfspre(rt);
	for(int i=sz(ord)-1;i;i--){
		int w=ord[i];
		for(int v:rev[w]){
			int u=eval(v);
			if(rnk[semi[w]]>rnk[semi[u]])semi[w]=semi[u];
		}
		dom[semi[w]].pb(w); anc[w]=pre[w];
		for(int v:dom[pre[w]]){
			int u=eval(v);
			idom[v]=(rnk[pre[w]]>rnk[semi[u]]?u:pre[w]);
		}
		dom[pre[w]].clear();
	}
	for(int w:ord) if(w!=rt&&idom[w]!=semi[w]) idom[w]=idom[idom[w]];
	for (int i=(0), nb_fin_3=(n); i<nb_fin_3; ++i) if(idom[i]==n)idom[i]=-1; else dom[idom[i]].pb(i);
}
#endif
