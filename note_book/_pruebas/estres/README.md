# Pruebas de estrés contra fuerza bruta

Complementan el [juez local de Library Checker](../yosupo/README.md). Allá se usan casos grandes oficiales, pero solo las operaciones que pide cada problema. Acá cada prueba ejecuta **todas las operaciones públicas** de un archivo, miles de veces, con entradas aleatorias pequeñas, y compara cada respuesta con una implementación ingenua.

```powershell
node _pruebas/estres/correr.mjs            # todas -> resultados.md
node _pruebas/estres/correr.mjs lazy arbol # solo las que contienen ese texto
```

En VS Code: **Terminal → Ejecutar tarea… → Estrés: probar todo el notebook contra fuerza bruta**.

Se compila con `-D_GLIBCXX_ASSERTIONS`: un acceso fuera de rango en un `vector` aborta en lugar de pasar desapercibido. Así aparecieron dos errores que en el juez daban AC «por suerte».

**Estado (2026-11-05): 42/42 OK** ([resultados.md](resultados.md)); además 28/28 AC en Library Checker.

## Errores encontrados y corregidos

| Archivo | Error | Síntoma |
| --- | --- | --- |
| [general-lazy-tree.cpp](../../01_Estructuras/Segment_Tree/Lazy/general-lazy-tree.cpp) | `update` puntual no hacía `push` del hijo que no contiene `pos` y recalculaba el padre con su valor viejo | resultados incorrectos al mezclar `apply` de rango con `update` |
| [polynomial-sum-lazy-segtree-problem.cpp](../../01_Estructuras/Segment_Tree/Lazy/polynomial-sum-lazy-segtree-problem.cpp) | el mismo error de `update` | igual |
| [persistantsegmenttree.cpp](../../01_Estructuras/Segment_Tree/Persistente/persistantsegmenttree.cpp) | `copy` de una hoja creaba `Vertex(l, r)` con hijos nulos | la copia de una versión con n = 1 valía 0 |
| [spare-table.cpp](../../01_Estructuras/Sparse_Table/spare-table.cpp) | `n = a.size()+10`, pero `v[0]` tenía `a.size()` elementos | lectura fuera de rango (comportamiento indefinido) |
| [heap-sort.cpp](../../01_Estructuras/Heaps/heap-sort.cpp) | `find` usaba `i > n`; `del` no subía el elemento movido; el centinela -1 fallaba con negativos | lectura fuera de rango; heap inválido tras borrar |
| [link-cut.cpp](../../03_Arboles/Link_Cut_Tree/link-cut.cpp) | `father`, `getR` y `lift` bajaban por el splay sin `push` | nodos incorrectos después de `mkR` (y de `query`/`modify`/`link`, que llaman a `mkR`) |
| [persistent-treap.cpp](../../01_Estructuras/Treap/persistent-treap.cpp) | `#define pitem item*` y `#define f first` / `s second` | `pitem L, R;` declaraba `R` como `item`; rompía variables `f`/`s` posteriores |

Errores corregidos antes con Library Checker: `fast-hash-map`, `lowest-common-ancestor`, `union-find-partial-persistent`, `tree-isomorphism`, `sqrt-descomposition`, `merge-sort-tree`, los treaps (`rand()`) y `mo-s` (ver [yosupo/README.md](../yosupo/README.md)).

## Contrato de uso (lo que el código NO verifica)

Cada estructura está probada **dentro de estas condiciones**; fuera de ellas puede fallar sin aviso.

