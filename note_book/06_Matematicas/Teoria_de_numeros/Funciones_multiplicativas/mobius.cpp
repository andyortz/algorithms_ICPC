// Selección: Seleccionada la variante lineal de Möbius; retirada la alternativa O(n log n).
// Tema: 06_Matematicas/Teoria_de_numeros/Funciones_multiplicativas
// Base: Template/simple.cpp (int = long long).
// Llamar variante_lineal::init() una vez antes de consultar mo[n].
// Adaptación: Alias de tipos ausentes declarados localmente: vl.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_C12F067702985388
#define NOTEBOOK_GENERADO_C12F067702985388
#include "../../../_base/template-simple.hpp"
using vl = vector<long long>;
/*
Mobius Function.
 Multiplicative function that is useful to inclusion/exclusion with
 prime numbers (it gives the coeficient). Also you can reduce some
 sumatories using its equality with unit(n) function (see the key below)

 unit(n) = [ n == 1 ]
 unit(1) = 1, unit(2) = 0, unit(0) = 0
 
 (This is the key!!)
 unit(n) = sum_{ d divides n } mobius(d) 
 
 mobius(1) = 1 
 mobius(quantity of primes is odd) = -1
 mobius(quantity of primes is even) = 1
 mobius(n is divisible by a square prime) = 0

 Check https://codeforces.com/blog/entry/53925 for more information.
 Check mobius examples
*/ 

namespace variante_lineal {
// This is O(n), but not too much difference of speed with the other
const int mxN = 1e6 + 10;
vl sv(mxN); // prime if sv[i]==i, it stores the lowest prime of i
vl primes; // Primes less than mxN
vl mo(mxN); // Mobius
void init() { 
    // sv[1] = 1; // Check if needed
    for (int i = 2;i<mxN;i++) { // Linear Sieve
        if (sv[i]==0) { sv[i]=i; primes.pb(i); }
        for (int j = 0;j<primes.size() && primes[j]*i<mxN;j++) {
            sv[primes[j]*i] = primes[j];
            if (primes[j] == sv[i]) break;
        }
    }

    mo[1] = 1; // Mobius
    for (int i=2;i<mxN;i++) {
       if (sv[i/sv[i]] == sv[i]) mo[i] = 0;
       else mo[i] = -1*mo[i/sv[i]];
    }
}
} // namespace variante_lineal
#endif
