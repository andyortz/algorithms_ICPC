// Tema: 07_Geometria/Geometria_3D — PARTE A: biblioteca 3D esencial.
// Base: Template/simple.cpp (int = long long). Compilar con GNU G++20 (-std=gnu++20).
// IPoint3 (long long, |coord| <= 1e9): predicados EXACTOS; dot/norm2/triple en __int128, cross en ll.
// Point3 (long double): construcciones (proyecciones, intersecciones, raíces); EPS3 según la escala.
// Pruebas: _pruebas/geometria-3d.cpp. Guía y tabla «¿Qué uso?»: README.md.

#ifndef GEO3D_A_ESENCIAL
#define GEO3D_A_ESENCIAL
#include "../../_base/template-simple.hpp"

using ll = long long;
using ld = long double;
using i128 = __int128;
const ld EPS3 = 1e-9;
const ld PI3 = acosl(-1.0L);

// Tipo "ancho" para productos: __int128 si T es entero, T si es flotante.
template<class T> using Wide = conditional_t<is_floating_point_v<T>, T, i128>;

// Uso: signo con tolerancia para flotantes y exacto para enteros (incluye __int128).
// Retorna: -1, 0 o 1. Complejidad: O(1).
template<class T> int sgn3(T x) {
    if constexpr (is_floating_point_v<T>) return (x > EPS3) - (x < -EPS3);
    else return (x > 0) - (x < 0);
}

// Uso: imprimir un __int128 (cout no lo soporta).
string toString128(i128 v) {
    if (v == 0) return "0";
    bool neg = v < 0; string s;
    while (v != 0) { int d = (int)(v % 10); s += char('0' + (d < 0 ? -d : d)); v /= 10; }
    if (neg) s += '-';
    reverse(s.begin(), s.end());
    return s;
}

// ============================================================================
// 1. PUNTO / VECTOR 3D
// ============================================================================
template<class T> struct P3 {
    T x = 0, y = 0, z = 0;
    P3() {}
    P3(T x_, T y_, T z_) : x(x_), y(y_), z(z_) {}
    template<class U> explicit P3(const P3<U>& o) : x(T(o.x)), y(T(o.y)), z(T(o.z)) {}
    P3 operator+(const P3& o) const { return {x + o.x, y + o.y, z + o.z}; }
    P3 operator-(const P3& o) const { return {x - o.x, y - o.y, z - o.z}; }
    P3 operator-() const { return {-x, -y, -z}; }
    P3 operator*(T k) const { return {x * k, y * k, z * k}; }
    P3 operator/(T k) const { return {x / k, y / k, z / k}; }      // entero: división truncada
    P3& operator+=(const P3& o) { return *this = *this + o; }
    P3& operator-=(const P3& o) { return *this = *this - o; }
    T& operator[](int i) { return i == 0 ? x : (i == 1 ? y : z); }
    T operator[](int i) const { return i == 0 ? x : (i == 1 ? y : z); }
    bool operator==(const P3& o) const { return x == o.x && y == o.y && z == o.z; }
    bool operator!=(const P3& o) const { return !(*this == o); }
    bool operator<(const P3& o) const {                              // lexicográfico (x,y,z)
        if (x != o.x) return x < o.x;
        if (y != o.y) return y < o.y;
        return z < o.z;
    }
};
using Point3 = P3<ld>;   // construcciones con raíces / divisiones
using IPoint3 = P3<ll>;  // predicados exactos

template<class T> ostream& operator<<(ostream& os, const P3<T>& p) {
    return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
}
template<class T> istream& operator>>(istream& is, P3<T>& p) { return is >> p.x >> p.y >> p.z; }

