// Tema: 06_Matematicas/Combinatoria
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_893DD527A5B89C12
#define NOTEBOOK_GENERADO_893DD527A5B89C12
#include "../../_base/template-simple.hpp"
using ll = long long;
using vl = vector<long long>;
/*Catalan, counts the number of ways of:
( A ) B, where |A|+|B| = N, for N+1
*/

const int MOD = 1e9 + 7;
ll mul(ll x, ll y) { return (x*y)%MOD; }
ll pot(ll x, ll y) {
    if(y==0) return 1;
    ll ans = pot(x,y/2);
    ans = mul(ans,ans);
    if (y&1)ans=mul(ans,x);
    return ans;
}
ll inv(ll x) { return pot(x, MOD-2); }

// mxN it the double of the max input 'n'
const int mxN = 2e6 + 10;
vl fact(mxN,1);
void init() {
    for (int i =1;i<=mxN;i++) {
        fact[i] = mul(fact[i-1],i);
    }
}

ll catalan(ll n) {
    if (n<0) return 0;
    ll up = fact[2*n];
    ll down = mul(fact[n],fact[n+1]);
    return mul(up,inv(down));
}
#endif
