# Template completo: imports típicos + debug + límites. Para concursos.
# Local:  python sol.py -d < in.txt      (PowerShell: Get-Content in.txt | python sol.py -d)
# Juez:   se ejecuta sin "-d" -> dbg() no imprime nada.
import sys, os, math, random
from collections import defaultdict, Counter, deque
from heapq import heappush, heappop, heapify
from bisect import bisect_left, bisect_right, insort
from itertools import accumulate, permutations, combinations, product, groupby
from functools import lru_cache, reduce, cmp_to_key

LOCAL = "-d" in sys.argv
if LOCAL and os.path.exists("in.txt"):
    sys.stdin = open("in.txt")              # redirigir ANTES de "input = sys.stdin.readline"
input = sys.stdin.readline

if hasattr(sys, "set_int_max_str_digits"):  # Python 3.11+: int(str)/str(int) fallan con
    sys.set_int_max_str_digits(0)           # más de 4300 dígitos; 0 = sin límite

def dbg(*args):                             # va a stderr: el juez no lo lee
    if LOCAL:
        print(*args, file=sys.stderr)

def I():   return int(input())                    # un entero
def MI():  return map(int, input().split())       # varios enteros en una línea
def LI():  return list(map(int, input().split())) # lista de enteros
def S():   return input().strip()                 # una cadena (readline deja el '\n')
def LS():  return input().split()                 # lista de palabras

INF = float("inf")                          # o 1 << 62 si quieres que todo siga siendo int
MOD = 10**9 + 7
DIRS = ((1, 0), (-1, 0), (0, 1), (0, -1))

out = []

def solve():
    n = I()
    a = LI()
    dbg(f"{n=} {a=}")                       # imprime "n=3 a=[1, 2, 3]"
    out.append(str(sum(a)))

def main():                                 # código dentro de función: variables locales,
    for _ in range(I()):                    # más rápido que a nivel global
        solve()
    sys.stdout.write("\n".join(out) + "\n")

main()

# --- Si hay recursión profunda (DFS de 10^5 niveles) en CPython, reemplaza main() por:
# import threading
# sys.setrecursionlimit(1 << 25)
# threading.stack_size(1 << 27)             # 128 MB de pila; bajar a 1 << 26 si da MLE
# threading.Thread(target=main).start()
# En PyPy esto no sirve: usar DFS iterativo o @bootstrap (ver rendimiento.py).
