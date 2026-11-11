// Tema: 07_Geometria/Geometria_3D — PARTE C: algoritmos avanzados (separados a propósito).
// Base: Template/simple.cpp (int = long long). Compilar con GNU G++20. Requiere PARTES A y B.
// Hull 3D exacto O(n^2), par más cercano, triángulo-triángulo, OBB (SAT), rayo-malla,
// tetraedro mínimo por un punto. Todo probado contra fuerza bruta.

#ifndef GEO3D_C_AVANZADO
#define GEO3D_C_AVANZADO
#include "b-geo3d-solidos.cpp"

// ============================================================================
// 1. ENVOLVENTE CONVEXA 3D (incremental, exacta con enteros |coord| <= 1e9)
// ============================================================================
// Uso: Hull3 h = convexHull3D(pts);
// Retorna: dim = -1 (vacío), 0 (todos iguales), 1 (colineales), 2 (coplanares: usar hull 2D
//   en Plane::to2D o dropAxis), 3 (sólido). Con dim == 3, faces = triángulos con índices
//   ORIGINALES de pts, orientados antihorario vistos desde fuera (normal hacia afuera).
// Caras coplanares salen trianguladas (usar countFacets para contar caras reales). Un punto
//   que cae sobre la envolvente ya construida no se agrega; uno agregado antes puede quedar
//   luego sobre una arista/cara y seguir en la triangulación (área y volumen no cambian).
//   Esquinas reales: hullExtremeVertices.
// Complejidad: O(n·F) = O(n^2) peor caso; n <= ~5000 cómodo.
struct Hull3 { int dim = -1; vector<Face> faces; };
inline Hull3 convexHull3D(const vector<IPoint3>& P) {
    Hull3 h;
    int n = P.size();
    if (n == 0) return h;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int a, int b) { return P[a] < P[b]; });
    ord.erase(unique(ord.begin(), ord.end(), [&](int a, int b) { return P[a] == P[b]; }), ord.end());
    // Tetraedro inicial con vértices EXTREMOS (si no, un punto interior a una cara quedaría como
    //   vértice): i0 = mínimo y i1 = máximo lexicográfico; i2 = más lejano a la recta i0i1
    //   (empate: menor proyección sobre la recta); i3 = mayor |volumen| (empate: menor lexicográfico).
    int m = ord.size(), i0 = ord[0], i1 = ord[m - 1], i2 = -1, i3 = -1;
    h.dim = 0;
    if (m == 1) return h;
    h.dim = 1;
    IPoint3 dir = P[i1] - P[i0];
    unsigned __int128 bestD = 0; i128 bestDot = 0;
    for (int k : ord) {
        IPoint3 c = cross(P[k] - P[i0], dir);
        unsigned __int128 d = 0;
        for (int j = 0; j < 3; j++) d += (unsigned __int128)((i128)c[j] * c[j]);
        i128 dt = dot(P[k], dir);
        if (d > bestD || (d == bestD && d > 0 && dt < bestDot)) { bestD = d; bestDot = dt; i2 = k; }
    }
    if (i2 < 0) return h;
    h.dim = 2;
    i128 bestV = 0;
    for (int k : ord) {
        i128 v = triple(P[i1] - P[i0], P[i2] - P[i0], P[k] - P[i0]);
        if (v < 0) v = -v;
        if (v > bestV) { bestV = v; i3 = k; }
    }
    if (i3 < 0) return h;
    h.dim = 3;
    vector<Face> F;
    auto addOut = [&](int a, int b, int c, int inside) {   // orienta la cara hacia afuera
        if (orient(P[a], P[b], P[c], P[inside]) > 0) swap(b, c);
        F.pb({a, b, c});
    };
    addOut(i0, i1, i2, i3); addOut(i0, i1, i3, i2); addOut(i0, i2, i3, i1); addOut(i1, i2, i3, i0);
    unordered_set<ll> vis;
    for (int p : ord) {
        if (p == i0 || p == i1 || p == i2 || p == i3) continue;
        vis.clear();
        vector<char> isVis(F.size(), 0);
        bool any = false;
        for (size_t f = 0; f < F.size(); f++)
            if (orient(P[F[f][0]], P[F[f][1]], P[F[f][2]], P[p]) > 0) {
                isVis[f] = 1; any = true;
                for (int j = 0; j < 3; j++) vis.insert((ll)F[f][j] * n + F[f][(j + 1) % 3]);
            }
        if (!any) continue;                                  // dentro o sobre la envolvente
        vector<Face> G;
        for (size_t f = 0; f < F.size(); f++) {
            if (!isVis[f]) { G.pb(F[f]); continue; }
            for (int j = 0; j < 3; j++) {                    // arista del horizonte: (u,v) visible, (v,u) no
                int u = F[f][j], v = F[f][(j + 1) % 3];
                if (!vis.count((ll)v * n + u)) G.pb({u, v, p});
            }
        }
        F.swap(G);
    }
    h.faces = F;
    return h;
}
// Volumen x6 (exacto) y área de la envolvente (dim == 3).
inline i128 hullVolume6(const vector<IPoint3>& P, const Hull3& h) { return meshVolume6(P, h.faces); }
inline ld hullSurface(const vector<IPoint3>& P, const Hull3& h) { return meshSurface(P, h.faces); }
// Número de caras planas reales (une triángulos coplanares por su normal primitiva).
inline int countFacets(const vector<IPoint3>& P, const Hull3& h) {
    set<IPoint3> normals;
    for (auto& f : h.faces) normals.insert(normDir(triNormal(P[f[0]], P[f[1]], P[f[2]]), false));
    return normals.size();
}
// Índices de los vértices de la TRIANGULACIÓN (puede incluir puntos sobre aristas o caras).
inline vector<int> hullVertices(const Hull3& h) {
    vector<int> r;
    for (auto& f : h.faces) for (int x : f) r.pb(x);
    sort(r.begin(), r.end()); r.erase(unique(r.begin(), r.end()), r.end());
    return r;
}
// Índices de los vértices EXTREMOS (esquinas reales): les inciden >= 3 caras planas distintas.
inline vector<int> hullExtremeVertices(const vector<IPoint3>& P, const Hull3& h) {
    map<int, set<IPoint3>> inc;
    for (auto& f : h.faces) {
        IPoint3 nr = normDir(triNormal(P[f[0]], P[f[1]], P[f[2]]), false);
        for (int x : f) inc[x].insert(nr);
    }
    vector<int> r;
    for (auto& [v, s] : inc) if (s.size() >= 3) r.pb(v);
    return r;
}

