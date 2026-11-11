// Tema: 09_Utilidades/Interactivos
// Base: Template/simple.cpp (int = long long).
// Requisito: Contiene main de ejemplo/prueba: usar su main o el de simple.cpp, nunca ambos.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_A1850CAA925FDCEA
#define NOTEBOOK_GENERADO_A1850CAA925FDCEA
#include "../../_base/template-simple.hpp"

using namespace std;
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);	
	vector<int> mapa(static_cast<long long>(1e6), 0);
	int res= 1, n;
	cin>>n; 
	for (int s = 0; s<n; s++) {
		int x; cin>>x;
		for (int i = 1; i*i<=x; i++) 
		if (!(x%i)) {
			mapa[i]++;
			if (mapa[i]>1) res = max(res, i);
			if (i*i!=x) {
				mapa[x/i]++;
				if (mapa[x/i]>1) 
					res = max(res, x/i);
			}
		}
	}
	cout<<res<<'\n';
	return 0;
}
#endif
