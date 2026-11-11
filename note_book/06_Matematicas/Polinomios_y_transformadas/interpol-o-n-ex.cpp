// Tema: 06_Matematicas/Polinomios_y_transformadas
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vll.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_F74DEF756001D11C
#define NOTEBOOK_GENERADO_F74DEF756001D11C
#include "../../_base/template-simple.hpp"
using ll = long long;
using vll = vector<long long>;
// evaluar un "polinomio interpolado" en o(nlogMOD) 
// debe cumplir xi+1 - xi = xj+1 - xj for all i, j < n
// recibe vector de ys tal que f(i) = y[i]
vi fac(tam), sig(tam), facin(tam);
ll eval(vll &ys, ll x) {
	int n = ys.size();
	if(x < n) return ys[x];
	ll upi, dowi, res = 0;
    vi pre(n), suf(n);
    pre[1] = 1, suf[n - 1] = 1;
    for (int i=(1), nb_fin_1=(n); i<nb_fin_1; ++i)
    {
		if(i > 1)
        pre[i] = pre[i - 1] * (x - i + 1) % MOD;
        suf[n - i - 1] = suf[n - i] * (x - n + i) % MOD;
    }
	for (int i=(1), nb_fin_3=(n); i<nb_fin_3; ++i) {
        upi = pre[i] * suf[i] % MOD;
        dowi = facin[n - i - 1] * facin[i - 1] % MOD * sig[n - i - 1] % MOD;
		res = (res + ys[i] * upi % MOD * dowi % MOD) % MOD;
	}
	return res;
}
#endif
