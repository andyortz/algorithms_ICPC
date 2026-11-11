// Tema: 09_Utilidades/Bits
// Base: Template/simple.cpp (int = long long).
// Adaptación: Apunte o implementación comentada; conservado para consulta.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

// APUNTE ORIGINAL: no es una unidad C++ compilable.
y = x & (x-1)   // apagar el 1 más a la derecha
y = x & (-x)    // aislar el 1 más a la derecha (lowbit)
y = x | (x-1)   // propagar a la derecha el 1 más a la derecha
y = x | (x+1)   // encender el 0 más a la derecha
y = ~x & (x+1)  // aislar el 0 más a la derecha
// Builtins (sufijo ll para long long; x = 0 indefinido en clz/ctz):
__builtin_popcount(x)  // cantidad de unos      __builtin_parity(x) // 1 si es impar
__builtin_clz(x)       // ceros a la izquierda  __builtin_ctz(x)    // ceros a la derecha
__builtin_ffs(x)       // 1 + índice del 1 más bajo (0 si x == 0)
for(int s=m;s;s=(s-1)&m)  // submáscaras no vacías de m, orden decreciente
for(int s=0;s=s-m&m;)     // submáscaras no vacías de m, orden creciente
