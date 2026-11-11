# Python para competencias

| Archivo | Contenido |
|---|---|
| [template.py](template.py) | Template base: lectura rápida, `I/MI/LI/S`, salida acumulada en `out` |
| [template_completo.py](template_completo.py) | Imports típicos, `dbg` con `-d`, límite de dígitos, recursión con hilo |
| [enteros_y_bits.py](enteros_y_bits.py) | `bit_length`, popcount, máscaras, bases, `//` y `%` con negativos, `isqrt`, `pow` modular, nCr, CRT, criba, `Fraction` |
| [estructuras.py](estructuras.py) | Tuplas, listas, dict/Counter/defaultdict, set, deque, heapq, bisect, itertools, `lru_cache`, `cmp_to_key`, strings |
| [rendimiento.py](rendimiento.py) | Leer todo de una vez, DFS iterativo, Euler tour, `@bootstrap`, hilo con pila grande, memoria |
| [debug.py](debug.py) | `dbg`, `f"{x=}"`, `trace`, cómo correr en PowerShell y 19 errores típicos |
| [stress.py](stress.py) | Comparar `sol.py` contra `brute.py` con casos aleatorios (sirve también para C++) |
| [problemas_python_vs_cpp.py](problemas_python_vs_cpp.py) | 7 problemas que en Python salen en pocas líneas (bigint, bitset con int, fracciones) |

Los `.py` de referencia (`debug.py`, `rendimiento.py`, `problemas_python_vs_cpp.py`) se ejecutan solos y verifican sus ejemplos con `assert`. `enteros_y_bits.py` y `estructuras.py` son hojas de referencia compactas: los resultados van en comentarios.
Más ejemplos de Python en [09_Utilidades/Python](../09_Utilidades/Python) (precisión con `decimal`, abrir archivos) y [09_Utilidades/Entrada_salida](../09_Utilidades/Entrada_salida).

## Equivalencias C++ → Python

| C++ | Python |
|---|---|
| `__lg(n)` / `63 - __builtin_clzll(n)` | `n.bit_length() - 1` |
| ceil(log2 n), menor `k` con `2^k >= n` | `(n - 1).bit_length()` |
| `__builtin_popcountll(x)` | `x.bit_count()` (3.10+) o `bin(x).count("1")` |
| `__builtin_ctzll(x)` | `(x & -x).bit_length() - 1` |
| `__int128`, bigint a mano | `int` normal, no desborda |
| `sqrtl` + ajuste | `math.isqrt(n)` exacto |
| exponenciación binaria, inverso modular | `pow(a, b, m)`, `pow(a, -1, m)` (3.8+) |
| `__gcd`, lcm | `math.gcd(*v)`, `math.lcm(*v)` (3.9+) |
| `((a % m) + m) % m` | `a % m` (nunca negativo si `m > 0`) |
| división entera truncada `a / b` | `a // b` redondea hacia −∞ (ojo con negativos) |
| `pair`, `tuple` | tupla `(a, b)`; se compara igual, es hashable |
| `vector<vector<int>> g(n, vector<int>(m))` | `[[0] * m for _ in range(n)]` |
| `map` / `unordered_map` | `dict`, `defaultdict(int)`, `Counter` |
| `set` / `unordered_set` | `set` (sin orden): ordenado = lista + `bisect` |
| `queue`, `deque` | `collections.deque` (`append`, `popleft`) |
| `priority_queue` (máximos) | `heapq` es de **mínimos**: guardar `-x` |
| `lower_bound` / `upper_bound` | `bisect_left` / `bisect_right` |
| `next_permutation` | `itertools.permutations` (ya en orden) |
| `partial_sum` | `itertools.accumulate(v, initial=0)` |
| `sort(..., cmp)` | `sort(key=...)`; si hace falta comparador: `cmp_to_key` |
| `bitset<N>` | un `int`: `b \|= b << x`, `b >> i & 1` |
| `memo` con arreglos | `@lru_cache(maxsize=None)` |
| `reverse`, `substr` | `s[::-1]`, `s[l:r]` |

## Cuándo usar Python y cuándo no

- **Sí:** números grandes, fracciones exactas, mucho manejo de cadenas, fuerza bruta pequeña con `itertools`, problemas de pocas operaciones donde importa escribir rápido.
- **No:** más de ~10^7 operaciones en loops, DFS profundos en PyPy, cuando el límite de tiempo está ajustado para C++.
- En Codeforces, enviar con **PyPy 3-64** si hay loops; con CPython si casi todo lo hacen builtins (`sort`, `int` grandes, `str`).
- Versiones: `isqrt`, `pow(a, -1, m)`, `f"{x=}"`, `accumulate(initial=)` → 3.8+; `gcd` con varios argumentos y `lcm` → 3.9+; `bit_count`, `bisect(key=)` → 3.10+; límite de 4300 dígitos → 3.11+.
