// Tema: 09_Utilidades/CPP
// Base: Template/simple.cpp (int = long long).
// Adaptación: Apunte o implementación comentada; conservado para consulta.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

// APUNTE ORIGINAL: no es una unidad C++ compilable.
const double DINF=numeric_limits<double>::infinity();
// set/map de doubles con tolerancia (builtins y submáscaras: ver Bits/bit-tricks.cpp)
struct comp {
	bool operator()(const double& a, const double& b) const {
		return a+EPS<b;}
};
set<double,comp> w; // o map<double,int,comp>
