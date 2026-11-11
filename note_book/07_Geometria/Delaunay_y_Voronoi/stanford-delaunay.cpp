// Tema: 07_Geometria/Delaunay_y_Voronoi
// Base: Template/simple.cpp (int = long long).
// Adaptación: Formatos de scanf/printf ajustados al tipo real diagnosticado por GCC bajo int = long long.
// Adaptación: Includes adicionales protegidos de las macros de la plantilla.
// Requisito: E/S C: revisar formatos contra los tipos de 64 bits; ver diagnóstico -Wformat. No activar fast si se mezcla con cin/cout.
// Requisito: Contiene main de ejemplo/prueba: usar su main o el de simple.cpp, nunca ambos.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_131214E6E86DDE35
#define NOTEBOOK_GENERADO_131214E6E86DDE35
#include "../../_base/template-simple.hpp"
#pragma push_macro("int")
#undef int
#pragma push_macro("fast")
#undef fast
#pragma push_macro("pb")
#undef pb
#pragma push_macro("F")
#undef F
#pragma push_macro("S")
#undef S
#pragma push_macro("all")
#undef all
#pragma push_macro("sortt")
#undef sortt
#pragma push_macro("sortn")
#undef sortn
#pragma push_macro("pi")
#undef pi
#pragma push_macro("vi")
#undef vi
#pragma push_macro("vb")
#undef vb
#pragma push_macro("vpi")
#undef vpi
#pragma push_macro("vs")
#undef vs
#pragma push_macro("endl")
#undef endl
#include <vector>
#pragma pop_macro("endl")
#pragma pop_macro("vs")
#pragma pop_macro("vpi")
#pragma pop_macro("vb")
#pragma pop_macro("vi")
#pragma pop_macro("pi")
#pragma pop_macro("sortn")
#pragma pop_macro("sortt")
#pragma pop_macro("all")
#pragma pop_macro("S")
#pragma pop_macro("F")
#pragma pop_macro("pb")
#pragma pop_macro("fast")
#pragma pop_macro("int")

// Slow but simple Delaunay triangulation. Does not handle
// degenerate cases (from O'Rourke, Computational Geometry in C)
//
// Running time: O(n^4)
//
// INPUT:    x[] = x-coordinates
//           y[] = y-coordinates
//
// OUTPUT:   triples = a vector containing m triples of indices
//                     corresponding to triangle vertices


using namespace std;

typedef double T;

struct triple {
    int i, j, k;
    triple() {}
    triple(int i, int j, int k) : i(i), j(j), k(k) {}
};

vector<triple> delaunayTriangulation(vector<T>& x, vector<T>& y) {
	int n = x.size();
	vector<T> z(n);
	vector<triple> ret;

	for (int i = 0; i < n; i++)
	    z[i] = x[i] * x[i] + y[i] * y[i];

	for (int i = 0; i < n-2; i++) {
	    for (int j = i+1; j < n; j++) {
		for (int k = i+1; k < n; k++) {
		    if (j == k) continue;
		    double xn = (y[j]-y[i])*(z[k]-z[i]) - (y[k]-y[i])*(z[j]-z[i]);
		    double yn = (x[k]-x[i])*(z[j]-z[i]) - (x[j]-x[i])*(z[k]-z[i]);
		    double zn = (x[j]-x[i])*(y[k]-y[i]) - (x[k]-x[i])*(y[j]-y[i]);
		    bool flag = zn < 0;
		    for (int m = 0; flag && m < n; m++)
			flag = flag && ((x[m]-x[i])*xn + 
					(y[m]-y[i])*yn + 
					(z[m]-z[i])*zn <= 0);
		    if (flag) ret.push_back(triple(i, j, k));
		}
	    }
	}
	return ret;
}

signed main()
{
    T xs[]={0, 0, 1, 0.9};
    T ys[]={0, 1, 0, 0.9};
    vector<T> x(&xs[0], &xs[4]), y(&ys[0], &ys[4]);
    vector<triple> tri = delaunayTriangulation(x, y);
    
    //expected: 0 1 3
    //          0 3 2
    
    int i;
    for(i = 0; i < tri.size(); i++)
        printf("%lld %lld %lld\n", tri[i].i, tri[i].j, tri[i].k);
    return 0;
}
#endif
