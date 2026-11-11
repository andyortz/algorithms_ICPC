# STRESS TEST: compara tu solución contra una fuerza bruta con casos aleatorios
# hasta encontrar uno en el que difieran. Sirve también para C++ (cambia los comandos).
#
# Uso:   python stress.py
#   - sol.py   : tu solución
#   - brute.py : solución lenta pero segura (backtracking, todas las permutaciones...)
#   - El caso que falla se guarda en fail.txt para reproducirlo:
#       python sol.py < fail.txt          (PowerShell: Get-Content fail.txt | python sol.py)
import random, subprocess, sys

SOL   = [sys.executable, "sol.py"]       # C++: ["sol.exe"]  (compilado antes con g++)
BRUTE = [sys.executable, "brute.py"]
ITER  = 500

def gen():
    """Casos PEQUEÑOS: si fallan, se pueden revisar a mano."""
    n = random.randint(1, 8)
    a = [random.randint(1, 10) for _ in range(n)]
    return f"1\n{n}\n{' '.join(map(str, a))}\n"

def run(cmd, inp):
    r = subprocess.run(cmd, input=inp, capture_output=True, text=True, timeout=10)
    if r.returncode != 0:
        return "RE:\n" + r.stderr
    return r.stdout.split()              # comparar por tokens: ignora espacios y saltos

for it in range(1, ITER + 1):
    random.seed(it)                      # reproducible: la iteración it siempre genera lo mismo
    inp = gen()
    a, b = run(SOL, inp), run(BRUTE, inp)
    if a != b:
        print(f"FALLA en la iteración {it}")
        print("--- entrada ---", inp, "--- sol ---", a, "--- brute ---", b, sep="\n")
        with open("fail.txt", "w") as f:
            f.write(inp)
        sys.exit(1)
print(f"OK: {ITER} casos iguales")

# Respuestas con decimales: comparar con tolerancia en vez de a != b, p. ej.
#   all(abs(float(x) - float(y)) < 1e-6 for x, y in zip(a, b)) and len(a) == len(b)