| Archivo | Condiciones |
| --- | --- |
| `general-segtree` | consultas `[l, r]` inclusivas, 0-indexado; operación de suma fija (editar `Node`/`op` para otra) |
| `general-lazy-tree` | `[l, r]` inclusivo; **inicializar cada posición con `update`** antes de `apply` (el neutro `INT64_MAX` no admite sumas) |
| `iterative-lazytree` | `[l, r]` inclusivo; `max_right`/`min_left` solo con n **potencia de 2** y predicado monótono con `g(e())` verdadero |
| `lazy-st1` | rangos semiabiertos `[i, j)` dentro de la raíz `[l, r)` que pases (sirve para coordenadas hasta 1e9) |
| `segment-tree-lazy-vasito` | rangos semiabiertos `[a, b)`; `init` recibe un puntero a `long long` |
| `polynomial-sum-lazy` | `apply(l, r, {a, b})` suma `a + b·(p−l+1)` en cada posición p; `[l, r]` inclusivo |
| `lazy-creation-pacha` | suma puntual, consulta `[i, j]` inclusiva; rango de la raíz fijo en cada llamada |
| `persistantsegmenttree` | `[l, r]` inclusivo; ~20 nodos nuevos por `update` (memoria: 5·10⁵ updates ≈ 300 MB) |
| `merge-sort-tree` | `query(l, r)` inclusivo; memoria O(n log n) con dos vectores por nodo |
| `fenwick-tree` | 0-indexado, `sum(l, r)` inclusivo |
| `fenwick-tree-2d` | **1-indexado**, rejilla densa (n·m memoria) |
| `segment-tree-2d` | 0-indexado inclusivo, rejilla densa |
| `spare-table` | mínimo, `get(l, r)` inclusivo |
| `sparse-table-2d` | n, m ≤ `MAX_N`, `MAX_M` (100 por defecto); llamar `calc_log2()` una vez y `build()` |
| `wavelet-tree-vasito` | **valores en `[0, n)`** (comprimir); `query0(a, b, i)` en `[a, b)`; el `WT` debe ser global (2²⁰ vectores) |
| `min-queue` | `min()`/`pop()` solo con la cola no vacía |
| `treap-pacha` / `treap-implicit-vasito` | `split` por clave (`< x` a la izquierda) / por tamaño |
| `treap-implicit-father-vasito` | el `item` debe tener el puntero `f`; no se puede incluir junto con `treap-implicit-vasito` (redefine `merge`/`split`) |
| `persistent-treap-pacha` | ver comentario de uso en el archivo; `splitat` necesita un `new item()` |
| `persistent-trie-pacha` | valores en `[0, 2^tao)`; la versión k contiene los k primeros insertados |
| `multiorderedset` | usa el truco `less_equal` (no es un orden estricto); pasó todas las pruebas, pero `oset.find`/`erase(valor)` directos sobre el árbol interno no funcionan: usar los métodos del struct |
| `gain-cost-set-vasito` | definir `INF` antes de incluirlo |
| `disjoint-intervals-pacha` | intervalos semiabiertos `[a, b)`; une también los que se tocan |
| `heap-sort` | max-heap; `del(v, i)` recibe una **posición** válida |
| `dsu` | 0-indexado (reserva n+1) |
| `union-find-rollback-pacha` | definir `N`; `rollback()` solo si el último `unite` sí unió (comparar `sp.size()`) |
| `union-find-partial-persistent-pacha` | definir `N`; llamar `initDSU()`; el tiempo cuenta solo uniones efectivas |
| `lowest-common-ancestor` | árbol de padres a hijos, raíz 0 |
| `binary-lifting-o-n-memory-pacha` | la raíz con `par = go = sí misma` y `de = 0`; `find(x, d)` requiere `d ≤ profundidad(x)` |
| `hld-lca-con-heavy-paths-pacha` | raíz 0; `hldQuery` combina con **max empezando en 0** (valores ≥ 0); implementar `segQuery` |
| `link-cut-pacha` | `cut(x, y)` requiere la arista; `cut(x)` requiere que x no sea la raíz; `lca`/`father`/`depth`/`lift` son respecto de la raíz actual (`mkR`) |
| `max-weight-lca-pacha` | 1-indexado, raíz 1, pesos ≥ 0, n < `N` (1e5) |
| `euler-tour-sum` | `test_case` lee el formato de CSES 1138 (1-indexado) |
| `centroid-decomposition-extra` | `c_ans` con tamaño ≥ n y valor `N`; `dep` en 0; `query` exige al menos un nodo marcado |
| `dsu-on-tree-sack-extra` | las respuestas se calculan dentro de `dfs` (editar el punto marcado); `col` < `N` |
| `re-rooting` | declarar `grafo`, `dp`, `maxi` antes de incluir y ponerlos en **0** |
| `block-tree` | `Block` es específico del problema (suma por profundidad); `SQRT = 320` |
| `mo-s-in-tree-s` | programa completo (scanf); N ≤ 50 000, Q ≤ 100 000 por los arreglos fijos |
| `lca-multiplication-path` | programa de CF 587C; a ≤ 10 |

## Lo que sigue sin cobertura

* `priority-queue.cpp` (solo dos alias de `priority_queue`), `custom-hash-pair` cubierto solo con `unordered_set`.
* `03_Arboles/Problemas` (`nearest-selected-nodes`, `two-pieces-on-tree`): son soluciones de problemas concretos, no estructuras.
* Las pruebas usan tamaños pequeños; el rendimiento con tamaños grandes está medido solo para lo que cubre Library Checker.
