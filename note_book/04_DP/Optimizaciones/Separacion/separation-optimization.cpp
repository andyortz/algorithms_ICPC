// Tema: 04_DP/Optimizaciones/Separacion
// Base: Template/simple.cpp (int = long long).
// Adaptación: Apunte o implementación comentada; conservado para consulta.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

// APUNTE ORIGINAL: no es una unidad C++ compilable.
No se si tiene un nombre, pero en varios problemas vi este truco:

dp[x] = f(x,y) donde se necesita un optimo 'y'.

Truco: si puedes separarlo en f(x,y) en f(x) (+) f(y), puedes guardar en una estructa optima f(y) como un segment tree.
