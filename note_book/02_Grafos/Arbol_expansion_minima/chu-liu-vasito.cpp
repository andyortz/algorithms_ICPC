// Tema: 02_Grafos/Arbol_expansion_minima
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_F7F635925BF1ADA2
#define NOTEBOOK_GENERADO_F7F635925BF1ADA2
#include "../../_base/template-simple.hpp"

//O(n*m) minimum spanning tree in directed graph
//returns -1 if not possible
//included i-th edge if take[i]!=0
typedef int tw; tw INF=1ll<<30;
struct edge{int u,v,id;tw len;};
struct ChuLiu{
	int n; vector<edge> e;
	vector<int> inc,dec,take,pre,num,id,vis;
	vector<tw> inw;
	void add_edge(int x, int y, tw w){
		inc.pb(0); dec.pb(0); take.pb(0);
		e.pb({x,y,static_cast<long long>((e).size()),w});
	}
	ChuLiu(int n):n(n),pre(n),num(n),id(n),vis(n),inw(n){}
	tw doit(int root){
		auto e2=e;
		tw ans=0; int eg=static_cast<long long>((e).size())-1,pos=static_cast<long long>((e).size())-1;
		while(1){
			for (int i=(0), nb_fin_4=(n); i<nb_fin_4; ++i) inw[i]=INF,id[i]=vis[i]=-1;
			for(auto ed:e2) if(ed.len<inw[ed.v]){
				inw[ed.v]=ed.len; pre[ed.v]=ed.u;
				num[ed.v]=ed.id;
			}
			inw[root]=0;
			for (int i=(0), nb_fin_6=(n); i<nb_fin_6; ++i) if(inw[i]==INF) return -1;
			int tot=-1;
			for (int i=(0), nb_fin_8=(n); i<nb_fin_8; ++i){
				ans+=inw[i];
				if(i!=root)take[num[i]]++;
				int j=i;
				while(vis[j]!=i&&j!=root&&id[j]<0)vis[j]=i,j=pre[j];
				if(j!=root&&id[j]<0){
					id[j]=++tot;
					for(int k=pre[j];k!=j;k=pre[k]) id[k]=tot;
				}
			}
			if(tot<0)break;
			for (int i=(0), nb_fin_10=(n); i<nb_fin_10; ++i) if(id[i]<0)id[i]=++tot;
			n=tot+1; int j=0;
			for (int i=(0), nb_fin_12=(static_cast<long long>((e2).size())); i<nb_fin_12; ++i){
				int v=e2[i].v;
				e2[j].v=id[e2[i].v];
				e2[j].u=id[e2[i].u];
				if(e2[j].v!=e2[j].u){
					e2[j].len=e2[i].len-inw[v];
					inc.pb(e2[i].id);
					dec.pb(num[v]);
					take.pb(0);
					e2[j++].id=++pos;
				}
			}
			e2.resize(j);
			root=id[root];
		}
		while(pos>eg){
			if(take[pos]>0) take[inc[pos]]++, take[dec[pos]]--;
			pos--;
		}
		return ans;
	}
};
#endif
