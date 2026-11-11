# ENTEROS Y BITS: int no desborda (sin __int128 ni bigint). Resultados en comentarios.
import math
from fractions import Fraction
from decimal import Decimal, ROUND_HALF_UP

# --- log2 exacto (int(math.log(1000, 10)) da 2: nunca usar floats para esto) ---
# n.bit_length() = floor(log2 n) + 1  ->  floor(log2 n) = n.bit_length() - 1  (== __lg)
def ceil_log2(n): return (n - 1).bit_length()          # menor k con 2^k >= n
def next_pow2(n): return 1 << (n - 1).bit_length()     # tamaño de segment tree iterativo
def is_pow2(x): return x > 0 and x & (x - 1) == 0

# --- bits --- popcount: bin(m).count("1") o m.bit_count() (3.10+)
# lowbit: m & -m   ctz: (m & -m).bit_length() - 1   bit i: m >> i & 1
# Prioridad: en Python & | ^ van ANTES que == (en C++ al revés): x & 1 == 1 es (x & 1) == 1
def bits(mask):                          # índices de los bits encendidos
    while mask:
        low = mask & -mask
        yield low.bit_length() - 1
        mask ^= low
def submasks(m):                         # submáscaras no vacías de m (todas: O(3^n))
    s = m
    while s:
        yield s
        s = (s - 1) & m
MASK64 = (1 << 64) - 1                   # (-1) & MASK64 = 2^64 - 1 (ver como unsigned)
def to_signed64(x):                      # simular overflow de long long
    x &= MASK64
    return x - (1 << 64) if x >> 63 else x

# --- bases --- int("ff", 16) = 255   int("z", 36) = 35   int(" 42\n") = 42
# format(5, "08b") = "00000101"   f"{255:x}" = "ff"   bin(10)[2:] = "1010"
DIG = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
def to_base(n, b):                       # entero -> cadena en base b (2..36)
    if n == 0: return "0"
    neg, n, s = n < 0, abs(n), []
    while n:
        n, r = divmod(n, b)
        s.append(DIG[r])
    return "-" * neg + "".join(reversed(s))

# --- división (DISTINTA a C++) --- -7 // 2 = -4, -7 % 2 = 1 (C++: -3, -1); con m > 0, a % m >= 0
# "/" SIEMPRE da float: (10**17 + 1) / 1 pierde el +1. Con enteros usar "//".
def ceil_div(a, b): return -(-a // b)
def div_trunc(a, b):                     # división truncada como en C++
    q = abs(a) // abs(b)
    return q if (a < 0) == (b < 0) else -q

# --- raíces exactas --- int(math.sqrt(10**18 - 1)) = 10**9 (MAL); math.isqrt da el piso exacto
def is_square(n): r = math.isqrt(n); return r * r == n
def iroot(n, k):                         # piso de la raíz k-ésima (n >= 0)
    lo, hi = 0, 1 << (n.bit_length() // k + 1)
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if mid ** k <= n: lo = mid
        else: hi = mid - 1
    return lo

# --- modular --- pow(a, e, m); inverso: pow(a, -1, m) (3.8+, ValueError si gcd != 1)
MOD = 10**9 + 7
def build_fact(n, mod=MOD):              # factoriales e inversos para nCr en O(1)
    fact = [1] * (n + 1)
    for i in range(1, n + 1): fact[i] = fact[i - 1] * i % mod
    inv = [1] * (n + 1)
    inv[n] = pow(fact[n], mod - 2, mod)
    for i in range(n, 0, -1): inv[i - 1] = inv[i] * i % mod
    return fact, inv
def ext_gcd(a, b):                       # (g, x, y) con a*x + b*y = g
    if b == 0: return a, 1, 0
    g, x, y = ext_gcd(b, a % b)
    return g, y, x - (a // b) * y
def crt(r1, m1, r2, m2):                 # x = r1 (m1), x = r2 (m2) -> (x, lcm) o None
    g, p, _ = ext_gcd(m1, m2)
    if (r2 - r1) % g: return None
    l = m1 // g * m2
    return (r1 + (r2 - r1) // g * p % (m2 // g) * m1) % l, l

# --- math --- gcd/lcm con varios argumentos (3.9+); comb, perm, factorial, prod: exactos
def sieve(n):                            # criba con slicing (mucho más rápida que doble for)
    is_p = bytearray([1]) * (n + 1)
    is_p[0:2] = b"\x00\x00"
    for i in range(2, math.isqrt(n) + 1):
        if is_p[i]: is_p[i * i::i] = bytes(len(range(i * i, n + 1, i)))
    return is_p
# str(10**5000) da ValueError en 3.11+: sys.set_int_max_str_digits(0)

# --- exactos y floats ---
# Fraction("0.1") + Fraction("0.2") == Fraction("0.3"); Fraction(0.1) arrastra el error del float
# Fraction(math.pi).limit_denominator(1000) = 355/113
# round(2.5) = 2 (al par); escolar: Decimal("2.5").quantize(Decimal("1"), rounding=ROUND_HALF_UP)
# Imprimir floats SIEMPRE con formato: f"{x:.6f}" (str(0.00001) = "1e-05")
