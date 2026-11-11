// Tema: 06_Matematicas/Aritmetica_modular/Logaritmo_discreto
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_309DE5AD8FE1B22E
#define NOTEBOOK_GENERADO_309DE5AD8FE1B22E
#include "../../../_base/template-simple.hpp"
using ll = long long;
// Devuelve un entero x tal que a^x = b (mod m) or -1 si no existe tal x.

int expmod(int b, int e, int m) { // Always check if change int to ll !!!
    int ans = 1;
    while (e) {
        if (e&1) ans = (1ll*ans*b) % m;
        b = (1ll*b*b) % m;
        e /= 2;
    }
    return ans;
}

ll discrete_log(ll a, ll b, ll m) {
    a %= m, b %= m;
    if (b == 1) return 0;
    int cnt = 0;
    ll tmp = 1;
    for (int g = __gcd(a, m); g != 1; g = __gcd(a, m)) {
        if (b%g) return -1;
        m /= g, b /= g;
        tmp = tmp*a / g % m;
        ++cnt;
        if (b == tmp) return cnt;
    }
    map<ll, int> w;
    int s = ceil(sqrt(m));
    ll base = b;
    for (int i = 0; i < s; i++) {
        w[base] = i;
        base = base*a % m;
    }
    base = expmod(a, s, m);
    ll key = tmp;
    for (int i = 1; i <= s+1; i++) {
        key = key*base % m;
        if (w.count(key)) return i*s - w[key] + cnt;
    }
    return -1;
}
#endif
