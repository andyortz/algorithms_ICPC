// Tema: 06_Matematicas/Teoria_de_numeros/Euclides
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_CC8A4D19FF6D7117
#define NOTEBOOK_GENERADO_CC8A4D19FF6D7117
#include "../../../_base/template-simple.hpp"

// Calculo del minimo comun multiplo usando el maximo comun divisor.

// O(log(max(a, b)))
int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}
#endif
