// Selección: Solo división de prueba O(sqrt(n)); Pollard Rho y criba viven en sus archivos propios.
// Tema: 06_Matematicas/Teoria_de_numeros/Primos_y_factorizacion
// Base: Template/simple.cpp (int = long long).
// Adaptación: Subtítulos de variantes convertidos a comentarios.
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_526405DF445B0524
#define NOTEBOOK_GENERADO_526405DF445B0524
#include "../../../_base/template-simple.hpp"
using ll = long long;
// Tres funciones diferentes que guardan en el map f los pares <primo, exponente> de la descomposicion en factores primos de n.

// 1.1) Iterando hasta sqrt(n)
// O(sqrt(n))
void fact(ll n, map<ll, int> &f) {
    for (int p = 2; 1ll*p*p <= n; p++) 
        while (n%p == 0) f[p]++, n /= p;
    if (n > 1) f[n]++;
}

#endif
