// Tema: 06_Matematicas/Aritmetica_modular/Operaciones
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_2185021B2D8AF760
#define NOTEBOOK_GENERADO_2185021B2D8AF760
#include "../../../_base/template-simple.hpp"
using ll = long long;
const ll MOD = 998244353;

struct frac : public pair<ll, ll> {
    using pair<ll, ll>::pair;

    frac simplify() {
        if (first == 0) {
            return frac(0, 1);
        }
        ll gcd_val = __gcd(first, second);
        return frac(first / gcd_val, second / gcd_val);
    }

    frac operator*(const frac &other) {
        // a * invmod(b) = a / b
        // a * invmod(b) * a2 * invmod(b2) = (a * a2) / (b * b2)
        return frac((first * other.first) % MOD , (second * other.second) % MOD ).simplify();
    }

    frac operator+(const frac &other) {
        // opertaor + with module
        // a * invmod(b) + a2 * invmod(b2) = (a * b2 + a2 * b) / (b * b2)
        ll up = (first * other.second) % MOD + (other.first * second) % MOD;
        ll down = (second * other.second) % MOD;
        // TODO: check if simplify should be here
        return frac(up, down).simplify();
    }
};

// Expected Value is the sum of all the possible values multiplied by their probability
// Geometrica is reversed.
#endif
