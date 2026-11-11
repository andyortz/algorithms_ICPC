// Tema: 09_Utilidades/Aleatoriedad
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_B77AE9A20220B79B
#define NOTEBOOK_GENERADO_B77AE9A20220B79B
#include "../../_base/template-simple.hpp"
using ll = long long;
// Get random numbers between [a, b]
mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
// also for ll exists mt19937_64
ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
}
#endif
