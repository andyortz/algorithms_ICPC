// Tema: 07_Geometria/Geometria_3D — PARTE B: sólidos, intersecciones y distancias.
// Base: Template/simple.cpp (int = long long). Compilar con GNU G++20. Requiere la PARTE A.
// Cajas, prefix/diff 3D, voxeles, rectas, planos, triángulos, tetraedros, esferas y mallas.
// Los estados son enums explícitos; "6V"/"2A" = magnitudes multiplicadas (exactas).

#ifndef GEO3D_B_SOLIDOS
#define GEO3D_B_SOLIDOS
#include "a-geo3d-esencial.cpp"

// ============================================================================
// 1. CAJAS ALINEADAS A LOS EJES (exacto, long long)
// ============================================================================
// Box3 cerrada [lo.x,hi.x] x [lo.y,hi.y] x [lo.z,hi.z] con lo <= hi en cada eje.
struct Box3 { IPoint3 lo, hi; };

// Uso: caja desde dos vértices opuestos cualesquiera (ordena cada eje).
inline Box3 makeBox(const IPoint3& a, const IPoint3& b) {
    return {{min(a.x, b.x), min(a.y, b.y), min(a.z, b.z)}, {max(a.x, b.x), max(a.y, b.y), max(a.z, b.z)}};
}
// Uso: longitud de la intersección de [l1,r1] y [l2,r2]: max(0, min(r1,r2) - max(l1,l2)).
// Truco base de TODO lo de cajas: los ejes son independientes.
inline ll overlapLen(ll l1, ll r1, ll l2, ll r2) { return max(0LL, min(r1, r2) - max(l1, l2)); }
// Lados, volumen (ancho*alto*prof.), área superficial 2(ab+bc+ca), diagonal^2 = a^2+b^2+c^2.
// boxVolume en long long: lados <= ~2e6 seguros; si no, usar boxVolume128.
inline ll side(const Box3& b, int k) { return b.hi[k] - b.lo[k]; }
inline ll boxVolume(const Box3& b) { return side(b, 0) * side(b, 1) * side(b, 2); }
inline i128 boxVolume128(const Box3& b) { return (i128)side(b, 0) * side(b, 1) * side(b, 2); }
inline ll boxSurface(const Box3& b) { ll a = side(b, 0), c = side(b, 1), h = side(b, 2); return 2 * (a * c + c * h + h * a); }
inline ll boxDiag2(const Box3& b) { ll a = side(b, 0), c = side(b, 1), h = side(b, 2); return a * a + c * c + h * h; }
inline bool isCube(const Box3& b) { return side(b, 0) == side(b, 1) && side(b, 1) == side(b, 2); }
// Puntos enteros dentro de la caja cerrada (incluye borde) = prod(lado+1).
// Cubitos unitarios dentro = volumen (si las coordenadas son enteras).
inline ll latticePointsInBox(const Box3& b) { return (side(b, 0) + 1) * (side(b, 1) + 1) * (side(b, 2) + 1); }

// Uso: volumen de la intersección = producto de las 3 longitudes de solape. O(1).
inline ll interVolume(const Box3& a, const Box3& b) {
    ll r = 1;
    for (int k = 0; k < 3; k++) r *= overlapLen(a.lo[k], a.hi[k], b.lo[k], b.hi[k]);
    return r;
}
// Uso: caja intersección si existe (puede ser degenerada: cara/arista/vértice).
inline optional<Box3> interBox(const Box3& a, const Box3& b) {
    Box3 r;
    for (int k = 0; k < 3; k++) {
        r.lo[k] = max(a.lo[k], b.lo[k]); r.hi[k] = min(a.hi[k], b.hi[k]);
        if (r.lo[k] > r.hi[k]) return nullopt;
    }
    return r;
}
// Uso: ¿volumen de intersección POSITIVO? Cada eje con solape ESTRICTAMENTE > 0. (ABC361 B)
inline bool overlapPositive(const Box3& a, const Box3& b) {
    for (int k = 0; k < 3; k++) if (min(a.hi[k], b.hi[k]) - max(a.lo[k], b.lo[k]) <= 0) return false;
    return true;
}
// Uso: ¿se tocan o intersecan (cerradas)? Cada eje con solape >= 0.
inline bool boxesTouchOrOverlap(const Box3& a, const Box3& b) {
    for (int k = 0; k < 3; k++) if (min(a.hi[k], b.hi[k]) - max(a.lo[k], b.lo[k]) < 0) return false;
    return true;
}
// Uso: tipo de contacto entre dos cajas. Por eje: g = min(hi) - max(lo).
//   algún g<0 -> SEPARADAS; nº de ejes con g==0: 0 VOLUMEN, 1 CARA, 2 ARISTA, 3 VÉRTICE.
// Supone cajas de volumen positivo (para CARA = área de contacto > 0). (ABC312 E)
enum BoxContact { BC_SEPARATED, BC_VERTEX, BC_EDGE, BC_FACE, BC_VOLUME };
inline BoxContact boxContact(const Box3& a, const Box3& b) {
    int zeros = 0;
    for (int k = 0; k < 3; k++) {
        ll g = min(a.hi[k], b.hi[k]) - max(a.lo[k], b.lo[k]);
        if (g < 0) return BC_SEPARATED;
        zeros += g == 0;
    }
    return zeros == 0 ? BC_VOLUME : zeros == 1 ? BC_FACE : zeros == 2 ? BC_EDGE : BC_VERTEX;
}
// Uso: área de contacto por cara (0 si el contacto no es de cara).
inline ll contactArea(const Box3& a, const Box3& b) {
    if (boxContact(a, b) != BC_FACE) return 0;
    ll r = 1;
    for (int k = 0; k < 3; k++) { ll g = min(a.hi[k], b.hi[k]) - max(a.lo[k], b.lo[k]); if (g > 0) r *= g; }
    return r;
}
// Uso: ¿inner está contenida en outer (cerradas)?
inline bool containsBox(const Box3& outer, const Box3& inner) {
    for (int k = 0; k < 3; k++) if (inner.lo[k] < outer.lo[k] || inner.hi[k] > outer.hi[k]) return false;
    return true;
}
inline bool pointInBox(const Box3& b, const IPoint3& p) {
    for (int k = 0; k < 3; k++) if (p[k] < b.lo[k] || p[k] > b.hi[k]) return false;
    return true;
}
// Unión de dos cajas por inclusión-exclusión: |A|+|B|-|A∩B|.
inline ll unionVolume2(const Box3& a, const Box3& b) { return boxVolume(a) + boxVolume(b) - interVolume(a, b); }
// Intersección común de tres cajas (volumen).
inline ll interVolume3(const Box3& a, const Box3& b, const Box3& c) {
    auto ab = interBox(a, b);
    return ab ? interVolume(*ab, c) : 0;
}
// Uso: volumen cubierto por EXACTAMENTE 1, 2 y 3 de tres cajas. Retorna {V1,V2,V3}. (ABC343 E)
//   S1 = Σ|Ai|, S2 = Σ|Ai∩Aj|, S3 = |A1∩A2∩A3|:
//   V3 = S3, V2 = S2 - 3 S3, V1 = S1 - 2 S2 + 3 S3.
inline array<ll, 3> exactlyCovered3(const Box3& a, const Box3& b, const Box3& c) {
    ll s1 = boxVolume(a) + boxVolume(b) + boxVolume(c);
    ll s2 = interVolume(a, b) + interVolume(b, c) + interVolume(a, c);
    ll s3 = interVolume3(a, b, c);
    return {s1 - 2 * s2 + 3 * s3, s2 - 3 * s3, s3};
}
// Uso: caja contenedora (bounding box) de puntos no vacíos. O(n).
inline Box3 boundingBox(const vector<IPoint3>& pts) {
    Box3 b{pts[0], pts[0]};
    for (auto& p : pts) for (int k = 0; k < 3; k++) { b.lo[k] = min(b.lo[k], p[k]); b.hi[k] = max(b.hi[k], p[k]); }
    return b;
}

