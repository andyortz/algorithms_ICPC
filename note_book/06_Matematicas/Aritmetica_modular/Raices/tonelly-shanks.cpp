// Tema: 06_Matematicas/Aritmetica_modular/Raices
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: Operaciones de bits/ensamblador: revisar ancho de palabra (32/64 bits) y el caso cero; preservar tipos explícitos cuando el algoritmo lo exige.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_786BC778B1340983
#define NOTEBOOK_GENERADO_786BC778B1340983
#include "../../../_base/template-simple.hpp"
using ll = long long;
ll legendre(ll a, ll p){
  if(a%p==0)return 0; if(p==2)return 1;
  return fpow(a,(p-1)/2,p);
}
ll tonelli_shanks(ll n, ll p){	// sqrt(n) mod p (p must be a prime)
  assert(legendre(n,p)==1); if(p==2)return 1;
  ll s=__builtin_ctzll(p-1), q=(p-1LL)>>s, z=rnd(1,p-1);
  if(s==1)return fpow(n,(p+1)/4LL,p);
  while(legendre(z,p)!=p-1)z=rnd(1,p-1);
  ll c=fpow(z,q,p), r=fpow(n,(q+1)/2,p), t=fpow(n,q,p), m=s;
  while(t!=1){
    ll i=1, ts=(t*t)%p;
    while(ts!=1)i++,ts=(ts*ts)%p;
    ll b=c; 
    for (int _=(0), nb_fin_1=(m-i-1); _<nb_fin_1; ++_)b=(b*b)%p;
    r=r*b%p;c=b*b%p;t=t*c%p;m=i;
  }
  return r;
}
#endif
