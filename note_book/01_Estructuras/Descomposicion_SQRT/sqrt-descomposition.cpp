// Tema: 01_Estructuras/Descomposicion_SQRT
// Base: Template/simple.cpp (int = long long).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_BDE948D22FBBB92A
#define NOTEBOOK_GENERADO_BDE948D22FBBB92A
#include "../../_base/template-simple.hpp"

// Suma en rango y asignación puntual en O(sqrt(n)) por operación.
// Uso: leer n, q y los n valores en v; llamar sqrt_(). Consultas (1-indexadas):
//   "1 l r" -> imprime la suma de v[l..r]      "2 i x" -> v[i] = x
// Tested (query + bloques): https://judge.yosupo.jp/problem/point_add_range_sum
vi v, p;
int block, n, q;
int query(int i) { // suma de v[0..i] (0-indexado); i < 0 -> 0
    if (i<0) return 0;
    int res = 0;
    for (int j = 0; j<i/block; j++) res+=p[j];
    for (int j = (i/block)*block; j<=i; j++) res+=v[j];
    return res;
}
void sqrt_() {
    block = sqrt(n)+2;
    v.resize(n, 0), p.assign(block, 0);
    for (int i =0 ; i<n;i++) p[i/block]+=v[i];
    for (; q--; ) {
        int type; cin>>type; // antes "if (query)": evaluaba el puntero a la función (siempre true)
        if (type == 1) {
            int l, r; cin>>l>>r; l--, r--;
            cout<<query(r)-query(l-1)<<endl; // sum in range
        } else {// point update
            int i, x; cin>>i>>x; i--;
            p[i/block]-=v[i];
            v[i] = x;
            p[i/block]+=v[i];
        }
    }
}
#endif