// ============================================================================
// 2. PAR MÁS CERCANO EN 3D (rejilla aleatorizada, exacto)
// ============================================================================
// Uso: auto [i, j] = closestPair3D(pts, d2); d2 = distancia^2 mínima (exacta, __int128).
// Idea: con celdas de lado s >= d actual, un punto a distancia < d está en las 27 celdas
//   vecinas. Si d mejora, se reconstruye la rejilla (O(n) esperado en orden aleatorio).
// Requiere n >= 2. |coord| <= 1e9.
inline pair<int, int> closestPair3D(const vector<IPoint3>& P, i128& best) {
    int n = P.size();
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    shuffle(o.begin(), o.end(), mt19937(20261105));
    pair<int, int> res = {o[0], o[1]};
    best = dist2(P[o[0]], P[o[1]]);
    auto fdiv = [](ll a, ll b) { return a / b - ((a % b != 0) && ((a < 0) != (b < 0))); };
    auto hsh = [](ll x, ll y, ll z) {
        unsigned long long h = (unsigned long long)x * 0x9E3779B97F4A7C15ULL;
        h ^= (unsigned long long)y * 0xC2B2AE3D27D4EB4FULL + (h << 6) + (h >> 2);
        h ^= (unsigned long long)z * 0x165667B19E3779F9ULL + (h << 6) + (h >> 2);
        return h;
    };
    ll s = 1;
    unordered_map<unsigned long long, vector<int>> grid;
    auto key = [&](const IPoint3& p) { return hsh(fdiv(p.x, s), fdiv(p.y, s), fdiv(p.z, s)); };
    auto rebuild = [&](int upto) {
        ll r = (ll)sqrtl((ld)best);
        while ((i128)r * r < best) r++;
        while (r > 1 && (i128)(r - 1) * (r - 1) >= best) r--;
        s = max(1LL, r);
        grid.clear();
        for (int k = 0; k <= upto; k++) grid[key(P[o[k]])].pb(o[k]);
    };
    if (best == 0) return res;
    rebuild(1);
    for (int i = 2; i < n; i++) {
        const IPoint3& p = P[o[i]];
        ll cx = fdiv(p.x, s), cy = fdiv(p.y, s), cz = fdiv(p.z, s);
        bool improved = false;
        for (ll dx = -1; dx <= 1; dx++) for (ll dy = -1; dy <= 1; dy++) for (ll dz = -1; dz <= 1; dz++) {
            auto it = grid.find(hsh(cx + dx, cy + dy, cz + dz));
            if (it == grid.end()) continue;
            for (int q : it->second) {
                i128 d = dist2(p, P[q]);
                if (d < best) { best = d; res = {q, o[i]}; improved = true; }
            }
        }
        if (best == 0) return res;
        if (improved) rebuild(i);
        else grid[key(p)].pb(o[i]);
    }
    return res;
}

// ============================================================================
// 3. INTERSECCIÓN TRIÁNGULO-TRIÁNGULO 3D (exacta, triángulos no degenerados)
// ============================================================================
// Idea: si se cortan, algún lado de uno toca al otro triángulo (no coplanares: los extremos
//   del segmento de corte están en bordes; coplanares: cruce de lados o contención).
// Complejidad: O(1) (6 pruebas segmento-triángulo). Contacto en un punto cuenta.
inline bool triTriIntersectExact(const array<IPoint3, 3>& A, const array<IPoint3, 3>& B) {
    for (int i = 0; i < 3; i++) {
        if (segTriangleExact(A[i], A[(i + 1) % 3], B[0], B[1], B[2])) return true;
        if (segTriangleExact(B[i], B[(i + 1) % 3], A[0], A[1], A[2])) return true;
    }
    return false;
}

