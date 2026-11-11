# ESTRUCTURAS DE PYTHON (y su equivalente en C++). Resultados en comentarios.
import random
from collections import defaultdict, Counter, deque
from heapq import heappush, heappop, heapify, nlargest
from bisect import bisect_left, bisect_right, insort
from itertools import accumulate, permutations, combinations, product, groupby
from functools import lru_cache, cmp_to_key
from operator import itemgetter

# --- tuplas (pair): se comparan lexicográficamente y son hashables (claves de dict/set) ---
pts = [(1, 2), (3, 2), (0, 5)]
pts.sort(key=lambda t: (-t[1], t[0]))    # y desc, luego x asc; también key=itemgetter(1, 0)
first, *mid, last = [1, 2, 3, 4]         # mid = [2, 3]
M = [[1, 2, 3], [4, 5, 6]]
T = [list(r) for r in zip(*M)]           # transpuesta; rotar 90° horario: zip(*M[::-1])

# --- listas (vector) ---
good = [[0] * 3 for _ in range(2)]       # [[0]*3]*2 comparte la MISMA fila (error clásico)
v = [1, 2, 3, 4, 5]                      # v[::-1], v[1:3], v[-2:], copia: v[:]
pre = list(accumulate(v, initial=0))     # suma de v[l:r] = pre[r] - pre[l]   (3.8+)
uniq = list(dict.fromkeys([3, 1, 3, 2])) # [3, 1, 2]: sin repetidos y sin reordenar
xs = sorted(set(v)); idx = {x: i for i, x in enumerate(xs)}   # compresión de coordenadas
# max([], default=0); argmin: min(range(len(a)), key=a.__getitem__); print(*v)

# --- dict / defaultdict / Counter (map) ---
g = defaultdict(list)                    # OJO: leer g[k] CREA la clave; consultar con "k in g"
cnt = Counter("abracadabra")             # cnt["z"] = 0 sin crearla; cnt.most_common(2)
# Counter: anagramas c1 == c2; resta c1 - c2; intersección c1 & c2 (mínimos)
RND = random.getrandbits(60)             # anti-hack: guardar claves como k ^ RND
# --- set --- A | B, A & B, A - B, A ^ B, A <= B; frozenset es hashable
# No hay set ordenado: lista ordenada + bisect/insort, heap con borrado perezoso o Fenwick.

# --- deque: colas (list.pop(0) es O(n)) ---
def window_max(a, k):                    # máximo de cada ventana de tamaño k, O(n)
    dq, res = deque(), []
    for i, x in enumerate(a):
        while dq and a[dq[-1]] <= x: dq.pop()
        dq.append(i)
        if dq[0] <= i - k: dq.popleft()
        if i >= k - 1: res.append(a[dq[0]])
    return res

# --- heapq: heap de MÍNIMOS (max-heap: guardar -x); h[0] = mínimo; nlargest(k, a) ---
def dijkstra(adj, s):                    # adj[u] = [(v, w)]
    dist = [float("inf")] * len(adj)
    dist[s] = 0
    pq = [(0, s)]
    while pq:
        d, u = heappop(pq)
        if d > dist[u]: continue         # entrada vieja (borrado perezoso)
        for v2, w in adj[u]:
            if d + w < dist[v2]:
                dist[v2] = d + w
                heappush(pq, (d + w, v2))
    return dist

# --- bisect: lower_bound = bisect_left, upper_bound = bisect_right ---
# cuántos en [l, r]: bisect_right(s, r) - bisect_left(s, l); insort(s, x) inserta ordenado
def first_true(lo, hi, ok):              # menor x en [lo, hi) con ok(x); hi si ninguno
    while lo < hi:
        mid = (lo + hi) // 2
        if ok(mid): hi = mid
        else: lo = mid + 1
    return lo

# --- itertools: fuerza bruta --- permutations(a, k), combinations(a, k), product([0, 1], repeat=n)
rle = [(ch, len(list(gr))) for ch, gr in groupby("aaabcc")]   # run-length: [(a,3),(b,1),(c,2)]

# --- functools ---
@lru_cache(maxsize=None)                 # DP top-down; fib.cache_clear() entre casos
def fib(n): return n if n < 2 else fib(n - 1) + fib(n - 2)
def largest_number(nums):                # comparador custom con cmp_to_key
    cmp = lambda a, b: (a + b < b + a) - (a + b > b + a)
    return str(int("".join(sorted(map(str, nums), key=cmp_to_key(cmp)))))

# --- strings: inmutables --- "  a  b ".split() = ["a", "b"]; s.find("z") = -1
# ord("a") = 97, chr(99) = "c"; editar: t = list(s) ... "".join(t)
# Construir cadenas largas con lista + "".join(): s += ... en un loop es lento.