// Uso: producto punto a·b. Retorna: exacto (__int128) con enteros. O(1).
// Signo: >0 ángulo agudo, 0 perpendiculares, <0 obtuso.
template<class T> Wide<T> dot(const P3<T>& a, const P3<T>& b) {
    using W = Wide<T>;
    return W(a.x) * b.x + W(a.y) * b.y + W(a.z) * b.z;
}
// Uso: producto cruz a×b (perpendicular a ambos, |a×b| = área del paralelogramo). O(1).
// Retorna: P3<T>. Con long long es exacto si |componentes| <= 2e9 (cada término <= 4e18).
template<class T> P3<T> cross(const P3<T>& a, const P3<T>& b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
// Uso: producto triple a·(b×c) = det[a;b;c] = volumen orientado del paralelepípedo.
// Retorna: exacto con enteros (todo en __int128, |comp| <= 2e9 -> |res| <= ~5e28). O(1).
// Ejemplo: triple({1,0,0},{0,1,0},{0,0,1}) = 1.
template<class T> Wide<T> triple(const P3<T>& a, const P3<T>& b, const P3<T>& c) {
    using W = Wide<T>;
    return W(a.x) * (W(b.y) * c.z - W(b.z) * c.y)
         + W(a.y) * (W(b.z) * c.x - W(b.x) * c.z)
         + W(a.z) * (W(b.x) * c.y - W(b.y) * c.x);
}
// Uso: determinante 3x3 por filas. Igual a triple(fila0, fila1, fila2).
template<class T> Wide<T> det3(const P3<T>& r0, const P3<T>& r1, const P3<T>& r2) { return triple(r0, r1, r2); }

// Uso: norma cuadrada |a|^2 (exacta con enteros). Comparar distancias SIN sqrt.
template<class T> Wide<T> norm2(const P3<T>& a) { return dot(a, a); }
// Uso: norma |a| (aproximada, long double).
template<class T> ld norm(const P3<T>& a) { return sqrtl((ld)norm2(a)); }
template<class T> Wide<T> dist2(const P3<T>& a, const P3<T>& b) { return norm2(a - b); }
template<class T> ld dist(const P3<T>& a, const P3<T>& b) { return norm(a - b); }

// Uso: true si todas las componentes son 0 (exacto) o |c| <= EPS3 (flotante).
template<class T> bool isZero(const P3<T>& a) { return !sgn3(a.x) && !sgn3(a.y) && !sgn3(a.z); }

// Uso: vector unitario. Requiere a != 0 (si no, devuelve (0,0,0)).
inline Point3 unit(const Point3& a) { ld n = norm(a); return n < EPS3 ? Point3() : a / n; }
// Uso: proyección del vector u sobre la dirección v (v != 0). Retorna (u·v/|v|^2) v.
inline Point3 projVec(const Point3& u, const Point3& v) { return v * (dot(u, v) / norm2(v)); }
// Uso: componente de u perpendicular a v.
inline Point3 rejectVec(const Point3& u, const Point3& v) { return u - projVec(u, v); }

// Uso: un vector NO nulo perpendicular a v (v != 0). Exacto con enteros. O(1).
// Hace v × (eje menos alineado con v): bien condicionado también con flotantes.
// Ejemplo: anyPerp({0,0,5}) = {0,5,0}.
template<class T> P3<T> anyPerp(const P3<T>& v) {
    T ax = v.x < 0 ? -v.x : v.x, ay = v.y < 0 ? -v.y : v.y, az = v.z < 0 ? -v.z : v.z;
    if (ax <= ay && ax <= az) return {0, v.z, -v.y};   // v × (1,0,0)
    if (ay <= az) return {-v.z, 0, v.x};               // v × (0,1,0)
    return {v.y, -v.x, 0};                             // v × (0,0,1)
}
// Uso: ángulo entre u y v en [0, pi]. Usa atan2(|u×v|, u·v): estable cerca de 0 y pi
// (acos pierde precisión ahí y necesita recortar a [-1,1]). Vector nulo -> 0.
template<class T> ld angle(const P3<T>& u, const P3<T>& v) {
    return atan2l(norm(cross(Point3(u), Point3(v))), (ld)dot(u, v));
}
// Uso: acos protegido (por si se necesita). Recorta a [-1,1] antes de acos.
inline ld safeAcos(ld c) { return acosl(max((ld)-1, min((ld)1, c))); }
inline ld safeSqrt(ld x) { return sqrtl(max((ld)0, x)); }
inline ld toRad(ld deg) { return deg * PI3 / 180; }
inline ld toDeg(ld rad) { return rad * 180 / PI3; }

// Uso: interpolación a + (b-a)t. t=0 -> a, t=1 -> b, t=0.5 -> punto medio.
inline Point3 lerp(const Point3& a, const Point3& b, ld t) { return a + (b - a) * t; }
inline Point3 midpoint(const Point3& a, const Point3& b) { return (a + b) / 2; }
// Truco exacto: el punto medio de enteros puede no ser entero; usar 2*M = a+b.
template<class T> P3<T> midpoint2(const P3<T>& a, const P3<T>& b) { return a + b; }

// ---------------- Predicados (exactos con IPoint3) ----------------
// Uso: orientación de d respecto al plano orientado abc.
// Retorna: +1 si d está del lado hacia el que apunta (b-a)×(c-a) (desde d, a->b->c se ve
//   antihorario), -1 del otro lado, 0 si coplanares. Exacto con enteros. O(1).
template<class T> int orient(const P3<T>& a, const P3<T>& b, const P3<T>& c, const P3<T>& d) {
    return sgn3(triple(b - a, c - a, d - a));
}
template<class T> bool collinear(const P3<T>& a, const P3<T>& b, const P3<T>& c) { return isZero(cross(b - a, c - a)); }
template<class T> bool coplanar(const P3<T>& a, const P3<T>& b, const P3<T>& c, const P3<T>& d) { return orient(a, b, c, d) == 0; }
// Paralelos incluye antiparalelos; el vector nulo es paralelo a todo.
template<class T> bool parallelVec(const P3<T>& u, const P3<T>& v) { return isZero(cross(u, v)); }
template<class T> bool sameDirection(const P3<T>& u, const P3<T>& v) { return parallelVec(u, v) && sgn3(dot(u, v)) > 0; }
template<class T> bool perpendicularVec(const P3<T>& u, const P3<T>& v) { return sgn3(dot(u, v)) == 0; }

// ============================================================================
// 2. DISTANCIAS DIRECTAS Y TRUCOS ARITMÉTICOS
// ============================================================================
// Uso: Manhattan |dx|+|dy|+|dz| y Chebyshev max(|dx|,|dy|,|dz|). Exactas. O(1).
inline ll manhattan(const IPoint3& a, const IPoint3& b) { return llabs(a.x - b.x) + llabs(a.y - b.y) + llabs(a.z - b.z); }
inline ll chebyshev(const IPoint3& a, const IPoint3& b) { return max({llabs(a.x - b.x), llabs(a.y - b.y), llabs(a.z - b.z)}); }

// Uso: máxima distancia Manhattan entre dos puntos de pts. O(4n).
// Truco: |dx|+|dy|+|dz| = max sobre signos (s1,s2,s3) de s1dx+s2dy+s3dz.
//   Basta fijar s1=+1 (4 combinaciones): para cada una, max(f) - min(f).
inline ll maxManhattan(const vector<IPoint3>& pts) {
    ll best = 0;
    for (int m = 0; m < 4; m++) {
        ll sy = (m & 1) ? -1 : 1, sz = (m & 2) ? -1 : 1, mx = LLONG_MIN, mn = LLONG_MAX;
        for (auto& p : pts) { ll f = p.x + sy * p.y + sz * p.z; mx = max(mx, f); mn = min(mn, f); }
        if (!pts.empty()) best = max(best, mx - mn);
    }
    return best;
}
// Truco: Chebyshev en 3D NO se transforma en Manhattan como en 2D; pero max Chebyshev
// = max por eje de (max coord - min coord). Distancia a planos coordenados: |z| a XY, etc.
inline ll maxChebyshev(const vector<IPoint3>& pts) {
    if (pts.empty()) return 0;
    ll best = 0;
    for (int k = 0; k < 3; k++) {
        ll mx = LLONG_MIN, mn = LLONG_MAX;
        for (auto& p : pts) { mx = max(mx, p[k]); mn = min(mn, p[k]); }
        best = max(best, mx - mn);
    }
    return best;
}

// Uso: cantidad de puntos enteros en el segmento cerrado AB = gcd(|dx|,|dy|,|dz|) + 1.
// Ejemplo: (0,0,0)-(2,4,6) -> gcd=2 -> 3 puntos. Si A==B -> 1.
inline ll latticePointsSegment(const IPoint3& a, const IPoint3& b) {
    return gcd(gcd(llabs(b.x - a.x), llabs(b.y - a.y)), llabs(b.z - a.z)) + 1;
}
// Uso: dirección primitiva (dividida por el MCD). v != 0.
//   asLine=true: además fija el signo (primera coordenada no nula > 0) para que v y -v
//   coincidan (rectas). asLine=false conserva el sentido (rayos/direcciones).
inline IPoint3 normDir(IPoint3 v, bool asLine = true) {
    ll g = gcd(gcd(llabs(v.x), llabs(v.y)), llabs(v.z));
    if (g == 0) return v;
    v = v / g;
    if (asLine && (v.x < 0 || (v.x == 0 && (v.y < 0 || (v.y == 0 && v.z < 0))))) v = -v;
    return v;
}
// Uso: número de pares de vectores paralelos (misma recta) en vs. O(n log n).
// Vectores nulos se ignoran.
inline ll countParallelPairs(const vector<IPoint3>& vecs) {
    map<IPoint3, ll> cnt; ll res = 0;
    for (auto v : vecs) if (!isZero(v)) res += cnt[normDir(v)]++;
    return res;
}
// Uso: máximo número de puntos sobre una misma recta. O(n^2 log n). Duplicados cuentan.
inline ll maxCollinear(const vector<IPoint3>& pts) {
    ll n = pts.size(), best = min<ll>(n, 1);
    for (ll i = 0; i < n; i++) {
        map<IPoint3, ll> cnt; ll same = 0, top = 0;
        for (ll j = i + 1; j < n; j++) {
            IPoint3 d = pts[j] - pts[i];
            if (isZero(d)) { same++; continue; }
            top = max(top, ++cnt[normDir(d)]);
        }
        best = max(best, 1 + same + top);
    }
    return best;
}
// Uso: cuántos puntos de pts están en el plano de a,b,c (no colineales). O(n). Exacto.
inline ll countOnPlane(const IPoint3& a, const IPoint3& b, const IPoint3& c, const vector<IPoint3>& pts) {
    ll r = 0;
    for (auto& p : pts) r += orient(a, b, c, p) == 0;
    return r;
}
// Uso: ¿p y q equidistan de a? Exacto, sin sqrt.
inline bool equidistant(const IPoint3& a, const IPoint3& p, const IPoint3& q) { return dist2(a, p) == dist2(a, q); }

// ============================================================================
// 3. ROTACIONES Y TRANSFORMACIONES
// ============================================================================
// --- Rotaciones de 90° exactas (sentido antihorario mirando desde +eje hacia el origen) ---
// Regla: rotar 90° sobre Z: (x,y,z) -> (-y, x, z). Sobre X: (x,y,z) -> (x,-z,y).
//        Sobre Y: (x,y,z) -> (z, y, -x). k veces = 90k grados (k puede ser negativo).
template<class T> P3<T> rotX90(P3<T> p, int k = 1) { k = ((k % 4) + 4) % 4; while (k--) p = {p.x, -p.z, p.y}; return p; }
template<class T> P3<T> rotY90(P3<T> p, int k = 1) { k = ((k % 4) + 4) % 4; while (k--) p = {p.z, p.y, -p.x}; return p; }
template<class T> P3<T> rotZ90(P3<T> p, int k = 1) { k = ((k % 4) + 4) % 4; while (k--) p = {-p.y, p.x, p.z}; return p; }
// Reflexiones respecto a planos coordenados (cambian la orientación: det = -1).
template<class T> P3<T> reflXY(const P3<T>& p) { return {p.x, p.y, -p.z}; }
template<class T> P3<T> reflXZ(const P3<T>& p) { return {p.x, -p.y, p.z}; }
template<class T> P3<T> reflYZ(const P3<T>& p) { return {-p.x, p.y, p.z}; }

// Uso: las 24 rotaciones propias del cubo como matrices de permutación con signo (det=+1).
//   Con includeReflections=true devuelve las 48 (incluye espejos, det=-1).
// Aplicación típica: comparar figuras de voxeles "salvo rotación": normalizar cada
//   orientación (trasladar al mínimo, ordenar) y quedarse con la menor.
using SignedPerm = array<array<ll, 3>, 3>;
inline vector<SignedPerm> cubeRotations(bool includeReflections = false) {
    vector<SignedPerm> res;
    array<ll, 3> perm = {0, 1, 2};
    do {
        for (int s = 0; s < 8; s++) {
            SignedPerm m{};
            for (int r = 0; r < 3; r++) m[r][perm[r]] = (s >> r & 1) ? -1 : 1;
            ll det = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
                   - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
                   + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
            if (det == 1 || includeReflections) res.pb(m);
        }
    } while (next_permutation(perm.begin(), perm.end()));
    return res;
}
template<class T> P3<T> applyPerm(const SignedPerm& m, const P3<T>& p) {
    return {m[0][0] * p.x + m[0][1] * p.y + m[0][2] * p.z,
            m[1][0] * p.x + m[1][1] * p.y + m[1][2] * p.z,
            m[2][0] * p.x + m[2][1] * p.y + m[2][2] * p.z};
}

// --- Matriz 3x3 (long double) ---
struct Mat3 {
    ld a[3][3] = {};
    static Mat3 identity() { Mat3 m; for (int i = 0; i < 3; i++) m.a[i][i] = 1; return m; }
    Mat3 operator*(const Mat3& o) const {             // composición: (A*B)p = A(Bp)
        Mat3 r;
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) r.a[i][j] += a[i][k] * o.a[k][j];
        return r;
    }
    Point3 operator*(const Point3& p) const {
        return {a[0][0] * p.x + a[0][1] * p.y + a[0][2] * p.z,
                a[1][0] * p.x + a[1][1] * p.y + a[1][2] * p.z,
                a[2][0] * p.x + a[2][1] * p.y + a[2][2] * p.z};
    }
    Mat3 transpose() const { Mat3 r; for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) r.a[i][j] = a[j][i]; return r; }
    ld det() const {
        return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
             + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
    }
};
// Uso: rotación de ángulo t (radianes, antihoraria vista desde +eje) sobre X, Y o Z.
// La inversa de una rotación es su transpuesta.
inline Mat3 rotXMat(ld t) { Mat3 m = Mat3::identity(); ld c = cosl(t), s = sinl(t); m.a[1][1] = c; m.a[1][2] = -s; m.a[2][1] = s; m.a[2][2] = c; return m; }
inline Mat3 rotYMat(ld t) { Mat3 m = Mat3::identity(); ld c = cosl(t), s = sinl(t); m.a[0][0] = c; m.a[0][2] = s; m.a[2][0] = -s; m.a[2][2] = c; return m; }
inline Mat3 rotZMat(ld t) { Mat3 m = Mat3::identity(); ld c = cosl(t), s = sinl(t); m.a[0][0] = c; m.a[0][1] = -s; m.a[1][0] = s; m.a[1][1] = c; return m; }
// Uso: matriz de Rodrigues: rotación de ángulo t alrededor del eje (dirección) axis != 0,
//   antihoraria vista desde la punta de axis. R = I cos t + (1-cos t) k k^T + sin t [k]x.
inline Mat3 rodrigues(Point3 axis, ld t) {
    Point3 k = unit(axis); ld c = cosl(t), s = sinl(t), C = 1 - c;
    Mat3 m;
    m.a[0][0] = c + k.x * k.x * C;       m.a[0][1] = k.x * k.y * C - k.z * s; m.a[0][2] = k.x * k.z * C + k.y * s;
    m.a[1][0] = k.y * k.x * C + k.z * s; m.a[1][1] = c + k.y * k.y * C;       m.a[1][2] = k.y * k.z * C - k.x * s;
    m.a[2][0] = k.z * k.x * C - k.y * s; m.a[2][1] = k.z * k.y * C + k.x * s; m.a[2][2] = c + k.z * k.z * C;
    return m;
}
// Uso: rotar p ángulo t alrededor de la recta que pasa por o con dirección axis.
inline Point3 rotateAroundLine(const Point3& p, const Point3& o, const Point3& axis, ld t) {
    return o + rodrigues(axis, t) * (p - o);
}
// Uso: rotación de Rodrigues aplicada directamente (sin matriz).
inline Point3 rotateRodrigues(const Point3& v, const Point3& axis, ld t) {
    Point3 k = unit(axis);
    return v * cosl(t) + cross(k, v) * sinl(t) + k * (dot(k, v) * (1 - cosl(t)));
}

