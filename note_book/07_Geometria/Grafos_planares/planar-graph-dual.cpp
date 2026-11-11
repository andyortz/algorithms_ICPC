// Tema: 07_Geometria/Grafos_planares
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Adaptación: Alias de tipos ausentes declarados localmente: ii.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_F6E42167B208A1F7
#define NOTEBOOK_GENERADO_F6E42167B208A1F7
#include "../../_base/template-simple.hpp"
using ii = pair<int, int>;
vi g[tam];int n; // input graph (must be connected)
vi gd[tam];int nd; // output graph
vi nodes[tam]; // nodes delimiting region (in CW order)
map<ii,int> ps,es;
void get_dual(vector<pt> &p, vi &nods){ // p: points corresponding to nodes
	ps.clear();es.clear();
	for(int x : nods){
        pt p1, p2;
        auto cmp = [&](int a, int b){
            p1 = p[a] - p[x], p2 = p[b] - p[x];
            a = p1.x > 0 && p1.y == 0 || p1.y > 0, b = p2.x > 0 && p2.y == 0 || p2.y > 0;
            if(a == b)
                return p1 % p2 > 0;
            return a < b;
        };
		sort(all(g[x]), cmp);
		for (int i=(0), nb_fin_1=(g[x].size()); i<nb_fin_1; ++i)ps[{x,g[x][i]}]=i;
	}
	nd=0;
	for(int xx : nods)for(auto yy:g[xx])if(!es.count({xx,yy})){
		int x=xx,y=yy;gd[nd].clear();nodes[nd].clear();
		while(!es.count({x,y})){
			es[{x,y}]=nd;nodes[nd].pb(y);
			int z=g[y][(ps[{y,x}]+1)%g[y].size()];x=y;y=z;
		}
		nd++;
	}
	for(auto p:es){
		pair<int,int> q={p.f.s,p.f.f};
		assert(es.count(q));
		if(es[q]!=p.s)gd[p.s].pb(es[q]);
	}
	for (int i=(0), nb_fin_3=(nd); i<nb_fin_3; ++i){
		sort(all(gd[i]));
		gd[i].erase(unique(all(gd[i])),gd[i].end());
	}
}
#endif
