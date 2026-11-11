// Tema: 06_Matematicas/Aritmetica_modular/Operaciones
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_613E84894AA70C6B
#define NOTEBOOK_GENERADO_613E84894AA70C6B
#include "../../../_base/template-simple.hpp"
using ll = long long;
// Calc a^b^c % MOD
// MOD is prime

ll pou(ll a, ll b, ll m) {
    ll ans = 1;
    while (b) {
        if (b&1) ans *= a, ans%=m;
        a*=a;
        a%=m;
        b/=2;
    }
    return ans;
}
 
void test_case() {
    ll a, b, c;
    cin >> a >> b >> c;
    // fermat theorem
    // a^(p-1) = 1 (mod p)
    b = pou(b, c, MOD - 1);
    a = pou(a, b, MOD);
 
    cout << a << "\n";
}
#endif
