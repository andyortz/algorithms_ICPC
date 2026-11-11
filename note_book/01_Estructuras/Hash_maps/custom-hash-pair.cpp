// Tema: 01_Estructuras/Hash_maps
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_352B5BD762C3F826
#define NOTEBOOK_GENERADO_352B5BD762C3F826
#include "../../_base/template-simple.hpp"
using ll = long long;
// Example: unordered_set<pair<ll,ll>, HASH> exists;
// It's better to convine with other custom hash
struct chash {
  size_t operator()(const pair<ll,ll>&x)const{
    return hash<ll>()(((ll)x.first)^(((ll)x.second)<<32));
  }
};
#endif
