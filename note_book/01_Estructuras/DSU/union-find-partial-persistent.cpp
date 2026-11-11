// Tema: 01_Estructuras/DSU
// Base: Template/simple.cpp (int = long long).
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_730B529D29498D20
#define NOTEBOOK_GENERADO_730B529D29498D20
#include "../../_base/template-simple.hpp"

// DSU parcialmente persistente: unite y find(a, tiempo) O(log n).
// his[x] = tiempo en que x recibió padre; t = cantidad de uniones efectivas.

int t, par[N], sz[N], his[N];

int find(int a, int t){
    if(par[a] == a) return a;
    if(his[a] > t) return a;
    return find(par[a], t);
}

void unite(int a, int b){
    if(find(a, t) == find(b, t)) return;
    a = find(a, t), b = find(b, t), t++;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b], par[b] = a, his[b] = t;
}

// Llamar al inicio del main (antes estaba suelto fuera de una función y no compilaba).
// Requiere definir N antes de incluir este archivo.
void initDSU(){
    t = 0;
    for(int i = 0; i < N; i++) par[i] = i, sz[i] = 1, his[i] = 0;
}
#endif
