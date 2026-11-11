# Catálogo de implementaciones seleccionadas

El estado «sintaxis OK» solo verifica cada archivo bajo la plantilla, no una garantía algorítmica. Los requisitos del original y de la selección se listan junto a cada entrada.

## 01_Estructuras/Colas_monotonas

### [min-queue.cpp](01_Estructuras/Colas_monotonas/min-queue.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/range_queries/min_queue.cpp](../Alex/range_queries/min_queue.cpp).

Implementación compacta con la plantilla; elimina alternativas del mismo contenedor.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).

## 01_Estructuras/DSU

### [dsu.cpp](01_Estructuras/DSU/dsu.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/range_queries/dsu.cpp](../Alex/range_queries/dsu.cpp).

Usa directamente vi, int y vector; verificada con prueba funcional.

Adaptaciones:

- Corregido typo del constructor: usa el parámetro ni.

### [union-find-partial-persistent.cpp](01_Estructuras/DSU/union-find-partial-persistent.cpp)

**Requiere integración** · fragmento. Origen: [pacha/data structures/union find partial persistent.cpp](../pacha/data%20structures/union%20find%20partial%20persistent.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'N' was not declared in this scope`
- `'par' was not declared in this scope; did you mean '__pstl::execution::v1::par'?`
- `'his' was not declared in this scope`

### [union-find-rollback.cpp](01_Estructuras/DSU/union-find-rollback.cpp)

**Requiere integración** · programa. Origen: [pacha/data structures/union find rollback.cpp](../pacha/data%20structures/union%20find%20rollback.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: pii.

Requisitos y observaciones:

- Contiene main de ejemplo/prueba: usar su main o el de simple.cpp, nunca ambos.
- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'N' was not declared in this scope`
- `'par' was not declared in this scope; did you mean '__pstl::execution::v1::par'?`
- `'sz' was not declared in this scope; did you mean 'ss'?`

## 01_Estructuras/Descomposicion_SQRT

### [mo-xd.cpp](01_Estructuras/Descomposicion_SQRT/mo-xd.cpp)

**Apunte** · apunte. Origen: [Alex/range_queries/mo_xd.cpp](../Alex/range_queries/mo_xd.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.

### [sqrt-descomposition.cpp](01_Estructuras/Descomposicion_SQRT/sqrt-descomposition.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/range_queries/sqrt_descomposition.cpp](../Alex/range_queries/sqrt_descomposition.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

## 01_Estructuras/Fenwick

### [fenwick-tree-2d.cpp](01_Estructuras/Fenwick/fenwick-tree-2d.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/Fenwick Tree 2D.cpp](../Nicolas/3%20Data%20Structures/Fenwick%20Tree%202D.cpp).

Mantener separado: consultas y actualizaciones en dos dimensiones.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.

### [fenwick-tree.cpp](01_Estructuras/Fenwick/fenwick-tree.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/Fenwick Tree.cpp](../Nicolas/3%20Data%20Structures/Fenwick%20Tree.cpp).

Vectores dimensionados por el constructor y prueba de valores de 64 bits.

## 01_Estructuras/Hash_maps

### [custom-hash.cpp](01_Estructuras/Hash_maps/custom-hash.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/Custom Hash.cpp](../Nicolas/3%20Data%20Structures/Custom%20Hash.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Se conserva únicamente custom_hash_splitmix64.

### [custom-hash-pair.cpp](01_Estructuras/Hash_maps/custom-hash-pair.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/Custom Hash Pair.cpp](../Nicolas/3%20Data%20Structures/Custom%20Hash%20Pair.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

### [fast-hash-map.cpp](01_Estructuras/Hash_maps/fast-hash-map.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/Fast Hash Map.cpp](../Nicolas/3%20Data%20Structures/Fast%20Hash%20Map.cpp).

Una definición de gp_hash_table protegida de macros.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.
- Includes adicionales protegidos de las macros de la plantilla.

## 01_Estructuras/Heaps

### [heap-sort.cpp](01_Estructuras/Heaps/heap-sort.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/sorting/heap_sort.cpp](../Alex/sorting/heap_sort.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

Requisitos y observaciones:

- En find el original comprueba i>n; para índices 0..n-1 debe comprobar i>=n. Revisar además el contrato de del y los valores centinela.

### [priority-queue.cpp](01_Estructuras/Heaps/priority-queue.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/Priority Queue.cpp](../Nicolas/3%20Data%20Structures/Priority%20Queue.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

## 01_Estructuras/Intervalos_y_dominancia

### [disjoint-intervals.cpp](01_Estructuras/Intervalos_y_dominancia/disjoint-intervals.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/data structures/disjoint_intervals.cpp](../pacha/data%20structures/disjoint_intervals.cpp).

Copias de la misma estructura, corregidas de la misma manera.

Adaptaciones:

- Accesos abreviados a pair reemplazados por first/second, sin macros auxiliares.
- Corregido nombre del conjunto: s.

### [gain-cost-set-vasito.cpp](01_Estructuras/Intervalos_y_dominancia/gain-cost-set-vasito.cpp)

**Requiere integración** · fragmento. Origen: [vasito/data_structures/gain_cost_set.cpp](../vasito/data_structures/gain_cost_set.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'INF' was not declared in this scope`
- `no matching function for call to 'std::pair<long long int, long long int>::pair(<brace-enclosed initializer list>)'`

## 01_Estructuras/Mo

### [mo-s-hilbert-curve.cpp](01_Estructuras/Mo/mo-s-hilbert-curve.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/Mo's Hilbert Curve.cpp](../Nicolas/3%20Data%20Structures/Mo's%20Hilbert%20Curve.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [mo-s.cpp](01_Estructuras/Mo/mo-s.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/Mo's.cpp](../Nicolas/3%20Data%20Structures/Mo's.cpp).

Contenedores estándar y sin límites externos sin declarar.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll, vl.

## 01_Estructuras/Ordered_Set_PBDS

### [multiorderedset.cpp](01_Estructuras/Ordered_Set_PBDS/multiorderedset.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/MultiOrderedSet.cpp](../Nicolas/3%20Data%20Structures/MultiOrderedSet.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.
- Includes adicionales protegidos de las macros de la plantilla.

Requisitos y observaciones:

- El comparador less_equal del original no cumple el orden estricto requerido por PBDS. Compilar no valida este truco; preferir claves (valor,id) en la selección posterior.

### [orderedset.cpp](01_Estructuras/Ordered_Set_PBDS/orderedset.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/OrderedSet.cpp](../Nicolas/3%20Data%20Structures/OrderedSet.cpp).

PBDS con comparador estricto y protección frente a la macro int.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.
- Includes adicionales protegidos de las macros de la plantilla.

## 01_Estructuras/Rope

### [rope.cpp](01_Estructuras/Rope/rope.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/Rope.cpp](../Nicolas/3%20Data%20Structures/Rope.cpp).

Ejemplo adaptado a bucles normales y cout.

Adaptaciones:

- F0R, sz, pr y ps reemplazados por bucles, size y cout.
- Includes adicionales protegidos de las macros de la plantilla.

## 01_Estructuras/Segment_Tree/Basico

### [general-segtree.cpp](01_Estructuras/Segment_Tree/Basico/general-segtree.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/query/general_segtree.cpp](../Nicolas/query/general_segtree.cpp).

Núcleo simple con Node/op/e; suma, máximo y XOR se configuran aquí.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

## 01_Estructuras/Segment_Tree/Dinamico

### [lazy-creation.cpp](01_Estructuras/Segment_Tree/Dinamico/lazy-creation.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/data structures/lazy creation.cpp](../pacha/data%20structures/lazy%20creation.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

## 01_Estructuras/Segment_Tree/Dos_dimensiones

### [segment-tree-2d.cpp](01_Estructuras/Segment_Tree/Dos_dimensiones/segment-tree-2d.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/Segment Tree 2D.cpp](../Nicolas/3%20Data%20Structures/Segment%20Tree%202D.cpp).

Una implementación autocontenida para rectángulos.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

## 01_Estructuras/Segment_Tree/Lazy

### [general-lazy-tree.cpp](01_Estructuras/Segment_Tree/Lazy/general-lazy-tree.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/General Lazy Tree.cpp](../Nicolas/3%20Data%20Structures/General%20Lazy%20Tree.cpp).

Conserva Node/Func para mínimo; distinto contrato del lazy de suma.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Inicializar todos los valores con update antes de sumar en rangos: el neutro INT64_MAX no admite incrementos positivos.

### [iterative-lazytree.cpp](01_Estructuras/Segment_Tree/Lazy/iterative-lazytree.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/Iterative Lazytree.cpp](../Nicolas/3%20Data%20Structures/Iterative%20Lazytree.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Operaciones de bits/ensamblador: revisar ancho de palabra (32/64 bits) y el caso cero; preservar tipos explícitos cuando el algoritmo lo exige.
- Para max_right/min_left usar tamaño potencia de dos y predicado monótono que cumpla g(e()).

### [lazy-st1.cpp](01_Estructuras/Segment_Tree/Lazy/lazy-st1.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/range_queries/lazy_st1.cpp](../Alex/range_queries/lazy_st1.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [polynomial-sum-lazy-segtree-problem.cpp](01_Estructuras/Segment_Tree/Lazy/polynomial-sum-lazy-segtree-problem.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/A. To Order/Polynomial Sum Lazy SegTree Problem.cpp](../Nicolas/A.%20To%20Order/Polynomial%20Sum%20Lazy%20SegTree%20Problem.cpp).

Actualización por progresión aritmética; no equivalente al incremento constante.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

### [segment-tree-lazy-vasito.cpp](01_Estructuras/Segment_Tree/Lazy/segment-tree-lazy-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/data_structures/segment_tree_lazy.cpp](../vasito/data_structures/segment_tree_lazy.cpp).

Suma en rangos con incremento de rangos; prueba aleatoria contra vector.

## 01_Estructuras/Segment_Tree/Merge_Sort_Tree

### [merge-sort-tree.cpp](01_Estructuras/Segment_Tree/Merge_Sort_Tree/merge-sort-tree.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/A. To Order/Merge Sort Tree.cpp](../Nicolas/A.%20To%20Order/Merge%20Sort%20Tree.cpp).

Implementación con sus contenedores declarados.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.

## 01_Estructuras/Segment_Tree/Persistente

### [persistantsegmenttree.cpp](01_Estructuras/Segment_Tree/Persistente/persistantsegmenttree.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/PersistantSegmentTree.cpp](../Nicolas/3%20Data%20Structures/PersistantSegmentTree.cpp).

Versiones históricas en vectores; compila con la plantilla.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

## 01_Estructuras/Sparse_Table

### [spare-table.cpp](01_Estructuras/Sparse_Table/spare-table.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/range_queries/spare_table.cpp](../Alex/range_queries/spare_table.cpp).

Código basado en int/vector; una tabla idempotente configurable.

Requisitos y observaciones:

- Operaciones de bits/ensamblador: revisar ancho de palabra (32/64 bits) y el caso cero; preservar tipos explícitos cuando el algoritmo lo exige.

### [sparse-table-2d.cpp](01_Estructuras/Sparse_Table/sparse-table-2d.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/range_queries/sparse_table_2d.cpp](../Alex/range_queries/sparse_table_2d.cpp).

Variante multidimensional distinta de la tabla 1D.

## 01_Estructuras/Treap

### [persistent-treap.cpp](01_Estructuras/Treap/persistent-treap.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/data structures/Persistent Treap.cpp](../pacha/data%20structures/Persistent%20Treap.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [treap-implicit-father-vasito.cpp](01_Estructuras/Treap/treap-implicit-father-vasito.cpp)

**Requiere integración** · fragmento. Origen: [vasito/data_structures/treap_implicit_father.cpp](../vasito/data_structures/treap_implicit_father.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Primeros errores detectados:

- `variable or field 'merge' declared void`
- `'pitem' was not declared in this scope`
- `'t' was not declared in this scope; did you mean 'tm'?`

### [treap-implicit-vasito.cpp](01_Estructuras/Treap/treap-implicit-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/data_structures/treap_implicit.cpp](../vasito/data_structures/treap_implicit.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Formatos de scanf/printf ajustados al tipo real diagnosticado por GCC bajo int = long long.

Requisitos y observaciones:

- E/S C: revisar formatos contra los tipos de 64 bits; ver diagnóstico -Wformat. No activar fast si se mezcla con cin/cout.

### [treap.cpp](01_Estructuras/Treap/treap.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/data structures/treap.cpp](../pacha/data%20structures/treap.cpp).

Mantiene orden por valor; una sola implementación.

## 01_Estructuras/Trie_persistente

### [persistent-trie.cpp](01_Estructuras/Trie_persistente/persistent-trie.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/data structures/Persistent Trie.cpp](../pacha/data%20structures/Persistent%20Trie.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

## 01_Estructuras/Wavelet_Tree

### [wavelet-tree-vasito.cpp](01_Estructuras/Wavelet_Tree/wavelet-tree-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/data_structures/wavelet_tree.cpp](../vasito/data_structures/wavelet_tree.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

## 02_Grafos/Arbol_expansion_minima

### [chu-liu-vasito.cpp](02_Grafos/Arbol_expansion_minima/chu-liu-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/graphs/chu_liu.cpp](../vasito/graphs/chu_liu.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [kruskal.cpp](02_Grafos/Arbol_expansion_minima/kruskal.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/4 Graphs/Kruskal.cpp](../Nicolas/4%20Graphs/Kruskal.cpp).

Compila sin arrastrar una segunda implementación independiente de DSU.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.

### [prim-extra.cpp](02_Grafos/Arbol_expansion_minima/prim-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Graphs/Prim.cpp](../extra/Graphs/Prim.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).
- Alias de tipos ausentes declarados localmente: ll.

## 02_Grafos/Articulaciones_puentes_biconexas

### [articulation-bridges-biconnected-extra.cpp](02_Grafos/Articulaciones_puentes_biconexas/articulation-bridges-biconnected-extra.cpp)

**Requiere integración** · fragmento. Origen: [extra/Graphs/Articulation Bridges Biconnected.cpp](../extra/Graphs/Articulation%20Bridges%20Biconnected.cpp).

Una implementación reúne las tres operaciones; conserva requisitos de integración.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).

Primeros errores detectados:

- `'tree' was not declared in this scope; did you mean 'free'?`
- `'id' was not declared in this scope`
- `'comps' was not declared in this scope; did you mean 'comp'?`

### [tarjan-y-blockcuttree.cpp](02_Grafos/Articulaciones_puentes_biconexas/tarjan-y-blockcuttree.cpp)

**Requiere integración** · fragmento. Origen: [pacha/graphs/Tarjan y BlockCutTree.cpp](../pacha/graphs/Tarjan%20y%20BlockCutTree.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Corregido typo vectotr.
- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

Primeros errores detectados:

- `'IS_CUTPOINT' was not declared in this scope`
- `'IS_BRIDGE' was not declared in this scope`
- `'cutpoint' was not declared in this scope`

## 02_Grafos/Caminos_eulerianos

### [eulerian-path.cpp](02_Grafos/Caminos_eulerianos/eulerian-path.cpp)

**Requiere integración** · fragmento. Origen: [pacha/graphs/eulerian-path.cpp](../pacha/graphs/eulerian-path.cpp).

Una variante del recorrido por aristas.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'MAXN' was not declared in this scope`
- `'g' was not declared in this scope`

## 02_Grafos/Caminos_minimos/Bellman_Ford

### [bellman-ford-extra.cpp](02_Grafos/Caminos_minimos/Bellman_Ford/bellman-ford-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Graphs/Bellman Ford.cpp](../extra/Graphs/Bellman%20Ford.cpp).

Autocontenida, con int y vector.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (2 líneas).
- Alias de tipos ausentes declarados localmente: ll, pii.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [bellmanford-find-negative-cycle.cpp](02_Grafos/Caminos_minimos/Bellman_Ford/bellmanford-find-negative-cycle.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/4 Graphs/Shortest Path/BellmanFord Find Negative Cycle.cpp](../Nicolas/4%20Graphs/Shortest%20Path/BellmanFord%20Find%20Negative%20Cycle.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

## 02_Grafos/Caminos_minimos/Dijkstra

### [dijkstra-extra.cpp](02_Grafos/Caminos_minimos/Dijkstra/dijkstra-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Graphs/Dijkstra.cpp](../extra/Graphs/Dijkstra.cpp).

Autocontenida, sin macros adicionales de recorridos.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).
- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [dijkstra-k-shortest-path.cpp](02_Grafos/Caminos_minimos/Dijkstra/dijkstra-k-shortest-path.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/4 Graphs/Shortest Path/Dijkstra K-Shortest Path.cpp](../Nicolas/4%20Graphs/Shortest%20Path/Dijkstra%20K-Shortest%20Path.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

## 02_Grafos/Caminos_minimos/Floyd_Warshall

### [floyd-warshall-extra.cpp](02_Grafos/Caminos_minimos/Floyd_Warshall/floyd-warshall-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Graphs/Floyd Warshall.cpp](../extra/Graphs/Floyd%20Warshall.cpp).

Implementación directa sobre la plantilla.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [floyd-warshall-negative-weights.cpp](02_Grafos/Caminos_minimos/Floyd_Warshall/floyd-warshall-negative-weights.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/4 Graphs/Shortest Path/Floyd Warshall Negative Weights.cpp](../Nicolas/4%20Graphs/Shortest%20Path/Floyd%20Warshall%20Negative%20Weights.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
- El ejemplo original no lee/inicializa n ni m antes de reservar dist; completar la entrada antes de ejecutarlo.

## 02_Grafos/Conectividad_dinamica

### [dynamic-connectivity.cpp](02_Grafos/Conectividad_dinamica/dynamic-connectivity.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/Dynamic Connectivity.cpp](../Nicolas/3%20Data%20Structures/Dynamic%20Connectivity.cpp).

Interfaz encapsulada y compatible con la plantilla.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

## 02_Grafos/Dominadores

### [dominator-tree.cpp](02_Grafos/Dominadores/dominator-tree.cpp)

**Requiere integración** · fragmento. Origen: [pacha/graphs/dominator_tree.cpp](../pacha/graphs/dominator_tree.cpp).

Una variante; conserva los requisitos de integración del original.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'tam' was not declared in this scope; did you mean 'tm'?`

## 02_Grafos/Orden_topologico

### [topological-sort.cpp](02_Grafos/Orden_topologico/topological-sort.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/4 Graphs/Topological Sort.cpp](../Nicolas/4%20Graphs/Topological%20Sort.cpp).

Usa contenedores estándar y compila con la plantilla.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 02_Grafos/Recorridos_y_conectividad

### [bfs-extra.cpp](02_Grafos/Recorridos_y_conectividad/bfs-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Graphs/BFS.cpp](../extra/Graphs/BFS.cpp).

Recorrido básico autocontenido.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (2 líneas).
- Alias de tipos ausentes declarados localmente: ll.

### [bipartite-check-extra.cpp](02_Grafos/Recorridos_y_conectividad/bipartite-check-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Graphs/Bipartite Check.cpp](../extra/Graphs/Bipartite%20Check.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).

### [cycle-detection-extra.cpp](02_Grafos/Recorridos_y_conectividad/cycle-detection-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Graphs/Cycle Detection.cpp](../extra/Graphs/Cycle%20Detection.cpp).

Una implementación específica de detección.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).

### [dfs-extra.cpp](02_Grafos/Recorridos_y_conectividad/dfs-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Graphs/DFS.cpp](../extra/Graphs/DFS.cpp).

Recorrido básico con contenedores declarados.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (2 líneas).

### [flood-fill-extra.cpp](02_Grafos/Recorridos_y_conectividad/flood-fill-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Graphs/Flood Fill.cpp](../extra/Graphs/Flood%20Fill.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (2 líneas).

### [parallel-dfs-vasito.cpp](02_Grafos/Recorridos_y_conectividad/parallel-dfs-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/graphs/parallel_dfs.cpp](../vasito/graphs/parallel_dfs.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [transitive-closure.cpp](02_Grafos/Recorridos_y_conectividad/transitive-closure.cpp)

**Requiere integración** · fragmento. Origen: [Nicolas/4 Graphs/Transitive Closure.cpp](../Nicolas/4%20Graphs/Transitive%20Closure.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'n' was not declared in this scope; did you mean 'yn'?`
- `'n' was not declared in this scope`
- `invalid types '<unresolved overloaded function type>[long long int]' for array subscript`

## 02_Grafos/SCC_y_2SAT

### [or-statements-like-2-sat-problem.cpp](02_Grafos/SCC_y_2SAT/or-statements-like-2-sat-problem.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/A. To Order/Or Statements like 2 Sat Problem.cpp](../Nicolas/A.%20To%20Order/Or%20Statements%20like%202%20Sat%20Problem.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

### [strongly-connected-components.cpp](02_Grafos/SCC_y_2SAT/strongly-connected-components.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/4 Graphs/Strongly Connected Components.cpp](../Nicolas/4%20Graphs/Strongly%20Connected%20Components.cpp).

Clase con vectores e interfaz explícita.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl, vvl.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [two-sat.cpp](02_Grafos/SCC_y_2SAT/two-sat.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/4 Graphs/Two Sat.cpp](../Nicolas/4%20Graphs/Two%20Sat.cpp).

Interfaz encapsulada; no depende de macros de otro notebook.

## 02_Grafos/Secuencias_de_grados

### [erdos-gallai.cpp](02_Grafos/Secuencias_de_grados/erdos-gallai.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/graphs/erdos gallai.cpp](../pacha/graphs/erdos%20gallai.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

## 02_Grafos/Teoria

### [theorems.cpp](02_Grafos/Teoria/theorems.cpp)

**Apunte** · apunte. Origen: [Alex/graph_theory/theorems.cpp](../Alex/graph_theory/theorems.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.

## 03_Arboles/DSU_on_Tree

### [dsu-on-tree-sack-extra.cpp](03_Arboles/DSU_on_Tree/dsu-on-tree-sack-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Data structures/Dsu on Tree (Sack).cpp](../extra/Data%20structures/Dsu%20on%20Tree%20(Sack).cpp).

Patrón Sack general; no confundir con UnionFind.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (3 líneas).

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 03_Arboles/Descomposicion_SQRT

### [block-tree.cpp](03_Arboles/Descomposicion_SQRT/block-tree.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/Block Tree.cpp](../Nicolas/3%20Data%20Structures/Block%20Tree.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

## 03_Arboles/Descomposicion_centroide

### [centroid-decomposition-extra.cpp](03_Arboles/Descomposicion_centroide/centroid-decomposition-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Data structures/Centroid Decomposition.cpp](../extra/Data%20structures/Centroid%20Decomposition.cpp).

Una descomposición que además soporta actualización y consulta de distancia.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
- Antes de build, dimensionar c_ans a N con N como infinito; inicializar dep y dist. Las consultas esperan nodos previamente marcados con upd.

## 03_Arboles/Euler_Tour

### [euler-tour-sum.cpp](03_Arboles/Euler_Tour/euler-tour-sum.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/6 Tree/Euler Tour - Sum.cpp](../Nicolas/6%20Tree/Euler%20Tour%20-%20Sum.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Dependencias: [Nicolas/3 Data Structures/Fenwick Tree.cpp](01_Estructuras/Fenwick/fenwick-tree.cpp).

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.
- Dependencias del mismo origen incluidas explícitamente: Nicolas/3 Data Structures/Fenwick Tree.cpp.

## 03_Arboles/Heavy_Light

### [hld-lca-con-heavy-paths.cpp](03_Arboles/Heavy_Light/hld-lca-con-heavy-paths.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/data structures/HLD LCA con heavy paths.cpp](../pacha/data%20structures/HLD%20LCA%20con%20heavy%20paths.cpp).

Implementación que compila con la plantilla.

## 03_Arboles/Isomorfismo_y_hashing

### [tree-isomorphism-extra.cpp](03_Arboles/Isomorfismo_y_hashing/tree-isomorphism-extra.cpp)

**Requiere integración** · fragmento. Origen: [extra/Graphs/Tree Isomorphism.cpp](../extra/Graphs/Tree%20Isomorphism.cpp).

Una implementación del reconocimiento de isomorfismo; revisar requisitos indicados.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (2 líneas).
- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `too many arguments to function 'int rand()'`
- `'N' was not declared in this scope`
- `'sum' was not declared in this scope`

## 03_Arboles/LCA_y_binary_lifting

### [binary-lifting-o-n-memory.cpp](03_Arboles/LCA_y_binary_lifting/binary-lifting-o-n-memory.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/graphs/binary lifting O(n) memory.cpp](../pacha/graphs/binary%20lifting%20O(n)%20memory.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [lca-multiplication-path.cpp](03_Arboles/LCA_y_binary_lifting/lca-multiplication-path.cpp)

**Sintaxis OK** · programa. Origen: [Alex/graph_theory/lca_multiplication_path.cpp](../Alex/graph_theory/lca_multiplication_path.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Usa fast de simple.cpp en lugar de la macro hana.

Requisitos y observaciones:

- Contiene main de ejemplo/prueba: usar su main o el de simple.cpp, nunca ambos.
- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [lowest-common-ancestor.cpp](03_Arboles/LCA_y_binary_lifting/lowest-common-ancestor.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/6 Tree/Lowest Common Ancestor.cpp](../Nicolas/6%20Tree/Lowest%20Common%20Ancestor.cpp).

Implementación con vectores; incluye salto de ancestros.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vvl.

Requisitos y observaciones:

- Árbol dirigido de padre a hijos, raíz 0. LOG=18 limita los saltos; kParent requiere k<=depth[x]. Aumentar LOG según n.

### [max-weight-lca.cpp](03_Arboles/LCA_y_binary_lifting/max-weight-lca.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/graphs/max weight lca.cpp](../pacha/graphs/max%20weight%20lca.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Accesos abreviados a pair reemplazados por first/second, sin macros auxiliares.
- Alias de tipos ausentes declarados localmente: pii.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 03_Arboles/Link_Cut_Tree

### [link-cut.cpp](03_Arboles/Link_Cut_Tree/link-cut.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/data structures/link-cut.cpp](../pacha/data%20structures/link-cut.cpp).

Una implementación de bosque dinámico.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

## 03_Arboles/Mo_en_arboles

### [mo-s-in-tree-s.cpp](03_Arboles/Mo_en_arboles/mo-s-in-tree-s.cpp)

**Sintaxis OK** · programa. Origen: [Nicolas/A. To Order/Mo's in Tree's.cpp](../Nicolas/A.%20To%20Order/Mo's%20in%20Tree's.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Formatos de scanf/printf ajustados al tipo real diagnosticado por GCC bajo int = long long.

Requisitos y observaciones:

- E/S C: revisar formatos contra los tipos de 64 bits; ver diagnóstico -Wformat. No activar fast si se mezcla con cin/cout.
- Contiene main de ejemplo/prueba: usar su main o el de simple.cpp, nunca ambos.
- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 03_Arboles/Problemas

### [nearest-selected-nodes-problem.cpp](03_Arboles/Problemas/nearest-selected-nodes-problem.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/A. To Order/Nearest Selected Nodes Problem.cpp](../Nicolas/A.%20To%20Order/Nearest%20Selected%20Nodes%20Problem.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl, vvl.

### [two-pieces-on-tree-problem.cpp](03_Arboles/Problemas/two-pieces-on-tree-problem.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/A. To Order/Two Pieces on Tree (Problem).cpp](../Nicolas/A.%20To%20Order/Two%20Pieces%20on%20Tree%20(Problem).cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll, vl, vvl.

## 03_Arboles/Rerooting

### [re-rooting.cpp](03_Arboles/Rerooting/re-rooting.cpp)

**Requiere integración** · fragmento. Origen: [Alex/graph_theory/re-rooting.cpp](../Alex/graph_theory/re-rooting.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Primeros errores detectados:

- `'grafo' was not declared in this scope`
- `'dp' was not declared in this scope; did you mean 'p'?`
- `'maxi' was not declared in this scope`

## 04_DP/Cambio_de_monedas

### [coin-change-large-n.cpp](04_DP/Cambio_de_monedas/coin-change-large-n.cpp)

**Requiere integración** · programa. Origen: [Alex/techniques/coin_change.cpp](../Alex/techniques/coin_change.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Contiene main de ejemplo/prueba: usar su main o el de simple.cpp, nunca ambos.
- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'m' was not declared in this scope`
- `'INF' was not declared in this scope`

### [coin-change.cpp](04_DP/Cambio_de_monedas/coin-change.cpp)

**Requiere integración** · fragmento. Origen: [Nicolas/2 DP/Typical Problems/Coin Change.cpp](../Nicolas/2%20DP/Typical%20Problems/Coin%20Change.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll, vl.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'inf' was not declared in this scope; did you mean 'sinf'?`

## 04_DP/Contribuciones_XOR

### [sum-of-xor-subarrays-times-its-size-problem.cpp](04_DP/Contribuciones_XOR/sum-of-xor-subarrays-times-its-size-problem.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/A. To Order/Sum of xor Subarrays times its size Problem.cpp](../Nicolas/A.%20To%20Order/Sum%20of%20xor%20Subarrays%20times%20its%20size%20Problem.cpp).

Programa con sus dependencias declaradas.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 04_DP/Digit_DP

### [digit-dp.cpp](04_DP/Digit_DP/digit-dp.cpp)

**Requiere integración** · fragmento. Origen: [Alex/techniques/digit_dp.cpp](../Alex/techniques/digit_dp.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'N' was not declared in this scope`
- `'dp' was not declared in this scope; did you mean 'd'?`

## 04_DP/LCS_y_distancia_edicion

### [lcs-lis.cpp](04_DP/LCS_y_distancia_edicion/lcs-lis.cpp)

**Añadido** · Longitud de LCS por posiciones y LIS. O(N log N) para permutaciones de tamaño N; en general O((n+m+r) log(m+2)), con r pares coincidentes. Acepta strings y vectores, incluidos repetidos. Memoria O(m).

### [lcs-bitset.cpp](04_DP/LCS_y_distancia_edicion/lcs-bitset.cpp)

**Añadido** · Longitud de LCS para strings generales mediante bloques uint64_t. O(m + (n+256)·ceil(m/64)), con m la longitud menor; sin límite fijo de 20. No es O(N log N) general.

Ver [condiciones de uso y pruebas](04_DP/LCS_y_distancia_edicion/README.md). Ambas versiones son compatibles con `00_Template/simple.cpp` y devuelven la longitud, sin reconstrucción.

### [edit-distance.cpp](04_DP/LCS_y_distancia_edicion/edit-distance.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/Typical Problems/Edit Distance.cpp](../Nicolas/2%20DP/Typical%20Problems/Edit%20Distance.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl, vvl.
- Se conserva la DP O(n*m); eliminada la alternativa recursiva exponencial.

### [longest-common-subsequence-3.cpp](04_DP/LCS_y_distancia_edicion/longest-common-subsequence-3.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/Typical Problems/Longest Common Subsequence 3.cpp](../Nicolas/2%20DP/Typical%20Problems/Longest%20Common%20Subsequence%203.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [longest-common-subsequence.cpp](04_DP/LCS_y_distancia_edicion/longest-common-subsequence.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/Typical Problems/Longest Common Subsequence.cpp](../Nicolas/2%20DP/Typical%20Problems/Longest%20Common%20Subsequence.cpp).

Versión simple; LCS de tres secuencias permanece aparte.

## 04_DP/LIS

La versión seleccionada ya calcula la longitud de la LIS estrictamente creciente en **O(N log N)** con `lower_bound` y memoria O(N). Para subsecuencia no decreciente, usar `upper_bound` como indica su comentario. Ver [pruebas LIS/LCS](04_DP/LCS_y_distancia_edicion/README.md).

### [longest-increasing-subsequence.cpp](04_DP/LIS/longest-increasing-subsequence.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/Longest Increasing Subsequence.cpp](../Nicolas/2%20DP/Longest%20Increasing%20Subsequence.cpp).

Contenedores estándar y compilación comprobada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: vl.

## 04_DP/Mascaras_y_SOS

### [dp-mask-over-submasks.cpp](04_DP/Mascaras_y_SOS/dp-mask-over-submasks.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/DP Mask Over Submasks.cpp](../Nicolas/2%20DP/DP%20Mask%20Over%20Submasks.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.

### [sos-dp.cpp](04_DP/Mascaras_y_SOS/sos-dp.cpp)

**Requiere integración** · fragmento. Origen: [Nicolas/2 DP/SOS DP.cpp](../Nicolas/2%20DP/SOS%20DP.cpp).

Un esquema de transformada; inversa/supermáscaras se conserva por separado.

Requisitos y observaciones:

- M y dp; pegar el bucle dentro de solve() o una función.
- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `expected unqualified-id before 'for'`
- `'M' was not declared in this scope`

### [sos-dp-reverse.cpp](04_DP/Mascaras_y_SOS/sos-dp-reverse.cpp)

**Requiere integración** · fragmento. Origen: [Nicolas/2 DP/SOS DP - Reverse.cpp](../Nicolas/2%20DP/SOS%20DP%20-%20Reverse.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- n, M y vectores; pegar el bloque dentro de solve().

Primeros errores detectados:

- `'n' was not declared in this scope; did you mean 'yn'?`
- `expected unqualified-id before 'for'`

## 04_DP/Mascaras_y_TSP

### [elevator-problem.cpp](04_DP/Mascaras_y_TSP/elevator-problem.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/Typical Problems/Elevator Problem.cpp](../Nicolas/2%20DP/Typical%20Problems/Elevator%20Problem.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.

### [traveling-sales-man-cycle.cpp](04_DP/Mascaras_y_TSP/traveling-sales-man-cycle.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/Typical Problems/Traveling Sales Man (Cycle).cpp](../Nicolas/2%20DP/Typical%20Problems/Traveling%20Sales%20Man%20(Cycle).cpp).

Una implementación; conteo de caminos hamiltonianos es un problema distinto.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll, vl, vvl.

### [traveling-sales-man-path.cpp](04_DP/Mascaras_y_TSP/traveling-sales-man-path.cpp)

**Requiere integración** · fragmento. Origen: [Nicolas/2 DP/Typical Problems/Traveling Sales Man (Path).cpp](../Nicolas/2%20DP/Typical%20Problems/Traveling%20Sales%20Man%20(Path).cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl, vvl.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'MOD' was not declared in this scope`

## 04_DP/Notas

### [dp.cpp](04_DP/Notas/dp.cpp)

**Apunte** · apunte. Origen: [Alex/techniques/dp.cpp](../Alex/techniques/dp.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.

## 04_DP/Optimizaciones/CHT_y_Li_Chao

### [convex-hull-trick-extra.cpp](04_DP/Optimizaciones/CHT_y_Li_Chao/convex-hull-trick-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Data structures/Convex Hull Trick.cpp](../extra/Data%20structures/Convex%20Hull%20Trick.cpp).

Precondiciones y complejidad distintas del dinámico.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).
- Alias de tipos ausentes declarados localmente: ll.

### [convex-hull-trick.cpp](04_DP/Optimizaciones/CHT_y_Li_Chao/convex-hull-trick.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/Convex Hull Trick.cpp](../Nicolas/2%20DP/Convex%20Hull%20Trick.cpp).

LineContainer autocontenido; evita macros adicionales.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [li-chao-tree-vasito.cpp](04_DP/Optimizaciones/CHT_y_Li_Chao/li-chao-tree-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/data_structures/li_chao_tree.cpp](../vasito/data_structures/li_chao_tree.cpp).

Conserva inserción de segmentos además de rectas.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [persistent-convex-hull-trick.cpp](04_DP/Optimizaciones/CHT_y_Li_Chao/persistent-convex-hull-trick.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/data structures/persistent convex hull trick.cpp](../pacha/data%20structures/persistent%20convex%20hull%20trick.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

## 04_DP/Optimizaciones/Divide_and_Conquer

### [divide-and-conquer.cpp](04_DP/Optimizaciones/Divide_and_Conquer/divide-and-conquer.cpp)

**Requiere integración** · fragmento. Origen: [pacha/dp/Divide and conquer.cpp](../pacha/dp/Divide%20and%20conquer.cpp).

Una implementación; el apunte no aporta una segunda versión ejecutable.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
- El comentario anuncia mínimo, pero el cuerpo usa max y centinela -1. Ajustar objetivo, centinela, tam y función de coste juntos.

Primeros errores detectados:

- `'tam' was not declared in this scope; did you mean 'tm'?`
- `'lastDP' was not declared in this scope`

## 04_DP/Optimizaciones/Knuth

### [knuths-optimization.cpp](04_DP/Optimizaciones/Knuth/knuths-optimization.cpp)

**Requiere integración** · fragmento. Origen: [Nicolas/2 DP/Knuths Optimization.cpp](../Nicolas/2%20DP/Knuths%20Optimization.cpp).

Versión con estructura de DP explícita; requiere función de coste.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'n' was not declared in this scope; did you mean 'yn'?`
- `'nums' was not declared in this scope`
- `'pf' was not declared in this scope; did you mean 'pb'?`

## 04_DP/Optimizaciones/Mochila

### [multiple-knacksack-optimizacion.cpp](04_DP/Optimizaciones/Mochila/multiple-knacksack-optimizacion.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/Multiple Knacksack Optimizacion.cpp](../Nicolas/2%20DP/Multiple%20Knacksack%20Optimizacion.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Variable vs renombrada a nb_vs para no colisionar con vector<string> de la plantilla.
- Alias de tipos ausentes declarados localmente: ll, vl.

Requisitos y observaciones:

- El original intercambia valor y peso al descomponer objetos; revisar/corregir antes de usar.

## 04_DP/Optimizaciones/Separacion

### [separation-optimization.cpp](04_DP/Optimizaciones/Separacion/separation-optimization.cpp)

**Apunte** · apunte. Origen: [Nicolas/2 DP/Separation Optimization.cpp](../Nicolas/2%20DP/Separation%20Optimization.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.

## 04_DP/Steiner_Tree

### [steiner-tree.cpp](04_DP/Steiner_Tree/steiner-tree.cpp)

**Requiere integración** · fragmento. Origen: [pacha/data structures/steiner_tree.cpp](../pacha/data%20structures/steiner_tree.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'N' was not declared in this scope`
- `'T' was not declared in this scope`
- `'dist' was not declared in this scope`

## 04_DP/Subarreglos_y_submatrices

### [max-sum-1d.cpp](04_DP/Subarreglos_y_submatrices/max-sum-1d.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/Typical Problems/Max Sum 1D.cpp](../Nicolas/2%20DP/Typical%20Problems/Max%20Sum%201D.cpp).

Una implementación, distinta de 2D/3D.

### [max-sum-2d.cpp](04_DP/Subarreglos_y_submatrices/max-sum-2d.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/Typical Problems/Max Sum 2D.cpp](../Nicolas/2%20DP/Typical%20Problems/Max%20Sum%202D.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [max-sum-3d.cpp](04_DP/Subarreglos_y_submatrices/max-sum-3d.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/Typical Problems/Max Sum 3D.cpp](../Nicolas/2%20DP/Typical%20Problems/Max%20Sum%203D.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Dimensiones globales de la matriz declaradas const.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [min-max-range-extra.cpp](04_DP/Subarreglos_y_submatrices/min-max-range-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Dynamic programming/Min Max Range.cpp](../extra/Dynamic%20programming/Min%20Max%20Range.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).
- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- El original carece de return ans, inicializa ans a -1 para minimizar y recurre con i+1 aunque el corte termina en j: revisar transición e inicialización antes de usar.
- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 05_Flujos_y_matching/Corte_minimo

### [min-cut.cpp](05_Flujos_y_matching/Corte_minimo/min-cut.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/5 Flow/Min Cut.cpp](../Nicolas/5%20Flow/Min%20Cut.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Dependencias: [Nicolas/5 Flow/Max Flow.cpp](05_Flujos_y_matching/Flujo_maximo/max-flow.cpp).

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vvl.
- Dependencias del mismo origen incluidas explícitamente: Nicolas/5 Flow/Max Flow.cpp.

### [stoer-wagner-extra.cpp](05_Flujos_y_matching/Corte_minimo/stoer-wagner-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Network flows/Stoer Wagner.cpp](../extra/Network%20flows/Stoer%20Wagner.cpp).

Versión que compila; distinto del corte fuente-sumidero.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).

## 05_Flujos_y_matching/Flujo_costo_minimo

### [min-cost-max-flow-vasito.cpp](05_Flujos_y_matching/Flujo_costo_minimo/min-cost-max-flow-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/flow/min_cost_max_flow.cpp](../vasito/flow/min_cost_max_flow.cpp).

Implementación que compila con la plantilla.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll.

## 05_Flujos_y_matching/Flujo_maximo

### [max-flow.cpp](05_Flujos_y_matching/Flujo_maximo/max-flow.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/5 Flow/Max Flow.cpp](../Nicolas/5%20Flow/Max%20Flow.cpp).

Usa int/vi/pb; lo reutiliza el ejemplo de corte mínimo.

Adaptaciones:

- Ejemplo renombrado para que Min Cut pueda incluir Dinitz sin duplicar test_case.
- Nombres que chocan con macros renombrados con prefijo nb_: S.
- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 05_Flujos_y_matching/Hopcroft_Karp

### [hopcroft-karp.cpp](05_Flujos_y_matching/Hopcroft_Karp/hopcroft-karp.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/flow/hopcroft-karp.cpp](../pacha/flow/hopcroft-karp.cpp).

Versión autocontenida para matching bipartito.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 05_Flujos_y_matching/Hungaro

### [hungarian.cpp](05_Flujos_y_matching/Hungaro/hungarian.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/5 Flow/Hungarian.cpp](../Nicolas/5%20Flow/Hungarian.cpp).

Una asignación ponderada; interfaz compatible con la plantilla.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 05_Flujos_y_matching/Matching_bipartito

### [kuhn.cpp](05_Flujos_y_matching/Matching_bipartito/kuhn.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/flow/kuhn.cpp](../pacha/flow/kuhn.cpp).

Versión simple de caminos aumentantes.

## 05_Flujos_y_matching/Matching_general

### [blossom-extra.cpp](05_Flujos_y_matching/Matching_general/blossom-extra.cpp)

**Requiere integración** · fragmento. Origen: [extra/Network flows/Blossom.cpp](../extra/Network%20flows/Blossom.cpp).

Matching general; no sustituible por matching bipartito.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).

Primeros errores detectados:

- `'MAXE' was not declared in this scope`
- `'pool' was not declared in this scope; did you mean 'powl'?`

## 06_Matematicas/Algebra_lineal/Base_XOR

### [xor-basis.cpp](06_Matematicas/Algebra_lineal/Base_XOR/xor-basis.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/3 Data Structures/Xor Basis.cpp](../Nicolas/3%20Data%20Structures/Xor%20Basis.cpp).

Contenedores y tipos locales; sin macros externas.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

## 06_Matematicas/Algebra_lineal/Matrices_y_Gauss

### [gauss.cpp](06_Matematicas/Algebra_lineal/Matrices_y_Gauss/gauss.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/math/gauss.cpp](../pacha/math/gauss.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [gaussian-function.cpp](06_Matematicas/Algebra_lineal/Matrices_y_Gauss/gaussian-function.cpp)

**Requiere integración** · fragmento. Origen: [Alex/maths/gaussian_function.cpp](../Alex/maths/gaussian_function.cpp).

Preserva las dos aritméticas distintas; evita otra eliminación modular con parámetros externos.

Adaptaciones:

- Gauss modular y XOR, no eliminación real con double.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
- Gauss modular requiere divide/sub/mul/add; Gauss XOR requiere N. La comprobación final XOR original usa ans[i] para i<n y debe revisar consistencia de las filas reducidas.

Primeros errores detectados:

- `'divide' was not declared in this scope`
- `'mul' was not declared in this scope`
- `'sub' was not declared in this scope`

### [matrix-determinant.cpp](06_Matematicas/Algebra_lineal/Matrices_y_Gauss/matrix-determinant.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/math/matrix-determinant.cpp](../pacha/math/matrix-determinant.cpp).

La misma eliminación real, con tolerancia declarada.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [matrix-fast-pow.cpp](06_Matematicas/Algebra_lineal/Matrices_y_Gauss/matrix-fast-pow.cpp)

**Requiere integración** · fragmento. Origen: [pacha/dp/matrix-fast-pow.cpp](../pacha/dp/matrix-fast-pow.cpp).

Una implementación para potencia matricial.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'sz' was not declared in this scope`
- `'m' was not declared in this scope`
- `'z' was not declared in this scope`

### [matrix-multiplication-extra.cpp](06_Matematicas/Algebra_lineal/Matrices_y_Gauss/matrix-multiplication-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Modular arithmetic/Matrix Multiplication.cpp](../extra/Modular%20arithmetic/Matrix%20Multiplication.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).
- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 06_Matematicas/Aritmetica_modular/CRT

### [chinese-remainder-theorem-extra.cpp](06_Matematicas/Aritmetica_modular/CRT/chinese-remainder-theorem-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Modular arithmetic/Chinese Remainder Theorem.cpp](../extra/Modular%20arithmetic/Chinese%20Remainder%20Theorem.cpp).

Reutiliza el único Euclides extendido seleccionado.

Dependencias: [extra/Math/Extended Euclides.cpp](06_Matematicas/Teoria_de_numeros/Euclides/extended-euclides-extra.cpp).

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (4 líneas).
- Alias de tipos ausentes declarados localmente: pii.
- Dependencias del mismo origen incluidas explícitamente: extra/Math/Extended Euclides.cpp.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 06_Matematicas/Aritmetica_modular/Logaritmo_discreto

### [discrete-log.cpp](06_Matematicas/Aritmetica_modular/Logaritmo_discreto/discrete-log.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/1 Math/Modular Arithmethics/Discrete Log.cpp](../Nicolas/1%20Math/Modular%20Arithmethics/Discrete%20Log.cpp).

Interfaz autocontenida, sin proveedor adicional de exponenciación.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).
- Alias de tipos ausentes declarados localmente: ll.

## 06_Matematicas/Aritmetica_modular/Operaciones

### [big-expontent-modular-exponentiation.cpp](06_Matematicas/Aritmetica_modular/Operaciones/big-expontent-modular-exponentiation.cpp)

**Requiere integración** · fragmento. Origen: [Nicolas/1 Math/Modular Arithmethics/Big Expontent Modular Exponentiation.cpp](../Nicolas/1%20Math/Modular%20Arithmethics/Big%20Expontent%20Modular%20Exponentiation.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'MOD' was not declared in this scope`

### [fraction-modular.cpp](06_Matematicas/Aritmetica_modular/Operaciones/fraction-modular.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/A. To Order/Fraction Modular.cpp](../Nicolas/A.%20To%20Order/Fraction%20Modular.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [modular-exponentiation-extra.cpp](06_Matematicas/Aritmetica_modular/Operaciones/modular-exponentiation-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Modular arithmetic/Modular Exponentiation.cpp](../extra/Modular%20arithmetic/Modular%20Exponentiation.cpp).

Función autocontenida; reutilizada por inversos y raíces primitivas.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (2 líneas).

### [modular-inverse-extra.cpp](06_Matematicas/Aritmetica_modular/Operaciones/modular-inverse-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Modular arithmetic/Modular Inverse.cpp](../extra/Modular%20arithmetic/Modular%20Inverse.cpp).

Cubre módulo coprimo general y módulo primo con funciones diferenciadas.

Dependencias: [extra/Math/Extended Euclides.cpp](06_Matematicas/Teoria_de_numeros/Euclides/extended-euclides-extra.cpp), [extra/Modular arithmetic/Modular Exponentiation.cpp](06_Matematicas/Aritmetica_modular/Operaciones/modular-exponentiation-extra.cpp).

Adaptaciones:

- Variantes con Euclides y Fermat preservadas como invmod e invmod_primo.
- Texto explicativo original convertido a comentarios C++ (2 líneas).
- Alias de tipos ausentes declarados localmente: ll.
- Dependencias del mismo origen incluidas explícitamente: extra/Math/Extended Euclides.cpp; extra/Modular arithmetic/Modular Exponentiation.cpp.

### [modular-multiplication-extra.cpp](06_Matematicas/Aritmetica_modular/Operaciones/modular-multiplication-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Modular arithmetic/Modular Multiplication.cpp](../extra/Modular%20arithmetic/Modular%20Multiplication.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).
- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- La fórmula original usa overflow signed en a*b; requiere reemplazo por __int128 para aritmética definida en todo el rango positivo de int64.

## 06_Matematicas/Aritmetica_modular/Raices

### [primitive-root-extra.cpp](06_Matematicas/Aritmetica_modular/Raices/primitive-root-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Modular arithmetic/Primitive Root.cpp](../extra/Modular%20arithmetic/Primitive%20Root.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Dependencias: [extra/Modular arithmetic/Modular Exponentiation.cpp](06_Matematicas/Aritmetica_modular/Operaciones/modular-exponentiation-extra.cpp).

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (3 líneas).
- Dependencias del mismo origen incluidas explícitamente: extra/Modular arithmetic/Modular Exponentiation.cpp.

### [tonelly-shanks.cpp](06_Matematicas/Aritmetica_modular/Raices/tonelly-shanks.cpp)

**Requiere integración** · fragmento. Origen: [pacha/math/tonelly shanks.cpp](../pacha/math/tonelly%20shanks.cpp).

Una implementación; se conservan sus requisitos de integración.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Operaciones de bits/ensamblador: revisar ancho de palabra (32/64 bits) y el caso cero; preservar tipos explícitos cuando el algoritmo lo exige.

Primeros errores detectados:

- `'fpow' was not declared in this scope; did you mean 'pow'?`
- `'rnd' was not declared in this scope; did you mean 'rand'?`
- `'t' was not declared in this scope`

## 06_Matematicas/Combinatoria

### [catalan-convolution.cpp](06_Matematicas/Combinatoria/catalan-convolution.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/1 Math/Catalan Convolution.cpp](../Nicolas/1%20Math/Catalan%20Convolution.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [catalan.cpp](06_Matematicas/Combinatoria/catalan.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/1 Math/Catalan.cpp](../Nicolas/1%20Math/Catalan.cpp).

Evaluación de Catalan, separada de convolución de Catalan.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [combinatorics.cpp](06_Matematicas/Combinatoria/combinatorics.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/1 Math/Combinatorics.cpp](../Nicolas/1%20Math/Combinatorics.cpp).

Una implementación para combinaciones sin módulo; estrellas y barras usa la misma operación.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

### [modular-combinatorics.cpp](06_Matematicas/Combinatoria/modular-combinatorics.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/1 Math/Modular Arithmethics/Modular Combinatorics.cpp](../Nicolas/1%20Math/Modular%20Arithmethics/Modular%20Combinatorics.cpp).

Precomputación factorial/inversos para combinaciones módulo primo.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll, vl.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [stirling-y-bell.cpp](06_Matematicas/Combinatoria/stirling-y-bell.cpp)

**Requiere integración** · fragmento. Origen: [pacha/math/stirling y bell.cpp](../pacha/math/stirling%20y%20bell.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'tam' was not declared in this scope; did you mean 'tm'?`
- `'stir' was not declared in this scope`

### [subfactorial.cpp](06_Matematicas/Combinatoria/subfactorial.cpp)

**Requiere integración** · fragmento. Origen: [Nicolas/1 Math/SubFactorial.cpp](../Nicolas/1%20Math/SubFactorial.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'MOD' was not declared in this scope`

## 06_Matematicas/Fibonacci_y_Pisano

### [fibonacci-mod-m-extra.cpp](06_Matematicas/Fibonacci_y_Pisano/fibonacci-mod-m-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Modular arithmetic/Fibonacci mod m.cpp](../extra/Modular%20arithmetic/Fibonacci%20mod%20m.cpp).

Función sin matrices auxiliares externas.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).
- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Operaciones de bits/ensamblador: revisar ancho de palabra (32/64 bits) y el caso cero; preservar tipos explícitos cuando el algoritmo lo exige.

### [pisano-period-extra.cpp](06_Matematicas/Fibonacci_y_Pisano/pisano-period-extra.cpp)

**Requiere integración** · fragmento. Origen: [extra/Modular arithmetic/Pisano Period.cpp](../extra/Modular%20arithmetic/Pisano%20Period.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (2 líneas).
- Alias de tipos ausentes declarados localmente: ll.

Primeros errores detectados:

- `'expmod' was not declared in this scope; did you mean 'expm1l'?`

## 06_Matematicas/Josephus

### [josephus.cpp](06_Matematicas/Josephus/josephus.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/math/josephus.cpp](../pacha/math/josephus.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.
- Una sola recurrencia de Josephus, posiciones desde 1; O(n) y pila O(n).

## 06_Matematicas/Metodos_numericos

### [fraction-extra.cpp](06_Matematicas/Metodos_numericos/fraction-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Math/Fraction.cpp](../extra/Math/Fraction.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).
- Alias de tipos ausentes declarados localmente: ll.

### [simpson.cpp](06_Matematicas/Metodos_numericos/simpson.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/math/simpson.cpp](../pacha/math/simpson.cpp).

Copias de la misma técnica de integración numérica.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

### [stablesum.cpp](06_Matematicas/Metodos_numericos/stablesum.cpp)

**Requiere integración** · fragmento. Origen: [pacha/geometry/stableSum.cpp](../pacha/geometry/stableSum.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Primeros errores detectados:

- `'pref' was not declared in this scope; did you mean 'prefs'?`

## 06_Matematicas/Polinomios_y_transformadas

### [bairstow-vasito.cpp](06_Matematicas/Polinomios_y_transformadas/bairstow-vasito.cpp)

**Requiere integración** · fragmento. Origen: [vasito/math/bairstow.cpp](../vasito/math/bairstow.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'poly' was not declared in this scope`
- `expected primary-expression before '>' token`
- `'p' was not declared in this scope; did you mean 'pb'?`

### [fast-hadamard-transform.cpp](06_Matematicas/Polinomios_y_transformadas/fast-hadamard-transform.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/1 Math/FFT/Fast Hadamard Transform.cpp](../Nicolas/1%20Math/FFT/Fast%20Hadamard%20Transform.cpp).

Transformada XOR/AND/OR, distinta de FFT y NTT.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll, vl.

Requisitos y observaciones:

- Operaciones de bits/ensamblador: revisar ancho de palabra (32/64 bits) y el caso cero; preservar tipos explícitos cuando el algoritmo lo exige.
- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [fft.cpp](06_Matematicas/Polinomios_y_transformadas/fft.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/maths/fft.cpp](../Alex/maths/fft.cpp).

Variante compacta que compila con la plantilla.

### [fft-operations-vasito.cpp](06_Matematicas/Polinomios_y_transformadas/fft-operations-vasito.cpp)

**Requiere integración** · fragmento. Origen: [vasito/math/fft_operations.cpp](../vasito/math/fft_operations.cpp).

Una biblioteca de operaciones; conserva dependencia de FFT.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
- Necesita proveedor con API poly/multiply/fft del mismo diseño; no basta pegar la FFT de Alex por nombre.

Primeros errores detectados:

- `'poly' does not name a type`

### [fft-shifts-trick.cpp](06_Matematicas/Polinomios_y_transformadas/fft-shifts-trick.cpp)

**Requiere integración** · fragmento. Origen: [Nicolas/1 Math/FFT/FFT Shifts trick.cpp](../Nicolas/1%20Math/FFT/FFT%20Shifts%20trick.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- actual, answer y multiply; pegar el bloque dentro de solve().

Primeros errores detectados:

- `'actual' was not declared in this scope`
- `expected constructor, destructor, or type conversion before '(' token`
- `reference to 'copy' is ambiguous`

### [interpol-o-n-ex.cpp](06_Matematicas/Polinomios_y_transformadas/interpol-o-n-ex.cpp)

**Requiere integración** · fragmento. Origen: [pacha/math/interpol o(n) ex.cpp](../pacha/math/interpol%20o(n)%20ex.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll, vll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'tam' was not declared in this scope; did you mean 'tm'?`
- `'MOD' was not declared in this scope`

### [karatsuba-vasito.cpp](06_Matematicas/Polinomios_y_transformadas/karatsuba-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/math/karatsuba.cpp](../vasito/math/karatsuba.cpp).

Versión sobre coeficientes enteros; el módulo puede aplicarse al resultado.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll.

### [ntt-vasito.cpp](06_Matematicas/Polinomios_y_transformadas/ntt-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/math/ntt.cpp](../vasito/math/ntt.cpp).

Transformada modular validada mediante convolución ingenua.

Adaptaciones:

- min/max con argumentos enteros mixtos tipados explícitamente como long long para la plantilla.
- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Requiere compilador GNU con enteros de 128 bits.

### [poly-definitions.cpp](06_Matematicas/Polinomios_y_transformadas/poly-definitions.cpp)

**Apunte** · apunte. Origen: [Nicolas/A. To Order/Poly Definitions.cpp](../Nicolas/A.%20To%20Order/Poly%20Definitions.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.

### [polynomial-vasito.cpp](06_Matematicas/Polinomios_y_transformadas/polynomial-vasito.cpp)

**Requiere integración** · fragmento. Origen: [vasito/math/polynomial.cpp](../vasito/math/polynomial.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Nombres que chocan con macros renombrados con prefijo nb_: S.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'EPS' was not declared in this scope`

## 06_Matematicas/Programacion_lineal

### [simplex.cpp](06_Matematicas/Programacion_lineal/simplex.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/maths/simplex.cpp](../Alex/maths/simplex.cpp).

Implementación que compila bajo la plantilla.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [simplex-integer-extra.cpp](06_Matematicas/Programacion_lineal/simplex-integer-extra.cpp)

**Apunte** · apunte. Origen: [extra/Math/Simplex integer.cpp](../extra/Math/Simplex%20integer.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.
- Instrucciones de modificación del Simplex racional, no una implementación independiente.
- Texto explicativo original convertido a comentarios C++ (2 líneas).

## 06_Matematicas/Recurrencias_lineales

### [berlekamp-massey-vasito.cpp](06_Matematicas/Recurrencias_lineales/berlekamp-massey-vasito.cpp)

**Requiere integración** · fragmento. Origen: [vasito/math/berlekamp_massey.cpp](../vasito/math/berlekamp_massey.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll, ld.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'MOD' was not declared in this scope`
- `'fast_pow' was not declared in this scope`

### [linear-recurrence-cayley-halmiton.cpp](06_Matematicas/Recurrencias_lineales/linear-recurrence-cayley-halmiton.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/Linear Recurrence Cayley Halmiton.cpp](../Nicolas/2%20DP/Linear%20Recurrence%20Cayley%20Halmiton.cpp).

Evaluación por polinomio característico; evita matrices cuando no son necesarias.

Adaptaciones:

- Nombres que chocan con macros renombrados con prefijo nb_: S.
- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [linear-recurrence-matrix-exponciation.cpp](06_Matematicas/Recurrencias_lineales/linear-recurrence-matrix-exponciation.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/Linear Recurrence Matrix Exponciation.cpp](../Nicolas/2%20DP/Linear%20Recurrence%20Matrix%20Exponciation.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 06_Matematicas/Sumas_de_pisos

### [floor-division-vasito.cpp](06_Matematicas/Sumas_de_pisos/floor-division-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/math/floor_division.cpp](../vasito/math/floor_division.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

### [floor-sums.cpp](06_Matematicas/Sumas_de_pisos/floor-sums.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/1 Math/Floor Sums.cpp](../Nicolas/1%20Math/Floor%20Sums.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [harmonic-lemma.cpp](06_Matematicas/Sumas_de_pisos/harmonic-lemma.cpp)

**Requiere integración** · fragmento. Origen: [pacha/shortcuts/harmonic lemma.cpp](../pacha/shortcuts/harmonic%20lemma.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Primeros errores detectados:

- `expected unqualified-id before 'for'`
- `'i' does not name a type; did you mean 'vi'?`

### [points-under-line-vasito.cpp](06_Matematicas/Sumas_de_pisos/points-under-line-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/math/points_under_line.cpp](../vasito/math/points_under_line.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

### [sqrt-mod.cpp](06_Matematicas/Sumas_de_pisos/sqrt-mod.cpp)

**Requiere integración** · fragmento. Origen: [Nicolas/3 Data Structures/SQRT Mod.cpp](../Nicolas/3%20Data%20Structures/SQRT%20Mod.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- n y nums; el llenado de ch va dentro de solve().

Primeros errores detectados:

- `expected unqualified-id before 'for'`
- `'n' was not declared in this scope; did you mean 'yn'?`

## 06_Matematicas/Teoria_de_numeros/Diofanticas

### [diophantine-ecuations-extra.cpp](06_Matematicas/Teoria_de_numeros/Diofanticas/diophantine-ecuations-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Math/Diophantine Ecuations.cpp](../extra/Math/Diophantine%20Ecuations.cpp).

Reutiliza el mismo proveedor de Euclides extendido.

Dependencias: [extra/Math/Extended Euclides.cpp](06_Matematicas/Teoria_de_numeros/Euclides/extended-euclides-extra.cpp).

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (2 líneas).
- Alias de tipos ausentes declarados localmente: ll.
- Dependencias del mismo origen incluidas explícitamente: extra/Math/Extended Euclides.cpp.

## 06_Matematicas/Teoria_de_numeros/Divisores

### [divisors-extra.cpp](06_Matematicas/Teoria_de_numeros/Divisores/divisors-extra.cpp)

**Requiere integración** · fragmento. Origen: [extra/Math/Divisors.cpp](../extra/Math/Divisors.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Subtítulos explicativos convertidos a comentarios.
- Alias de tipos ausentes declarados localmente: ll.

Primeros errores detectados:

- `'fact' was not declared in this scope; did you mean 'fast'?`
- `no matching function for call to 'exp(const long long int&, long long int)'`

### [divisors-vasito.cpp](06_Matematicas/Teoria_de_numeros/Divisores/divisors-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/math/divisors.cpp](../vasito/math/divisors.cpp).

Función que recibe la factorización; no duplica Pollard Rho.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll.

### [hcn-all-vasito.txt](06_Matematicas/Teoria_de_numeros/Divisores/hcn-all-vasito.txt)

**Recurso** · recurso. Origen: [vasito/other/hcn_all.txt](../vasito/other/hcn_all.txt).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [hcn-vasito.txt](06_Matematicas/Teoria_de_numeros/Divisores/hcn-vasito.txt)

**Recurso** · recurso. Origen: [vasito/other/hcn.txt](../vasito/other/hcn.txt).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

## 06_Matematicas/Teoria_de_numeros/Euclides

### [extended-euclides-extra.cpp](06_Matematicas/Teoria_de_numeros/Euclides/extended-euclides-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Math/Extended Euclides.cpp](../extra/Math/Extended%20Euclides.cpp).

Proveedor único para las diofánticas, CRT e inverso modular seleccionados.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).

### [fast-gcd.cpp](06_Matematicas/Teoria_de_numeros/Euclides/fast-gcd.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/math/fast-gcd.cpp](../pacha/math/fast-gcd.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Revisar casos cero, productos y desplazamientos antes de usar en el rango completo de 64 bits.
- Operaciones de bits/ensamblador: revisar ancho de palabra (32/64 bits) y el caso cero; preservar tipos explícitos cuando el algoritmo lo exige.
- Adaptación de 64 bits: __builtin_ctz debe ser __builtin_ctzll. Usar entradas no negativas y tratar el cero antes del builtin.

### [greatest-common-divisor-extra.cpp](06_Matematicas/Teoria_de_numeros/Euclides/greatest-common-divisor-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Math/Greatest Common Divisor.cpp](../extra/Math/Greatest%20Common%20Divisor.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).

### [lowest-common-multiple-extra.cpp](06_Matematicas/Teoria_de_numeros/Euclides/lowest-common-multiple-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Math/Lowest Common Multiple.cpp](../extra/Math/Lowest%20Common%20Multiple.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).

## 06_Matematicas/Teoria_de_numeros/Funciones_multiplicativas

### [euler-totient.cpp](06_Matematicas/Teoria_de_numeros/Funciones_multiplicativas/euler-totient.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/maths/euler_totient.cpp](../Alex/maths/euler_totient.cpp).

Incluye evaluación puntual y tabla; dos interfaces de un mismo algoritmo.

Adaptaciones:

- Separados los nombres phi(n) y phi_tabla[] para conservar ambas variantes.

### [gcd-a-i-a-j-k-text-queries.cpp](06_Matematicas/Teoria_de_numeros/Funciones_multiplicativas/gcd-a-i-a-j-k-text-queries.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/1 Math/Mobius/[gcd(a_i, a_j) == k]text{ Queries}.cpp](../Nicolas/1%20Math/Mobius/%5Bgcd(a_i%2C%20a_j)%20%3D%3D%20k%5D%EF%81%9Ctext%7B%20Queries%7D.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.

### [gcd-i-j-k.cpp](06_Matematicas/Teoria_de_numeros/Funciones_multiplicativas/gcd-i-j-k.cpp)

**Requiere integración** · fragmento. Origen: [Nicolas/1 Math/Mobius/[gcd(i, j) == k].cpp](../Nicolas/1%20Math/Mobius/%5Bgcd(i%2C%20j)%20%3D%3D%20k%5D.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Primeros errores detectados:

- `'mo' was not declared in this scope`

### [linear-sieve.cpp](06_Matematicas/Teoria_de_numeros/Funciones_multiplicativas/linear-sieve.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/1 Math/Mobius/Linear Sieve.cpp](../Nicolas/1%20Math/Mobius/Linear%20Sieve.cpp).

Una criba lineal, distinta de Eratóstenes.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.

### [mobius-inclusion-exclusion-example.tex](06_Matematicas/Teoria_de_numeros/Funciones_multiplicativas/mobius-inclusion-exclusion-example.tex)

**Recurso** · recurso. Origen: [Nicolas/1 Math/Mobius/Mobius Inclusion-Exclusion Example.tex](../Nicolas/1%20Math/Mobius/Mobius%20Inclusion-Exclusion%20Example.tex).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [mobius.cpp](06_Matematicas/Teoria_de_numeros/Funciones_multiplicativas/mobius.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/1 Math/Mobius/Mobius.cpp](../Nicolas/1%20Math/Mobius/Mobius.cpp).

Se conserva solamente la variante lineal del archivo; pruebas contra identidades de divisores.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: vl.
- Seleccionada la variante lineal de Möbius; retirada la alternativa O(n log n).

### [multiplicative-functions.tex](06_Matematicas/Teoria_de_numeros/Funciones_multiplicativas/multiplicative-functions.tex)

**Recurso** · recurso. Origen: [Nicolas/1 Math/Mobius/Multiplicative Functions.tex](../Nicolas/1%20Math/Mobius/Multiplicative%20Functions.tex).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [sigma-n-i-1-frac-n-gcd-i-n.cpp](06_Matematicas/Teoria_de_numeros/Funciones_multiplicativas/sigma-n-i-1-frac-n-gcd-i-n.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/1 Math/Mobius/Sigma^{n}_{i=1} frac{n}{gcd(i,n)}.cpp](../Nicolas/1%20Math/Mobius/%EF%81%9CSigma%5E%7Bn%7D_%7Bi%3D1%7D%20%EF%81%9Cfrac%7Bn%7D%7Bgcd(i%2Cn)%7D.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.

## 06_Matematicas/Teoria_de_numeros/Primos_y_factorizacion

### [count-primes-with-pi-function.cpp](06_Matematicas/Teoria_de_numeros/Primos_y_factorizacion/count-primes-with-pi-function.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/1 Math/Count Primes with PI Function.cpp](../Nicolas/1%20Math/Count%20Primes%20with%20PI%20Function.cpp).

Una implementación completa de pi(n).

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

### [fermat.cpp](06_Matematicas/Teoria_de_numeros/Primos_y_factorizacion/fermat.cpp)

**Apunte** · apunte. Origen: [Nicolas/A. To Order/Fermat.cpp](../Nicolas/A.%20To%20Order/Fermat.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.

### [optimized-polard-rho.cpp](06_Matematicas/Teoria_de_numeros/Primos_y_factorizacion/optimized-polard-rho.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/1 Math/Optimized Polard Rho.cpp](../Nicolas/1%20Math/Optimized%20Polard%20Rho.cpp).

Implementación encapsulada que compila; evita el archivo con dos versiones.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Llamar init_sv(). La multiplicación modular aproximada original tiene overflow signed; reemplazar por __int128 antes de usar valores grandes. rabin no es determinista para todo el rango de 64 bits.

### [prime-factorization-extra.cpp](06_Matematicas/Teoria_de_numeros/Primos_y_factorizacion/prime-factorization-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Math/Prime Factorization.cpp](../extra/Math/Prime%20Factorization.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Subtítulos de variantes convertidos a comentarios.
- Texto explicativo original convertido a comentarios C++ (1 líneas).
- Alias de tipos ausentes declarados localmente: ll.
- Solo división de prueba O(sqrt(n)); Pollard Rho y criba viven en sus archivos propios.

### [prime-numbers.cpp](06_Matematicas/Teoria_de_numeros/Primos_y_factorizacion/prime-numbers.cpp)

**Apunte** · apunte. Origen: [pacha/shortcuts/prime numbers.cpp](../pacha/shortcuts/prime%20numbers.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.

### [sieve.cpp](06_Matematicas/Teoria_de_numeros/Primos_y_factorizacion/sieve.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/maths/sieve.cpp](../Alex/maths/sieve.cpp).

Implementación disponible que compila con la plantilla; revisar rango y bases antes de usar.

Adaptaciones:

- A pesar del nombre sieve, el contenido es Miller-Rabin probabilístico.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
- Requiere compilador GNU con enteros de 128 bits.

### [sieve-of-eratosthenes-extra.cpp](06_Matematicas/Teoria_de_numeros/Primos_y_factorizacion/sieve-of-eratosthenes-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Math/Sieve of Eratosthenes.cpp](../extra/Math/Sieve%20of%20Eratosthenes.cpp).

Una implementación básica autocontenida.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).
- Alias de tipos ausentes declarados localmente: ll.

## 06_Matematicas/Teoria_y_formulas

### [formulas-extra.tex](06_Matematicas/Teoria_y_formulas/formulas-extra.tex)

**Recurso** · recurso. Origen: [extra/Values sequences and results/Formulas.tex](../extra/Values%20sequences%20and%20results/Formulas.tex).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [formulas.cpp](06_Matematicas/Teoria_y_formulas/formulas.cpp)

**Apunte** · apunte. Origen: [pacha/math/formulas.cpp](../pacha/math/formulas.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.

### [in.txt](06_Matematicas/Teoria_y_formulas/in.txt)

**Recurso** · recurso. Origen: [Alex/maths/in](../Alex/maths/in).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [math-concepts.txt](06_Matematicas/Teoria_y_formulas/math-concepts.txt)

**Recurso** · recurso. Origen: [Alex/maths/math_concepts](../Alex/maths/math_concepts).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [pi.cpp](06_Matematicas/Teoria_y_formulas/pi.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/A. To Order/Pi.cpp](../Nicolas/A.%20To%20Order/Pi.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ld.

### [sequences-extra.tex](06_Matematicas/Teoria_y_formulas/sequences-extra.tex)

**Recurso** · recurso. Origen: [extra/Values sequences and results/Sequences.tex](../extra/Values%20sequences%20and%20results/Sequences.tex).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [theo.cpp](06_Matematicas/Teoria_y_formulas/theo.cpp)

**Apunte** · apunte. Origen: [pacha/shortcuts/theo.cpp](../pacha/shortcuts/theo.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.

### [theorems.tex](06_Matematicas/Teoria_y_formulas/theorems.tex)

**Recurso** · recurso. Origen: [Nicolas/1 Math/Theorems.tex](../Nicolas/1%20Math/Theorems.tex).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [theorems-vasito.txt](06_Matematicas/Teoria_y_formulas/theorems-vasito.txt)

**Recurso** · recurso. Origen: [vasito/math/theorems.txt](../vasito/math/theorems.txt).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

## 07_Geometria/Circulos_y_triangulos

### [circle-extra.cpp](07_Geometria/Circulos_y_triangulos/circle-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Geometry/circle.cpp](../extra/Geometry/circle.cpp).

Usa el tipo pt y line seleccionados; incluye intersección y tangencias.

Dependencias: [extra/Geometry/Point.cpp](07_Geometria/Puntos_rectas_y_segmentos/point-extra.cpp), [extra/Geometry/line.cpp](07_Geometria/Puntos_rectas_y_segmentos/line-extra.cpp).

Adaptaciones:

- Dependencias del mismo origen incluidas explícitamente: extra/Geometry/Point.cpp; extra/Geometry/line.cpp.

### [heron-formula.cpp](07_Geometria/Circulos_y_triangulos/heron-formula.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/8. Geometry/Heron Formula.cpp](../Nicolas/8.%20Geometry/Heron%20Formula.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ld.

### [triangles-and-circles.cpp](07_Geometria/Circulos_y_triangulos/triangles-and-circles.cpp)

**Requiere integración** · fragmento. Origen: [pacha/geometry/Triangles and Circles.cpp](../pacha/geometry/Triangles%20and%20Circles.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Errores previos: if(a.b=0) asigna, perp no devuelve res y se escribe l2 dos veces en circumCircle. Revisar fórmulas, tipos y dependencias de rectas/puntos.
- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'line' does not name a type`
- `'point' was not declared in this scope`

## 07_Geometria/Convex_Hull

### [convexhull.cpp](07_Geometria/Convex_Hull/convexhull.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/geometry/convexhull.cpp](../Alex/geometry/convexhull.cpp).

Código compacto con int y vector; evita dependencias geométricas externas.

## 07_Geometria/Delaunay_y_Voronoi

### [stanford-delaunay.cpp](07_Geometria/Delaunay_y_Voronoi/stanford-delaunay.cpp)

**Sintaxis OK** · programa. Origen: [pacha/geometry/stanford delaunay.cpp](../pacha/geometry/stanford%20delaunay.cpp).

Variante que compila con la plantilla; considerar su complejidad antes de usar.

Adaptaciones:

- Formatos de scanf/printf ajustados al tipo real diagnosticado por GCC bajo int = long long.
- Includes adicionales protegidos de las macros de la plantilla.

Requisitos y observaciones:

- E/S C: revisar formatos contra los tipos de 64 bits; ver diagnóstico -Wformat. No activar fast si se mezcla con cin/cout.
- Contiene main de ejemplo/prueba: usar su main o el de simple.cpp, nunca ambos.

### [voronoy.cpp](07_Geometria/Delaunay_y_Voronoi/voronoy.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/geometry/voronoy.cpp](../pacha/geometry/voronoy.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 07_Geometria/Grafos_planares

### [planar-graph-dual.cpp](07_Geometria/Grafos_planares/planar-graph-dual.cpp)

**Requiere integración** · fragmento. Origen: [pacha/geometry/planar graph dual.cpp](../pacha/geometry/planar%20graph%20dual.cpp).

Copias del mismo procedimiento.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ii.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'tam' was not declared in this scope; did you mean 'tm'?`
- `'pt' was not declared in this scope; did you mean 'ps'?`
- `template argument 1 is invalid`

## 07_Geometria/Minkowski

### [minkowski-sum-of-convex-polygons.cpp](07_Geometria/Minkowski/minkowski-sum-of-convex-polygons.cpp)

**Requiere integración** · fragmento. Origen: [pacha/geometry/Minkowski sum of convex polygons.cpp](../pacha/geometry/Minkowski%20sum%20of%20convex%20polygons.cpp).

Una implementación para suma de polígonos convexos.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll.

Primeros errores detectados:

- `'point' was not declared in this scope`
- `template argument 1 is invalid`
- `template argument 2 is invalid`

## 07_Geometria/Poligonos

### [centroide.cpp](07_Geometria/Poligonos/centroide.cpp)

**Requiere integración** · fragmento. Origen: [pacha/geometry/centroide.cpp](../pacha/geometry/centroide.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

Primeros errores detectados:

- `'point' does not name a type; did you mean 'int'?`

### [lattice-points.cpp](07_Geometria/Poligonos/lattice-points.cpp)

**Requiere integración** · fragmento. Origen: [pacha/geometry/Lattice points.cpp](../pacha/geometry/Lattice%20points.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'EPS' was not declared in this scope`
- `'point' was not declared in this scope`
- `expected ',' or ';' before '{' token`

### [point-in-convex-polygon.cpp](07_Geometria/Poligonos/point-in-convex-polygon.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/8. Geometry/Point in Convex Polygon.cpp](../Nicolas/8.%20Geometry/Point%20in%20Convex%20Polygon.cpp).

Consulta logarítmica autocontenida.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

### [point-in-general-polygon.cpp](07_Geometria/Poligonos/point-in-general-polygon.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/8. Geometry/Point In General Polygon.cpp](../Nicolas/8.%20Geometry/Point%20In%20General%20Polygon.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [polygon-diameter.cpp](07_Geometria/Poligonos/polygon-diameter.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/8. Geometry/Polygon Diameter.cpp](../Nicolas/8.%20Geometry/Polygon%20Diameter.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

### [polygon-extra.cpp](07_Geometria/Poligonos/polygon-extra.cpp)

**Requiere integración** · fragmento. Origen: [extra/Geometry/polygon.cpp](../extra/Geometry/polygon.cpp).

Colección con dependencias en la base geométrica seleccionada.

Dependencias: [extra/Geometry/Point.cpp](07_Geometria/Puntos_rectas_y_segmentos/point-extra.cpp), [extra/Geometry/segment.cpp](07_Geometria/Puntos_rectas_y_segmentos/segment-extra.cpp), [extra/Geometry/line.cpp](07_Geometria/Puntos_rectas_y_segmentos/line-extra.cpp).

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, pii.
- Dependencias del mismo origen incluidas explícitamente: extra/Geometry/Point.cpp; extra/Geometry/segment.cpp; extra/Geometry/line.cpp.

Primeros errores detectados:

- `'line' was not declared in this scope`
- `'l' was not declared in this scope`

## 07_Geometria/Proximidad_y_KD_Tree

### [closest-pair-of-points.cpp](07_Geometria/Proximidad_y_KD_Tree/closest-pair-of-points.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/8. Geometry/Closest Pair Of Points.cpp](../Nicolas/8.%20Geometry/Closest%20Pair%20Of%20Points.cpp).

Implementación con tipos y contenedores locales.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, ld.

### [kdtree.cpp](07_Geometria/Proximidad_y_KD_Tree/kdtree.cpp)

**Requiere integración** · programa. Origen: [pacha/data structures/kdtree.cpp](../pacha/data%20structures/kdtree.cpp).

Una estructura espacial; distinta de la búsqueda offline del par más cercano.

Requisitos y observaciones:

- Contiene main de ejemplo/prueba: usar su main o el de simple.cpp, nunca ambos.
- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'maxlongint' was not declared in this scope`
- `'xr' was not declared in this scope; did you mean 'zr'?`
- `'maxc' was not declared in this scope; did you mean 'maxn'?`

### [nearest-neighbour.cpp](07_Geometria/Proximidad_y_KD_Tree/nearest-neighbour.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/geometry/nearest neighbour.cpp](../pacha/geometry/nearest%20neighbour.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
- El corte por coordenadas no distingue puntos idénticos; resolver duplicados antes de recursión para evitar una partición vacía.

## 07_Geometria/Puntos_rectas_y_segmentos

### [line-extra.cpp](07_Geometria/Puntos_rectas_y_segmentos/line-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Geometry/line.cpp](../extra/Geometry/line.cpp).

Usa la base geométrica seleccionada.

Dependencias: [extra/Geometry/Point.cpp](07_Geometria/Puntos_rectas_y_segmentos/point-extra.cpp).

Adaptaciones:

- Dependencias del mismo origen incluidas explícitamente: extra/Geometry/Point.cpp.

### [point-extra.cpp](07_Geometria/Puntos_rectas_y_segmentos/point-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Geometry/Point.cpp](../extra/Geometry/Point.cpp).

Base compartida por rectas, círculos y semiplanos; no duplicar tipos de punto incompatibles.

Adaptaciones:

- Conservadas ambas variantes: angle_no_orientado usa acos; angle usa atan2 y es la requerida por angle360.
- La resta de puntos es const para usarse en el comparador de orden radial.

### [radial-order-vasito.cpp](07_Geometria/Puntos_rectas_y_segmentos/radial-order-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/geometry/radial_order.cpp](../vasito/geometry/radial_order.cpp).

Reutiliza directamente el tipo pt seleccionado.

Dependencias: [extra/Geometry/Point.cpp](07_Geometria/Puntos_rectas_y_segmentos/point-extra.cpp).

Adaptaciones:

- Orden radial compatible con pt de la base geométrica elegida.
- Reutiliza extra/Geometry/Point.cpp como proveedor único.

### [segment-extra.cpp](07_Geometria/Puntos_rectas_y_segmentos/segment-extra.cpp)

**Requiere integración** · fragmento. Origen: [extra/Geometry/segment.cpp](../extra/Geometry/segment.cpp).

Usa la base geométrica seleccionada.

Dependencias: [extra/Geometry/Point.cpp](07_Geometria/Puntos_rectas_y_segmentos/point-extra.cpp).

Adaptaciones:

- Dependencias del mismo origen incluidas explícitamente: extra/Geometry/Point.cpp.

Primeros errores detectados:

- `'line' was not declared in this scope`
- `'l' was not declared in this scope`

### [segment-intersection.cpp](07_Geometria/Puntos_rectas_y_segmentos/segment-intersection.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/8. Geometry/Segment Intersection.cpp](../Nicolas/8.%20Geometry/Segment%20Intersection.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ld.

## 07_Geometria/Semiplanos

### [halfplanes-extra.cpp](07_Geometria/Semiplanos/halfplanes-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Geometry/halfplanes.cpp](../extra/Geometry/halfplanes.cpp).

Reutiliza pt seleccionado.

Dependencias: [extra/Geometry/Point.cpp](07_Geometria/Puntos_rectas_y_segmentos/point-extra.cpp).

Adaptaciones:

- Dependencias del mismo origen incluidas explícitamente: extra/Geometry/Point.cpp.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 07_Geometria/Teoria_y_formulas

### [some-formulas.tex](07_Geometria/Teoria_y_formulas/some-formulas.tex)

**Recurso** · recurso. Origen: [Nicolas/8. Geometry/Some Formulas.tex](../Nicolas/8.%20Geometry/Some%20Formulas.tex).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

## 07_Geometria/Geometria_3D

### [a-geo3d-esencial.cpp](07_Geometria/Geometria_3D/a-geo3d-esencial.cpp)

**Añadido** · PARTE A. `P3<T>` (`Point3` long double, `IPoint3` exacto), punto/cruz/triple en `__int128`, `orient`, colineal/coplanar, distancias, Manhattan/Chebyshev, MCD y direcciones, rotaciones de 90° y las 24/48 del cubo, `Mat3`, Rodrigues, `Mat4`, `Frame`. Exacto con |coord| ≤ 1e9.

### [b-geo3d-solidos.cpp](07_Geometria/Geometria_3D/b-geo3d-solidos.cpp)

**Añadido** · PARTE B (incluye A). Cajas alineadas (intersección, contacto, inclusión-exclusión, unión de N), `Pref3`/`Diff3`, voxeles, rectas y segmentos (alabeadas), planos (`Plane`, `IPlane` exacto), triángulos, tetraedros, esferas (incluye la esfera mínima) y mallas.

### [c-geo3d-avanzado.cpp](07_Geometria/Geometria_3D/c-geo3d-avanzado.cpp)

**Añadido** · PARTE C (incluye B). Envolvente convexa 3D exacta O(n²) con duplicados, colineales y coplanares; par más cercano 3D O(n) esperado; triángulo-triángulo exacto; OBB con SAT; rayo-malla; tetraedro mínimo por un punto.

Ver la [guía, la tabla «¿Qué uso?» y la priorización](07_Geometria/Geometria_3D/README.md), el [cheat sheet](07_Geometria/Geometria_3D/cheat-sheet-3d.md) y los [problemas](07_Geometria/Geometria_3D/problemas-3d.md). Pruebas: [_pruebas/geometria-3d.cpp](_pruebas/geometria-3d.cpp), 136 325 comprobaciones contra fuerza bruta, compiladas con GNU G++20 y sin avisos.

## 07_Geometria/Tres_dimensiones

### [latlong.cpp](07_Geometria/Tres_dimensiones/latlong.cpp)

**Sintaxis OK** · programa. Origen: [pacha/geometry/latlong.cpp](../pacha/geometry/latlong.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Includes adicionales protegidos de las macros de la plantilla.

Requisitos y observaciones:

- Contiene main de ejemplo/prueba: usar su main o el de simple.cpp, nunca ambos.

### [plane-vasito.cpp](07_Geometria/Tres_dimensiones/plane-vasito.cpp)

**Requiere integración** · fragmento. Origen: [vasito/geometry/plane.cpp](../vasito/geometry/plane.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Necesita una versión 3D de pt con z y producto cruzado; point.cpp del origen es 2D por defecto.
- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'pt' does not name a type; did you mean 'pb'?`
- `expected ')' before 'a'`
- `'pt' has not been declared`

## 08_Busqueda_y_ordenamiento/Busqueda_binaria_paralela

### [parallel-binary-search.cpp](08_Busqueda_y_ordenamiento/Busqueda_binaria_paralela/parallel-binary-search.cpp)

**Requiere integración** · fragmento. Origen: [pacha/other/parallel_binary search.cpp](../pacha/other/parallel_binary%20search.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: vl.

Primeros errores detectados:

- `expected primary-expression before ')' token`

## 08_Busqueda_y_ordenamiento/Busqueda_ternaria

### [ternary-search.cpp](08_Busqueda_y_ordenamiento/Busqueda_ternaria/ternary-search.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/other/ternary search.cpp](../pacha/other/ternary%20search.cpp).

Un archivo con variantes para dominios continuo/discreto.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.
- Función objetivo recibida como parámetro; máximo inicial válido para valores negativos; precisión configurable.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 08_Busqueda_y_ordenamiento/Divide_and_Conquer

### [divide-and-conquer.cpp](08_Busqueda_y_ordenamiento/Divide_and_Conquer/divide-and-conquer.cpp)

**Requiere integración** · fragmento. Origen: [Alex/techniques/divide_and_conquer.cpp](../Alex/techniques/divide_and_conquer.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
- Alias de tipos ausentes declarados localmente: ll.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'N' was not declared in this scope`
- `variable or field 'dc' declared void`
- `'vcor' was not declared in this scope`

## 08_Busqueda_y_ordenamiento/Greedy_y_comparadores

### [exchange-argument.cpp](08_Busqueda_y_ordenamiento/Greedy_y_comparadores/exchange-argument.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/sorting/exchange_argument.cpp](../Alex/sorting/exchange_argument.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

## 08_Busqueda_y_ordenamiento/Merge_sort_e_inversiones

### [merge-sort.cpp](08_Busqueda_y_ordenamiento/Merge_sort_e_inversiones/merge-sort.cpp)

**Requiere integración** · fragmento. Origen: [pacha/other/merge sort.cpp](../pacha/other/merge%20sort.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- La línea ans.resize(v.size()) se ejecuta dentro de solve(), antes de mergesort.

Primeros errores detectados:

- `'ans' does not name a type`

## 08_Strings/Aho_Corasick

### [ahocorasik.cpp](08_Strings/Aho_Corasick/ahocorasik.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/strings/ahocorasik.cpp](../Alex/strings/ahocorasik.cpp).

Versión compatible con int/vector; dinámica es un algoritmo distinto.

### [dinamic-aho-corasick.cpp](08_Strings/Aho_Corasick/dinamic-aho-corasick.cpp)

**Requiere integración** · fragmento. Origen: [pacha/strings/Dinamic Aho Corasick.cpp](../pacha/strings/Dinamic%20Aho%20Corasick.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'tam' was not declared in this scope; did you mean 'tm'?`
- `'node' was not declared in this scope; did you mean 'nnode'?`
- `'mem' was not declared in this scope`

## 08_Strings/Hashing

### [fast-hashing.cpp](08_Strings/Hashing/fast-hashing.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/7. Strings/Fast Hashing.cpp](../Nicolas/7.%20Strings/Fast%20Hashing.cpp).

Una implementación doble modular en lugar de alternativas incompatibles de hash.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

## 08_Strings/KMP

### [kmp-automaton.cpp](08_Strings/KMP/kmp-automaton.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/7. Strings/KMP Automaton.cpp](../Nicolas/7.%20Strings/KMP%20Automaton.cpp).

Autómata explícito; capacidad distinta de la búsqueda KMP simple.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

### [kmp-vasito.cpp](08_Strings/KMP/kmp-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/strings/kmp.cpp](../vasito/strings/kmp.cpp).

Una implementación de prefijos y búsqueda, ya verificada funcionalmente.

Adaptaciones:

- Formatos de scanf/printf ajustados al tipo real diagnosticado por GCC bajo int = long long.
- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

Requisitos y observaciones:

- E/S C: revisar formatos contra los tipos de 64 bits; ver diagnóstico -Wformat. No activar fast si se mezcla con cin/cout.

## 08_Strings/Manacher

### [manacher.cpp](08_Strings/Manacher/manacher.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/strings/manacher.cpp](../Alex/strings/manacher.cpp).

Implementación que compila con la plantilla.

## 08_Strings/Palindromic_Tree

### [palindromic-tree.cpp](08_Strings/Palindromic_Tree/palindromic-tree.cpp)

**Sintaxis OK** · fragmento. Origen: [Alex/strings/palindromic_tree.cpp](../Alex/strings/palindromic_tree.cpp).

Una implementación; no sustituye a Manacher.

Adaptaciones:

- min/max con argumentos enteros mixtos tipados explícitamente como long long para la plantilla.
- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

## 08_Strings/Rotacion_minima

### [minimum-expression-extra.cpp](08_Strings/Rotacion_minima/minimum-expression-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Strings/Minimum Expression.cpp](../extra/Strings/Minimum%20Expression.cpp).

Implementación compacta sin dependencias.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (1 líneas).

## 08_Strings/Suffix_Array_y_LCP

### [suffix-array-extra.cpp](08_Strings/Suffix_Array_y_LCP/suffix-array-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Strings/Suffix Array.cpp](../extra/Strings/Suffix%20Array.cpp).

Clase con bucles normales e int; incluye LCP y longest common substring en el mismo archivo.

Adaptaciones:

- La longitud m de la segunda cadena pasa a ser parámetro explícito de lcs(m).
- Alias de tipos ausentes declarados localmente: pii.
- Una clase para SA, LCP y LCS; corregidos accesos fuera de rango al comparar bloques y prefijos. Reservar $ como centinela y # como separador de LCS.

## 08_Strings/Suffix_Automaton

### [suffix-automaton-extra.cpp](08_Strings/Suffix_Automaton/suffix-automaton-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Strings/Suffix Automaton.cpp](../extra/Strings/Suffix%20Automaton.cpp).

Una implementación compatible con la plantilla.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

## 08_Strings/Suffix_Tree

### [suffix-tree-vasito.cpp](08_Strings/Suffix_Tree/suffix-tree-vasito.cpp)

**Requiere integración** · fragmento. Origen: [vasito/strings/suffix_tree.cpp](../vasito/strings/suffix_tree.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.

Primeros errores detectados:

- `'MAXN' was not declared in this scope`

## 08_Strings/Trie

### [trie.cpp](08_Strings/Trie/trie.cpp)

**Requiere integración** · fragmento. Origen: [Alex/strings/trie.cpp](../Alex/strings/trie.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Contiene dominios distintos (letras, bits y comodines) con nombres repetidos y errores de índice/typos del original; requiere separar namespaces, inicializar contadores y completar go/ter.

Primeros errores detectados:

- `expected ';' at end of member declaration`
- `redefinition of 'const long long int MAXSIZE'`
- `redefinition of 'struct node'`

## 08_Strings/Z_Function

### [z-function-vasito.cpp](08_Strings/Z_Function/z-function-vasito.cpp)

**Sintaxis OK** · fragmento. Origen: [vasito/strings/z_function.cpp](../vasito/strings/z_function.cpp).

Función compacta y validada contra comparación directa.

Adaptaciones:

- Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.

## 09_Utilidades/Aleatoriedad

### [randoms.cpp](09_Utilidades/Aleatoriedad/randoms.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/9. Utils/Randoms.cpp](../Nicolas/9.%20Utils/Randoms.cpp).

Generador y distribuciones de la biblioteca estándar.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

## 09_Utilidades/Bits

### [bit-tricks.cpp](09_Utilidades/Bits/bit-tricks.cpp)

**Apunte** · apunte. Origen: [Nicolas/9. Utils/Bit Tricks.cpp](../Nicolas/9.%20Utils/Bit%20Tricks.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.

### [bits-manipulation-extra.cpp](09_Utilidades/Bits/bits-manipulation-extra.cpp)

**Apunte** · apunte. Origen: [extra/Utilities/Bits Manipulation.cpp](../extra/Utilities/Bits%20Manipulation.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.

### [optimizing-pragmas-for-bitset.cpp](09_Utilidades/Bits/optimizing-pragmas-for-bitset.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/2 DP/Optimizing Pragmas For BitSet.cpp](../Nicolas/2%20DP/Optimizing%20Pragmas%20For%20BitSet.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

## 09_Utilidades/CPP

### [ascii-table-extra.tex](09_Utilidades/CPP/ascii-table-extra.tex)

**Recurso** · recurso. Origen: [extra/Values sequences and results/ASCII Table.tex](../extra/Values%20sequences%20and%20results/ASCII%20Table.tex).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [bultin-functions-out-dated.cpp](09_Utilidades/CPP/bultin-functions-out-dated.cpp)

**Apunte** · apunte. Origen: [Nicolas/A. To Order/Bultin functions (out dated).cpp](../Nicolas/A.%20To%20Order/Bultin%20functions%20(out%20dated).cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.

### [cpp-stuff.cpp](09_Utilidades/CPP/cpp-stuff.cpp)

**Apunte** · apunte. Origen: [pacha/shortcuts/cpp stuff.cpp](../pacha/shortcuts/cpp%20stuff.cpp).

Copias del mismo apunte.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.

### [exponential-notation.cpp](09_Utilidades/CPP/exponential-notation.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/9. Utils/Exponential Notation.cpp](../Nicolas/9.%20Utils/Exponential%20Notation.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll.

## 09_Utilidades/Entrada_salida

### [io-int128.cpp](09_Utilidades/Entrada_salida/io-int128.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/9. Utils/IO int128.cpp](../Nicolas/9.%20Utils/IO%20int128.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Una sola salida por cout y entrada por cin, evitando mezclar stdio con fast. Entrada válida dentro del rango signed de 128 bits.

Requisitos y observaciones:

- Requiere compilador GNU con enteros de 128 bits.

### [python-fast-in.py](09_Utilidades/Entrada_salida/python-fast-in.py)

**Recurso** · recurso. Origen: [pacha/shortcuts/python fast in.py](../pacha/shortcuts/python%20fast%20in.py).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [scanf-and-printf-extra.cpp](09_Utilidades/Entrada_salida/scanf-and-printf-extra.cpp)

**Apunte** · apunte. Origen: [extra/Utilities/scanf and printf.cpp](../extra/Utilities/scanf%20and%20printf.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Apunte o implementación comentada; conservado para consulta.

Requisitos y observaciones:

- En simple.cpp int significa long long: usar %lld para esos valores. Los formatos listados describen los tipos nativos.

### [split-string-extra.cpp](09_Utilidades/Entrada_salida/split-string-extra.cpp)

**Sintaxis OK** · fragmento. Origen: [extra/Utilities/Split String.cpp](../extra/Utilities/Split%20String.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Texto explicativo original convertido a comentarios C++ (2 líneas).

### [string-streams.cpp](09_Utilidades/Entrada_salida/string-streams.cpp)

**Requiere integración** · fragmento. Origen: [Nicolas/9. Utils/String Streams.cpp](../Nicolas/9.%20Utils/String%20Streams.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Adaptaciones:

- Alias de tipos ausentes declarados localmente: ll, vl.

Requisitos y observaciones:

- Ejemplo de lectura: el bloque pertenece a solve().

Primeros errores detectados:

- `expected constructor, destructor, or type conversion before '(' token`
- `expected unqualified-id before 'while'`

## 09_Utilidades/Fechas

### [dates.cpp](09_Utilidades/Fechas/dates.cpp)

**Sintaxis OK** · fragmento. Origen: [pacha/shortcuts/dates.cpp](../pacha/shortcuts/dates.cpp).

Copias de la misma implementación.

## 09_Utilidades/Interactivos

### [main.cpp](09_Utilidades/Interactivos/main.cpp)

**Sintaxis OK** · programa. Origen: [Alex/interactive/main.cpp](../Alex/interactive/main.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- Contiene main de ejemplo/prueba: usar su main o el de simple.cpp, nunca ambos.

### [interactive-tester-vasito.py](09_Utilidades/Interactivos/pruebas/interactive-tester-vasito.py)

**Recurso** · recurso. Origen: [vasito/other/interactive_tester.py](../vasito/other/interactive_tester.py).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

## 09_Utilidades/Python

### [decimal-precisition-python.py](09_Utilidades/Python/decimal-precisition-python.py)

**Recurso** · recurso. Origen: [Nicolas/9. Utils/Decimal Precisition Python.py](../Nicolas/9.%20Utils/Decimal%20Precisition%20Python.py).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [python.py](09_Utilidades/Python/python.py)

**Recurso** · recurso. Origen: [pacha/shortcuts/python.py](../pacha/shortcuts/python.py).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

## 09_Utilidades/Rendimiento

### [pragmas.cpp](09_Utilidades/Rendimiento/pragmas.cpp)

**Sintaxis OK** · fragmento. Origen: [Nicolas/9. Utils/Pragmas.cpp](../Nicolas/9.%20Utils/Pragmas.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [time-complexities-extra.tex](09_Utilidades/Rendimiento/time-complexities-extra.tex)

**Recurso** · recurso. Origen: [extra/Values sequences and results/Time Complexities.tex](../extra/Values%20sequences%20and%20results/Time%20Complexities.tex).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

### [while-tle.cpp](09_Utilidades/Rendimiento/while-tle.cpp)

**Requiere integración** · fragmento. Origen: [pacha/shortcuts/while TLE.cpp](../pacha/shortcuts/while%20TLE.cpp).

Tema o variante con contrato propio; sin alternativa equivalente seleccionada.

Requisitos y observaciones:

- El bucle de tiempo va dentro de solve(); definir su trabajo antes de ejecutar.

Primeros errores detectados:

- `expected unqualified-id before 'while'`
