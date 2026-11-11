// Tema: 01_Estructuras/Rope
// Base: Template/simple.cpp (int = long long).
// Adaptación: F0R, sz, pr y ps reemplazados por bucles, size y cout.
// Adaptación: Includes adicionales protegidos de las macros de la plantilla.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_DBE2A188E2C8F357
#define NOTEBOOK_GENERADO_DBE2A188E2C8F357
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
#include <ext/rope>
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

// rope (GNU): insertar en la posición i, cortar y reinsertar subcadenas en O(log n).
// En la práctica ~2 veces más lento que un treap propio (TLE con 2e5 en CSES 1749).


using namespace __gnu_cxx;
void ropeExample() {
	rope<int> v(5,0); // initialize with 5 zeroes
	for (int i=0; i<(int)v.size(); ++i) v.mutable_reference_at(i) = i+1; 
	for (int i=0; i<5; ++i) v.pb(i+1); // constant time pb
	rope<int> cur = v.substr(1,2); 
	v.erase(1,3); // erase 3 elements starting from 1st element
	for (rope<int>::iterator it = v.mutable_begin(); 
		it != v.mutable_end(); ++it) cout << (int)*it << ' ';
	cout << '\n'; // 1 5 1 2 3 4 5
	v.insert(v.mutable_begin()+2,cur); // or just 2
	v += cur; for (int i=0; i<(int)v.size(); ++i) cout << v[i] << ' ';
	cout << '\n'; // 1 5 2 3 1 2 3 4 5 2 3
}

// push_back/pop_back/substr/replace O(log n); insert O(log n), peor caso O(n).
#endif
