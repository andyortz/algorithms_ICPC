# PARTE D — Cheat sheet 3D

Fórmulas directas, trucos aritméticos, reducciones a 2D/1D y riesgos numéricos. Las funciones citadas están en [a-geo3d-esencial.cpp](a-geo3d-esencial.cpp) (A), [b-geo3d-solidos.cpp](b-geo3d-solidos.cpp) (B) y [c-geo3d-avanzado.cpp](c-geo3d-avanzado.cpp) (C).

## 1. Vectores en una línea

| Qué | Fórmula | Función |
| --- | --- | --- |
| Punto | `a·b = ax bx + ay by + az bz` | `dot` (A) |
| Cruz | `a×b = (ay bz − az by, az bx − ax bz, ax by − ay bx)` | `cross` (A) |
| Triple | `[a,b,c] = a·(b×c) = det[a;b;c]`, cíclico: `[a,b,c]=[b,c,a]=−[b,a,c]` | `triple` (A) |
| Orientación | `sgn((B−A)·((C−A)×(D−A)))`; 0 ⇔ coplanares | `orient` (A) |
| Colineales | `(B−A)×(C−A) = 0` | `collinear` (A) |
| Paralelos / perpendiculares | `u×v = 0` / `u·v = 0` | `parallelVec`, `perpendicularVec` (A) |
| Ángulo | `atan2(\|u×v\|, u·v)` ∈ [0,π] (no `acos`) | `angle` (A) |
| Proyección de u sobre v | `(u·v / \|v\|²) v` | `projVec` (A) |
| Punto medio exacto | guardar `2M = A+B` | `midpoint2` (A) |
| Perpendicular a v | `v × (eje menos alineado con v)` | `anyPerp` (A) |

**Cuándo NO hace falta nada de esto.** Si solo hay que comparar distancias, usa `dist2` y no hagas `sqrt`. Para "¿qué punto está más alto?" basta comparar la z. Si el enunciado da cajas alineadas a los ejes, cada eje se resuelve por separado como un intervalo. Ejemplo: "¿P está a distancia ≤ R de C?" con enteros se resuelve con `dist2(P,C) <= R*R`. El resultado es exacto, sin EPS.

## 2. Áreas y volúmenes

| Objeto | Fórmula |
| --- | --- |
| Triángulo ABC | `A = \|(B−A)×(C−A)\| / 2` (en 3D no hay "área con signo" escalar: el signo es la dirección de la normal) |
| Tetraedro ABCD | `V = \|(B−A)·((C−A)×(D−A))\| / 6`; `6V` con signo es exacto con enteros |
| Paralelepípedo (a,b,c) | `\|[a,b,c]\|` |
| Prisma / cilindro | `área base × altura` |
| Pirámide / cono | `área base × altura / 3` |
| Caja | `V = a·b·c`, `S = 2(ab+bc+ca)`, `diagonal² = a²+b²+c²` |
| Esfera | `S = 4πr²`, `V = 4πr³/3` |
| Casquete (altura h) | `S = 2πRh` (lateral), `V = πh²(3R−h)/3` |
| Lente (dos bolas, d) | `a = (d²+r1²−r2²)/(2d)`, `V = cap(r1, r1−a) + cap(r2, r2−(d−a))` |
| Cuerda a distancia d | `2√(r²−d²)` |
| Malla cerrada orientada | `6V = Σ v0·(v1×v2)` (caras antihorarias vistas desde fuera) |
| Polígono plano en 3D | `2A·n̂ = Σ p_i × p_{i+1}` (Newell) |
| Altura de tetraedro | `h = \|6V\| / \|(B−A)×(C−A)\|` |
| Distancia en esfera | `R · ángulo central`; lat/long → `(R cos φ cos λ, R cos φ sin λ, R sin φ)` |

**El producto triple.** `[a,b,c]` es el volumen con signo del paralelepípedo generado por a, b y c. Es positivo si (a,b,c) forma una terna derecha. En un tetraedro, el signo dice de qué lado del plano ABC queda D; el **volumen geométrico** es el valor absoluto. Para sumar volúmenes de una malla hay que usar el valor **con signo**: si cada cara se toma en valor absoluto, las partes que quedan fuera del sólido se suman en lugar de cancelarse.

## 3. Trucos aritméticos directos