// ---------------- Prefix sums 3D y difference arrays 3D ----------------
// Pref3: suma de un bloque [x1..x2]x[y1..y2]x[z1..z2] (índices 0-based inclusivos) en O(1).
//   Construcción O(X*Y*Z). Inclusión-exclusión con 8 esquinas. (ABC366 D)
struct Pref3 {
    int X, Y, Z; vector<ll> s;   // s tiene (X+1)(Y+1)(Z+1) celdas, borde 0
    int id(int x, int y, int z) const { return (x * (Y + 1) + y) * (Z + 1) + z; }
    // a(x,y,z) devuelve el valor de la celda 0-based.
    template<class Fn> Pref3(int X_, int Y_, int Z_, Fn a) : X(X_), Y(Y_), Z(Z_), s((X_ + 1) * (Y_ + 1) * (Z_ + 1), 0) {
        for (int x = 1; x <= X; x++) for (int y = 1; y <= Y; y++) for (int z = 1; z <= Z; z++)
            s[id(x, y, z)] = a(x - 1, y - 1, z - 1)
                + s[id(x - 1, y, z)] + s[id(x, y - 1, z)] + s[id(x, y, z - 1)]
                - s[id(x - 1, y - 1, z)] - s[id(x - 1, y, z - 1)] - s[id(x, y - 1, z - 1)]
                + s[id(x - 1, y - 1, z - 1)];
    }
    ll query(int x1, int x2, int y1, int y2, int z1, int z2) const {
        if (x1 > x2 || y1 > y2 || z1 > z2) return 0;
        x2++; y2++; z2++;
        return s[id(x2, y2, z2)] - s[id(x1, y2, z2)] - s[id(x2, y1, z2)] - s[id(x2, y2, z1)]
             + s[id(x1, y1, z2)] + s[id(x1, y2, z1)] + s[id(x2, y1, z1)] - s[id(x1, y1, z1)];
    }
};
// Diff3: sumar v a todo un bloque en O(1); build() reconstruye los valores en O(XYZ).
struct Diff3 {
    int X, Y, Z; vector<ll> d;
    Diff3(int X_, int Y_, int Z_) : X(X_), Y(Y_), Z(Z_), d((X_ + 1) * (Y_ + 1) * (Z_ + 1), 0) {}
    int id(int x, int y, int z) const { return (x * (Y + 1) + y) * (Z + 1) + z; }
    void add(int x1, int x2, int y1, int y2, int z1, int z2, ll v) {   // inclusivo, 0-based
        x2++; y2++; z2++;
        d[id(x1, y1, z1)] += v; d[id(x2, y1, z1)] -= v; d[id(x1, y2, z1)] -= v; d[id(x1, y1, z2)] -= v;
        d[id(x2, y2, z1)] += v; d[id(x2, y1, z2)] += v; d[id(x1, y2, z2)] += v; d[id(x2, y2, z2)] -= v;
    }
    vector<ll> build() const {   // valor de (x,y,z) en res[(x*Y + y)*Z + z]
        vector<ll> a = d;
        for (int x = 0; x <= X; x++) for (int y = 0; y <= Y; y++) for (int z = 1; z <= Z; z++) a[id(x, y, z)] += a[id(x, y, z - 1)];
        for (int x = 0; x <= X; x++) for (int y = 1; y <= Y; y++) for (int z = 0; z <= Z; z++) a[id(x, y, z)] += a[id(x, y - 1, z)];
        for (int x = 1; x <= X; x++) for (int y = 0; y <= Y; y++) for (int z = 0; z <= Z; z++) a[id(x, y, z)] += a[id(x - 1, y, z)];
        vector<ll> res(X * Y * Z);
        for (int x = 0; x < X; x++) for (int y = 0; y < Y; y++) for (int z = 0; z < Z; z++) res[(x * Y + y) * Z + z] = a[id(x, y, z)];
        return res;
    }
};
// Uso: volumen cubierto por exactamente k cajas, para k = 0..n (res[0] = volumen libre dentro
//   de la bounding box). Compresión de coordenadas + Diff3. O(n^3) tiempo y memoria (n <= ~150).
//   unionVolume = suma de res[k] para k >= 1.
inline vector<ll> coverVolumes(const vector<Box3>& boxes) {
    int n = boxes.size();
    vector<ll> res(n + 1, 0);
    if (n == 0) return res;
    vector<ll> cs[3];
    for (auto& b : boxes) for (int k = 0; k < 3; k++) { cs[k].pb(b.lo[k]); cs[k].pb(b.hi[k]); }
    for (int k = 0; k < 3; k++) { sort(cs[k].begin(), cs[k].end()); cs[k].erase(unique(cs[k].begin(), cs[k].end()), cs[k].end()); }
    int X = cs[0].size() - 1, Y = cs[1].size() - 1, Z = cs[2].size() - 1;
    if (X <= 0 || Y <= 0 || Z <= 0) return res;   // todas las cajas son planas
    auto idx = [&](int k, ll v) { return (int)(lower_bound(cs[k].begin(), cs[k].end(), v) - cs[k].begin()); };
    Diff3 df(X, Y, Z);
    for (auto& b : boxes) {
        int x1 = idx(0, b.lo.x), x2 = idx(0, b.hi.x) - 1, y1 = idx(1, b.lo.y), y2 = idx(1, b.hi.y) - 1;
        int z1 = idx(2, b.lo.z), z2 = idx(2, b.hi.z) - 1;
        if (x1 <= x2 && y1 <= y2 && z1 <= z2) df.add(x1, x2, y1, y2, z1, z2, 1);
    }
    vector<ll> cnt = df.build();
    for (int x = 0; x < X; x++) for (int y = 0; y < Y; y++) for (int z = 0; z < Z; z++)
        res[cnt[(x * Y + y) * Z + z]] += (cs[0][x + 1] - cs[0][x]) * (cs[1][y + 1] - cs[1][y]) * (cs[2][z + 1] - cs[2][z]);
    return res;
}
inline ll unionVolume(const vector<Box3>& boxes) {
    auto r = coverVolumes(boxes); ll s = 0;
    for (size_t k = 1; k < r.size(); k++) s += r[k];
    return s;
}

