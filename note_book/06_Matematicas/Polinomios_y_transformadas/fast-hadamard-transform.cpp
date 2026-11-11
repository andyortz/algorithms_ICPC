// Tema: 06_Matematicas/Polinomios_y_transformadas
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl.
// Requisito: Operaciones de bits/ensamblador: revisar ancho de palabra (32/64 bits) y el caso cero; preservar tipos explícitos cuando el algoritmo lo exige.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_094A05337C5CC289
#define NOTEBOOK_GENERADO_094A05337C5CC289
#include "../../_base/template-simple.hpp"
using ll = long long;
using vl = vector<long long>;
// like polynomial multiplication, but XORing exponents
// instead of adding them (also ANDing, ORing)
const int MAXN=1<<18;




ll c1[MAXN+9],c2[MAXN+9];//MAXN must be power of 2!
void fht(ll* p, int n, bool inv){
    for(int l=1;2*l<=n;l*=2)for(int i=0;i<n;i+=2*l)for(int j=static_cast<long long>(0);j<static_cast<long long>(l);++j){
        ll u=p[i+j],v=p[i+l+j];
        // if(!inv)p[i+j]=u+v,p[i+l+j]=u-v; // XOR
        // else p[i+j]=(u+v)/2,p[i+l+j]=(u-v)/2;
        //if(!inv)p[i+j]=v,p[i+l+j]=u+v; // AND
        //else p[i+j]=-u+v,p[i+l+j]=u;
        if(!inv)p[i+j]=u+v,p[i+l+j]=u; // OR
        else p[i+j]=v,p[i+l+j]=u-v;
    }
}
// like polynomial multiplication, but XORing exponents
// instead of adding them (also ANDing, ORing)
vector<ll> multiply(vector<ll>& p1, vector<ll>& p2){
    int n=1<<(32-__builtin_clz(max(((int)(p1).size()),((int)(p2).size()))-1));
    for(int i=static_cast<long long>(0);i<static_cast<long long>(n);++i)c1[i]=0,c2[i]=0;
    for(int i=static_cast<long long>(0);i<static_cast<long long>(((int)(p1).size()));++i)c1[i]=p1[i];
    for(int i=static_cast<long long>(0);i<static_cast<long long>(((int)(p2).size()));++i)c2[i]=p2[i];
    fht(c1,n,false);fht(c2,n,false);
    for(int i=static_cast<long long>(0);i<static_cast<long long>(n);++i)c1[i]*=c2[i];
    fht(c1,n,true);
    return vector<ll>(c1,c1+n);
}

// maxime the OR of a pair of given nums and count 
// how many pairs can get that maximum OR
// tested: https://csacademy.com/contest/archive/task/maxor
void test_case() {
    ll n; cin >> n;
    vl a(MAXN),b(MAXN);
    for (int i =0;i<n;i++) {
        ll x;
        cin >> x;
        a[x]++;
        b[x]++;
    }
    vl c = multiply(a,b);
    pair<ll,ll> best = {0, c[0]};
    for (int i = 0;i<MAXN;i++) {
        if (c[i]) best = {i,(c[i]-a[i])/2};
    }
    cout <<best.first << " " << best.second << endl;
}
#endif