| Truco | Fórmula / idea | Ejemplo | Implementación | Problema típico |
| --- | --- | --- | --- | --- |
| Intersección de intervalos | `max(0, min(r1,r2) − max(l1,l2))` | [0,5]∩[3,10] → 2 | `overlapLen` (B) | ABC361 B |
| Volumen de intersección de cajas | producto de las 3 longitudes | ver abajo | `interVolume` (B) | ABC343 E |
| ¿Volumen positivo? | **cada** eje con `min(r) − max(l) > 0` (estricto) | caras tocándose → no | `overlapPositive` (B) | ABC361 B |
| Contacto cara/arista/vértice | por eje `g = min(hi) − max(lo)`; nº de ejes con g = 0: 1 cara, 2 arista, 3 vértice | cubos [0,1]³ y [1,2]×[0,1]² → cara | `boxContact`, `contactArea` (B) | ABC312 E |
| Unión de 2 cajas | `\|A\|+\|B\|−\|A∩B\|` | | `unionVolume2` (B) | |
| Exactamente 1/2/3 de 3 cajas | `V3=S3`, `V2=S2−3S3`, `V1=S1−2S2+3S3` | | `exactlyCovered3` (B) | ABC343 E |
| Unión de N cajas | compresión de coordenadas + diferencias 3D, O(N³) | | `coverVolumes`, `unionVolume` (B) | |
| Distancia sin raíz | comparar `dist2` | `dist2 ≤ R²` | `dist2` (A) | casi todos |
| Máx. Manhattan | `max` sobre signos (1, ±1, ±1) de `max f − min f`, `f = x ± y ± z` | O(4n) | `maxManhattan` (A) | |
| Máx. Chebyshev | máximo por eje de `max − min` | | `maxChebyshev` (A) | |
| Puntos enteros en un segmento | `gcd(\|dx\|,\|dy\|,\|dz\|) + 1` | (0,0,0)–(2,4,6) → 3 | `latticePointsSegment` (A) | |
| Dirección canónica | dividir por el MCD; para rectas, el primer componente no nulo > 0 | (−2,4,−6) → (1,−2,3) | `normDir` (A) | conteo de paralelas |
| Pares paralelos | agrupar por `normDir` | | `countParallelPairs` (A) | |
| Máx. colineales | por cada i, histograma de `normDir(pj−pi)` | O(n² log n) | `maxCollinear` (A) | |
| Coplanares con un plano | `orient(a,b,c,p) == 0` | | `countOnPlane`, `IPlane` (A/B) | |
| Puntos enteros en una caja | `Π (lado+1)`; cubitos = volumen | | `latticePointsInBox` (B) | |
| Equidistantes | `dist2(a,p) == dist2(a,q)` | | `equidistant` (A) | |
| Paridad en rejilla 3D | cada paso de 1 unidad cambia la paridad de `x+y+z` (coloreo de tablero 3D) | | — | alcanzabilidad |
| Traslación | trasladar todo para fijar un punto en el origen: no cambia distancias, ángulos ni volúmenes | | — | |
| Simetrías | cambiar signos o permutar coordenadas conserva las distancias (las 48 isometrías del cubo) | | `cubeRotations(true)` (A) | figuras salvo simetría |
| Proyección | si la condición es por eje, resolver cada eje como un problema 1D | | `dropAxis` (B) | |

**Cuándo multiplicar y cuándo comparar.** Se multiplican las tres longitudes `overlapLen` cuando piden un **volumen**; el resultado ya vale 0 si algún eje no se solapa. Cuando piden un **sí/no** con volumen positivo, se compara que cada `min(r) − max(l)` sea **> 0**. Cuando solo importa que se toquen (contacto), basta **≥ 0**. Para contacto de área positiva, un eje debe dar exactamente 0 y los otros dos > 0.

Ejemplo (ABC343 E): los cubos [0,7]³ y [0,7]×[6,13]×[0,7] se solapan 7·1·7 = 49 por inclusión-exclusión, sin construir ningún sólido.

## 4. Rotaciones y transformaciones