// --- Transformación afín 4x4 (coordenadas homogéneas, último renglón 0 0 0 1) ---
struct Mat4 {
    ld a[4][4] = {};
    static Mat4 identity() { Mat4 m; for (int i = 0; i < 4; i++) m.a[i][i] = 1; return m; }
    static Mat4 translate(const Point3& t) { Mat4 m = identity(); m.a[0][3] = t.x; m.a[1][3] = t.y; m.a[2][3] = t.z; return m; }
    static Mat4 scale(ld sx, ld sy, ld sz) { Mat4 m = identity(); m.a[0][0] = sx; m.a[1][1] = sy; m.a[2][2] = sz; return m; }
    static Mat4 fromMat3(const Mat3& r) { Mat4 m = identity(); for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) m.a[i][j] = r.a[i][j]; return m; }
    // Composición: (A*B) aplica primero B y luego A.
    Mat4 operator*(const Mat4& o) const {
        Mat4 r;
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int k = 0; k < 4; k++) r.a[i][j] += a[i][k] * o.a[k][j];
        return r;
    }
    Point3 apply(const Point3& p) const {   // punto (w=1): se traslada
        return {a[0][0] * p.x + a[0][1] * p.y + a[0][2] * p.z + a[0][3],
                a[1][0] * p.x + a[1][1] * p.y + a[1][2] * p.z + a[1][3],
                a[2][0] * p.x + a[2][1] * p.y + a[2][2] * p.z + a[2][3]};
    }
    Point3 applyVec(const Point3& v) const { // vector (w=0): NO se traslada
        return {a[0][0] * v.x + a[0][1] * v.y + a[0][2] * v.z,
                a[1][0] * v.x + a[1][1] * v.y + a[1][2] * v.z,
                a[2][0] * v.x + a[2][1] * v.y + a[2][2] * v.z};
    }
};
// Uso: rotación alrededor de un punto c: T(c) * R * T(-c).
inline Mat4 rotateAroundPoint(const Point3& c, const Mat3& r) {
    return Mat4::translate(c) * Mat4::fromMat3(r) * Mat4::translate(-c);
}

// --- Base local ortonormal (cambio de base) ---
// Uso: Frame f(o, w) crea base {u,v,w} ortonormal derecha con w = unit(dirección dada).
//   toLocal: coordenadas globales -> locales. toGlobal: inversa.
// Aplicación: llevar un plano a z=0 (geometría 2D en el plano), o un eje a la dirección Z.
struct Frame {
    Point3 o, u, v, w;
    Frame() : o(), u(1, 0, 0), v(0, 1, 0), w(0, 0, 1) {}
    Frame(Point3 origin, Point3 dirW) : o(origin) {
        w = unit(dirW); u = unit(anyPerp(w)); v = cross(w, u);
    }
    Point3 toLocal(const Point3& p) const { Point3 d = p - o; return {dot(d, u), dot(d, v), dot(d, w)}; }
    Point3 toGlobal(const Point3& q) const { return o + u * q.x + v * q.y + w * q.z; }
};

#endif
