# Geometría 3D para ICPC (C++20)

Esta biblioteca está pensada para usarse como caja negra. Usa **predicados exactos con enteros** (`IPoint3`, `__int128`) para decidir y **`long double`** para construir puntos, distancias y ángulos. Se compila con GNU G++20 sobre la plantilla `00_Template/simple.cpp` (`int = long long`).

| Parte | Archivo | Contenido |
| --- | --- | --- |
| A — Esencial | [a-geo3d-esencial.cpp](a-geo3d-esencial.cpp) | `P3<T>`, `Point3`/`IPoint3`, punto/cruz/triple, `orient`, colineal/coplanar, distancias, Manhattan/Chebyshev, MCD y direcciones, rotaciones de 90° y las 24/48 del cubo, `Mat3`, Rodrigues, `Mat4`, `Frame` |
| B — Sólidos | [b-geo3d-solidos.cpp](b-geo3d-solidos.cpp) | `Box3` (intersección, contacto, inclusión-exclusión, unión de N), `Pref3`/`Diff3`, voxeles, `Line3`, segmentos, `Plane`/`IPlane`, triángulos, tetraedros, `Sphere`, esfera mínima, mallas |
| C — Avanzado | [c-geo3d-avanzado.cpp](c-geo3d-avanzado.cpp) | envolvente convexa 3D exacta, par más cercano 3D, triángulo-triángulo, OBB (SAT), rayo-malla, tetraedro mínimo por un punto |
| D — Cheat sheet | [cheat-sheet-3d.md](cheat-sheet-3d.md) | fórmulas, trucos aritméticos, rotaciones, reducciones a 2D/1D, overflow y precisión |
| E — ¿Qué uso? | este archivo | tabla de situación → función |
| F — Problemas | [problemas-3d.md](problemas-3d.md) | 14 problemas con enlaces, análisis y orden de práctica |
| G — Priorización | este archivo | imprescindible / recomendable / avanzado |
| Pruebas | [_pruebas/geometria-3d.cpp](../../_pruebas/geometria-3d.cpp) | 136 325 comprobaciones contra fuerza bruta ([resultado](../../_pruebas/geometria-3d-resultado.txt)) |

## Uso

```cpp
#include "c-geo3d-avanzado.cpp"   // incluye B, que incluye A, que incluye la plantilla
signed main() {
    IPoint3 A(0,0,0), B(4,0,0), C(0,4,0), D(0,0,4);
    cout << toString128(tetVolume6(A, B, C, D)) << endl;   // 64 (= 6V, exacto)
    cout << tetVolume(A, B, C, D) << endl;                 // 10.6667
}
```

* Para copiar a mano, conserva la parte A y agrega solo las secciones de B o C que necesites; cada sección depende de las anteriores. Las tres partes juntas compilan sin avisos con `-Wall -Wextra`.
* `IPoint3` acepta `|coordenada| ≤ 1e9`: la cruz se guarda en `long long`, y `dot`, `norm2` y `triple` devuelven `__int128`. Para imprimir un `__int128` usa `toString128`.
* `Point3(ip)` convierte de entero a flotante. `EPS3 = 1e-9` es absoluto: escálalo según el tamaño de los datos.
* Las funciones devuelven estados explícitos (`LineRel`, `InterKind`, `SphereRel`, `BoxContact`, `optional`, `bool`). Ninguna supone que existe una intersección única.
* Los nombres evitan las macros de la plantilla (`pi`, `F`, `S`, `all`, `vi`, `vb`, `vs`).

### Verificación

```
g++ -std=gnu++20 -O2 -Wall -Wextra _pruebas/geometria-3d.cpp -o <tmp.exe>   (desde note_book)
geometria-3d: 136325 comprobaciones OK
```

Qué se compara contra fuerza bruta: voxeles para cajas (1, 2 y 3 cajas, unión de N, prefix y difference 3D); conteos directos para Manhattan, Chebyshev, MCD, colineales y paralelos; muestreo fino para la distancia entre segmentos; un oráculo racional exacto para segmento-triángulo; volúmenes parciales para "punto en tetraedro"; subconjuntos de 2, 3 y 4 puntos para la esfera mínima; todas las ternas O(n⁴) para el número de caras de la envolvente; O(n²) para el par más cercano; muestreo exacto para triángulo-triángulo y OBB; y minimización numérica para Gym 104248 G.