* **90° exactos (sin trigonometría):** sobre Z, `(x,y,z) → (−y, x, z)`. Sobre X, `(x,y,z) → (x, −z, y)`. Sobre Y, `(x,y,z) → (z, y, −x)`. Para 180° sobre Z se cambian los dos signos: `(−x, −y, z)`. 270° equivale a −90°. Son `rotX90/rotY90/rotZ90(p, k)` (A).
* **24 orientaciones del cubo:** son las permutaciones de ejes con cambios de signo de determinante +1 (`cubeRotations()`). Con reflexiones hay 48 (`cubeRotations(true)`). Para comparar figuras de voxeles "salvo rotación": por cada orientación se aplica, se traslada al mínimo, se ordena y se queda la menor como forma canónica.
* **Rotación ≠ reflexión.** Una reflexión invierte `orient` y el signo de los volúmenes (`det = −1`). Si el problema distingue piezas "en espejo" (quiralidad), usa solo las 24 rotaciones.
* **Ángulo arbitrario sobre un eje coordenado:** `rotXMat/rotYMat/rotZMat(t)` (antihorario mirando desde +eje). La composición es `(A*B)p = A(Bp)` y la inversa de una rotación es su transpuesta.
* **Eje arbitrario (Rodrigues):** `R = I cos t + (1−cos t) k kᵀ + sin t [k]×`, con `rodrigues(axis, t)` y `rotateRodrigues(v, axis, t)`. Si el eje pasa por un punto o: `o + R(p−o)` (`rotateAroundLine`).
* **Afín 4×4:** `Mat4::translate`, `scale`, `fromMat3`; `apply` trata puntos (w=1) y `applyVec` vectores (w=0). Para rotar alrededor de un punto: `T(c)·R·T(−c)` (`rotateAroundPoint`).
* **Cambio de base:** `Frame(o, w)` construye una base ortonormal derecha {u,v,w}; `toLocal` y `toGlobal` son inversas. Con w = normal de un plano, las coordenadas (x,y) locales son geometría 2D dentro del plano.
* **Errores acumulados:** al encadenar muchas rotaciones flotantes conviene recalcular desde el ángulo total, o reortonormalizar. Con ángulos múltiplos de 90° usa siempre las versiones enteras.
* **Cuaterniones:** no se incluyen. En ICPC, Rodrigues más matrices cubren lo necesario, y los cuaterniones solo convienen cuando hay que interpolar orientaciones (SLERP), algo que casi no aparece.

## 5. Rectas, planos y distancias

| Qué | Fórmula |
| --- | --- |
| Punto–recta | `\|d × (Q−P)\| / \|d\|` |
| Punto–plano (con signo) | `(n·Q − d) / \|n\|` |
| Recta–recta (no paralelas) | `\|(P2−P1)·(d1×d2)\| / \|d1×d2\|` |
| Clasificación de rectas | `d1×d2 = 0` → paralelas (coincidentes si además `d1×(P2−P1) = 0`); si no, `[P2−P1, d1, d2] = 0` → se cortan; si no, **alabeadas** |
| Perpendicular común | `n = d1×d2`, `c1 = P1 + d1 ((P2−P1)·(d2×n))/(d1·(d2×n))` |
| Recta ∩ plano | `t = −(n·P − d)/(n·dir)`; si `n·dir = 0`, paralela (o contenida) |
| Plano ∩ plano | dirección `n1×n2`; punto `α n1 + β n2` resolviendo un sistema 2×2 |
| Tres planos | `x = (d1(n2×n3) + d2(n3×n1) + d3(n1×n2)) / [n1,n2,n3]` |
| Reflexión en un plano | `P − 2 (n·P − d) n / \|n\|²` |
| Ángulo diedro | `atan2(\|n1×n2\|, \|n1·n2\|)` ∈ [0, π/2] |
| Recta–plano | `atan2(\|d·n\|, \|d×n\|)` ∈ [0, π/2] |
| Esfera por 4 puntos | `c = A + (\|u\|²(v×w) + \|v\|²(w×u) + \|w\|²(u×v)) / (2[u,v,w])` |
| Circuncentro 3D | `c = A + ((w×u)\|v\|² + (v×w)\|u\|²) / (2\|w\|²)`, con `w = u×v` |

## 6. Geometría 3D que se reduce a 2D o 1D

| Patrón | Reducción | Ejemplo sin cruz ni planos |
| --- | --- | --- |
| Cajas alineadas que se cortan o tocan | 3 problemas 1D de intervalos | ABC361 B: `min(r)−max(l) > 0` en x, y, z |
| Volumen = área 2D × altura | prisma de sección constante | ABC144 D: la botella inclinada se reduce a la sección a×b (rectángulo de lados a y b) |
| Sólido cortado por un plano paralelo a una cara | sección 2D | el volumen bajo z = h es el área de la base × h |
| Proyección a XY/XZ/YZ | `dropAxis(p, k)` quita una coordenada | "sombra" de puntos sobre el piso: geometría 2D en (x,y) |
| Plano general | `Plane::to2D`/`Frame` | puntos coplanares → envolvente 2D en coordenadas locales |
| Colisión de cajas | condición por eje | tres comparaciones en lugar de SAT |
| Rotación 3D sobre un eje coordenado | rotación 2D de las otras dos coordenadas | rotar sobre Z: (x,y) gira y z queda fija |
| Búsqueda espacial | ordenar por coordenada o usar una rejilla | par más cercano: rejilla de celdas de lado d |
| Consultas de suma en cubos | prefix sums 3D (8 esquinas) | ABC366 D (`Pref3`) |
| Muchas cajas pintadas | difference array 3D | `Diff3` |
| Celdas conectadas, cavidades | BFS/DFS en voxeles (6 vecinos) | `voxelSurface(…, true)` |
| Coordenadas enormes, pocas cajas | compresión de coordenadas y luego flood fill | `coverVolumes` |
| Conteos de regiones superpuestas | inclusión-exclusión | `exactlyCovered3` |
| Problema invariante por traslación | fijar un objeto en el origen | ABC343 E: primer cubo en (0,0,0) |
| Posiciones relativas | trabajar con diferencias `pj − pi` | conteo de colineales con `normDir` |
| "Vistas" de pilas de cubos | máximos por fila y por columna (2D) | WF 2017 Mission Improbable |

