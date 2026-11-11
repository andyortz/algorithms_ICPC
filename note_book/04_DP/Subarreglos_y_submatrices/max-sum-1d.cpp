// Tema: 04_DP/Subarreglos_y_submatrices
// Base: Template/simple.cpp (int = long long).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_3166E6AF90257357
#define NOTEBOOK_GENERADO_3166E6AF90257357
#include "../../_base/template-simple.hpp"

int maxRangeSum(vector<int> a){
	int sum = 0, ans = 0;
	for (int i = 0; i < a.size(); i++){
		if (sum + a[i] >= 0) {  
			sum += a[i];
		  ans = max(ans, sum);          
	  } else sum = 0;
	}
	return ans;
}
#endif
