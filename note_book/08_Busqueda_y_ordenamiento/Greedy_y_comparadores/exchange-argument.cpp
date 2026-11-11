// Tema: 08_Busqueda_y_ordenamiento/Greedy_y_comparadores
// Base: Template/simple.cpp (int = long long).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_40548BD1E2C12802
#define NOTEBOOK_GENERADO_40548BD1E2C12802
#include "../../_base/template-simple.hpp"

// prove that the sequence AB provides a better answer than BA 
// so you need to find a possible inequation: A < B
// and that its impossible: B < A
int cmp(array<int,2> &a, array<int,2> &b) {
    int ok = a[1] >= a[0];
    ok|= (b[1] >= b[0]? 2: 0);
    if (ok==3) return a[0] < b[0];
    else if (!ok) return a[1] > b[1];
    else return ok&1;
}
#endif