// ============================================================================
// 4. CAJAS ORIENTADAS (OBB) — Teorema del eje separador
// ============================================================================
// OBB: centro c, ejes ortonormales u[0..2] (base derecha), semilados e[0..2] >= 0.
// Dos convexos son disjuntos <=> existe un eje que separa sus proyecciones. Para dos OBB
//   basta probar 15 ejes: 3 de A, 3 de B y 9 productos cruz. Tocarse cuenta como intersección.
// Aproximado (long double). AbsR + EPS evita falsos "separados" con aristas paralelas.
struct OBB { Point3 c; Point3 u[3]; ld e[3]; };
inline OBB obbFromBox(const Box3& b) {
    OBB o;
    o.c = (Point3(b.lo) + Point3(b.hi)) / 2;
    o.u[0] = {1, 0, 0}; o.u[1] = {0, 1, 0}; o.u[2] = {0, 0, 1};
    for (int k = 0; k < 3; k++) o.e[k] = (ld)(b.hi[k] - b.lo[k]) / 2;
    return o;
}
inline bool pointInOBB(const OBB& o, const Point3& p) {
    Point3 d = p - o.c;
    for (int k = 0; k < 3; k++) if (fabsl(dot(d, o.u[k])) > o.e[k] + EPS3) return false;
    return true;
}
inline bool obbIntersect(const OBB& A, const OBB& B) {
    ld R[3][3], AR[3][3], T[3];
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) { R[i][j] = dot(A.u[i], B.u[j]); AR[i][j] = fabsl(R[i][j]) + EPS3; }
    Point3 t = B.c - A.c;
    for (int i = 0; i < 3; i++) T[i] = dot(t, A.u[i]);
    for (int i = 0; i < 3; i++) {
        ld rb = B.e[0] * AR[i][0] + B.e[1] * AR[i][1] + B.e[2] * AR[i][2];
        if (fabsl(T[i]) > A.e[i] + rb) return false;
    }
    for (int j = 0; j < 3; j++) {
        ld ra = A.e[0] * AR[0][j] + A.e[1] * AR[1][j] + A.e[2] * AR[2][j];
        if (fabsl(T[0] * R[0][j] + T[1] * R[1][j] + T[2] * R[2][j]) > ra + B.e[j]) return false;
    }
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {      // eje A.u[i] × B.u[j]
        int i1 = (i + 1) % 3, i2 = (i + 2) % 3, j1 = (j + 1) % 3, j2 = (j + 2) % 3;
        ld ra = A.e[i1] * AR[i2][j] + A.e[i2] * AR[i1][j];
        ld rb = B.e[j1] * AR[i][j2] + B.e[j2] * AR[i][j1];
        if (fabsl(T[i2] * R[i1][j] - T[i1] * R[i2][j]) > ra + rb) return false;
    }
    return true;
}

// ============================================================================
// 5. RAYO CONTRA MALLA
// ============================================================================
// Uso: primer impacto del rayo o + t·dir (t >= 0) con una malla triangular. O(F).
//   Retorna (t, índice de cara) o nullopt. Para muchas consultas: BVH/rejilla (no incluido).
inline optional<pair<ld, int>> rayMesh(const Point3& o, const Point3& dir, const vector<Point3>& v, const vector<Face>& f) {
    optional<pair<ld, int>> best;
    for (int i = 0; i < (int)f.size(); i++) {
        auto t = rayTriangle(o, dir, v[f[i][0]], v[f[i][1]], v[f[i][2]]);
        if (t && (!best || *t < best->first)) best = make_pair(*t, i);
    }
    return best;
}

// ============================================================================
// 6. OPTIMIZACIÓN: tetraedro de volumen mínimo cortado por un plano que pasa por P
// ============================================================================
// Ángulo triedro con vértice en el ORIGEN y aristas en direcciones A, B, C; P interior.
// P = αA + βB + γC (α,β,γ > 0, por Cramer con productos triples). Un plano que corta las
//   aristas en sA, tB, uC contiene a P <=> α/s + β/t + γ/u = 1. V = s·t·u·|det(A,B,C)|/6.
//   Por AM-GM el mínimo es con α/s = β/t = γ/u = 1/3 (P = centroide del triángulo de corte):
//   V_min = 27αβγ·|det|/6 = 4.5·αβγ·|det|. Si el vértice no es el origen, trasladar antes.
inline ld minTetraThroughPoint(const Point3& A, const Point3& B, const Point3& C, const Point3& P) {
    ld D = triple(A, B, C);
    ld al = triple(P, B, C) / D, be = triple(A, P, C) / D, ga = triple(A, B, P) / D;
    return 4.5L * al * be * ga * fabsl(D);
}

#endif
