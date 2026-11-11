// Tema: 01_Estructuras/Hash_maps
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Adaptación: Includes adicionales protegidos de las macros de la plantilla.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_0FEEB8026968199F
#define NOTEBOOK_GENERADO_0FEEB8026968199F
#include "../../_base/template-simple.hpp"
#pragma push_macro("int")
#undef int
#pragma push_macro("fast")
#undef fast
#pragma push_macro("pb")
#undef pb
#pragma push_macro("F")
#undef F
#pragma push_macro("S")
#undef S
#pragma push_macro("all")
#undef all
#pragma push_macro("sortt")
#undef sortt
#pragma push_macro("sortn")
#undef sortn
#pragma push_macro("pi")
#undef pi
#pragma push_macro("vi")
#undef vi
#pragma push_macro("vb")
#undef vb
#pragma push_macro("vpi")
#undef vpi
#pragma push_macro("vs")
#undef vs
#pragma push_macro("endl")
#undef endl
#include <ext/pb_ds/assoc_container.hpp>
#pragma pop_macro("endl")
#pragma pop_macro("vs")
#pragma pop_macro("vpi")
#pragma pop_macro("vb")
#pragma pop_macro("vi")
#pragma pop_macro("pi")
#pragma pop_macro("sortn")
#pragma pop_macro("sortt")
#pragma pop_macro("all")
#pragma pop_macro("S")
#pragma pop_macro("F")
#pragma pop_macro("pb")
#pragma pop_macro("fast")
#pragma pop_macro("int")
using ll = long long;
using namespace __gnu_pbds;
// gp_hash_table usa los bits BAJOS del hash como índice. Con "x ^ RANDOM" las claves que
// comparten bits bajos (ej. múltiplos de 2^k) caen todas en el mismo grupo: TLE en
// Library Checker associative_array (caso 2_powers). splitmix64 mezcla todos los bits.
struct chash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(const ll &x) const {
        static const uint64_t RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + RANDOM);
    }
};
// There is no mp.count(x), so use mp.find(x) != mp.end()
gp_hash_table<ll,ll,chash> mp;
#endif
