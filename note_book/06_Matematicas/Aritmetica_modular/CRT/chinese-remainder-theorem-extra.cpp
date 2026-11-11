// Tema: 06_Matematicas/Aritmetica_modular/CRT
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (4 líneas).
// Adaptación: Alias de tipos ausentes declarados localmente: pii.
// Adaptación: Dependencias del mismo origen incluidas explícitamente: extra/Math/Extended Euclides.cpp.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_169B4784DE85955C
#define NOTEBOOK_GENERADO_169B4784DE85955C
#include "../../../_base/template-simple.hpp"
#include "../../Teoria_de_numeros/Euclides/extended-euclides-extra.cpp"
using pii = pair<int, int>;
// Encuentra un x tal que para cada i : x es congruente con A_i mod M_i
// Devuelve {x, lcm}, donde x es la solucion con modulo lcm (lcm = LCM(M_0, M_1, ...)). Dado un k : x + k*lcm es solucion tambien.
// Si la solucion no existe o la entrada no es valida devuelve {-1, -1}
// Agregar Extended Euclides.

pii crt(vector<int> A, vector<int> M) {
    int n = A.size(), ans = A[0], lcm = M[0];
    for (int i = 1; i < n; i++) {
        int d = euclid(lcm, M[i]);
        if ((A[i] - ans) % d) return {-1, -1};
        int mod = lcm / d * M[i];
        ans = (ans + x * (A[i] - ans) / d % (M[i] / d) * lcm) % mod;
        if (ans < 0) ans += mod;
        lcm = mod;
    }
    return {ans, lcm};
}
#endif