Casos fijos: cubo unitario, cubos iguales, disjuntos, con contacto por cara, por arista o por vértice, rectas alabeadas, paralelas y coincidentes, planos coincidentes y paralelos, tetraedro de volumen 0, cuatro puntos coplanares, cuatro rotaciones de 90°, vectores nulos, triples con coordenadas de 2e9, esferas tangentes (externa e interna), cáscara de voxeles con cavidad, envolventes de rejillas (L+1)³ con duplicados y los ejemplos de ABC312 E, ABC343 E y ABC144 D.

Además se corrió un estrés aparte, no guardado en el repo: 5 926 envolventes con muchos coplanares sin ninguna discrepancia, y la envolvente más el par más cercano con 20 000 puntos en 41 ms.

## ¿Cuánta maquinaria necesito?

Ve de arriba hacia abajo y detente en el primer nivel que resuelva el problema:

1. **Una multiplicación:** volumen de una caja, de un prisma o el número de cubitos.
2. **Comparar intervalos:** cajas alineadas que se cortan, se tocan o se contienen (`overlapLen`).
3. **Una distancia:** usa `dist2` si solo hay que comparar, `dist` si piden el valor, y Manhattan o Chebyshev si el movimiento es por ejes.
4. **Proyectar a 2D o 1D:** un plano horizontal, condiciones por eje, una sección constante o rotaciones sobre un eje (ver el cheat sheet, §6).
5. **Producto punto o cruz:** ángulos, perpendicularidad, normales, áreas, punto–recta.
6. **Producto triple:** volúmenes, coplanaridad, lado de un plano, rectas alabeadas.
7. **Algoritmo avanzado:** envolvente 3D, par más cercano, esfera mínima, SAT, triángulo-triángulo.

## PARTE E — ¿Qué uso?

| Situación en el enunciado | Técnica / función |
| --- | --- |
| Cubos o cajas alineadas que se superponen | `overlapLen` por eje, multiplicar: `interVolume` |
| "¿Intersección de volumen positivo?" | `overlapPositive` (> 0 en los 3 ejes) |
| "¿Comparten una cara?" / tipo de contacto | `boxContact`, `contactArea` |
| Volumen cubierto por exactamente k de 3 cajas | `exactlyCovered3` |
| Unión de muchas cajas | `coverVolumes` / `unionVolume` (compresión + `Diff3`) |
| Sumas sobre subcubos | `Pref3` |
| Sumar a muchos subcubos y consultar al final | `Diff3` |
| Figura de cubitos: área, cavidades, componentes | `voxelSurface`, BFS de 6 vecinos |
| Muchas cajas con coordenadas ≤ 100 | rejilla de ids de 100³ (ABC312 E) |
| Distancia entre puntos / ¿dentro del radio? | `dist`, `dist2` ≤ R² |
| Distancia máxima en Manhattan | `maxManhattan` (4 combinaciones de signos) |
| Puntos enteros sobre un segmento | `latticePointsSegment` (MCD + 1) |
| Contar rectas o direcciones paralelas | `normDir`, `countParallelPairs`, `maxCollinear` |
| Rotar 90° sobre Z | `(x,y,z) → (−y, x, z)`: `rotZ90` |
| Piezas iguales "salvo rotación" | `cubeRotations()` (24); con espejo, 48 |
| Rotar un ángulo cualquiera alrededor de un eje | `rodrigues`, `rotateAroundLine` |
| Componer traslaciones y rotaciones | `Mat4` |
| Puntos en un plano horizontal | geometría 2D en (x,y): `dropAxis(p, 2)` |
| Puntos en un plano cualquiera | `Plane::to2D` / `Frame` + biblioteca 2D |
| Volumen de un tetraedro | `tetVolume6` (producto triple), `/6` |
| ¿Cuatro puntos coplanares? | `orient(a,b,c,d) == 0` |
| ¿De qué lado del plano está un punto? | `orient` (exacto), `IPlane::classify`, `Plane::side` |
| Rectas en 3D: ¿se cortan? | `lineRelationExact` / `lineRelation` (¡alabeadas!) |
| Distancia entre rectas alabeadas | `distLineLine`, `closestPointsLines` |
| Distancia entre segmentos | `distSegSeg` |
| ¿Se cortan dos segmentos 3D? | `segSegIntersectExact` |
| Proyección o reflexión en un plano | `Plane::proj`, `Plane::reflect` |
| Recta o segmento contra plano | `interLinePlane`, `interSegmentPlane` |
| Corte de 2 o 3 planos | `interPlanePlane`, `interThreePlanes` |
| Punto en un triángulo 3D / baricéntricas | `pointInTriangleExact`, `barycentric` |
| Distancia punto–triángulo | `distPointTriangle` |
| Rayo o segmento contra triángulo | `rayTriangle` (Möller–Trumbore), `segTriangleExact` |
| ¿Se cortan dos triángulos? | `triTriIntersectExact` |
| Punto en un tetraedro | `pointInTetraExact` |
| Esfera: punto dentro/fuera, corte con recta o rayo | `cmpPointSphereExact`, `lineSphere`, `raySphere` |
| Esfera contra esfera o plano | `sphereSphere`, `planeSphere`, `sphereIntersectionVolume` |
| Esfera por 4 puntos | `circumsphere` |
| Punto que minimiza la distancia máxima | `minEnclosingSphere` |
| Distancia sobre la Tierra | `fromLatLon`, `greatCircleDist` |
| Volumen o área de una malla cerrada | `meshVolume6`, `meshSurface`, `orientMesh` |
| Envolvente convexa: volumen, área, caras | `convexHull3D`, `hullVolume6`, `hullSurface`, `countFacets` |
| Par de puntos más cercano | `closestPair3D` |
| Cajas rotadas que colisionan | `obbIntersect` (SAT, 15 ejes) |
| Primer triángulo que toca un rayo | `rayMesh` |
| Plano por P que corta el volumen mínimo de un triedro | `minTetraThroughPoint` |

