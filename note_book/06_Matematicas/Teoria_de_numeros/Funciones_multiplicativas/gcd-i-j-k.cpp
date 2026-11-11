// Tema: 06_Matematicas/Teoria_de_numeros/Funciones_multiplicativas
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_C4BE4CE2DCC03AB2
#define NOTEBOOK_GENERADO_C4BE4CE2DCC03AB2
#include "../../../_base/template-simple.hpp"
using ll = long long;
// Counts pairs gcd(i,j) == k
// 1 <= i <= a, 1 <= j <= b, where (1,2) equals to (2,1)
// Call Mobius First !!!
// O(min(a,b)/K)
// Tested: https://vjudge.net/problem/HDU-1695
ll solve(ll a, ll b, ll k) {
    if (k==0) return 0;
    a/=k;
    b/=k;
    if (a > b) swap(a,b);
    if (a == 0) return 0;
    ll ans = 0;
    for (ll d = 1; d <= a; d++) {
        ans += (a/d) * (b/d) * mo[d];
    }
    ll sub = 0; // Substracting equals, e.g. (1,2) to (2,1)
    for (ll d = 1;d <= a; d++) {
        sub += (a/d)*(a/d) * mo[d];
    }
    ans-=(sub-1)/2;
    return ans;
}
#endif
