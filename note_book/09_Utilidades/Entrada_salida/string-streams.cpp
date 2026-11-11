// Tema: 09_Utilidades/Entrada_salida
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl.
// Requisito: Ejemplo de lectura: el bloque pertenece a solve().
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_889A83975DDEF37A
#define NOTEBOOK_GENERADO_889A83975DDEF37A
#include "../../_base/template-simple.hpp"
using ll = long long;
using vl = vector<long long>;
// For some complex reading of input
// st is the same as a cin, but you pass the string
string line;
getline(cin, line);
stringstream st(line);
vl in;
ll x;
while (st >> x) {
    in.pb(x);
}
#endif
