// Tema: 06_Matematicas/Teoria_de_numeros/Funciones_multiplicativas
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_60B08D4C2A4234D9
#define NOTEBOOK_GENERADO_60B08D4C2A4234D9
#include "../../../_base/template-simple.hpp"
using ll = long long;
using vl = vector<long long>;
/* For getting the primes less than mxN in O(mxN)*/
const int mxN = 1e6 + 10;
vl sv(mxN); // if prime sv[i]==i, it stores the lowest prime of 'i'
vl primes;
void init() { // O(n)
    for (int i = 2;i<mxN;i++) {
        if (sv[i]==0) {
            sv[i]=i;
            primes.pb(i);
        }
        for (int j = 0;j<primes.size() && primes[j]*i<mxN;j++) {
            sv[primes[j]*i] = primes[j];
            if (primes[j] == sv[i]) break;
        }
    }
}

// factorization using linear sieve, O(prime_count(n))
// Very fast factorization but only for (n < mxN) !!!
void fact(map<ll,int> &f, ll num) {
    while (num>1) {
        ll p = sv[num];
        while (num % p == 0) num/=p, f[p]++;
    }
}
#endif
