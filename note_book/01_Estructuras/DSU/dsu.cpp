// Tema: 01_Estructuras/DSU
// Base: Template/simple.cpp (int = long long).
// Adaptación: Corregido typo del constructor: usa el parámetro ni.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_F65E826ED6BD4A2B
#define NOTEBOOK_GENERADO_F65E826ED6BD4A2B
#include "../../_base/template-simple.hpp"

struct DSU {
    vi p;
    DSU(int ni) {p.resize(ni+1, -1);} 
    int find(int x) {return p[x] < 0? x: p[x] = find(p[x]);}
    void merge(int a, int b) {
        a = find(a), b = find(b);
        if (a==b) return;
        if (p[a] > p[b]) swap(a, b);
        p[a]+=p[b];
        p[b] = a;
    }
    int siz(int x) {return -p[find(x)];}
};
#endif
