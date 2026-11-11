// Tema: 06_Matematicas/Teoria_de_numeros/Primos_y_factorizacion
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_AFC33AB70DB0297C
#define NOTEBOOK_GENERADO_AFC33AB70DB0297C
#include "../../../_base/template-simple.hpp"
using ll = long long;
// Guarda en primes los numeros primos menores o iguales a MX. Para saber si p es un número primo, hacer: if (!marked[p]).

const int MX = 1e6;
bool marked[MX+1];
vector<int> primes;
// O(MX log(log(MX)))
void sieve() {
    marked[0] = marked[1] = true;
    for (int i = 2; i <= MX; i++) {
        if (marked[i]) continue;
        primes.pb(i);
        for (ll j = 1ll*i*i; j <= MX; j += i) marked[j] = true;
    }
}
#endif