## PARTE G — Priorización ICPC

### IMPRESCINDIBLE (llevar siempre)

* `P3` con `dot`, `cross`, `triple`, `norm2`, `dist2`, `orient`, `collinear`, `coplanar`.
* Intervalos por eje: `overlapLen`, `interVolume`, `overlapPositive`, `boxContact`, inclusión-exclusión de 2 y 3 cajas.
* `dist2` en lugar de `dist`, `maxManhattan`, `latticePointsSegment`, `normDir`.
* Rotaciones de 90° con cambios de signo y la regla "rotación ≠ reflexión".
* Volumen de tetraedro (`tetVolume6`) y su signo.
* Punto–recta, punto–segmento, punto–plano y proyección.
* Prefix sums 3D y BFS sobre voxeles.
* Reducir a 2D o 1D (cheat sheet §6) y la tabla de overflow (§7).

### RECOMENDABLE (aparece con frecuencia en regionales)

* `Line3`: relación entre rectas (alabeadas), `distLineLine`, `closestPointsLines`, `distSegSeg`, `segSegIntersectExact`.
* `Plane`: intersecciones recta/segmento/2 planos/3 planos, reflexión, `to2D`.
* Triángulos: área, `pointInTriangleExact`, `closestPointTriangle`, `rayTriangle`, `segTriangleExact`.
* Esferas: `lineSphere`, `sphereSphere`, `planeSphere`, casquetes, círculo máximo.
* `Diff3`, `coverVolumes` (compresión de coordenadas), `cubeRotations`.
* `rodrigues`, `Mat3`, `Frame`.
* Mallas: `meshVolume6`, `meshSurface`.

### AVANZADO / POCO FRECUENTE

* `convexHull3D` (aparece, pero pocas veces; O(n²) alcanza casi siempre).
* `closestPair3D`, `minEnclosingSphere` (alternativa aproximada: descenso hacia el punto más lejano).
* `triTriIntersectExact`, `obbIntersect`, `rayMesh`, `orientMesh`.
* Cilindro mínimo (Stars in a Can), MST cinético (Asteroid Rangers): se construyen a partir de las piezas anteriores.
* **No incluido a propósito:** envolvente 3D O(n log n), KD-tree 3D, Delaunay 3D, cuaterniones, booleanas de poliedros y unión de esferas. Su costo de implementación es alto y casi no aparecen; si hace falta, el KD-tree 2D del notebook se generaliza agregando la coordenada z.
