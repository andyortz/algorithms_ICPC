// Selección: Se conserva únicamente custom_hash_splitmix64.
// Tema: 01_Estructuras/Hash_maps
// Base: Template/simple.cpp (int = long long).
// Hash seleccionado: splitmix64.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_5EE9FD199F6FDD98
#define NOTEBOOK_GENERADO_5EE9FD199F6FDD98
#include "../../_base/template-simple.hpp"

// Avoid hashing hacks and improve performance of hash structures
// e.g. unordered_map<ll,ll,custom_hash> 
struct custom_hash_splitmix64 {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#endif
