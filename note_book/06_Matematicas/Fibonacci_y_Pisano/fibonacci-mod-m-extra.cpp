// Tema: 06_Matematicas/Fibonacci_y_Pisano
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: Operaciones de bits/ensamblador: revisar ancho de palabra (32/64 bits) y el caso cero; preservar tipos explícitos cuando el algoritmo lo exige.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_CDB6D9816380EA8A
#define NOTEBOOK_GENERADO_CDB6D9816380EA8A
#include "../../_base/template-simple.hpp"
using ll = long long;
// Calcula fibonacci(n) % m.

// O(log(n))
int fibmod(ll n, int m) {
    int a = 0, b = 1, c;
    for (int i = 63-__builtin_clzll(n); i >= 0; i--) {
        c = a;
        a = (1ll*c*(2ll*b-c+m)) % m;
        b = (1ll*c*c + 1ll*b*b) % m;
        if ((n>>i) & 1) {
            c = (a+b) % m;
            a = b; b = c;
        }
    }
    return a;
}
#endif