// ---------------- Voxeles (cubitos unitarios) ----------------
// Uso: área superficial de una figura formada por cubitos unitarios (celda (x,y,z) =
//   [x,x+1]x[y,y+1]x[z,z+1]). exteriorOnly=true descuenta cavidades cerradas (flood fill
//   desde afuera con 6 vecinos). O(V) con V = volumen de la bounding box + borde.
inline ll voxelSurface(const vector<IPoint3>& cubes, bool exteriorOnly) {
    if (cubes.empty()) return 0;
    Box3 bb = boundingBox(cubes);
    ll X = side(bb, 0) + 3, Y = side(bb, 1) + 3, Z = side(bb, 2) + 3;   // borde de 1 celda
    auto id = [&](ll x, ll y, ll z) { return (x * Y + y) * Z + z; };
    vector<char> full(X * Y * Z, 0), outside(X * Y * Z, 0);
    for (auto& c : cubes) full[id(c.x - bb.lo.x + 1, c.y - bb.lo.y + 1, c.z - bb.lo.z + 1)] = 1;
    const int D[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
    if (exteriorOnly) {
        vector<array<ll, 3>> st = {{0, 0, 0}}; outside[0] = 1;
        while (!st.empty()) {
            auto [x, y, z] = st.back(); st.pop_back();
            for (auto& d : D) {
                ll nx = x + d[0], ny = y + d[1], nz = z + d[2];
                if (nx < 0 || ny < 0 || nz < 0 || nx >= X || ny >= Y || nz >= Z) continue;
                ll j = id(nx, ny, nz);
                if (!full[j] && !outside[j]) { outside[j] = 1; st.pb({nx, ny, nz}); }
            }
        }
    }
    ll res = 0;
    for (ll x = 1; x + 1 < X; x++) for (ll y = 1; y + 1 < Y; y++) for (ll z = 1; z + 1 < Z; z++) {
        if (!full[id(x, y, z)]) continue;
        for (auto& d : D) {
            ll j = id(x + d[0], y + d[1], z + d[2]);
            if (!full[j] && (!exteriorOnly || outside[j])) res++;
        }
    }
    return res;
}

// ============================================================================
// 2. RECTAS, RAYOS Y SEGMENTOS
// ============================================================================
// Line3: p + t d, con d != 0 (dirección nula = recta indefinida: verificar antes).
struct Line3 {
    Point3 p, d;
    Line3() {}
    Line3(Point3 p_, Point3 d_) : p(p_), d(d_) {}
    Point3 at(ld t) const { return p + d * t; }
};
inline Line3 lineThrough(const Point3& a, const Point3& b) { return Line3(a, b - a); }   // requiere a != b

// Uso: parámetro t del pie de la perpendicular de q sobre l. Proyección = l.at(t).
inline ld paramOnLine(const Line3& l, const Point3& q) { return dot(q - l.p, l.d) / norm2(l.d); }
inline Point3 projOnLine(const Line3& l, const Point3& q) { return l.at(paramOnLine(l, q)); }
// Uso: distancia punto-recta = |d × (q-p)| / |d|.
inline ld distPointLine(const Line3& l, const Point3& q) { return norm(cross(l.d, q - l.p)) / norm(l.d); }
inline bool pointOnLine(const Line3& l, const Point3& q) { return distPointLine(l, q) <= EPS3; }
// Uso: punto del segmento [a,b] más cercano a q (a==b permitido). O(1).
inline Point3 closestOnSegment(const Point3& a, const Point3& b, const Point3& q) {
    ld L = norm2(b - a);
    if (L <= EPS3 * EPS3) return a;
    ld t = max((ld)0, min((ld)1, dot(q - a, b - a) / L));
    return a + (b - a) * t;
}
inline ld distPointSegment(const Point3& a, const Point3& b, const Point3& q) { return dist(q, closestOnSegment(a, b, q)); }
// Exacto: ¿p está en el segmento cerrado [a,b]? (a==b permitido)
template<class T> bool onSegment(const P3<T>& a, const P3<T>& b, const P3<T>& p) {
    return collinear(a, b, p) && sgn3(dot(p - a, p - b)) <= 0;
}

// Relación entre dos rectas en 3D. ¡No paralelas NO implica que se corten! (alabeadas)
enum LineRel { LR_SKEW, LR_INTERSECT, LR_PARALLEL, LR_COINCIDENT };
// Versión EXACTA con rectas a1b1 y a2b2 enteras (a != b).
inline LineRel lineRelationExact(const IPoint3& a1, const IPoint3& b1, const IPoint3& a2, const IPoint3& b2) {
    IPoint3 d1 = b1 - a1, d2 = b2 - a2;
    if (isZero(cross(d1, d2))) return collinear(a1, b1, a2) ? LR_COINCIDENT : LR_PARALLEL;
    return orient(a1, b1, a2, b2) == 0 ? LR_INTERSECT : LR_SKEW;
}
// Uso: distancia entre rectas. Paralelas -> punto-recta. Si no: |(p2-p1)·(d1×d2)| / |d1×d2|.
inline ld distLineLine(const Line3& l1, const Line3& l2) {
    Point3 n = cross(l1.d, l2.d);
    if (norm(n) <= EPS3 * norm(l1.d) * norm(l2.d)) return distPointLine(l1, l2.p);
    return fabsl(dot(l2.p - l1.p, n)) / norm(n);
}
// Versión flotante de la relación (tolerancia en unidades de distancia).
inline LineRel lineRelation(const Line3& l1, const Line3& l2) {
    if (norm(cross(unit(l1.d), unit(l2.d))) <= EPS3) return distPointLine(l1, l2.p) <= EPS3 ? LR_COINCIDENT : LR_PARALLEL;
    return distLineLine(l1, l2) <= EPS3 ? LR_INTERSECT : LR_SKEW;
}
// Uso: puntos más cercanos c1 en l1 y c2 en l2 (perpendicular común = segmento c1c2).
//   Requiere rectas NO paralelas. Si se cortan, c1 == c2 es la intersección.
//   n = d1×d2, c1 = p1 + d1 ((p2-p1)·(d2×n))/(d1·(d2×n)), simétrico para c2.
inline pair<Point3, Point3> closestPointsLines(const Line3& l1, const Line3& l2) {
    Point3 n = cross(l1.d, l2.d), n1 = cross(l1.d, n), n2 = cross(l2.d, n);
    Point3 c1 = l1.p + l1.d * (dot(l2.p - l1.p, n2) / dot(l1.d, n2));
    Point3 c2 = l2.p + l2.d * (dot(l1.p - l2.p, n1) / dot(l2.d, n1));
    return {c1, c2};
}
// Uso: intersección de dos rectas si es un único punto. Retorna false si son alabeadas,
//   paralelas o coincidentes.
inline bool lineIntersection(const Line3& l1, const Line3& l2, Point3& out) {
    if (lineRelation(l1, l2) != LR_INTERSECT) return false;
    out = closestPointsLines(l1, l2).first;
    return true;
}
// Uso: ángulo entre rectas en [0, pi/2] (no orientadas).
inline ld angleLines(const Point3& d1, const Point3& d2) { return atan2l(norm(cross(d1, d2)), fabsl(dot(d1, d2))); }

// Uso: distancia entre segmentos [a,b] y [c,d] (cualquiera puede ser degenerado). O(1).
//   La distancia es convexa en (s,t) ∈ [0,1]^2: mínimo interior (perpendicular común con
//   parámetros válidos) o en el borde (extremo contra segmento).
inline ld distSegSeg(const Point3& a, const Point3& b, const Point3& c, const Point3& d) {
    ld best = min({distPointSegment(c, d, a), distPointSegment(c, d, b), distPointSegment(a, b, c), distPointSegment(a, b, d)});
    Point3 d1 = b - a, d2 = d - c, n = cross(d1, d2);
    if (norm(d1) > EPS3 && norm(d2) > EPS3 && norm(n) > EPS3 * norm(d1) * norm(d2)) {
        Point3 n1 = cross(d1, n), n2 = cross(d2, n);
        ld s = dot(c - a, n2) / dot(d1, n2), t = dot(a - c, n1) / dot(d2, n1);
        if (s >= 0 && s <= 1 && t >= 0 && t <= 1) best = min(best, dist(a + d1 * s, c + d2 * t));
    }
    return best;
}
// Uso: ¿se cortan los segmentos cerrados [a,b] y [c,d]? EXACTO con enteros
//   (|coord| <= 1e9). Maneja degenerados, colineales y alabeados. O(1).
inline bool segSegIntersectExact(const IPoint3& a, const IPoint3& b, const IPoint3& c, const IPoint3& d) {
    if (a == b) return onSegment(c, d, a);
    if (c == d) return onSegment(a, b, c);
    if (orient(a, b, c, d) != 0) return false;                 // no coplanares
    IPoint3 n = cross(b - a, d - c);
    if (isZero(n)) {                                           // paralelos
        if (!collinear(a, b, c)) return false;
        return onSegment(a, b, c) || onSegment(a, b, d) || onSegment(c, d, a) || onSegment(c, d, b);
    }
    // Coplanares no paralelos: lado 2D = componente k de la cruz (k = mayor |n_k|).
    int k = 0;
    for (int j = 1; j < 3; j++) if (llabs(n[j]) > llabs(n[k])) k = j;
    auto sd = [&](const IPoint3& o, const IPoint3& e, const IPoint3& q) { return sgn3(cross(e - o, q - o)[k]); };
    return sd(a, b, c) * sd(a, b, d) <= 0 && sd(c, d, a) * sd(c, d, b) <= 0;
}

// ============================================================================
// 3. PLANOS
// ============================================================================
// Plane (long double): dot(n, x) = d con |n| = 1 (las fábricas normalizan).
//   Ecuación Ax+By+Cz+D=0 con (A,B,C) = n, D = -d. side(p) = distancia CON SIGNO
//   (>0 del lado al que apunta n).
struct Plane {
    Point3 n; ld d = 0;
    Plane() {}
    Plane(Point3 n_, ld d_) : n(n_), d(d_) { ld L = norm(n); n = n / L; d /= L; }   // n != 0
    static Plane fromPointNormal(const Point3& p, const Point3& nrm) { return Plane(nrm, dot(nrm, p)); }
    static Plane fromPoints(const Point3& a, const Point3& b, const Point3& c) {    // a,b,c no colineales
        Point3 nrm = cross(b - a, c - a); return Plane(nrm, dot(nrm, a));
    }
    static Plane fromCoeffs(ld A, ld B, ld C, ld D) { return Plane(Point3(A, B, C), -D); }
    array<ld, 4> coeffs() const { return {n.x, n.y, n.z, -d}; }
    ld side(const Point3& p) const { return dot(n, p) - d; }
    ld distTo(const Point3& p) const { return fabsl(side(p)); }
    int classify(const Point3& p) const { return sgn3(side(p)); }       // 1, 0, -1
    bool contains(const Point3& p) const { return classify(p) == 0; }
    Point3 proj(const Point3& p) const { return p - n * side(p); }       // proyección ortogonal
    Point3 reflect(const Point3& p) const { return p - n * (2 * side(p)); }
    Point3 anyPoint() const { return n * d; }
    // Base local: (u, v) en el plano y w = n. to2D da coordenadas 2D dentro del plano
    //   (preserva distancias, ángulos y áreas: se puede usar toda la geometría 2D).
    Frame frame() const { return Frame(anyPoint(), n); }
    pair<ld, ld> to2D(const Point3& p) const { Point3 q = frame().toLocal(p); return {q.x, q.y}; }
    Point3 from2D(ld u, ld v) const { return frame().toGlobal(Point3(u, v, 0)); }
};
// Mismo lado (estricto) / lados opuestos (estricto).
inline bool sameSide(const Plane& pl, const Point3& a, const Point3& b) { return pl.classify(a) * pl.classify(b) > 0; }
inline bool oppositeSides(const Plane& pl, const Point3& a, const Point3& b) { return pl.classify(a) * pl.classify(b) < 0; }

// IPlane EXACTO por tres puntos enteros: n = (b-a)×(c-a) (long long), d = n·a (__int128).
//   side(p) exacto en __int128 (|coord| <= 1e9: |n| <= 8e18, |n·p| <= 2.4e28). Clasificar
//   miles de puntos contra el mismo plano sin recalcular la cruz.
struct IPlane {
    IPoint3 n; i128 d = 0;
    IPlane() {}
    IPlane(const IPoint3& a, const IPoint3& b, const IPoint3& c) : n(cross(b - a, c - a)), d(dot(n, a)) {}
    bool valid() const { return !isZero(n); }   // false si a,b,c colineales
    int classify(const IPoint3& p) const { return sgn3(dot(n, p) - d); }
};

enum InterKind { IK_NONE, IK_POINT, IK_LINE, IK_PLANE };
// Uso: intersección recta-plano. IK_POINT con punto y parámetro t; IK_LINE si la recta está
//   contenida; IK_NONE si es paralela y fuera.
struct LPResult { InterKind kind; Point3 p; ld t; };
inline LPResult interLinePlane(const Line3& l, const Plane& pl) {
    ld den = dot(pl.n, l.d), num = pl.side(l.p);
    if (fabsl(den) <= EPS3 * norm(l.d)) return {fabsl(num) <= EPS3 ? IK_LINE : IK_NONE, Point3(), 0};
    ld t = -num / den;
    return {IK_POINT, l.at(t), t};
}
// Uso: intersección segmento [a,b]-plano. IK_POINT solo si el corte cae en el segmento.
inline LPResult interSegmentPlane(const Point3& a, const Point3& b, const Plane& pl) {
    if (norm(b - a) <= EPS3) return {pl.contains(a) ? IK_POINT : IK_NONE, a, 0};
    LPResult r = interLinePlane(lineThrough(a, b), pl);
    if (r.kind == IK_POINT && (r.t < -EPS3 || r.t > 1 + EPS3)) r.kind = IK_NONE;
    return r;
}
// Exacto: ¿el segmento cerrado [p,q] toca el plano abc? (a,b,c no colineales)
inline bool segmentTouchesPlaneExact(const IPoint3& a, const IPoint3& b, const IPoint3& c, const IPoint3& p, const IPoint3& q) {
    return orient(a, b, c, p) * orient(a, b, c, q) <= 0;
}
// Uso: intersección de dos planos. IK_LINE con la recta; IK_PLANE si coinciden;
//   IK_NONE si son paralelos distintos.
struct PPResult { InterKind kind; Line3 line; };
inline PPResult interPlanePlane(const Plane& p1, const Plane& p2) {
    Point3 dir = cross(p1.n, p2.n);
    if (norm(dir) <= EPS3) return {fabsl(p2.side(p1.anyPoint())) <= EPS3 ? IK_PLANE : IK_NONE, Line3()};
    ld a12 = dot(p1.n, p2.n), det = norm2(dir);           // |n1|=|n2|=1 => det = 1 - a12^2
    ld al = (p1.d - p2.d * a12) / det, be = (p2.d - p1.d * a12) / det;
    return {IK_LINE, Line3(p1.n * al + p2.n * be, dir)};
}
// Uso: intersección de tres planos. true y el punto si es único (det de normales != 0).
//   x = (d1 (n2×n3) + d2 (n3×n1) + d3 (n1×n2)) / (n1·(n2×n3)).
inline bool interThreePlanes(const Plane& a, const Plane& b, const Plane& c, Point3& out) {
    ld det = triple(a.n, b.n, c.n);
    if (fabsl(det) <= EPS3) return false;
    out = (cross(b.n, c.n) * a.d + cross(c.n, a.n) * b.d + cross(a.n, b.n) * c.d) / det;
    return true;
}
// Relación de planos: IK_PLANE coincidentes, IK_NONE paralelos, IK_LINE secantes.
inline InterKind planeRelation(const Plane& p1, const Plane& p2) { return interPlanePlane(p1, p2).kind; }
// Ángulo diedro (agudo) entre planos en [0, pi/2]; ángulo recta-plano en [0, pi/2].
inline ld anglePlanes(const Plane& p1, const Plane& p2) { return atan2l(norm(cross(p1.n, p2.n)), fabsl(dot(p1.n, p2.n))); }
inline ld angleLinePlane(const Point3& d, const Plane& pl) { return atan2l(fabsl(dot(d, pl.n)), norm(cross(d, pl.n))); }

// Proyección a planos coordenados: quitar el eje k (0=x,1=y,2=z). Preserva orientación 2D
//   si se usa el orden cíclico: quitar x -> (y,z), quitar y -> (z,x), quitar z -> (x,y).
template<class T> pair<T, T> dropAxis(const P3<T>& p, int k) {
    if (k == 0) return {p.y, p.z};
    if (k == 1) return {p.z, p.x};
    return {p.x, p.y};
}

// ============================================================================
// 4. TRIÁNGULOS
// ============================================================================
// Normal sin normalizar (|N| = 2·área). Exacta con enteros.
template<class T> P3<T> triNormal(const P3<T>& a, const P3<T>& b, const P3<T>& c) { return cross(b - a, c - a); }
template<class T> ld triArea(const P3<T>& a, const P3<T>& b, const P3<T>& c) { return norm(triNormal(a, b, c)) / 2; }
// (2·Área)^2 exacto en __int128: |coord| <= 9e8 (grado 4: 192·C^4 < 1.7e38).
inline i128 triArea2Squared(const IPoint3& a, const IPoint3& b, const IPoint3& c) { return norm2(triNormal(a, b, c)); }
template<class T> ld triPerimeter(const P3<T>& a, const P3<T>& b, const P3<T>& c) { return dist(a, b) + dist(b, c) + dist(c, a); }
inline Point3 triCentroid(const Point3& a, const Point3& b, const Point3& c) { return (a + b + c) / 3; }
template<class T> bool triDegenerate(const P3<T>& a, const P3<T>& b, const P3<T>& c) { return collinear(a, b, c); }

// Uso: coordenadas baricéntricas (wa, wb, wc) de la proyección de p sobre el plano abc.
//   p = wa a + wb b + wc c; dentro del triángulo <=> las tres >= 0. Triángulo no degenerado.
inline array<ld, 3> barycentric(const Point3& a, const Point3& b, const Point3& c, const Point3& p) {
    Point3 n = cross(b - a, c - a); ld n2 = norm2(n);
    ld wa = dot(cross(c - b, p - b), n) / n2, wb = dot(cross(a - c, p - c), n) / n2;
    return {wa, wb, 1 - wa - wb};
}
// Uso: ¿p está en el triángulo cerrado abc (en 3D)? EXACTO. Triángulo no degenerado.
//   Coplanar + los tres "lados" sin mezcla de signos (componente k dominante de la normal).
inline bool pointInTriangleExact(const IPoint3& a, const IPoint3& b, const IPoint3& c, const IPoint3& p) {
    if (orient(a, b, c, p) != 0) return false;
    IPoint3 n = triNormal(a, b, c);
    int k = 0;
    for (int j = 1; j < 3; j++) if (llabs(n[j]) > llabs(n[k])) k = j;
    int s1 = sgn3(cross(b - a, p - a)[k]), s2 = sgn3(cross(c - b, p - b)[k]), s3 = sgn3(cross(a - c, p - c)[k]);
    bool neg = s1 < 0 || s2 < 0 || s3 < 0, pos = s1 > 0 || s2 > 0 || s3 > 0;
    return !(neg && pos);
}
// Uso: punto del triángulo abc más cercano a p (Ericson, regiones de Voronoi). O(1).
//   Triángulo degenerado: se usa el mínimo sobre sus tres lados.
inline Point3 closestPointTriangle(const Point3& p, const Point3& a, const Point3& b, const Point3& c) {
    if (norm(cross(b - a, c - a)) <= EPS3) {
        Point3 best = closestOnSegment(a, b, p);
        for (Point3 q : {closestOnSegment(b, c, p), closestOnSegment(c, a, p)}) if (dist(q, p) < dist(best, p)) best = q;
        return best;
    }
    Point3 ab = b - a, ac = c - a, ap = p - a;
    ld d1 = dot(ab, ap), d2 = dot(ac, ap);
    if (d1 <= 0 && d2 <= 0) return a;
    Point3 bp = p - b; ld d3 = dot(ab, bp), d4 = dot(ac, bp);
    if (d3 >= 0 && d4 <= d3) return b;
    ld vc = d1 * d4 - d3 * d2;
    if (vc <= 0 && d1 >= 0 && d3 <= 0) return a + ab * (d1 / (d1 - d3));
    Point3 cp = p - c; ld d5 = dot(ab, cp), d6 = dot(ac, cp);
    if (d6 >= 0 && d5 <= d6) return c;
    ld vbb = d5 * d2 - d1 * d6;
    if (vbb <= 0 && d2 >= 0 && d6 <= 0) return a + ac * (d2 / (d2 - d6));
    ld va = d3 * d6 - d5 * d4;
    if (va <= 0 && d4 - d3 >= 0 && d5 - d6 >= 0) return b + (c - b) * ((d4 - d3) / ((d4 - d3) + (d5 - d6)));
    ld den = 1 / (va + vbb + vc);
    return a + ab * (vbb * den) + ac * (vc * den);
}
inline ld distPointTriangle(const Point3& p, const Point3& a, const Point3& b, const Point3& c) {
    return dist(p, closestPointTriangle(p, a, b, c));
}
// Uso: ¿el segmento cerrado [p,q] toca el triángulo cerrado abc? EXACTO. Triángulo no
//   degenerado. Caso coplanar: extremo dentro o cruce con algún lado.
inline bool segTriangleExact(const IPoint3& p, const IPoint3& q, const IPoint3& a, const IPoint3& b, const IPoint3& c) {
    int o1 = orient(a, b, c, p), o2 = orient(a, b, c, q);
    if (o1 * o2 > 0) return false;
    if (o1 == 0 && o2 == 0)
        return pointInTriangleExact(a, b, c, p) || pointInTriangleExact(a, b, c, q) ||
               segSegIntersectExact(p, q, a, b) || segSegIntersectExact(p, q, b, c) || segSegIntersectExact(p, q, c, a);
    // La recta pq atraviesa el plano dentro del segmento: verificar que pase por el triángulo.
    int s1 = orient(p, q, a, b), s2 = orient(p, q, b, c), s3 = orient(p, q, c, a);
    bool neg = s1 < 0 || s2 < 0 || s3 < 0, pos = s1 > 0 || s2 > 0 || s3 > 0;
    return !(neg && pos);
}
// Uso: intersección rayo o + t·dir (t >= 0) con triángulo (Möller–Trumbore). Retorna t.
//   Rayos paralelos al plano (incluido coplanar) -> nullopt. Aproximado.
inline optional<ld> rayTriangle(const Point3& o, const Point3& dir, const Point3& a, const Point3& b, const Point3& c) {
    Point3 e1 = b - a, e2 = c - a, h = cross(dir, e2);
    ld det = dot(e1, h);
    if (fabsl(det) <= EPS3 * norm(dir) * norm(e1) * norm(e2)) return nullopt;
    ld inv = 1 / det; Point3 s = o - a;
    ld u = dot(s, h) * inv;
    if (u < -EPS3 || u > 1 + EPS3) return nullopt;
    Point3 q = cross(s, e1);
    ld v = dot(dir, q) * inv;
    if (v < -EPS3 || u + v > 1 + EPS3) return nullopt;
    ld t = dot(e2, q) * inv;
    if (t < -EPS3) return nullopt;
    return t;
}
// Uso: punto donde el segmento [p,q] corta al triángulo (si no es coplanar). Aproximado.
//   Comprobar antes con segTriangleExact si las coordenadas son enteras.
inline optional<Point3> segTrianglePoint(const Point3& p, const Point3& q, const Point3& a, const Point3& b, const Point3& c) {
    auto t = rayTriangle(p, q - p, a, b, c);
    if (!t || *t > 1 + EPS3) return nullopt;
    return p + (q - p) * *t;
}

// ============================================================================
// 5. TETRAEDROS
// ============================================================================
// Uso: 6·V con signo = (B-A)·((C-A)×(D-A)). EXACTO con enteros. >0 si D está del lado de
//   la normal de ABC (ABC antihorario visto desde D). V = |6V| / 6.
template<class T> Wide<T> tetVolume6(const P3<T>& a, const P3<T>& b, const P3<T>& c, const P3<T>& d) {
    return triple(b - a, c - a, d - a);
}
template<class T> ld tetVolume(const P3<T>& a, const P3<T>& b, const P3<T>& c, const P3<T>& d) {
    ld v = (ld)tetVolume6(a, b, c, d); return fabsl(v) / 6;
}
template<class T> bool tetDegenerate(const P3<T>& a, const P3<T>& b, const P3<T>& c, const P3<T>& d) { return coplanar(a, b, c, d); }
// Uso: ¿p dentro del tetraedro cerrado abcd (no degenerado)? EXACTO.
//   Para cada cara, p debe estar del mismo lado que el vértice opuesto (o sobre la cara).
inline bool pointInTetraExact(const IPoint3& a, const IPoint3& b, const IPoint3& c, const IPoint3& d, const IPoint3& p) {
    IPoint3 v[4] = {a, b, c, d};
    for (int i = 0; i < 4; i++) {
        IPoint3 f0 = v[(i + 1) % 4], f1 = v[(i + 2) % 4], f2 = v[(i + 3) % 4];
        int ref = orient(f0, f1, f2, v[i]), sp = orient(f0, f1, f2, p);
        if (sp != 0 && sp != ref) return false;
    }
    return true;
}
// Altura desde d sobre la cara abc = 3V/Área(abc) = |6V| / |(b-a)×(c-a)|.
template<class T> ld tetHeight(const P3<T>& a, const P3<T>& b, const P3<T>& c, const P3<T>& d) {
    return fabsl((ld)tetVolume6(a, b, c, d)) / norm(triNormal(a, b, c));
}
template<class T> ld tetSurface(const P3<T>& a, const P3<T>& b, const P3<T>& c, const P3<T>& d) {
    return triArea(a, b, c) + triArea(a, b, d) + triArea(a, c, d) + triArea(b, c, d);
}
inline Point3 tetCentroid(const Point3& a, const Point3& b, const Point3& c, const Point3& d) { return (a + b + c + d) / 4; }

// ============================================================================
// 6. ESFERAS
// ============================================================================
struct Sphere { Point3 c; ld r = 0; };
inline ld sphereArea(ld r) { return 4 * PI3 * r * r; }
inline ld sphereVolume(ld r) { return 4 * PI3 * r * r * r / 3; }
// Casquete de altura h en esfera de radio R: área lateral 2πRh, volumen πh²(3R-h)/3.
inline ld capArea(ld R, ld h) { return 2 * PI3 * R * h; }
inline ld capVolume(ld R, ld h) { return PI3 * h * h * (3 * R - h) / 3; }
// Cuerda a distancia dd del centro: 2 sqrt(r² - dd²).
inline ld chordLength(ld r, ld dd) { return 2 * safeSqrt(r * r - dd * dd); }
// Uso: punto vs bola con centro y radio ENTEROS: -1 dentro, 0 sobre, 1 fuera. EXACTO.
inline int cmpPointSphereExact(const IPoint3& c, ll r, const IPoint3& p) { return sgn3(dist2(c, p) - (i128)r * r); }
inline int cmpPointSphere(const Sphere& s, const Point3& p) { return sgn3(dist(s.c, p) - s.r); }
inline ld distToSphereSurface(const Sphere& s, const Point3& p) { return fabsl(dist(s.c, p) - s.r); }
inline ld distToBall(const Sphere& s, const Point3& p) { return max((ld)0, dist(s.c, p) - s.r); }

// Uso: parámetros t (ordenados) donde l.at(t) toca la esfera: 0 (no corta), 1 (tangente),
//   2 (secante). Rayo: quedarse con t >= 0. Segmento [a,b] con lineThrough: 0 <= t <= 1.
inline vector<ld> lineSphere(const Line3& l, const Sphere& s) {
    ld t0 = paramOnLine(l, s.c);
    ld h2 = norm2(l.at(t0) - s.c), q = s.r * s.r - h2;
    if (q < -EPS3) return {};
    if (q <= EPS3) return {t0};
    ld dt = sqrtl(q) / norm(l.d);
    return {t0 - dt, t0 + dt};
}
inline vector<ld> raySphere(const Point3& o, const Point3& dir, const Sphere& s) {
    vector<ld> r;
    for (ld t : lineSphere(Line3(o, dir), s)) if (t >= -EPS3) r.pb(max((ld)0, t));
    return r;
}
inline vector<ld> segmentSphere(const Point3& a, const Point3& b, const Sphere& s) {
    vector<ld> r;
    if (norm(b - a) <= EPS3) return r;
    for (ld t : lineSphere(lineThrough(a, b), s)) if (t >= -EPS3 && t <= 1 + EPS3) r.pb(t);
    return r;
}
// Uso: relación esfera-esfera. Si hay contacto: circle (centro, normal, radio);
//   tangencias -> radio 0 y center = punto de tangencia.
enum SphereRel { SR_SEPARATE, SR_EXT_TANGENT, SR_INTERSECT, SR_INT_TANGENT, SR_CONTAINED, SR_SAME };
struct Circle3 { Point3 c, n; ld r = 0; };
inline SphereRel sphereSphere(const Sphere& s1, const Sphere& s2, Circle3& circ) {
    ld dd = dist(s1.c, s2.c);
    if (dd <= EPS3 && fabsl(s1.r - s2.r) <= EPS3) return SR_SAME;
    if (dd > s1.r + s2.r + EPS3) return SR_SEPARATE;
    if (dd < fabsl(s1.r - s2.r) - EPS3) return SR_CONTAINED;
    Point3 u = unit(s2.c - s1.c);
    if (fabsl(dd - (s1.r + s2.r)) <= EPS3) { circ = {s1.c + u * s1.r, u, 0}; return SR_EXT_TANGENT; }
    if (fabsl(dd - fabsl(s1.r - s2.r)) <= EPS3) {
        const Sphere& big = s1.r >= s2.r ? s1 : s2; Point3 dir = s1.r >= s2.r ? u : -u;
        circ = {big.c + dir * big.r, u, 0}; return SR_INT_TANGENT;
    }
    ld a = (dd * dd + s1.r * s1.r - s2.r * s2.r) / (2 * dd);
    circ = {s1.c + u * a, u, safeSqrt(s1.r * s1.r - a * a)};
    return SR_INTERSECT;
}
// Volumen de la intersección de dos bolas (radios r1, r2, centros a distancia dd) = 2 casquetes.
inline ld sphereIntersectionVolume(ld r1, ld r2, ld dd) {
    if (dd >= r1 + r2) return 0;
    if (dd <= fabsl(r1 - r2)) return sphereVolume(min(r1, r2));
    ld a = (dd * dd + r1 * r1 - r2 * r2) / (2 * dd);
    return capVolume(r1, r1 - a) + capVolume(r2, r2 - (dd - a));
}
// Distancia mínima entre las SUPERFICIES de dos esferas (0 si se cortan).
inline ld sphereSurfaceGap(const Sphere& s1, const Sphere& s2) {
    ld dd = dist(s1.c, s2.c);
    if (dd >= s1.r + s2.r) return dd - s1.r - s2.r;
    if (dd <= fabsl(s1.r - s2.r)) return fabsl(s1.r - s2.r) - dd;
    return 0;
}
// Uso: intersección plano-esfera. Retorna IK_NONE, o IK_POINT (tangente, radio 0) o
//   IK_LINE (círculo; se reutiliza el enum: "corte con dimensión 1").
inline InterKind planeSphere(const Plane& pl, const Sphere& s, Circle3& circ) {
    ld h = pl.side(s.c);
    if (fabsl(h) > s.r + EPS3) return IK_NONE;
    circ = {pl.proj(s.c), pl.n, safeSqrt(s.r * s.r - h * h)};
    return fabsl(fabsl(h) - s.r) <= EPS3 ? IK_POINT : IK_LINE;
}
// Circuncentro de un triángulo en 3D (en su plano). Triángulo no degenerado.
inline Point3 circumcenter3(const Point3& a, const Point3& b, const Point3& c) {
    Point3 u = b - a, v = c - a, w = cross(u, v);
    return a + (cross(w, u) * norm2(v) + cross(v, w) * norm2(u)) / (2 * norm2(w));
}
// Esfera por 4 puntos no coplanares: centro = a + (|u|²(v×w) + |v|²(w×u) + |w|²(u×v)) / (2 u·(v×w)).
inline bool circumsphere(const Point3& a, const Point3& b, const Point3& c, const Point3& d, Sphere& out) {
    Point3 u = b - a, v = c - a, w = d - a;
    ld den = 2 * triple(u, v, w);
    if (fabsl(den) <= EPS3) return false;
    Point3 cen = a + (cross(v, w) * norm2(u) + cross(w, u) * norm2(v) + cross(u, v) * norm2(w)) / den;
    out = {cen, dist(cen, a)};
    return true;
}
// Minimum Enclosing Sphere (Welzl iterativo). O(n) esperado. Aproximado (long double).
//   Degenerados: 3 colineales -> esfera del par más lejano; 4 coplanares -> mejor esfera de
//   3 de ellos que contenga a los 4. Probado contra fuerza bruta en _pruebas.
inline Sphere sphereFrom2(const Point3& a, const Point3& b) { return {midpoint(a, b), dist(a, b) / 2}; }
inline Sphere sphereFrom3(const Point3& a, const Point3& b, const Point3& c) {
    if (norm(cross(b - a, c - a)) <= EPS3 * max((ld)1, max({dist2(a, b), dist2(b, c), dist2(a, c)}))) {
        Sphere s = sphereFrom2(a, b);
        for (auto t : {sphereFrom2(b, c), sphereFrom2(a, c)}) if (t.r > s.r) s = t;
        return s;
    }
    Point3 cen = circumcenter3(a, b, c);
    return {cen, dist(cen, a)};
}
inline Sphere minEnclosingSphere(vector<Point3> p) {
    if (p.empty()) return {};
    shuffle(p.begin(), p.end(), mt19937(712367));
    auto out = [](const Sphere& s, const Point3& q) { return dist(s.c, q) > s.r * (1 + 1e-12L) + EPS3; };
    auto from4 = [&](const Point3& a, const Point3& b, const Point3& c, const Point3& d) {
        Sphere s;
        if (circumsphere(a, b, c, d, s) && s.r < 1e18) return s;
        Sphere best{Point3(), 1e30L};
        Point3 q[4] = {a, b, c, d};
        for (int i = 0; i < 4; i++) {
            Sphere t = sphereFrom3(q[(i + 1) % 4], q[(i + 2) % 4], q[(i + 3) % 4]);
            if (!out(t, q[i]) && t.r < best.r) best = t;
        }
        return best;
    };
    Sphere s{p[0], 0};
    int n = p.size();
    for (int i = 1; i < n; i++) if (out(s, p[i])) {
        s = {p[i], 0};
        for (int j = 0; j < i; j++) if (out(s, p[j])) {
            s = sphereFrom2(p[i], p[j]);
            for (int k = 0; k < j; k++) if (out(s, p[k])) {
                s = sphereFrom3(p[i], p[j], p[k]);
                for (int l = 0; l < k; l++) if (out(s, p[l])) s = from4(p[i], p[j], p[k], p[l]);
            }
        }
    }
    return s;
}
// Geometría esférica: punto desde latitud/longitud (grados) y distancia por círculo máximo.
inline Point3 fromLatLon(ld latDeg, ld lonDeg, ld R) {
    ld la = toRad(latDeg), lo = toRad(lonDeg);
    return {R * cosl(la) * cosl(lo), R * cosl(la) * sinl(lo), R * sinl(la)};
}
// Distancia sobre la esfera de radio R entre dos puntos de su superficie (centro en el origen)
//   = R · ángulo central (atan2 estable).
inline ld greatCircleDist(const Point3& u, const Point3& v, ld R) { return R * angle(u, v); }

// ============================================================================
// 7. POLIEDROS, PRISMAS Y MALLAS
// ============================================================================
inline ld prismVolume(ld baseArea, ld h) { return baseArea * h; }          // prisma / cilindro
inline ld pyramidVolume(ld baseArea, ld h) { return baseArea * h / 3; }    // pirámide / cono
template<class T> Wide<T> parallelepipedVolume(const P3<T>& a, const P3<T>& b, const P3<T>& c) {
    Wide<T> v = triple(a, b, c); return v < 0 ? -v : v;
}
// Malla triangular CERRADA y con orientación CONSISTENTE (todas las caras antihorarias vistas
//   desde fuera). 6V = Σ v0·(v1×v2) (tetraedros con el origen). Exacto con enteros.
//   Resultado < 0 => las caras están orientadas hacia adentro (invertir todas).
//   Si la malla no es cerrada el valor depende del origen y NO es un volumen.
using Face = array<int, 3>;
template<class T> Wide<T> meshVolume6(const vector<P3<T>>& v, const vector<Face>& f) {
    Wide<T> s = 0;
    for (auto& t : f) s += triple(v[t[0]], v[t[1]], v[t[2]]);
    return s;
}
template<class T> ld meshSurface(const vector<P3<T>>& v, const vector<Face>& f) {
    ld s = 0;
    for (auto& t : f) s += triArea(v[t[0]], v[t[1]], v[t[2]]);
    return s;
}
// Centroide del SÓLIDO (no de la superficie): Σ 6V_i (v0+v1+v2)/4 / Σ 6V_i. Malla cerrada y
//   orientada con volumen != 0.
template<class T> Point3 meshCentroid(const vector<P3<T>>& v, const vector<Face>& f) {
    Point3 acc; ld tot = 0;
    for (auto& t : f) {
        Point3 a(v[t[0]]), b(v[t[1]]), c(v[t[2]]);
        ld w = triple(a, b, c); tot += w; acc += (a + b + c) * (w / 4);
    }
    return acc / tot;
}
// ¿Cerrada y consistente? Cada arista dirigida (u,v) aparece una vez y (v,u) también.
inline bool meshClosedConsistent(const vector<Face>& f) {
    map<pair<int, int>, int> e;
    for (auto& t : f) for (int i = 0; i < 3; i++) if (++e[{t[i], t[(i + 1) % 3]}] > 1) return false;
    for (auto& [k, c] : e) if (!e.count({k.second, k.first})) return false;
    return true;
}
// Uso: orientar consistentemente una malla cerrada conexa (BFS sobre caras vecinas) y luego
//   hacia afuera (volumen positivo). Devuelve false si no es orientable / no es manifold.
template<class T> bool orientMesh(const vector<P3<T>>& v, vector<Face>& f) {
    int m = f.size();
    if (m == 0) return true;
    map<pair<int, int>, vector<int>> byEdge;
    for (int i = 0; i < m; i++) for (int j = 0; j < 3; j++) {
        int a = f[i][j], b = f[i][(j + 1) % 3];
        byEdge[{min(a, b), max(a, b)}].pb(i);
    }
    vector<int> seen(m, 0);
    auto hasDirected = [&](int i, int a, int b) {
        for (int j = 0; j < 3; j++) if (f[i][j] == a && f[i][(j + 1) % 3] == b) return true;
        return false;
    };
    for (int s = 0; s < m; s++) if (!seen[s]) {
        seen[s] = 1; vector<int> st = {s};
        while (!st.empty()) {
            int i = st.back(); st.pop_back();
            for (int j = 0; j < 3; j++) {
                int a = f[i][j], b = f[i][(j + 1) % 3];
                auto& lst = byEdge[{min(a, b), max(a, b)}];
                if (lst.size() != 2) return false;
                int o = lst[0] == i ? lst[1] : lst[0];
                bool bad = hasDirected(o, a, b);   // el vecino debe usar (b,a)
                if (!seen[o]) { if (bad) swap(f[o][1], f[o][2]); seen[o] = 1; st.pb(o); }
                else if (bad) return false;
            }
        }
    }
    if (meshVolume6(v, f) < 0) for (auto& t : f) swap(t[1], t[2]);
    return true;
}
// Polígono plano en 3D (vértices en orden): vector área (Newell) = Σ p_i × p_{i+1}.
//   |·|/2 = área, dirección = normal (regla de la mano derecha según el orden).
template<class T> P3<T> polygonVectorArea2(const vector<P3<T>>& poly) {
    P3<T> s;
    for (size_t i = 0; i < poly.size(); i++) s += cross(poly[i], poly[(i + 1) % poly.size()]);
    return s;
}
// Poliedro con caras poligonales PLANAS y CONVEXAS orientadas hacia afuera: triangulación en
//   abanico (v0, vi, vi+1) de cada cara. Retorna 6V exacto.
template<class T> Wide<T> polyhedronVolume6(const vector<P3<T>>& v, const vector<vector<int>>& faces) {
    Wide<T> s = 0;
    for (auto& f : faces) for (size_t i = 1; i + 1 < f.size(); i++) s += triple(v[f[0]], v[f[i]], v[f[i + 1]]);
    return s;
}

#endif
