// Tema: 06_Matematicas/Algebra_lineal/Base_XOR
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_B74AF12226D6F105
#define NOTEBOOK_GENERADO_B74AF12226D6F105
#include "../../../_base/template-simple.hpp"
using ll = long long;
#define i23 long long

vector<i23> basis;

void add(i23 x) {
  for (int i = 0; i < (int)basis.size(); i++) {  
    // reduce x using the current basis vectors
    x = min(x, x ^ basis[i]);
  }
  if (x != 0) { basis.push_back(x); }
}

// Other implement
// To count number of xor subsets
void test_case() {
    ll n;cin >> n;
    vector<ll> basis(32,0);
    ll cnt = 0;
    auto add = [&](ll x) {
        for (ll i = 31;i>=0;i--) {
            if ((x>>i)&1) {
                if (basis[i]==0) {
                    basis[i]=x;
                    cnt++;
                    return;
                } 
                x ^= basis[i];
            }
        }
    };
 
    for (int i =0;i<n;i++) {
        ll x;
        cin >> x;
        add(x);
    }
 
    ll ans = 1ll << (cnt);
    cout << ans << "\n";
}
#endif
