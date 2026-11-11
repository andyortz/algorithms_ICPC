// Tema: 06_Matematicas/Teoria_de_numeros/Euclides
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_17C7902AD91B3133
#define NOTEBOOK_GENERADO_17C7902AD91B3133
#include "../../../_base/template-simple.hpp"

// Calcula el maximo comun divisor entre a y b mediante el algoritmo de Euclides. Tambien se puede usar __gcd(a, b).

// O(log(max(a, b)))
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}
#endif
