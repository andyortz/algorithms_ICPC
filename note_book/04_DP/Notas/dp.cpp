// Tema: 04_DP/Notas
// Base: Template/simple.cpp (int = long long).
// Adaptación: Apunte o implementación comentada; conservado para consulta.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

// APUNTE ORIGINAL: no es una unidad C++ compilable.
sub array problems where the function is like this: 
f(l, r) - k*(r-l+1)/m; there is an algorithm that works in O (n*m) using: 
dp[i] = max/min over all len <= m: f(i-len+1, i) - k + dp[i-len] 
because dp[i] we assume that puts a complete cycle interval (division) to apply -k * 1 (new cycle created. 


check all submask from a mask efficiently: O(3^n):
for (submask = 0; submask; submask = (submask&mask)-1)

SOS dp (cuenta bien pero no se como)
for (i = 0; i<n; i++) for (int mask = 0; mask < (1<<n); mask)
if (mask & (1<<i)) dp[mask] += dp[mask ^ (1<<i)];