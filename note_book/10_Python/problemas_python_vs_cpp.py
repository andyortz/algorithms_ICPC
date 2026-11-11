# PROBLEMAS QUE SON MÁS FÁCILES EN PYTHON QUE EN C++
# Cada función recibe la entrada completa como texto y devuelve la salida esperada.
# Ejecutar: python problemas_python_vs_cpp.py  -> prueba los ejemplos.
# Para enviar: la función con  print(f(sys.stdin.read()))
import sys, math
from fractions import Fraction

if hasattr(sys, "set_int_max_str_digits"):
    sys.set_int_max_str_digits(0)

# --------------------------------------------------------------------------------
# 1) Codeforces 1606B "Update Files"  (n, k <= 10^18)
# Un archivo está en 1 computadora; hay n computadoras y k cables. Cada hora, cada
# computadora con el archivo puede copiarlo a otra por un cable. Horas mínimas.
# Idea: mientras haya menos de k copias, se duplican; luego crecen k por hora.
# Las horas duplicando son el menor h con 2^h >= min(n, k) = (min(n, k) - 1).bit_length().
# En C++ con log2 (double) y n ~ 10^18 el redondeo da respuestas erróneas; aquí es exacto.
def update_files(inp):
    data = inp.split()
    res = []
    for i in range(int(data[0])):
        n, k = int(data[1 + 2 * i]), int(data[2 + 2 * i])
        h = (min(n, k) - 1).bit_length()
        cur = 1 << h
        h += max(0, -(-(n - cur) // k))  # techo de (n - cur) / k
        res.append(h)
    return "\n".join(map(str, res))

assert update_files("4\n8 3\n6 6\n7 1\n1 1\n") == "4\n3\n6\n0"
assert update_files("1\n1000000000000000000 1000000000000000000\n") == "60"

# --------------------------------------------------------------------------------
# 2) CodeChef FCTRL2 "Small factorials": t casos, 1 <= n <= 100, imprimir n!
# 100! tiene 158 dígitos: en C++ hay que programar multiplicación de bigint con arreglos.
def small_factorials(inp):
    nums = list(map(int, inp.split()))
    return "\n".join(str(math.factorial(n)) for n in nums[1:])

assert small_factorials("4\n1\n2\n5\n3\n") == "1\n2\n120\n6"

# --------------------------------------------------------------------------------
# 3) SPOJ JULKA: Klaudia y Natalia tienen T manzanas juntas y Klaudia tiene D más.
# T y D con hasta 100 dígitos (10 casos). Imprimir lo de cada una.
# Klaudia = (T + D) / 2, Natalia = (T - D) / 2. En C++: suma, resta y división de bigint.
def julka(inp):
    data = inp.split()
    res = []
    for i in range(0, len(data), 2):
        total, more = int(data[i]), int(data[i + 1])
        res.append(str((total + more) // 2))
        res.append(str((total - more) // 2))
    return "\n".join(res)

assert julka("10\n2\n") == "6\n4"
assert julka(f"{10**100}\n2\n") == f"{5 * 10**99 + 1}\n{5 * 10**99 - 1}"

# --------------------------------------------------------------------------------
# 4) CSES 1745 "Money Sums": n <= 100 monedas de valor <= 1000. Imprimir cuántas sumas
# distintas se pueden formar y cuáles, en orden.
# Un int de Python funciona como bitset de tamaño ilimitado: el bit s indica si la suma s
# es posible y "reach << x" suma x a todas a la vez. En C++ necesitas bitset<MAXS>
# con el tamaño fijo en compilación; aquí no se fija nada.
def money_sums(inp):
    data = list(map(int, inp.split()))
    coins = data[1:1 + data[0]]
    reach = 1                            # solo la suma 0
    for x in coins:
        reach |= reach << x
    bits = bin(reach)[:1:-1]             # bits[s] == "1" <=> suma s posible (LSB primero)
    sums = [s for s in range(1, len(bits)) if bits[s] == "1"]
    return f"{len(sums)}\n{' '.join(map(str, sums))}"

assert money_sums("4\n4 2 5 2\n") == "9\n2 4 5 6 7 8 9 11 13"

# --------------------------------------------------------------------------------
# 5) Suma armónica exacta: dado n (<= 1000), imprimir 1 + 1/2 + ... + 1/n como p/q
# irreducible. El denominador llega a cientos de dígitos: en C++ desborda long long
# desde n ~ 40. Con Fraction se suma exacto y siempre queda reducida.
def harmonic(inp):
    n = int(inp)
    h = sum(Fraction(1, i) for i in range(1, n + 1))
    return f"{h.numerator}/{h.denominator}"

assert harmonic("1") == "1/1" and harmonic("3") == "11/6" and harmonic("4") == "25/12"
assert len(harmonic("1000")) > 300     # p/q con cientos de dígitos

# --------------------------------------------------------------------------------
# 6) Ordenar números de hasta 10^6 dígitos (sin ceros a la izquierda) de menor a mayor.
# Convertir a int sería lento (y pasa el límite de 4300 dígitos). Ordenar por la TUPLA
# (longitud, cadena): más dígitos = más grande; con igual longitud, gana el orden lexicográfico.
def sort_big(inp):
    data = inp.split()
    nums = data[1:1 + int(data[0])]
    nums.sort(key=lambda s: (len(s), s))
    return "\n".join(nums)

assert sort_big("5\n31415926535897932384626433832795\n1\n3\n10\n3\n") == \
    "1\n3\n3\n10\n31415926535897932384626433832795"

# --------------------------------------------------------------------------------
# 7) Producto de dos números de 10^4 dígitos, o a^b mod m con a de 1000 dígitos:
#    print(int(x) * int(y))   /   print(pow(int(a), b, m))
#    En C++: FFT/Karatsuba o leer a como cadena y reducir dígito a dígito.
assert int("9" * 50) * int("9" * 50) == 10**100 - 2 * 10**50 + 1
assert pow(int("12345678901234567890" * 50), 10**18, 10**9 + 7) == \
    pow(int("12345678901234567890" * 50) % (10**9 + 7), 10**18, 10**9 + 7)

print("problemas_python_vs_cpp.py: OK")
