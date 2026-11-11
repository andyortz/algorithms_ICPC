# DEBUG EN PYTHON + ERRORES QUE DAN WA/RE/TLE SIN QUE TE DES CUENTA.
# Ejecutar: python debug.py      (los asserts muestran el comportamiento real)
#
# Correr con archivo de entrada:
#   CMD / bash:   python sol.py < in.txt > out.txt
#   PowerShell:   Get-Content in.txt | python sol.py        (PowerShell no tiene "<")
#   Modo debug:   python sol.py -d < in.txt                 (activa dbg)
#   Comparar:     fc out.txt esperado.txt  (CMD)  /  diff out.txt esperado.txt  (bash)
import sys, time

LOCAL = "-d" in sys.argv

def dbg(*args, **kw):
    """Imprime a stderr. El juez solo compara stdout, así que olvidarlo no da WA,
    pero si está dentro de un loop de 10^6 sí gasta tiempo: quítalo o deja LOCAL en False."""
    if LOCAL:
        print(*args, file=sys.stderr, **kw)

# f-string con "=" (3.8+): imprime el nombre y el valor, ideal para dbg
n, arr = 5, [3, 1, 2]
assert f"{n=}" == "n=5" and f"{arr=}" == "arr=[3, 1, 2]"
assert f"{n * 2 = }" == "n * 2 = 10"
dbg(f"{n=} {arr=} {sorted(arr)=}")

def dbg_grid(g, w=3):                    # matriz alineada en columnas
    if LOCAL:
        for row in g:
            print(" ".join(f"{x:>{w}}" for x in row), file=sys.stderr)

def trace(f):                            # decorador: muestra cada llamada y su resultado
    def wrap(*args):
        r = f(*args)
        dbg(f"{f.__name__}{args} -> {r}")
        return r
    return wrap

@trace
def suma(a, b):
    return a + b
assert suma(2, 3) == 5                   # con -d imprime "suma(2, 3) -> 5"

t0 = time.perf_counter()                 # medir tiempo de una parte
_ = sum(range(10**5))
dbg(f"tiempo: {time.perf_counter() - t0:.3f}s")

# assert como chequeo: si falla en el juez da RE en vez de WA, y te dice que esa
# suposición es falsa.  assert 0 <= i < n, (i, n)  -> el mensaje muestra los valores.
# breakpoint() en local abre pdb:  n (siguiente), s (entrar), p x (imprimir), c (seguir), q.
# Compara contra fuerza bruta dentro del mismo archivo:
#   if LOCAL: assert rapido(caso) == bruto(caso), caso
# o entre programas con stress.py (genera casos aleatorios hasta que difieran).

# ======================= ERRORES TÍPICOS =======================

# 1) readline() deja el '\n' al final
line = "abc\n"                           # lo que devuelve sys.stdin.readline()
assert len(line) == 4 and line.strip() == "abc"   # por eso S() hace .strip()
assert list(line) == ["a", "b", "c", "\n"]        # list(input()) mete el '\n'
assert int("42\n") == 42                          # int() sí lo tolera

# 2) Pisar nombres: si escribes S = "hola" pierdes la función S(); lo mismo con
#    I, list, sum, max, min, input, str, map, len, id... Usa otros nombres.

# 3) Matriz [[0] * m] * n: todas las filas son la misma lista (ver estructuras.py).
#    b = a NO copia: usa a[:] o list(a); matriz: [r[:] for r in g] (deepcopy es lento).

# 4) Argumento por defecto mutable: se comparte entre llamadas
def agrega(x, acc=[]):
    acc.append(x)
    return acc
agrega(1)
assert agrega(2) == [1, 2]               # ¡arrastra el 1! usa acc=None y créala adentro

# 5) División y módulo con negativos distinto a C++; "/" siempre devuelve float
assert -7 // 2 == -4 and -7 % 2 == 1 and 6 / 2 == 3.0 and isinstance(6 / 2, float)

# 6) Ordenar números leídos como texto
assert sorted(["10", "9", "100"]) == ["10", "100", "9"]   # orden lexicográfico
assert sorted(map(int, ["10", "9", "100"])) == [9, 10, 100]

# 7) Imprimir floats sin formato
assert str(0.00001) == "1e-05" and str(1e16) == "1e+16"   # notación científica: WA
assert str(0.1 + 0.2) == "0.30000000000000004"
assert f"{0.00001:.6f}" == "0.000010"                    # usar siempre :.Nf

# 8) round() redondea al par
assert round(0.5) == 0 and round(1.5) == 2 and round(2.5) == 2

# 9) Índice -1 no da error: si un bug calcula i = -1, a[i] devuelve el último en silencio
a = [10, 20, 30]
assert a[-1] == 30                       # en C++ sería basura/RE; aquí parece correcto

# 10) Modificar una lista/dict mientras se recorre: salta elementos o lanza RuntimeError
nums = [1, 2, 2, 3]
for x in nums[:]:                        # recorre una COPIA si vas a borrar
    if x == 2:
        nums.remove(x)
assert nums == [1, 3]

# 11) "is" compara identidad, no valor: para números usa siempre ==
#     (x is y puede ser True para 5 y False para 1000 aunque sean iguales).

# 12) Recursión: límite de ~1000 niveles -> RecursionError (RE). Ver rendimiento.py.
assert sys.getrecursionlimit() >= 1000

# 13) @lru_cache entre casos de prueba: si la función depende de datos del caso,
#     llamar f.cache_clear() al iniciar cada caso (o resultados del caso anterior).

# 14) Más de 4300 dígitos en int(str) / str(int) (Python 3.11+) -> ValueError.
#     Solución: sys.set_int_max_str_digits(0) al inicio (ya está en template_completo.py).

# 15) print() en un loop de 10^5 líneas es lento: acumular en out y hacer un solo write.
#     EXCEPCIÓN: problemas interactivos -> print(x, flush=True) después de cada consulta,
#     y leer la respuesta con input() antes de seguir.

# 16) Leer hasta EOF (sin número de casos):
#       for line in sys.stdin: ...
#     o  data = sys.stdin.read().split()   y recorrer con un índice.
#     input() al llegar al final lanza EOFError; sys.stdin.readline() devuelve "".

# 17) Comparar floats con == falla; usar abs(a - b) < 1e-9 o math.isclose(a, b).
assert 0.1 + 0.2 != 0.3

# 18) True y False son enteros (1 y 0): sum(lista_de_bools) cuenta los True.
assert sum([True, False, True]) == 2

# 19) Mezclar input() y sys.stdin.read() en el mismo programa pierde datos: usa uno solo.

print("debug.py: OK")
