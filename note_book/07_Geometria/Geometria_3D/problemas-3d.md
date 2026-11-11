# PARTE F — Problemas progresivos de geometría 3D

La dificultad es aproximada y relativa a esta lista (★ fácil a ★★★★★ muy difícil); **no** son ratings oficiales.

**Verificación (noviembre de 2026).** Los enunciados de ABC312 E y ABC343 E se leyeron completos. Los demás problemas se comprobaron con búsquedas: título, juez y tema. El enunciado de Gym 104248 G devolvió 403, así que su formato de entrada no está confirmado. Los ejemplos de ABC312 E, ABC343 E y ABC144 D se reprodujeron en [_pruebas/geometria-3d.cpp](../../_pruebas/geometria-3d.cpp).

## Orden recomendado

| # | Problema | Juez | Técnica | ¿Aritmética simple? | Dificultad |
| --- | --- | --- | --- | --- | --- |
| 1 | [ABC361 B — Intersection of Cuboids](https://atcoder.jp/contests/abc361/tasks/abc361_b) | AtCoder | intervalos por eje | sí | ★ |
| 2 | [ABC144 D — Water Bottle](https://atcoder.jp/contests/abc144/tasks/abc144_d) | AtCoder | sección 2D + `atan` | sí | ★★ |
| 3 | [ABC366 D — Cuboid Sum Query](https://atcoder.jp/contests/abc366/tasks/abc366_d) | AtCoder | prefix sums 3D | sí | ★★ |
| 4 | [ABC343 E — 7x7x7](https://atcoder.jp/contests/abc343/tasks/abc343_e) | AtCoder | inclusión-exclusión + fuerza bruta | sí | ★★★ |
| 5 | [ABC312 E — Tangency of Cuboids](https://atcoder.jp/contests/abc312/tasks/abc312_e) | AtCoder | rejilla de voxeles / contacto por cara | sí | ★★★ |
| 6 | [Gym 104248 G — Minimum volume tetrahedron](https://codeforces.com/gym/104248/problem/G) | CF Gym | producto triple + AM-GM | casi (fórmula cerrada) | ★★★ |
| 7 | [CF 65C — Harry Potter and the Golden Snitch](https://codeforces.com/problemset/problem/65/C) | Codeforces | distancias 3D + búsqueda binaria | sí | ★★★ |
| 8 | [CF 89D — Space mines](https://codeforces.com/problemset/problem/89/D) | Codeforces | rayo-esfera | no (cuadrática) | ★★★★ |
| 9 | [CF 106E — Space Rescuers](https://codeforces.com/problemset/problem/106/E) | Codeforces | esfera mínima contenedora | no | ★★★★ |
| 10 | [SPOJ CH3D — Convex Hull 3D](https://www.spoj.com/problems/CH3D/) | SPOJ | envolvente 3D, área y volumen | no | ★★★★ |
| 11 | [UVa 11275 — 3D Triangles](https://onlinejudge.org/board/viewtopic.php?p=70723) (hilo del foro; el enunciado está en el juez UVa) | UVa | intersección triángulo-triángulo | no | ★★★★ |
| 12 | [WF 2017 — Mission Improbable](https://www.luogu.com.cn/problem/P6931) (espejo en Luogu) | ICPC WF | "vistas" 3D → matching bipartito | no geométrico | ★★★★ |
| 13 | [Kattis starsinacan — Stars in a Can](https://open.kattis.com/problems/starsinacan) (NAIPC 2017) | Kattis | envolvente 3D + cilindro mínimo | no | ★★★★★ |
| 14 | [WF 2012 A — Asteroid Rangers](https://basecamp.eolymp.com/en/problems/3387) (espejo en e-olymp) | ICPC WF | MST cinético con distancias 3D | no | ★★★★★ |

---

## Análisis de cada problema

### 1. ABC361 B — Intersection of Cuboids

1. **Pide:** decidir si dos cajas alineadas a los ejes se intersecan con **volumen positivo**.
2. **Parte geométrica:** solo la intersección de intervalos.
3. **Truco:** los ejes son independientes. Hay intersección si y solo si, en los tres ejes, `min(r1,r2) − max(l1,l2) > 0` (estricto, porque tocarse por una cara no cuenta).
4. **Función:** `overlapPositive`.
5. **Aritmética simple:** sí, seis comparaciones.
6. **Complejidad:** O(1).
7. **Dificultad:** ★.

```cpp
IPoint3 a, b, c, d; cin >> a >> b >> c >> d;
cout << (overlapPositive({a, b}, {c, d}) ? "Yes" : "No") << endl;
```

### 2. ABC144 D — Water Bottle

1. **Pide:** el ángulo máximo de inclinación de una botella prismática de base a×a y altura b, con x de agua, sin que se derrame.
2. **Parte geométrica:** la sección transversal (un rectángulo a×b) y el volumen = área de la sección × a.
3. **Truco:** reducir a 2D. El agua ocupa área `x/a` del rectángulo. Si `x ≥ a²b/2`, el agua forma un trapecio y `tan θ = 2(a²b − x)/a³`. Si no, forma un triángulo y `tan θ = a b² / (2x)`.
4. **Función:** `toDeg` y `atan2l` (no hace falta nada 3D).
5. **Aritmética simple:** sí.
6. **Complejidad:** O(1).
7. **Dificultad:** ★★.

```cpp
ld a, b, x; cin >> a >> b >> x;
ld t = x >= a*a*b/2 ? atan2l(2*(a*a*b - x), a*a*a) : atan2l(a*b*b, 2*x);
cout << fixed << setprecision(10) << toDeg(t) << endl;   // ejemplos: 45, 89.7834636934, 4.2363947991
```

### 3. ABC366 D — Cuboid Sum Query

1. **Pide:** sumas de A[x][y][z] en muchos subcubos (N ≤ 100).
2. **Parte geométrica:** ninguna; es una suma acumulada en 3D.
3. **Truco:** prefix sums 3D con inclusión-exclusión de las 8 esquinas.
4. **Función:** `Pref3` (índices 0-based inclusivos).
5. **Aritmética simple:** sí.
6. **Complejidad:** O(N³ + Q).
7. **Dificultad:** ★★.

### 4. ABC343 E — 7x7x7

1. **Pide:** colocar tres cubos de lado 7 (|coordenadas| ≤ 100) de modo que los volúmenes cubiertos exactamente por 1, 2 y 3 cubos sean V1, V2 y V3.
2. **Parte geométrica:** la intersección de cajas.
3. **Trucos:** (a) por invariancia de traslación, el primer cubo queda fijo en el origen; (b) desplazamientos de más de 7 no cambian nada (los cubos ya no se solapan), así que alcanza con probar un rango pequeño; (c) `V3 = S3`, `V2 = S2 − 3S3`, `V1 = S1 − 2S2 + 3S3`.
4. **Función:** `exactlyCovered3`, `interVolume`.
5. **Aritmética simple:** sí, inclusión-exclusión sin construir sólidos.
6. **Complejidad:** O(R⁶) con R ≈ 8–15 desplazamientos por coordenada (la prueba usa 8³·15³ ≈ 1,7 M combinaciones).
7. **Dificultad:** ★★★.

La solución completa está en `solve343E` de [_pruebas/geometria-3d.cpp](../../_pruebas/geometria-3d.cpp). Reproduce el ejemplo "840 84 7 → Yes" y "343 34 3 → No".

### 5. ABC312 E — Tangency of Cuboids

1. **Pide:** para cada una de N ≤ 1e5 cajas que no se solapan (coordenadas en [0,100]), cuántas otras comparten con ella una cara de área positiva.
2. **Parte geométrica:** el contacto por cara (`boxContact == BC_FACE`).
3. **Truco:** compararlas todas por pares es O(N²) y no entra. Como las coordenadas son ≤ 100 y las cajas no se solapan, se pinta una rejilla de 100³ cubitos con el id de cada caja (volumen total ≤ 1e6). Luego cada par de cubitos vecinos en +x, +y o +z con ids distintos (ambos no vacíos) aporta un par, que se guarda en un `set` para no repetirlo.
4. **Función:** `boxContact` (validación), rejilla de voxeles.
5. **Aritmética simple:** sí.
6. **Complejidad:** O(100³ + pares·log).
7. **Dificultad:** ★★★.

```cpp
const int M = 100; vector<int> id(M*M*M, -1);
auto at = [&](int x, int y, int z) -> int& { return id[(x*M + y)*M + z]; };
for (int i = 0; i < n; i++) for (x..) for (y..) for (z..) at(x,y,z) = i;   // [x1,x2) etc.
set<pair<int,int>> pr;
for (x,y,z) for (dir in {+x,+y,+z}) if (dentro && a != -1 && b != -1 && a != b) pr.insert(minmax(a,b));
// respuesta[i] = número de pares que contienen a i
```

### 6. Gym 104248 G — Minimum volume tetrahedron (Udmurt SU Contest 2010)

1. **Pide:** un ángulo triedro OABC con vértice O en el origen y un punto interior P. Hay que trazar un plano por P que corte un tetraedro de volumen mínimo. Coordenadas enteras ≤ 10³, tolerancia 1e-6. Este resumen viene de un buscador: el enunciado no pudo descargarse.
2. **Parte geométrica:** coordenadas en la base (A,B,C) y el volumen por producto triple.
3. **Truco:** se escribe `P = αA + βB + γC` por Cramer (`α = [P,B,C]/[A,B,C]`, etc.). Un plano que corta las aristas en sA, tB y uC pasa por P si y solo si `α/s + β/t + γ/u = 1`, y su volumen es `stu·|[A,B,C]|/6`. Por AM-GM, el mínimo se alcanza con `α/s = β/t = γ/u = 1/3`: **P es el centroide del triángulo de corte**. Queda `V = 4.5·αβγ·|[A,B,C]|`.
4. **Función:** `minTetraThroughPoint` (C).
5. **Aritmética simple:** sí, cuatro productos triples. Es optimización resuelta con una desigualdad, sin búsqueda numérica.
6. **Complejidad:** O(1).
7. **Dificultad:** ★★★.

La fórmula se validó contra una minimización numérica en las pruebas. **No** se validó contra el ejemplo del juez (salida 2.53125), porque no se pudo leer el formato de entrada; comprobar el orden de las líneas antes de enviar.

### 7. CF 65C — Harry Potter and the Golden Snitch

1. **Pide:** la snitch recorre una poligonal 3D a velocidad vs y Harry sale de P a velocidad vp ≥ vs. Hay que decir si la alcanza y dónde (y cuándo) a más tardar al final de la poligonal.
2. **Parte geométrica:** solo distancias 3D y la interpolación sobre segmentos.
3. **Truco:** como vp ≥ vs, si Harry la alcanza en un instante t también la alcanza en cualquier instante posterior. Eso es monótono, así que se busca el primer segmento donde `dist(P, fin) ≤ vp·t_fin` y luego se hace búsqueda binaria dentro de él (o se resuelve la cuadrática).
4. **Función:** `lerp`, `dist`.
5. **Aritmética simple:** sí, más una búsqueda binaria.
6. **Complejidad:** O(n + iteraciones).
7. **Dificultad:** ★★★.

### 8. CF 89D — Space mines

1. **Pide:** una esfera de radio R (la "Estrella de la Muerte") se mueve en línea recta. Hay que dar el primer instante en que choca con alguna mina, que es una bola con púas (segmentos).
2. **Parte geométrica:** la intersección rayo-esfera.
3. **Truco:** se reduce al movimiento del **centro**. Chocar con el cuerpo de la mina equivale a que el rayo del centro toque la esfera de radio `R + r`. Para las púas, las soluciones publicadas usan un rayo contra una esfera de radio R centrada en la punta; antes de confiar en eso, comprobar en el enunciado que no puede haber un contacto lateral con la púa (si lo hay, hace falta rayo contra cilindro). Muestrear el tiempo falla: el contacto puede ocurrir entre dos muestras.
4. **Función:** `raySphere` (el t más chico ≥ 0).
5. **Aritmética simple:** no, hay que resolver una cuadrática.
6. **Complejidad:** O(total de púas).
7. **Dificultad:** ★★★★.

### 9. CF 106E — Space Rescuers

1. **Pide:** el punto que minimiza la distancia máxima a n ≤ 100 planetas, con coordenadas enteras ≤ 1e4 en valor absoluto.
2. **Parte geométrica:** el centro de la esfera mínima contenedora.
3. **Truco:** Welzl en 3D (`minEnclosingSphere`), en O(n) esperado. Las soluciones publicadas suelen usar descenso u *annealing* hacia el punto más lejano; también funcionan, pero son aproximadas.
4. **Función:** `minEnclosingSphere`.
5. **Aritmética simple:** no.
6. **Complejidad:** O(n) esperado.
7. **Dificultad:** ★★★★.

### 10. SPOJ CH3D — Convex Hull 3D

1. **Pide:** el área superficial y el volumen de la envolvente convexa de 10 a 1000 puntos (hasta 100 casos), con coordenadas en [−10, 10] y precisión 0.01.
2. **Parte geométrica:** toda; es la envolvente 3D.
3. **Truco:** las coordenadas son reales. Si tienen pocas cifras decimales, se escalan (×10^k) y se redondean para usar `convexHull3D` exacto; el área se divide luego por 10^{2k} y el volumen por 10^{3k}. Si no, hace falta una versión con EPS (no incluida). La biblioteca ya maneja coplanares y duplicados, que es donde fallan muchas implementaciones.
4. **Función:** `convexHull3D`, `hullSurface`, `hullVolume6`.
5. **Aritmética simple:** no.
6. **Complejidad:** O(n²) por caso.
7. **Dificultad:** ★★★★.

### 11. UVa 11275 — 3D Triangles

1. **Pide:** decidir si dos triángulos en el espacio se intersecan.
2. **Parte geométrica:** toda.
3. **Truco:** si se cortan, algún lado de uno toca al otro triángulo, así que bastan 6 pruebas segmento-triángulo; el caso coplanar se resuelve con los lados dentro del plano. En el foro varios reportan WA con el método de "intervalos sobre la recta de corte".
4. **Función:** `triTriIntersectExact` (si la entrada es entera o se puede escalar).
5. **Aritmética simple:** no.
6. **Complejidad:** O(1).
7. **Dificultad:** ★★★★.

### 12. ICPC WF 2017 — Mission Improbable

1. **Pide (resumen de memoria; confirmar con el enunciado):** una rejilla de pilas de cajas. Hay que quitar la mayor cantidad posible sin cambiar la vista superior (qué celdas tienen alguna caja), la frontal (máximo por columna) ni la lateral (máximo por fila).
2. **Parte geométrica:** solo la interpretación de las "vistas", que son proyecciones de un objeto 3D a 2D y 1D.
3. **Truco:** es un problema 3D que se resuelve sin geometría. Cada celda no vacía conserva 1 caja; los máximos de fila y de columna se cubren con celdas que sirven para ambos, y eso se decide con un matching bipartito entre filas y columnas con el mismo máximo.
4. **Función:** ninguna de esta biblioteca (matching de [05_Flujos_y_matching](../../05_Flujos_y_matching)).
5. **Aritmética simple:** no geométrica.
6. **Complejidad:** la del matching.
7. **Dificultad:** ★★★★.

### 13. Kattis starsinacan — Stars in a Can (NAIPC 2017)

1. **Pide:** el cilindro de volumen mínimo, con orientación libre, que contiene todos los puntos; una base debe contener al menos 3 estrellas. No hay 4 puntos coplanares y las coordenadas son enteras en [−1000, 1000].
2. **Parte geométrica:** la envolvente 3D y la proyección sobre el plano de cada cara.
3. **Truco:** la base del cilindro óptimo está en el plano de una cara de la envolvente. Para cada cara: altura = punto más lejano a ese plano; radio = círculo mínimo de los puntos proyectados (`Plane::to2D` + círculo mínimo 2D).
4. **Función:** `convexHull3D`, `Plane`, `Frame`, más el círculo mínimo 2D del notebook.
5. **Aritmética simple:** no.
6. **Complejidad:** O(F·n) esperado.
7. **Dificultad:** ★★★★★.

### 14. ICPC WF 2012 A — Asteroid Rangers

1. **Pide:** puntos 3D con movimiento lineal. Hay que contar cuántas veces cambia el árbol generador mínimo con el paso del tiempo.
2. **Parte geométrica:** `dist2` entre dos puntos en movimiento lineal, que es una **cuadrática** en t.
3. **Truco:** "MST cinético". Los eventos son los instantes en que dos distancias cuadradas se igualan (una ecuación cuadrática), y en cada evento se recalcula el MST.
4. **Función:** `dist2` y álgebra; el resto es grafos.
5. **Aritmética simple:** la geometría sí; el algoritmo no.
6. **Complejidad:** O(n⁴) eventos en el peor caso, filtrados.
7. **Dificultad:** ★★★★★.

---

## Cómo practicar

1. Empieza por los problemas 1 a 5: casi todo lo de cajas se resuelve con `overlapLen`.
2. Sigue con 6 y 7: producto triple, distancias y monotonía.
3. Después 8 y 9: esferas y optimización.
4. Para terminar, 10, 11 y 13: envolvente y predicados exactos. Usa las pruebas de [_pruebas/geometria-3d.cpp](../../_pruebas/geometria-3d.cpp) como modelo para tus propios casos borde.
