// Tema: 06_Matematicas/Aritmetica_modular/Operaciones
// Base: Template/simple.cpp (int = long long).
// Adaptación: Variantes con Euclides y Fermat preservadas como invmod e invmod_primo.
// Adaptación: Texto explicativo original convertido a comentarios C++ (2 líneas).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Adaptación: Dependencias del mismo origen incluidas explícitamente: extra/Math/Extended Euclides.cpp; extra/Modular arithmetic/Modular Exponentiation.cpp.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_689850EDF4FAA20E
#define NOTEBOOK_GENERADO_689850EDF4FAA20E
#include "../../../_base/template-simple.hpp"
#include "../../Teoria_de_numeros/Euclides/extended-euclides-extra.cpp"
#include "modular-exponentiation-extra.cpp"
using ll = long long;
// Inverso b de a mod m: a*b % m = 1; existe si gcd(a, m) = 1. (n/a) % m = n*b % m.
// Con Euclides extendido, O(log(max(a, m))); -1 si no existe.
int invmod(int a, int m) {
    int d = euclid(a, m);
    if (d > 1) return -1;
    return (x % m + m) % m;
}

// m primo: Fermat, a^(m-2), O(log m).
int invmod_primo(int a, int m) {
    return expmod(a, m-2, m);
}

// Inversos de 1..MX módulo m (primo) en O(MX).
const int MX = 1e6;
int inv[MX+1];
void invmod(int m) {
    inv[1] = 1;
    for (int i = 2; i <= MX; i++) 
        inv[i] = m - ll(m/i) * inv[m%i] % m;
}
#endif
