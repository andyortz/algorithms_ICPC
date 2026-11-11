// Tema: 06_Matematicas/Teoria_de_numeros/Euclides
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_32C22D90BA11350F
#define NOTEBOOK_GENERADO_32C22D90BA11350F
#include "../../../_base/template-simple.hpp"

// El algoritmo de Euclides extendido retorna el gcd(a, b) y calcula los coeficientes enteros X y Y que satisfacen la ecuacion: a*X + b*Y = gcd(a, b).

int x, y;
// O(log(max(a, b)))
int euclid(int a, int b) {
    if (b == 0) { x = 1; y = 0; return a; }
    int d = euclid(b, a%b);
    int aux = x;
    x = y;
    y = aux - a/b*y;
    return d;
}
#endif
