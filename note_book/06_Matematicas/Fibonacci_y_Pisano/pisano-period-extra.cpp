// Tema: 06_Matematicas/Fibonacci_y_Pisano
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (2 líneas).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_16BBE407BD6C92DE
#define NOTEBOOK_GENERADO_16BBE407BD6C92DE
#include "../../_base/template-simple.hpp"
using ll = long long;
// Calcula el Periodo de Pisano de m, que es el periodo con el cual se repite la Sucesion de Fibonacci modulo m.
// Si m es primo el algoritmo funciona (considerable) para m < 10^6. Aregar Modular Exponentiation (sin el modulo) y Lowest Common Multiple (para ll).

ll period(ll m) {
    ll a = 0, b = 1, c, pp = 0;
    do {
        c = (a+b) % m;
        a = b; b = c; pp++;
    } while (a != 0 || b != 1);
    return pp;
}

ll pisanoPrime(ll p, int e) {
    return expmod(p, e-1) * period(p);
}

ll pisanoPeriod(ll m) {
    ll pp = 1;
    for (ll p = 2; p <= m/p; p++) {
        if (m%p == 0) {
            int e = 0;
            while (m%p == 0) e++, m /= p;
            pp = lcm(pp, pisanoPrime(p, e));
        }
    }
    if (m > 1) pp = lcm(pp, period(m));
    return pp;
}
#endif