## 7. Estabilidad numérica

### Tamaño de los productos (C = máx |coordenada|; las diferencias llegan a 2C)

| Cantidad | Grado | Cota | Tipo seguro |
| --- | --- | --- | --- |
| diferencias, Manhattan | 1 | 2C | `long long` |
| componente de `cross` | 2 | 8C² | `long long` hasta C = 1e9 (8e18 < 9.22e18) |
| `dot`, `norm2`, `dist2` | 2 | 12C² | **`__int128`** si C > ~8.7e8 (la biblioteca ya devuelve `__int128`) |
| `triple`, `orient`, `6V`, `IPlane::classify` | 3 | ~48C³ | `__int128` hasta C ≈ 1e12 |
| `norm2(cross)` = (2·área)², producto punto de dos normales | 4 | 192C⁴ | `__int128` hasta C ≈ 9e8; `unsigned __int128` hasta 1e9 |
| prueba "dentro de la esfera" por 4 puntos (determinante 5×5) | 5 | ~C⁵ | **no alcanza** con C ≈ 1e8: hace falta `long double` (aproximado) o enteros grandes |

Truco para evitar grado 4: para saber de qué lado está un punto **dentro de un plano** basta el signo de la componente dominante k de la cruz (`pointInTriangleExact`, `segSegIntersectExact`), que es de grado 2, en lugar de `dot(cross, normal)`.

### Riesgos y cómo los maneja la biblioteca

| Riesgo | Manejo |
| --- | --- |
| Overflow en cruz o triple | cruz en `ll` (C ≤ 1e9); triple siempre en `__int128` |
| Coordenadas reales con pocas cifras decimales | escalar a enteros (×10^k) y usar los predicados exactos |
| Cancelación numérica | restar primero (trabajar con `B−A`, `C−A`) y luego multiplicar |
| División entre valores cercanos a 0 | todas las funciones flotantes comparan el denominador con EPS y devuelven un estado (`IK_NONE`, `false`, `nullopt`) |
| Vector nulo / normal nula | `unit` devuelve (0,0,0); `IPlane::valid`; `triDegenerate`; `closestPointTriangle` cae a los lados |
| Planos degenerados | `Plane::fromPoints` requiere puntos no colineales: comprobar `collinear` antes |
| Rectas alabeadas | `lineRelation` nunca supone que dos rectas no paralelas se cortan |
| Puntos casi coplanares | con enteros, `orient` exacto; con flotantes, el resultado depende de EPS: escalar EPS al tamaño de los datos |
| Esferas tangentes | `sphereSphere` y `planeSphere` devuelven estados de tangencia con tolerancia |
| `sqrt` de negativo | `safeSqrt`; los discriminantes se recortan |
| `acos` fuera de [−1,1] | `angle` usa `atan2`; `safeAcos` recorta |
| Entero ↔ flotante | `Point3(ipoint)` es explícito; `long double` representa exactamente enteros hasta 2⁶⁴ |
| Errores tras rotaciones | usar las rotaciones enteras de 90°; reortonormalizar si se encadenan muchas |
| Comparaciones flotantes | `sgn3` con EPS3 = 1e-9 absoluto: ajustarlo (relativo) si las coordenadas son ~1e6 o ~1e-3 |
| Orientación de superficies | `meshClosedConsistent`, `orientMesh`; volumen negativo → caras hacia adentro |

### Exacto vs aproximado

* **Exactos** (IPoint3 con `|coord| ≤ 1e9`): `orient`, `collinear`, `coplanar`, `parallelVec`, `onSegment`, `segSegIntersectExact`, `lineRelationExact`, `pointInTriangleExact`, `segTriangleExact`, `pointInTetraExact`, `tetVolume6`, `meshVolume6`, `IPlane`, `cmpPointSphereExact`, `convexHull3D`, `closestPair3D`, `triTriIntersectExact`, todo lo de `Box3`.
* **Aproximados** (`long double`, EPS3): proyecciones, intersecciones con coordenadas, distancias con raíz, ángulos, esferas, Rodrigues, OBB y la esfera mínima.

Regla: **decide con los predicados exactos y construye después** con flotantes. Por ejemplo, primero `segTriangleExact` y, solo si da `true`, `segTrianglePoint`.
