# LIS y LCS: versión a elegir

Todas las funciones devuelven la **longitud** de la subsecuencia; no la reconstruyen.

| Caso | Función / archivo | Tiempo |
| --- | --- | --- |
| LIS estrictamente creciente | `lis(a)` en [LIS existente](../LIS/longest-increasing-subsequence.cpp) | O(N log N), memoria O(N) |
| LCS de permutaciones o con valores distintos en la segunda secuencia | `lcs_lis(a,b)` en [lcs-lis.cpp](lcs-lis.cpp) | O((n+m) log(m+2)); O(N log N) para tamaños N |
| LCS con pocas coincidencias, incluso repetidos | La misma `lcs_lis(a,b)` | O((n+m+r) log(m+2)), donde r cuenta pares de posiciones con valores iguales |
| LCS de strings generales, incluidos muchos repetidos | `lcs_bitset(a,b)` en [lcs-bitset.cpp](lcs-bitset.cpp) | O(m + (n+256)·ceil(m/64)), con n mayor longitud y m menor |
| DP clásica de referencia | `lcs(m,n)` en [LCS existente](longest-common-subsequence.cpp) | O(n·m) tiempo y memoria; tabla original limitada a 20 por cadena |

La reducción LCS → LIS no proporciona O(N log N) para cadenas arbitrarias: con repeticiones puede haber n·m coincidencias. El recorrido descendente de posiciones evita contar varias veces un mismo elemento. La versión con bloques de 64 bits acelera la DP general, pero tampoco ofrece O(N log N).

`lcs_lis` acepta dos `vi` o dos `string`. `lcs_bitset` recibe strings/string_view y compara bytes. Ambas soportan entradas vacías, no tienen el límite fijo de 20 y usan el preámbulo de `00_Template/simple.cpp`. Los tipos `uint64_t` de la versión por bits deben mantenerse unsigned aunque la plantilla defina `int` como `long long`.

```cpp
vi a = {3, 1, 2}, b = {1, 3, 2};
cout << lcs_lis(a, b) << endl; // 2
cout << lcs_bitset("banana", "atana") << endl; // 4
```

Referencias: [Hunt–Szymanski](https://doi.org/10.1145/359581.359603), [Allison–Dix](https://allisons.org/ll/Publications/1986IPL/).

Pruebas reproducibles: [_pruebas/lis-lcs.cpp](../../_pruebas/lis-lcs.cpp), con oráculos de DP, entradas vacías, repetidos, permutaciones, enteros de 64 bits y límites entre palabras de 64 bits. Ver el [resultado](../../_pruebas/lis-lcs-resultado.txt).
