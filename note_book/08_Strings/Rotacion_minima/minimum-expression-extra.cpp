// Tema: 08_Strings/Rotacion_minima
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_5257454F497BCB5C
#define NOTEBOOK_GENERADO_5257454F497BCB5C
#include "../../_base/template-simple.hpp"

// Dado un string s devuelve el indice donde comienza la rotación lexicograficamente menor de s.

// O(n)
int minimum_expression(string s) {
    s = s+s; // si no se concatena devuelve el indice del sufijo menor
    int len = s.size(), i = 0, j = 1, k = 0;
    while (i+k < len && j+k < len) {
        if (s[i+k] == s[j+k]) k++;
        else if (s[i+k] > s[j+k]) i = i+k+1, k = 0; // cambiar por < para maximum
        else j = j+k+1, k = 0;
        if (i == j) j++;
    }
    return min(i, j);
}
#endif
