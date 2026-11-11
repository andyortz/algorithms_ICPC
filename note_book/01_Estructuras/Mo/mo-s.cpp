// Tema: 01_Estructuras/Mo
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_A54401F03FBA4159
#define NOTEBOOK_GENERADO_A54401F03FBA4159
#include "../../_base/template-simple.hpp"
using ll = long long;
using vl = vector<long long>;
/*
Mo's algorithm O((N + Queries)*SQRT(N))

It answers queries offline using SQRT Descomposition, 
sometimes get TLE when you have Set, Map, various iteration when adding,
So you need to implement efficiently (with arrays) in O(1). You can answer
questions like in a range, the number of distincts values.
*/
/*
Uso: las consultas [l, r] (0-indexadas, inclusivas, l <= r) e idx = posición de la respuesta.
add(i) / remove(i) actualizan el estado al meter / sacar el índice i; getAnswer() lo lee.
Se pasan como lambdas (antes estaban definidas vacías en este archivo y no se podían completar).

Ejemplo: cantidad de valores distintos (valores comprimidos a [0, n)):
    vi cnt(n); ll distintos = 0;
    auto add = [&](int i) { if (cnt[a[i]]++ == 0) distintos++; };
    auto rem = [&](int i) { if (--cnt[a[i]] == 0) distintos--; };
    vector<ll> res = mo(queries, n, add, rem, [&]() { return distintos; });
Tested https://judge.yosupo.jp/problem/static_range_count_distinct (N = Q = 5e5)
*/
int BLOCK_SIZE = 430; // mo() lo recalcula: ~ n / sqrt(q) (antes fijo: 1e5 -> 310, 2e5 -> 430)

struct query {
    int l, r, idx;

    bool operator <(const query &other) const {
        if (l / BLOCK_SIZE != other.l / BLOCK_SIZE) return l < other.l;
        // orden par/impar: en bloques impares r decrece, así r no vuelve al inicio en cada bloque
        return (l / BLOCK_SIZE) & 1 ? r > other.r : r < other.r;
    }
};

template<class Add, class Remove, class Get>
vector<ll> mo(vector<query> queries, int n, Add add, Remove remove, Get getAnswer) {
    vector<ll> answers(queries.size());
    if (queries.empty()) return answers;
    BLOCK_SIZE = max<ll>(1, n / max<ll>(1, sqrtl(queries.size())));
    int l = 0;
    int r = -1;
    sort(all(queries));
    for (auto &q : queries) {
        while (q.l < l) add(--l);
        while (r < q.r) add(++r);
        while (l < q.l) remove(l++);
        while (q.r < r) remove(r--);
        answers[q.idx] = getAnswer();
    }
    return answers;
}
#endif
