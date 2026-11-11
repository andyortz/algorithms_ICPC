# Pruebas del notebook contra Library Checker (judge.yosupo.jp)

Enviar soluciones a [judge.yosupo.jp](https://judge.yosupo.jp) requiere iniciar sesión con GitHub. Por eso se usa un **juez local** con los **mismos casos del juez**: se generan con los generadores oficiales de [yosupo06/library-checker-problems](https://github.com/yosupo06/library-checker-problems), se comprueban byte a byte contra `hash.json` y se juzgan con el checker oficial y el límite de tiempo de `info.toml`.

## Uso

```powershell
# una vez (clon parcial, ~MB): desde la carpeta ICPC/repos
git clone --depth 1 --filter=blob:none --sparse https://github.com/yosupo06/library-checker-problems
# desde note_book
node _pruebas/yosupo/juez.mjs                  # todos los adaptadores -> resultados.md
node _pruebas/yosupo/juez.mjs lca ordered_set  # solo los que contienen ese texto
```

Requisitos: Node.js, g++ y git. No hace falta Python. El juez agrega solo los problemas que faltan (`git sparse-checkout add`) y guarda los casos en la carpeta de cada problema del clon (`in/`, `out/`, `.local/`).

Cada adaptador `problema--estructura.cpp` incluye el archivo del notebook **sin modificarlo** y solo agrega el `main` con el formato de entrada y salida del problema. La primera línea indica el problema (`// yosupo: ...`) y la segunda el archivo probado (`// prueba: ...`).

## Resultados

**28/28 adaptadores con AC** en todos los casos oficiales (detalle y tiempos en [resultados.md](resultados.md), que se regenera con cada corrida completa).

## Correcciones hechas al notebook a partir del juez

| Archivo | Veredicto antes | Causa | Corrección |
| --- | --- | --- | --- |
| [fast-hash-map.cpp](../../01_Estructuras/Hash_maps/fast-hash-map.cpp) | TLE (7.0 s en `2_powers_00`) | `x ^ RANDOM` no mezcla bits y `gp_hash_table` indexa con los bits bajos | hash splitmix64 con semilla aleatoria |
| [lowest-common-ancestor.cpp](../../03_Arboles/LCA_y_binary_lifting/lowest-common-ancestor.cpp) | RE en 7/25 (árboles en camino) | `LOG = 18` fijo: saltos ≥ 2¹⁸ fuera de rango | `LOG` calculado en `init` según n; recorrido BFS iterativo; `children` por referencia |
| [union-find-partial-persistent.cpp](../../01_Estructuras/DSU/union-find-partial-persistent.cpp) | CE | `for` de inicialización fuera de una función | función `initDSU()` |
| [tree-isomorphism-extra.cpp](../../03_Arboles/Isomorfismo_y_hashing/tree-isomorphism-extra.cpp) | CE | requería definir `N`, `g` y `rand(l, r)` por fuera; DFS recursivo | autocontenido: `dfs(g, root)` iterativo, `mt19937_64` propio, sumas `unsigned` |

### Segunda tanda (errores que no impedían el AC)

| Archivo | Problema | Corrección | Verificación |
| --- | --- | --- | --- |
| [sqrt-descomposition.cpp](../../01_Estructuras/Descomposicion_SQRT/sqrt-descomposition.cpp) | `if (query)` evaluaba el puntero a la función (siempre verdadero): `sqrt_()` nunca actualizaba | lee el tipo de consulta (`1 l r` suma, `2 i x` asignación); formato documentado; `p.assign` | [_pruebas/sqrt-descomposition.cpp](../sqrt-descomposition.cpp): 500 casos contra fuerza bruta; AC en point_add_range_sum |
| [merge-sort-tree.cpp](../../01_Estructuras/Segment_Tree/Merge_Sort_Tree/merge-sort-tree.cpp) | `init` con n = 0 no terminaba | `init` y `query` aceptan n = 0 y rangos vacíos | el adaptador ya no tiene protecciones: AC en static_range_frequency (incluye N = 0) |
| [treap.cpp](../../01_Estructuras/Treap/treap.cpp), [treap-implicit-vasito.cpp](../../01_Estructuras/Treap/treap-implicit-vasito.cpp), [persistent-treap.cpp](../../01_Estructuras/Treap/persistent-treap.cpp) | `rand()` con `RAND_MAX = 32767` en MinGW: prioridades repetidas; en el persistente, `rand() % tamaño` sesgado con tamaños > 32767 | `mt19937` / `mt19937_64` | AC en ordered_set (treap-pacha); los otros dos compilan |
| [mo-s.cpp](../../01_Estructuras/Mo/mo-s.cpp) | `add`/`remove` definidos vacíos en el archivo: no se podían completar; bloque fijo de 430 | `mo(queries, n, add, remove, getAnswer)` con lambdas; bloque ~ n/√q; orden par/impar | nuevo adaptador `static_range_count_distinct--mo.cpp`: AC (N = Q = 5·10⁵) |

Fuera de las estructuras quedan otros dos usos de `rand()` (`sieve.cpp`, `optimized-polard-rho.cpp`, en 06_Matematicas). Ahí los valores aleatorios pequeños no rompen el algoritmo; no se cambiaron.

## Sin problema equivalente en Library Checker

Estas estructuras, y todas las operaciones que Library Checker no ejercita (actualizaciones de rango, versiones viejas, funciones de raíz del link-cut, etc.), se cubren con las [pruebas de estrés contra fuerza bruta](../estres/README.md).


`min-queue`, `fenwick-tree-2d`, `segment-tree-2d`, `sparse-table-2d` (rejillas densas), `rope`, `treap-implicit*` (sin suma de rango en el archivo), `persistent-treap`, `persistent-trie` (sin borrado ni consulta), `gain-cost-set`, `disjoint-intervals`, `heap-sort`, `priority-queue` (solo alias). En `03_Arboles`: `euler-tour-sum` (la lógica está dentro de `test_case` para CSES), rerooting, centroid, DSU on tree, block tree y Mo en árboles son plantillas de problema concreto. Se pueden cubrir con pruebas contra fuerza bruta como las de `_pruebas/geometria-3d.cpp`.
