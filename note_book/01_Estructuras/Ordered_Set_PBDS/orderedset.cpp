// Tema: 01_Estructuras/Ordered_Set_PBDS
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Adaptación: Includes adicionales protegidos de las macros de la plantilla.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_AD218522B2D9979A
#define NOTEBOOK_GENERADO_AD218522B2D9979A
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
#include <ext/pb_ds/tree_policy.hpp>
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
// Same as set, but you can get the order of an element or the
// element in given sorted position in O(log n)


using namespace __gnu_pbds;
 
#define oset tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//find_by_order(k) order_of_key(k)
#endif
