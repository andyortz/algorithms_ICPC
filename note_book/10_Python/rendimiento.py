# RENDIMIENTO: Python hace loops ~10-50x más lento que C++. Cómo evitar TLE, RE y MLE.
# Ejecutar: python rendimiento.py  -> corre las demos con asserts.
#
# - En Codeforces elige "PyPy 3-64": loops mucho más rápidos. CPython es mejor solo si
#   todo el trabajo lo hacen builtins (sort, sum, str.join, int grandes, slicing).
# - Si la complejidad pasa justo en C++ (10^8 operaciones), en Python no pasa: usa C++.
import sys
from types import GeneratorType

# ======================= 1) ENTRADA Y SALIDA =======================
def leer_todo_demo():
    """Lo más rápido: leer toda la entrada de una vez y recorrer los tokens.
    Los tokens son bytes: int(b"12") funciona; para cadenas usar .decode()."""
    data = sys.stdin.buffer.read().split()
    pos = 0
    t = int(data[pos]); pos += 1
    out = []
    for _ in range(t):
        n = int(data[pos]); pos += 1
        a = list(map(int, data[pos:pos + n])); pos += n
        s = data[pos].decode(); pos += 1
        out.append(f"{sum(a)} {s}")
    sys.stdout.write("\n".join(out) + "\n")      # UNA sola escritura al final

# Variante con iterador:  it = iter(data);  nxt = lambda: int(next(it))

# ======================= 2) CÓDIGO DENTRO DE main() =======================
# Las variables locales son más rápidas que las globales. Además en loops calientes:
#   app = out.append          (evita buscar el atributo en cada vuelta)
#   for x in a:               (mejor que for i in range(len(a)): a[i])
#   sum(a), max(a), sorted(a), a.count(x), "".join(...)  -> corren en C
#   lista [0] * n             en vez de dict cuando las claves son 0..n-1
#   grilla aplanada: idx = r * C + c  en vez de lista de listas

def empaquetar_demo():
    """Meter un par en un solo int: más rápido que tuplas en heaps/sets de 10^6 elementos."""
    SHIFT = 20                           # nodo < 2^20 (~10^6)
    MASK = (1 << SHIFT) - 1
    d, u = 12345, 678
    code = d << SHIFT | u                # se ordena por d y luego por u, como la tupla (d, u)
    assert (code >> SHIFT, code & MASK) == (d, u)
    assert (5 << SHIFT | 999) < (6 << SHIFT | 0)
empaquetar_demo()

# ======================= 3) RECURSIÓN SIN RecursionError =======================
# Opción A: hacerlo iterativo con una pila (lo más rápido y seguro).
def dfs_order(adj, root=0):
    """Devuelve (orden, padre). En 'orden' cada padre aparece antes que sus hijos;
    recorrerlo al revés = hijos antes que el padre (sirve para DP en árbol)."""
    n = len(adj)
    parent = [-1] * n
    seen = [False] * n
    seen[root] = True
    order, stack = [], [root]
    while stack:
        u = stack.pop()
        order.append(u)
        for v in adj[u]:
            if not seen[v]:
                seen[v] = True
                parent[v] = u
                stack.append(v)
    return order, parent

adj = [[1, 2], [0, 3, 4], [0], [1], [1]]
order, par = dfs_order(adj)
size = [1] * len(adj)                    # tamaño de subárbol, sin recursión
for u in reversed(order):
    if par[u] != -1:
        size[par[u]] += size[u]
assert size == [5, 3, 1, 1, 1]

def euler_tour(adj, root=0):
    """tin/tout iterativos con tuplas (nodo, padre, ya_procesado) en la pila.
    v está en el subárbol de u  <=>  tin[u] <= tin[v] < tout[u]."""
    n = len(adj)
    tin, tout = [0] * n, [0] * n
    timer = 0
    stack = [(root, -1, False)]
    while stack:
        u, p, done = stack.pop()
        if done:
            tout[u] = timer
            continue
        tin[u] = timer
        timer += 1
        stack.append((u, p, True))       # se procesa cuando terminen los hijos
        for v in adj[u]:
            if v != p:
                stack.append((v, u, False))
    return tin, tout

tin, tout = euler_tour(adj)
assert all(tin[0] <= tin[v] < tout[0] for v in range(5))
assert tout[1] - tin[1] == 3             # el subárbol de 1 tiene 3 nodos

# Opción B: @bootstrap. Escribes la recursión casi igual, pero con yield:
#   - cada llamada recursiva:   r = yield f(args)
#   - cada return x:            yield x
# Corre en CPython y PyPy sin tocar el límite de recursión.
def bootstrap(f, stack=[]):
    def wrapped(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        to = f(*args, **kwargs)
        while True:
            if type(to) is GeneratorType:
                stack.append(to)
                to = next(to)
            else:
                stack.pop()
                if not stack:
                    break
                to = stack[-1].send(to)
        return to
    return wrapped

N = 10**5
path = [[] for _ in range(N)]            # camino 0-1-2-...-(N-1): profundidad 10^5
for i in range(N - 1):
    path[i].append(i + 1)
    path[i + 1].append(i)

@bootstrap
def sum_depths(u, p, d):
    total = d
    for v in path[u]:
        if v != p:
            r = yield sum_depths(v, u, d + 1)
            total += r
    yield total

assert sum_depths(0, -1, 0) == N * (N - 1) // 2   # recursión normal daría RecursionError

# Opción C (solo CPython): subir el límite y correr en un hilo con pila grande.
#   import threading
#   sys.setrecursionlimit(1 << 25)
#   threading.stack_size(1 << 27)        # 128 MB; bajar a 1 << 26 si da MLE
#   threading.Thread(target=main).start()
# Solo setrecursionlimit sin el hilo puede tumbar el proceso (segfault = RE).

# ======================= 4) MEMORIA =======================
# En CPython cada int de una lista ocupa ~28 bytes + 8 del puntero: 10^7 ints ~ 360 MB.
#   from array import array;  a = array("i", [0]) * n     # 4 bytes por elemento
#   bytearray(n)                                           # 1 byte: flags / visitados
# Liberar estructuras grandes que ya no usas:  del grande

print("rendimiento.py: OK")
