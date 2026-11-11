import sys
input = sys.stdin.readline

def I():   return int(input())                    # un entero
def MI():  return map(int, input().split())       # varios enteros en una línea
def LI():  return list(map(int, input().split())) # lista de enteros
def S():   return input().strip()                 # una cadena

out = []

def solve():
    n, k = MI()
    if n == 0:
        out.append("0")
        return                      # termina solo este caso
    out.append(str(n - (1 << k)))

for _ in range(I()):
    solve()

sys.stdout.write("\n".join(out) + "\n")
