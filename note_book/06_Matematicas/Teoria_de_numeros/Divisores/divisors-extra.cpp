// Tema: 06_Matematicas/Teoria_de_numeros/Divisores
// Base: Template/simple.cpp (int = long long).
// Adaptación: Subtítulos explicativos convertidos a comentarios.
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_6ECBE2E40A3B8B1F
#define NOTEBOOK_GENERADO_6ECBE2E40A3B8B1F
#include "../../../_base/template-simple.hpp"
using ll = long long;
// * Calcula la suma de los divisores de n. Agregar Prime Factorization y Modular Exponentiation (sin el modulo).

ll sumDiv(ll n) {
    map<ll, int> f;
    fact(n, f);
    ll ans = 1;
    for (auto p : f) {
        ans *= (exp(p.first, p.second+1)-1)/(p.first-1);
    }
    return ans;
}

// * Calcula la cantidad de divisores de n. Agregar Prime Factorization.

ll cantDiv(ll n) {
    map<ll, int> f;
    fact(n, f);
    ll ans = 1;
    for (auto p : f) ans *= (p.second + 1);
    return ans;
}

// * Calcular la cantidad de divisores para todos los numeros menores o iguales a MX con Sieve of Eratosthenes.

const int MX = 1e6;
bool marked[MX+1];
vector<int> cnt;

void sieve() {
    cnt.assign(MX+1, 1);
    marked[0] = marked[1] = true;
    for (int i = 2; i <= MX; i++) {
        if (marked[i]) continue;
        cnt[i]++;
        for (int j = i*2; j <= MX ; j += i) {
            int n = j, c = 1;
            while (n%i == 0) n /= i, c++;
            cnt[j] *= c;
            marked[j] = true;
        }
    }
}
#endif
