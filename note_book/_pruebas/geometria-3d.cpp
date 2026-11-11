// Compilar desde note_book: g++ -std=gnu++20 -O2 -Wall -Wextra _pruebas/geometria-3d.cpp -o <ruta_temporal.exe>
// Pruebas de 07_Geometria/Geometria_3D (partes A, B y C) con casos fijos y fuerza bruta.
#include "../07_Geometria/Geometria_3D/c-geo3d-avanzado.cpp"

int checks = 0;
#define CHECK(cond) do { ++checks; if (!(cond)) { cerr << "FALLO linea " << __LINE__ << ": " #cond << endl; exit(1); } } while (0)
bool near(ld a, ld b, ld eps = 1e-7) { return fabsl(a - b) <= eps * max((ld)1, max(fabsl(a), fabsl(b))); }
bool nearP(const Point3& a, const Point3& b, ld eps = 1e-7) { return near(a.x, b.x, eps) && near(a.y, b.y, eps) && near(a.z, b.z, eps); }
mt19937_64 rng(20261105);
ll rnd(ll l, ll r) { return l + (ll)(rng() % (unsigned long long)(r - l + 1)); }
ld rndD(ld l, ld r) { return l + (r - l) * (ld)(rng() % 1000000007ULL) / 1000000006.0L; }
IPoint3 rndP(ll l, ll r) { return {rnd(l, r), rnd(l, r), rnd(l, r)}; }
Point3 rndPD(ld l, ld r) { return {rndD(l, r), rndD(l, r), rndD(l, r)}; }
Box3 rndBox(ll l, ll r) { return makeBox(rndP(l, r), rndP(l, r)); }

void testBasico() {
    IPoint3 ex(1, 0, 0), ey(0, 1, 0), ez(0, 0, 1);
    CHECK(cross(ex, ey) == ez && cross(ey, ez) == ex && cross(ez, ex) == ey);
    CHECK(triple(ex, ey, ez) == 1 && triple(ey, ex, ez) == -1);
    CHECK(dot(IPoint3(1, 2, 3), IPoint3(4, 5, 6)) == 32);
    CHECK(norm2(IPoint3(1, 2, 2)) == 9 && near(norm(IPoint3(1, 2, 2)), 3));
    // Productos triples con coordenadas grandes: no cabe en long long, sí en __int128.
    ll B = 2000000000LL;
    i128 big = triple(IPoint3(B, 0, 0), IPoint3(0, B, 0), IPoint3(0, 0, B));
    CHECK(big == (i128)B * B * B && toString128(big) == "8000000000000000000000000000");
    for (int it = 0; it < 2000; it++) {
        IPoint3 a = rndP(-1000000000, 1000000000), b = rndP(-1000000000, 1000000000), c = rndP(-1000000000, 1000000000);
        i128 t = triple(a, b, c);
        CHECK(t == triple(b, c, a) && t == -triple(b, a, c) && t == dot(a, cross(b, c)));
        ld approx = (ld)a.x * ((ld)b.y * c.z - (ld)b.z * c.y) + (ld)a.y * ((ld)b.z * c.x - (ld)b.x * c.z) + (ld)a.z * ((ld)b.x * c.y - (ld)b.y * c.x);
        CHECK(fabsl((ld)t - approx) <= 1e-9L * 1e28L);
    }
    // Vectores de longitud cero.
    IPoint3 z0;
    CHECK(isZero(z0) && parallelVec(z0, ex) && collinear(z0, z0, ex) && near(angle(z0, ex), 0));
    CHECK(norm(unit(Point3())) == 0);
    CHECK(!isZero(anyPerp(IPoint3(0, 0, 5))) && dot(anyPerp(IPoint3(3, -4, 7)), IPoint3(3, -4, 7)) == 0);
    for (int it = 0; it < 200; it++) { Point3 v = rndPD(-5, 5); CHECK(fabsl(dot(unit(anyPerp(v)), unit(v))) < 1e-12); }
    CHECK(near(angle(ex, ey), PI3 / 2) && near(angle(ex, -ex), PI3) && near(angle(Point3(1, 1, 0), Point3(1, 0, 0)), PI3 / 4));
    CHECK(near(safeAcos(1.0000001L), 0) && safeSqrt(-1e-18L) == 0);
    CHECK(orient(IPoint3(0, 0, 0), ex, ey, ez) == 1 && orient(IPoint3(0, 0, 0), ey, ex, ez) == -1 && coplanar(z0, ex, ey, IPoint3(5, 7, 0)));
    CHECK(perpendicularVec(ex, ey) && sameDirection(ex, IPoint3(3, 0, 0)) && !sameDirection(ex, IPoint3(-3, 0, 0)));
    CHECK(midpoint2(IPoint3(1, 2, 3), IPoint3(2, 2, 2)) == IPoint3(3, 4, 5));
}

void testTrucos() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 30);
        vector<IPoint3> p(n);
        for (auto& q : p) q = rndP(-50, 50);
        ll bm = 0, bc = 0;
        for (auto& a : p) for (auto& b : p) { bm = max(bm, manhattan(a, b)); bc = max(bc, chebyshev(a, b)); }
        CHECK(maxManhattan(p) == bm && maxChebyshev(p) == bc);
    }
    for (int it = 0; it < 300; it++) {
        IPoint3 a = rndP(-6, 6), b = rndP(-6, 6);
        ll cnt = 0;
        for (ll x = -6; x <= 6; x++) for (ll y = -6; y <= 6; y++) for (ll z = -6; z <= 6; z++) cnt += onSegment(a, b, IPoint3(x, y, z));
        CHECK(latticePointsSegment(a, b) == cnt);
    }
    CHECK(latticePointsSegment(IPoint3(0, 0, 0), IPoint3(2, 4, 6)) == 3);
    CHECK(normDir(IPoint3(-2, 4, -6)) == IPoint3(1, -2, 3) && normDir(IPoint3(-2, 4, -6), false) == IPoint3(-1, 2, -3));
    for (int it = 0; it < 150; it++) {
        int n = rnd(1, 14);
        vector<IPoint3> p(n);
        for (auto& q : p) q = rndP(0, 3);
        ll best = 1;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            if (p[i] == p[j]) { ll c = 0; for (auto& q : p) c += q == p[i]; best = max(best, c); continue; }
            ll c = 0;
            for (auto& q : p) c += collinear(p[i], p[j], q);
            best = max(best, c);
        }
        CHECK(maxCollinear(p) == best);
        vector<IPoint3> vecs(n);
        for (auto& v : vecs) v = rndP(-3, 3);
        ll pairs = 0;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) pairs += !isZero(vecs[i]) && !isZero(vecs[j]) && parallelVec(vecs[i], vecs[j]);
        CHECK(countParallelPairs(vecs) == pairs);
    }
    CHECK(equidistant(IPoint3(0, 0, 0), IPoint3(1, 2, 2), IPoint3(3, 0, 0)));
}

void testRotaciones() {
    IPoint3 p(1, 2, 3);
    CHECK(rotZ90(IPoint3(1, 0, 0)) == IPoint3(0, 1, 0) && rotX90(IPoint3(0, 1, 0)) == IPoint3(0, 0, 1) && rotY90(IPoint3(0, 0, 1)) == IPoint3(1, 0, 0));
    CHECK(rotX90(p, 4) == p && rotY90(p, 4) == p && rotZ90(p, 4) == p && rotZ90(p, -1) == rotZ90(p, 3));
    CHECK(rotZ90(p, 2) == IPoint3(-1, -2, 3));
    for (int k = 0; k < 4; k++) {
        CHECK(nearP(Point3(rotX90(p, k)), rotXMat(k * PI3 / 2) * Point3(p)));
        CHECK(nearP(Point3(rotY90(p, k)), rotYMat(k * PI3 / 2) * Point3(p)));
        CHECK(nearP(Point3(rotZ90(p, k)), rotZMat(k * PI3 / 2) * Point3(p)));
    }
    auto R = cubeRotations(), RR = cubeRotations(true);
    set<IPoint3> img, img2;
    for (auto& m : R) img.insert(applyPerm(m, p));
    for (auto& m : RR) img2.insert(applyPerm(m, p));
    CHECK(R.size() == 24 && img.size() == 24 && RR.size() == 48 && img2.size() == 48);
    // Las 24 rotaciones = cierre de rotX90/rotY90 aplicados a p.
    set<IPoint3> clos = {p}; vector<IPoint3> st = {p};
    while (!st.empty()) { IPoint3 q = st.back(); st.pop_back(); for (IPoint3 r : {rotX90(q), rotY90(q)}) if (clos.insert(r).second) st.pb(r); }
    CHECK(clos == img);
    // Reflexión cambia orientación; rotación no.
    IPoint3 o, a(1, 0, 0), b(0, 1, 0), c(0, 0, 1);
    CHECK(orient(rotZ90(o), rotZ90(a), rotZ90(b), rotZ90(c)) == 1 && orient(reflXY(o), reflXY(a), reflXY(b), reflXY(c)) == -1);
    // Rodrigues.
    for (int it = 0; it < 200; it++) {
        Point3 ax = rndPD(-3, 3), v = rndPD(-3, 3); ld t = rndD(-7, 7);
        Mat3 M = rodrigues(ax, t);
        Point3 w = M * v;
        CHECK(near(norm(w), norm(v)) && near(dot(w, unit(ax)), dot(v, unit(ax))) && near(M.det(), 1));
        CHECK(nearP(w, rotateRodrigues(v, ax, t)) && nearP(M.transpose() * w, v));
    }
    CHECK(nearP(rodrigues(Point3(0, 0, 1), 0.7L) * Point3(1, 2, 3), rotZMat(0.7L) * Point3(1, 2, 3)));
    Point3 cen(1, 1, 1);
    Mat4 T = rotateAroundPoint(cen, rotZMat(PI3 / 2));
    CHECK(nearP(T.apply(cen), cen) && nearP(T.apply(Point3(2, 1, 1)), Point3(1, 2, 1)));
    CHECK(nearP(rotateAroundLine(Point3(2, 1, 1), cen, Point3(0, 0, 1), PI3 / 2), Point3(1, 2, 1)));
    Mat4 comp = Mat4::translate(Point3(5, 0, 0)) * Mat4::scale(2, 2, 2);
    CHECK(nearP(comp.apply(Point3(1, 1, 1)), Point3(7, 2, 2)) && nearP(comp.applyVec(Point3(1, 1, 1)), Point3(2, 2, 2)));
    CHECK(near(toDeg(toRad(37)), 37));
    for (int it = 0; it < 100; it++) {
        Frame f(rndPD(-5, 5), rndPD(-5, 5)); Point3 q = rndPD(-9, 9);
        CHECK(nearP(f.toGlobal(f.toLocal(q)), q) && near(dot(f.u, f.v), 0) && near(norm(cross(f.u, f.v) - f.w), 0));
    }
}

void testCajas() {
    Box3 u{{0, 0, 0}, {1, 1, 1}};
    CHECK(boxVolume(u) == 1 && boxSurface(u) == 6 && boxDiag2(u) == 3 && isCube(u) && latticePointsInBox(u) == 8);
    CHECK(interVolume(u, u) == 1 && overlapPositive(u, u) && boxContact(u, u) == BC_VOLUME && containsBox(u, u));
    Box3 far{{5, 5, 5}, {6, 6, 6}}, face{{1, 0, 0}, {2, 1, 1}}, edge{{1, 1, 0}, {2, 2, 1}}, vert{{1, 1, 1}, {2, 2, 2}};
    CHECK(boxContact(u, far) == BC_SEPARATED && interVolume(u, far) == 0 && !interBox(u, far));
    CHECK(boxContact(u, face) == BC_FACE && contactArea(u, face) == 1 && !overlapPositive(u, face) && boxesTouchOrOverlap(u, face));
    CHECK(boxContact(u, edge) == BC_EDGE && contactArea(u, edge) == 0);
    CHECK(boxContact(u, vert) == BC_VERTEX && interBox(u, vert).has_value());
    CHECK(unionVolume2(u, face) == 2 && makeBox(IPoint3(3, 0, 5), IPoint3(1, 2, 0)).lo == IPoint3(1, 0, 0));
    CHECK(overlapLen(0, 5, 3, 10) == 2 && overlapLen(0, 5, 5, 10) == 0 && overlapLen(0, 5, 7, 10) == 0);
    // Fuerza bruta por voxeles: tres cajas y conteos exactos 1/2/3.
    for (int it = 0; it < 400; it++) {
        Box3 b[3] = {rndBox(0, 7), rndBox(0, 7), rndBox(0, 7)};
        ll cnt[4] = {0, 0, 0, 0};
        for (int x = 0; x < 7; x++) for (int y = 0; y < 7; y++) for (int z = 0; z < 7; z++) {
            int k = 0;
            for (auto& bb : b) k += x >= bb.lo.x && x < bb.hi.x && y >= bb.lo.y && y < bb.hi.y && z >= bb.lo.z && z < bb.hi.z;
            cnt[k]++;
        }
        auto e = exactlyCovered3(b[0], b[1], b[2]);
        CHECK(e[0] == cnt[1] && e[1] == cnt[2] && e[2] == cnt[3]);
        CHECK(interVolume3(b[0], b[1], b[2]) == cnt[3] && unionVolume({b[0], b[1], b[2]}) == cnt[1] + cnt[2] + cnt[3]);
    }
    for (int it = 0; it < 200; it++) {
        int n = rnd(1, 8);
        vector<Box3> bs(n);
        for (auto& bb : bs) bb = rndBox(-4, 4);
        vector<ll> cnt(n + 1, 0);
        Box3 bb0 = bs[0];
        for (auto& bb : bs) for (int k = 0; k < 3; k++) { bb0.lo[k] = min(bb0.lo[k], bb.lo[k]); bb0.hi[k] = max(bb0.hi[k], bb.hi[k]); }
        for (ll x = bb0.lo.x; x < bb0.hi.x; x++) for (ll y = bb0.lo.y; y < bb0.hi.y; y++) for (ll z = bb0.lo.z; z < bb0.hi.z; z++) {
            int k = 0;
            for (auto& bb : bs) k += x >= bb.lo.x && x < bb.hi.x && y >= bb.lo.y && y < bb.hi.y && z >= bb.lo.z && z < bb.hi.z;
            cnt[k]++;
        }
        auto cv = coverVolumes(bs);
        for (int k = 1; k <= n; k++) CHECK(cv[k] == cnt[k]);
    }
    // Prefix sums y difference arrays 3D.
    for (int it = 0; it < 30; it++) {
        int X = rnd(1, 6), Y = rnd(1, 6), Z = rnd(1, 6);
        vector<ll> a(X * Y * Z);
        for (auto& v : a) v = rnd(-9, 9);
        Pref3 pf(X, Y, Z, [&](int x, int y, int z) { return a[(x * Y + y) * Z + z]; });
        Diff3 df(X, Y, Z);
        vector<ll> brute(X * Y * Z, 0);
        for (int q = 0; q < 50; q++) {
            int x1 = rnd(0, X - 1), x2 = rnd(x1, X - 1), y1 = rnd(0, Y - 1), y2 = rnd(y1, Y - 1), z1 = rnd(0, Z - 1), z2 = rnd(z1, Z - 1);
            ll s = 0;
            for (int x = x1; x <= x2; x++) for (int y = y1; y <= y2; y++) for (int z = z1; z <= z2; z++) s += a[(x * Y + y) * Z + z];
            CHECK(pf.query(x1, x2, y1, y2, z1, z2) == s);
            ll v = rnd(-5, 5);
            df.add(x1, x2, y1, y2, z1, z2, v);
            for (int x = x1; x <= x2; x++) for (int y = y1; y <= y2; y++) for (int z = z1; z <= z2; z++) brute[(x * Y + y) * Z + z] += v;
        }
        CHECK(df.build() == brute);
    }
    // Voxeles: cubo, dos cubos pegados, cáscara 3x3x3 con cavidad.
    CHECK(voxelSurface({IPoint3(0, 0, 0)}, false) == 6 && voxelSurface({IPoint3(0, 0, 0), IPoint3(1, 0, 0)}, true) == 10);
    vector<IPoint3> shell;
    for (int x = 0; x < 3; x++) for (int y = 0; y < 3; y++) for (int z = 0; z < 3; z++) if (!(x == 1 && y == 1 && z == 1)) shell.pb(IPoint3(x, y, z));
    CHECK(voxelSurface(shell, false) == 60 && voxelSurface(shell, true) == 54);
}

void testRectas() {
    // Rectas alabeadas: eje X y recta vertical por (0,1,0).
    Line3 l1(Point3(0, 0, 0), Point3(1, 0, 0)), l2(Point3(0, 1, 0), Point3(0, 0, 1));
    CHECK(lineRelation(l1, l2) == LR_SKEW && near(distLineLine(l1, l2), 1));
    auto [c1, c2] = closestPointsLines(l1, l2);
    CHECK(nearP(c1, Point3(0, 0, 0)) && nearP(c2, Point3(0, 1, 0)));
    // Paralelas, coincidentes, secantes.
    Line3 l3(Point3(0, 2, 0), Point3(-3, 0, 0)), l4(Point3(5, 0, 0), Point3(2, 0, 0)), l5(Point3(2, -1, 0), Point3(0, 1, 0));
    CHECK(lineRelation(l1, l3) == LR_PARALLEL && near(distLineLine(l1, l3), 2));
    CHECK(lineRelation(l1, l4) == LR_COINCIDENT && lineRelation(l1, l5) == LR_INTERSECT);
    Point3 X; CHECK(lineIntersection(l1, l5, X) && nearP(X, Point3(2, 0, 0)) && !lineIntersection(l1, l2, X));
    CHECK(lineRelationExact(IPoint3(0, 0, 0), IPoint3(1, 0, 0), IPoint3(0, 1, 0), IPoint3(0, 1, 1)) == LR_SKEW);
    CHECK(lineRelationExact(IPoint3(0, 0, 0), IPoint3(1, 0, 0), IPoint3(0, 2, 0), IPoint3(-3, 2, 0)) == LR_PARALLEL);
    CHECK(lineRelationExact(IPoint3(0, 0, 0), IPoint3(1, 0, 0), IPoint3(7, 0, 0), IPoint3(9, 0, 0)) == LR_COINCIDENT);
    CHECK(lineRelationExact(IPoint3(0, 0, 0), IPoint3(1, 0, 0), IPoint3(2, -1, 0), IPoint3(2, 5, 0)) == LR_INTERSECT);
    CHECK(near(angleLines(Point3(1, 0, 0), Point3(-1, 1, 0)), PI3 / 4));
    for (int it = 0; it < 300; it++) {
        Line3 a(rndPD(-5, 5), rndPD(-5, 5)), b(rndPD(-5, 5), rndPD(-5, 5));
        auto [p, q] = closestPointsLines(a, b);
        CHECK(near(dist(p, q), distLineLine(a, b), 1e-6) && fabsl(dot(q - p, a.d)) < 1e-6 && fabsl(dot(q - p, b.d)) < 1e-6);
        CHECK(distPointLine(a, p) < 1e-6 && distPointLine(b, q) < 1e-6);
        Point3 r = rndPD(-5, 5);
        CHECK(near(dist(r, projOnLine(a, r)), distPointLine(a, r), 1e-6));
    }
    // Distancia segmento-segmento contra muestreo fino.
    for (int it = 0; it < 300; it++) {
        Point3 a = rndPD(-3, 3), b = it % 10 == 0 ? a : rndPD(-3, 3), c = rndPD(-3, 3), d = rndPD(-3, 3);
        ld brute = 1e18;
        for (int k = 0; k <= 4000; k++) brute = min(brute, distPointSegment(c, d, lerp(a, b, (ld)k / 4000)));
        ld got = distSegSeg(a, b, c, d);
        CHECK(got <= brute + 1e-9 && brute - got <= 6e-3);
    }
    // Intersección exacta de segmentos contra distancia ~ 0 (coordenadas pequeñas).
    int hits = 0;
    for (int it = 0; it < 20000; it++) {
        IPoint3 a = rndP(0, 2), b = rndP(0, 2), c = rndP(0, 2), d = rndP(0, 2);
        if (it % 3 == 0) { a.z = b.z = c.z = d.z = 0; }
        bool ex = segSegIntersectExact(a, b, c, d);
        bool fl = distSegSeg(Point3(a), Point3(b), Point3(c), Point3(d)) < 1e-9;
        CHECK(ex == fl); hits += ex;
    }
    CHECK(hits > 1000);
}

void testPlanos() {
    Plane xy = Plane::fromPoints(Point3(0, 0, 0), Point3(1, 0, 0), Point3(0, 1, 0));
    CHECK(near(xy.side(Point3(3, 4, 5)), 5) && xy.classify(Point3(1, 1, -2)) == -1 && xy.contains(Point3(7, -3, 0)));
    Plane p1 = Plane::fromCoeffs(1, 2, 2, -6);   // x+2y+2z=6
    CHECK(near(p1.distTo(Point3(0, 0, 0)), 2) && p1.contains(p1.proj(Point3(4, 5, 6))));
    auto cf = p1.coeffs();
    CHECK(near(cf[0] * 3, 1) && near(cf[3] * 3, -6));
    for (int it = 0; it < 200; it++) {
        Plane pl = Plane::fromPoints(rndPD(-5, 5), rndPD(-5, 5), rndPD(-5, 5));
        Point3 q = rndPD(-5, 5);
        CHECK(nearP(pl.reflect(pl.reflect(q)), q, 1e-6) && near(pl.side(pl.reflect(q)), -pl.side(q), 1e-6));
        auto [u, v] = pl.to2D(q);
        CHECK(nearP(pl.from2D(u, v), pl.proj(q), 1e-6));
        Line3 l(rndPD(-5, 5), rndPD(-5, 5));
        auto r = interLinePlane(l, pl);
        if (r.kind == IK_POINT) CHECK(fabsl(pl.side(r.p)) < 1e-6 && distPointLine(l, r.p) < 1e-6);
        Plane p2 = Plane::fromPoints(rndPD(-5, 5), rndPD(-5, 5), rndPD(-5, 5)), p3 = Plane::fromPoints(rndPD(-5, 5), rndPD(-5, 5), rndPD(-5, 5));
        auto pp = interPlanePlane(pl, p2);
        if (pp.kind == IK_LINE) for (ld t : {-3.0L, 0.0L, 2.0L}) CHECK(fabsl(pl.side(pp.line.at(t))) < 1e-6 && fabsl(p2.side(pp.line.at(t))) < 1e-6);
        Point3 X;
        if (interThreePlanes(pl, p2, p3, X) && fabsl(triple(pl.n, p2.n, p3.n)) > 1e-3)
            CHECK(fabsl(pl.side(X)) < 1e-5 && fabsl(p2.side(X)) < 1e-5 && fabsl(p3.side(X)) < 1e-5);
    }
    // Planos coincidentes (puntos distintos y normal opuesta), paralelos y secantes.
    Plane a = Plane::fromPoints(Point3(0, 0, 1), Point3(1, 0, 1), Point3(0, 1, 1));
    Plane b = Plane::fromPoints(Point3(5, 5, 1), Point3(2, 7, 1), Point3(9, -1, 1));
    Plane c = Plane::fromPoints(Point3(0, 0, 3), Point3(1, 0, 3), Point3(0, 1, 3));
    CHECK(planeRelation(a, b) == IK_PLANE && planeRelation(a, c) == IK_NONE && planeRelation(a, xy) == IK_NONE);
    CHECK(planeRelation(a, Plane::fromCoeffs(1, 0, 0, -2)) == IK_LINE);
    CHECK(near(anglePlanes(xy, Plane::fromCoeffs(1, 0, 1, 0)), PI3 / 4) && near(angleLinePlane(Point3(1, 0, 1), xy), PI3 / 4));
    Point3 X; CHECK(!interThreePlanes(a, b, Plane::fromCoeffs(1, 0, 0, 0), X));
    CHECK(interThreePlanes(Plane::fromCoeffs(1, 0, 0, -1), Plane::fromCoeffs(0, 1, 0, -2), Plane::fromCoeffs(0, 0, 1, -3), X) && nearP(X, Point3(1, 2, 3)));
    CHECK(interLinePlane(Line3(Point3(0, 0, 1), Point3(1, 1, 0)), a).kind == IK_LINE && interLinePlane(Line3(Point3(0, 0, 2), Point3(1, 1, 0)), a).kind == IK_NONE);
    CHECK(interSegmentPlane(Point3(0, 0, 0), Point3(0, 0, 2), a).kind == IK_POINT && interSegmentPlane(Point3(0, 0, 2), Point3(0, 0, 4), a).kind == IK_NONE);
    CHECK(sameSide(xy, Point3(0, 0, 1), Point3(3, 3, 2)) && oppositeSides(xy, Point3(0, 0, 1), Point3(3, 3, -2)));
    IPlane ip(IPoint3(0, 0, 0), IPoint3(1000000000, 0, 0), IPoint3(0, 1000000000, 0));
    CHECK(ip.valid() && ip.classify(IPoint3(-1000000000, 1000000000, 1)) == 1 && ip.classify(IPoint3(5, 5, 0)) == 0);
    CHECK(!IPlane(IPoint3(0, 0, 0), IPoint3(1, 1, 1), IPoint3(2, 2, 2)).valid());
    CHECK(segmentTouchesPlaneExact(IPoint3(0, 0, 0), IPoint3(1, 0, 0), IPoint3(0, 1, 0), IPoint3(0, 0, -1), IPoint3(0, 0, 1)));
    CHECK(dropAxis(IPoint3(1, 2, 3), 1) == make_pair(3LL, 1LL));
}

void testTriangulosTetra() {
    IPoint3 A(0, 0, 0), B(4, 0, 0), C(0, 4, 0);
    CHECK(near(triArea(A, B, C), 8) && triArea2Squared(A, B, C) == 256 && near(triPerimeter(A, B, C), 8 + 4 * sqrtl(2)));
    CHECK(pointInTriangleExact(A, B, C, IPoint3(1, 1, 0)) && pointInTriangleExact(A, B, C, IPoint3(2, 2, 0)) && !pointInTriangleExact(A, B, C, IPoint3(3, 2, 0)));
    CHECK(!pointInTriangleExact(A, B, C, IPoint3(1, 1, 1)));
    auto bc = barycentric(Point3(A), Point3(B), Point3(C), Point3(1, 1, 7));
    CHECK(near(bc[0], 0.5L) && near(bc[1], 0.25L) && near(bc[2], 0.25L));
    for (int it = 0; it < 3000; it++) {
        IPoint3 a = rndP(-4, 4), b = rndP(-4, 4), c = rndP(-4, 4);
        if (collinear(a, b, c)) continue;
        IPoint3 n = triNormal(a, b, c);
        IPoint3 p = it % 2 ? rndP(-4, 4) : a + (b - a) * rnd(0, 2) / 2 + (c - a) * rnd(0, 2) / 2;
        bool fl = orient(a, b, c, p) == 0;
        if (fl) { auto w = barycentric(Point3(a), Point3(b), Point3(c), Point3(p)); fl = w[0] > -1e-12 && w[1] > -1e-12 && w[2] > -1e-12; }
        CHECK(pointInTriangleExact(a, b, c, p) == fl);
        (void)n;
    }
    // Punto más cercano en triángulo: oráculo = mín(lados, proyección si cae dentro).
    for (int it = 0; it < 2000; it++) {
        Point3 a = rndPD(-3, 3), b = rndPD(-3, 3), c = rndPD(-3, 3), p = rndPD(-5, 5);
        if (norm(cross(b - a, c - a)) < 1e-3) continue;
        ld best = min({distPointSegment(a, b, p), distPointSegment(b, c, p), distPointSegment(c, a, p)});
        auto w = barycentric(a, b, c, p);
        if (w[0] >= 0 && w[1] >= 0 && w[2] >= 0) best = min(best, Plane::fromPoints(a, b, c).distTo(p));
        CHECK(near(distPointTriangle(p, a, b, c), best, 1e-6));
    }
    // Segmento-triángulo exacto contra oráculo racional (no coplanar) o distancia (coplanar).
    int hits = 0;
    for (int it = 0; it < 20000; it++) {
        IPoint3 a = rndP(-3, 3), b = rndP(-3, 3), c = rndP(-3, 3), p = rndP(-3, 3), q = rndP(-3, 3);
        if (it % 4 == 0) a.z = b.z = c.z = p.z = q.z = 0;
        if (collinear(a, b, c)) continue;
        i128 tp = triple(b - a, c - a, p - a), tq = triple(b - a, c - a, q - a);
        bool oracle;
        if ((tp > 0 && tq > 0) || (tp < 0 && tq < 0)) oracle = false;
        else if (tp == 0 && tq == 0) {
            Point3 P(p), Q(q), Ad(a), Bd(b), Cd(c);
            ld dd = min({distSegSeg(P, Q, Ad, Bd), distSegSeg(P, Q, Bd, Cd), distSegSeg(P, Q, Cd, Ad), distPointTriangle(P, Ad, Bd, Cd), distPointTriangle(Q, Ad, Bd, Cd)});
            oracle = dd < 1e-9;
        } else {
            ll den = (ll)(tp - tq), num = (ll)tp;    // X = p + (q-p)·tp/(tp-tq), escalado por den
            IPoint3 Xs = p * den + (q - p) * num;
            oracle = pointInTriangleExact(a * den, b * den, c * den, Xs);
        }
        bool got = segTriangleExact(p, q, a, b, c);
        CHECK(got == oracle); hits += got;
    }
    CHECK(hits > 1000);
    // Rayo-triángulo.
    auto t = rayTriangle(Point3(1, 1, 5), Point3(0, 0, -1), Point3(A), Point3(B), Point3(C));
    CHECK(t && near(*t, 5) && !rayTriangle(Point3(1, 1, 5), Point3(0, 0, 1), Point3(A), Point3(B), Point3(C)));
    CHECK(!rayTriangle(Point3(1, 1, 0), Point3(1, 0, 0), Point3(A), Point3(B), Point3(C)));   // coplanar -> nullopt
    auto sp = segTrianglePoint(Point3(1, 1, -1), Point3(1, 1, 3), Point3(A), Point3(B), Point3(C));
    CHECK(sp && nearP(*sp, Point3(1, 1, 0)));
    // Tetraedros.
    IPoint3 D(0, 0, 4);
    CHECK(tetVolume6(A, B, C, D) == 64 && near(tetVolume(A, B, C, D), 64.0L / 6) && tetVolume6(A, C, B, D) == -64);
    CHECK(tetVolume6(IPoint3(0, 0, 0), IPoint3(1, 0, 0), IPoint3(0, 1, 0), IPoint3(0, 0, 1)) == 1);
    CHECK(tetDegenerate(A, B, C, IPoint3(9, 9, 0)) && tetVolume(A, B, C, IPoint3(9, 9, 0)) == 0);
    CHECK(near(tetHeight(A, B, C, D), 4) && near(tetSurface(A, B, C, D), 3 * 8 + sqrtl(3) / 4 * 32));
    CHECK(nearP(tetCentroid(Point3(A), Point3(B), Point3(C), Point3(D)), Point3(1, 1, 1)));
    for (int it = 0; it < 3000; it++) {
        IPoint3 a = rndP(-3, 3), b = rndP(-3, 3), c = rndP(-3, 3), d = rndP(-3, 3), p = rndP(-3, 3);
        if (coplanar(a, b, c, d)) continue;
        auto av = [&](const IPoint3& w, const IPoint3& x, const IPoint3& y, const IPoint3& z) { i128 v = tetVolume6(w, x, y, z); return v < 0 ? -v : v; };
        bool oracle = av(p, b, c, d) + av(a, p, c, d) + av(a, b, p, d) + av(a, b, c, p) == av(a, b, c, d);
        CHECK(pointInTetraExact(a, b, c, d, p) == oracle);
    }
}

void testEsferas() {
    Sphere s{Point3(0, 0, 0), 2};
    CHECK(near(sphereArea(2), 16 * PI3) && near(sphereVolume(2), 32 * PI3 / 3));
    CHECK(near(capArea(2, 4), sphereArea(2)) && near(capVolume(2, 4), sphereVolume(2)) && near(capVolume(2, 2), sphereVolume(2) / 2));
    CHECK(cmpPointSphere(s, Point3(1, 1, 1)) == -1 && cmpPointSphere(s, Point3(0, 2, 0)) == 0 && cmpPointSphere(s, Point3(3, 0, 0)) == 1);
    CHECK(cmpPointSphereExact(IPoint3(0, 0, 0), 3, IPoint3(1, 2, 2)) == 0 && cmpPointSphereExact(IPoint3(0, 0, 0), 3, IPoint3(1, 2, 3)) == 1);
    CHECK(near(distToSphereSurface(s, Point3(0, 0, 0.5)), 1.5) && distToBall(s, Point3(1, 0, 0)) == 0 && near(distToBall(s, Point3(5, 0, 0)), 3));
    CHECK(near(chordLength(5, 3), 8));
    auto ts = lineSphere(Line3(Point3(-5, 0, 0), Point3(1, 0, 0)), s);
    CHECK(ts.size() == 2 && near(ts[0], 3) && near(ts[1], 7));
    CHECK(lineSphere(Line3(Point3(-5, 2, 0), Point3(1, 0, 0)), s).size() == 1 && lineSphere(Line3(Point3(-5, 3, 0), Point3(1, 0, 0)), s).empty());
    CHECK(raySphere(Point3(0, 0, 0), Point3(0, 0, 1), s).size() == 1 && raySphere(Point3(5, 0, 0), Point3(1, 0, 0), s).empty());
    CHECK(segmentSphere(Point3(0, 0, 0), Point3(0, 0, 1), s).empty() && segmentSphere(Point3(0, 0, 0), Point3(0, 0, 3), s).size() == 1);
    for (int it = 0; it < 300; it++) {
        Sphere q{rndPD(-3, 3), rndD(0.5, 3)}; Line3 l(rndPD(-5, 5), rndPD(-5, 5));
        for (ld t : lineSphere(l, q)) CHECK(near(dist(l.at(t), q.c), q.r, 1e-6));
    }
    Circle3 ci;
    CHECK(sphereSphere(s, Sphere{Point3(4, 0, 0), 2}, ci) == SR_EXT_TANGENT && nearP(ci.c, Point3(2, 0, 0)));
    CHECK(sphereSphere(s, Sphere{Point3(1, 0, 0), 1}, ci) == SR_INT_TANGENT && nearP(ci.c, Point3(2, 0, 0)));
    CHECK(sphereSphere(Sphere{Point3(1, 0, 0), 1}, s, ci) == SR_INT_TANGENT && nearP(ci.c, Point3(2, 0, 0)));
    CHECK(sphereSphere(s, Sphere{Point3(9, 0, 0), 2}, ci) == SR_SEPARATE && sphereSphere(s, Sphere{Point3(0.5, 0, 0), 0.5}, ci) == SR_CONTAINED);
    CHECK(sphereSphere(s, s, ci) == SR_SAME && sphereSphere(s, Sphere{Point3(2, 0, 0), 2}, ci) == SR_INTERSECT);
    CHECK(nearP(ci.c, Point3(1, 0, 0)) && near(ci.r, sqrtl(3)));
    CHECK(near(sphereSurfaceGap(s, Sphere{Point3(9, 0, 0), 2}), 5) && near(sphereSurfaceGap(s, Sphere{Point3(0.5, 0, 0), 0.5}), 1));
    CHECK(near(sphereIntersectionVolume(1, 1, 1), 5 * PI3 / 12) && sphereIntersectionVolume(1, 1, 3) == 0 && near(sphereIntersectionVolume(3, 1, 1), sphereVolume(1)));
    Plane pz = Plane::fromCoeffs(0, 0, 1, -1);
    CHECK(planeSphere(pz, s, ci) == IK_LINE && near(ci.r, sqrtl(3)) && nearP(ci.c, Point3(0, 0, 1)));
    CHECK(planeSphere(Plane::fromCoeffs(0, 0, 1, -2), s, ci) == IK_POINT && planeSphere(Plane::fromCoeffs(0, 0, 1, -3), s, ci) == IK_NONE);
    for (int it = 0; it < 300; it++) {
        Point3 a = rndPD(-5, 5), b = rndPD(-5, 5), c = rndPD(-5, 5), d = rndPD(-5, 5);
        Point3 cc = circumcenter3(a, b, c);
        CHECK(near(dist(cc, a), dist(cc, b), 1e-6) && near(dist(cc, a), dist(cc, c), 1e-6) && fabsl(triple(b - a, c - a, cc - a)) < 1e-6);
        Sphere cs;
        if (circumsphere(a, b, c, d, cs) && cs.r < 1e4) CHECK(near(dist(cs.c, b), cs.r, 1e-6) && near(dist(cs.c, d), cs.r, 1e-6));
    }
    CHECK(!circumsphere(Point3(0, 0, 0), Point3(1, 0, 0), Point3(0, 1, 0), Point3(1, 1, 0), s));
    // Minimum enclosing sphere contra fuerza bruta (subconjuntos de 2, 3 y 4 puntos).
    for (int it = 0; it < 300; it++) {
        int n = rnd(1, 9);
        vector<Point3> p(n);
        for (auto& q : p) q = it % 3 == 0 ? Point3(rndP(0, 3)) : rndPD(-5, 5);
        if (it % 5 == 0) for (auto& q : p) q.z = 0;   // coplanares
        ld best = n == 1 ? 0 : 1e30;
        auto okS = [&](const Sphere& sp) { for (auto& q : p) if (dist(sp.c, q) > sp.r + 1e-9) return false; return true; };
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
            if (okS(sphereFrom2(p[i], p[j]))) best = min(best, sphereFrom2(p[i], p[j]).r);
            for (int k = j + 1; k < n; k++) {
                if (!collinear(p[i], p[j], p[k]) && okS(sphereFrom3(p[i], p[j], p[k]))) best = min(best, sphereFrom3(p[i], p[j], p[k]).r);
                for (int l = k + 1; l < n; l++) { Sphere t; if (circumsphere(p[i], p[j], p[k], p[l], t) && okS(t)) best = min(best, t.r); }
            }
        }
        Sphere got = minEnclosingSphere(p);
        CHECK(okS(Sphere{got.c, got.r + 1e-7L}) && near(got.r, best, 1e-7));
    }
    Point3 u = fromLatLon(0, 0, 1), v = fromLatLon(0, 90, 1), w = fromLatLon(90, 0, 1);
    CHECK(near(greatCircleDist(u, v, 1), PI3 / 2) && near(greatCircleDist(u, w, 6371), 6371 * PI3 / 2));
}

vector<IPoint3> cubeV(ll L) {
    vector<IPoint3> v;
    for (int m = 0; m < 8; m++) v.pb(IPoint3((m & 1) * L, (m >> 1 & 1) * L, (m >> 2 & 1) * L));
    return v;
}
void testMallas() {
    vector<IPoint3> v = cubeV(2);
    // 12 triángulos del cubo [0,2]^3 orientados hacia afuera (vértice m = bits x,y,z).
    vector<Face> f = {{0, 2, 3}, {0, 3, 1}, {4, 5, 7}, {4, 7, 6}, {0, 1, 5}, {0, 5, 4}, {2, 6, 7}, {2, 7, 3}, {0, 4, 6}, {0, 6, 2}, {1, 3, 7}, {1, 7, 5}};
    CHECK(meshClosedConsistent(f) && meshVolume6(v, f) == 48 && near(meshSurface(v, f), 24) && nearP(meshCentroid(v, f), Point3(1, 1, 1)));
    vector<Face> g = f;
    swap(g[3][1], g[3][2]);
    CHECK(!meshClosedConsistent(g));
    for (int it = 0; it < 50; it++) {
        vector<Face> h = f;
        for (auto& t : h) if (rng() % 2) swap(t[1], t[2]);
        CHECK(orientMesh(v, h) && meshClosedConsistent(h) && meshVolume6(v, h) == 48);
    }
    // Caras cuadradas (poliedro con caras poligonales).
    vector<vector<int>> quads = {{0, 2, 3, 1}, {4, 5, 7, 6}, {0, 1, 5, 4}, {2, 6, 7, 3}, {0, 4, 6, 2}, {1, 3, 7, 5}};
    CHECK(polyhedronVolume6(v, quads) == 48);
    CHECK(polygonVectorArea2(vector<IPoint3>{IPoint3(0, 0, 3), IPoint3(2, 0, 3), IPoint3(2, 2, 3), IPoint3(0, 2, 3)}) == IPoint3(0, 0, 8));
    CHECK(parallelepipedVolume(IPoint3(2, 0, 0), IPoint3(1, 3, 0), IPoint3(5, 5, 4)) == 24 && near(pyramidVolume(9, 4), 12) && near(prismVolume(3, 5), 15));
}

void testHull() {
    // Dimensiones degeneradas.
    CHECK(convexHull3D({}).dim == -1 && convexHull3D({IPoint3(1, 1, 1), IPoint3(1, 1, 1)}).dim == 0);
    CHECK(convexHull3D({IPoint3(0, 0, 0), IPoint3(1, 1, 1), IPoint3(2, 2, 2), IPoint3(0, 0, 0)}).dim == 1);
    CHECK(convexHull3D({IPoint3(0, 0, 0), IPoint3(1, 0, 0), IPoint3(0, 1, 0), IPoint3(5, 5, 0)}).dim == 2);
    // Rejilla (L+1)^3: muchos coplanares/colineales. Volumen L^3, área 6L^2, 6 caras, 8 vértices.
    for (ll L : {1, 2, 3, 5}) {
        vector<IPoint3> p;
        for (ll x = 0; x <= L; x++) for (ll y = 0; y <= L; y++) for (ll z = 0; z <= L; z++) p.pb(IPoint3(x, y, z));
        shuffle(p.begin(), p.end(), rng);
        p.pb(p[0]);   // duplicado
        Hull3 h = convexHull3D(p);
        CHECK(h.dim == 3 && hullVolume6(p, h) == 6 * L * L * L && near(hullSurface(p, h), 6 * L * L) && countFacets(p, h) == 6);
        CHECK(hullExtremeVertices(p, h).size() == 8 && hullVertices(h).size() >= 8 && meshClosedConsistent(h.faces));
    }
    // Octaedro: 8 caras.
    vector<IPoint3> oct = {IPoint3(1, 0, 0), IPoint3(-1, 0, 0), IPoint3(0, 1, 0), IPoint3(0, -1, 0), IPoint3(0, 0, 1), IPoint3(0, 0, -1), IPoint3(0, 0, 0)};
    Hull3 ho = convexHull3D(oct);
    CHECK(countFacets(oct, ho) == 8 && hullVolume6(oct, ho) == 8 && hullExtremeVertices(oct, ho).size() == 6);
    // Aleatorio: propiedades + número de caras contra fuerza bruta O(n^4).
    for (int it = 0; it < 400; it++) {
        int n = rnd(4, 18);
        ll R = it % 2 ? 2 : 1000000000;
        vector<IPoint3> p(n);
        for (auto& q : p) q = rndP(-R, R);
        Hull3 h = convexHull3D(p);
        if (h.dim != 3) continue;
        CHECK(meshClosedConsistent(h.faces) && hullVolume6(p, h) > 0);
        for (auto& f : h.faces) for (auto& q : p) CHECK(orient(p[f[0]], p[f[1]], p[f[2]], q) <= 0);
        set<IPoint3> brute;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) {
            IPoint3 nn = triNormal(p[i], p[j], p[k]);
            if (isZero(nn)) continue;
            bool ok = true;
            for (auto& q : p) if (orient(p[i], p[j], p[k], q) > 0) { ok = false; break; }
            if (ok) brute.insert(normDir(nn, false));
        }
        CHECK((int)brute.size() == countFacets(p, h));
        vector<IPoint3> p2 = p;
        shuffle(p2.begin(), p2.end(), rng);
        CHECK(hullVolume6(p2, convexHull3D(p2)) == hullVolume6(p, h));
    }
    // Rendimiento: 3000 puntos aleatorios.
    vector<IPoint3> big(3000);
    for (auto& q : big) q = rndP(-1000000, 1000000);
    Hull3 hb = convexHull3D(big);
    CHECK(hb.dim == 3 && meshClosedConsistent(hb.faces));
}

void testClosestPair() {
    for (int it = 0; it < 300; it++) {
        int n = rnd(2, 200);
        ll R = it % 3 == 0 ? 5 : (it % 3 == 1 ? 1000 : 1000000000);
        vector<IPoint3> p(n);
        for (auto& q : p) q = rndP(-R, R);
        i128 brute = -1;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) { i128 d = dist2(p[i], p[j]); if (brute < 0 || d < brute) brute = d; }
        i128 got; auto [a, b] = closestPair3D(p, got);
        CHECK(got == brute && a != b && dist2(p[a], p[b]) == got);
    }
}

void testTriTriObb() {
    using T3 = array<IPoint3, 3>;
    T3 base = {IPoint3(0, 0, 0), IPoint3(4, 0, 0), IPoint3(0, 4, 0)};
    CHECK(triTriIntersectExact(base, {IPoint3(1, 1, -1), IPoint3(1, 1, 1), IPoint3(5, 5, 5)}));            // perfora
    CHECK(!triTriIntersectExact(base, {IPoint3(1, 1, 1), IPoint3(2, 1, 1), IPoint3(1, 2, 1)}));           // paralelo arriba
    CHECK(triTriIntersectExact(base, {IPoint3(1, 1, 0), IPoint3(2, 1, 0), IPoint3(1, 2, 0)}));            // coplanar contenido
    CHECK(!triTriIntersectExact(base, {IPoint3(5, 5, 0), IPoint3(6, 5, 0), IPoint3(5, 6, 0)}));           // coplanar disjunto
    CHECK(triTriIntersectExact(base, {IPoint3(4, 0, 0), IPoint3(9, 0, 3), IPoint3(9, 0, -3)}));           // toca en un vértice
    CHECK(triTriIntersectExact(base, {IPoint3(0, 0, 0), IPoint3(4, 0, 0), IPoint3(0, 0, 4)}));            // comparten arista
    CHECK(!triTriIntersectExact(base, {IPoint3(3, 3, -1), IPoint3(3, 3, 1), IPoint3(9, 9, 0)}));          // casi, por fuera de la hipotenusa
    for (int it = 0; it < 3000; it++) {
        T3 A = {rndP(-3, 3), rndP(-3, 3), rndP(-3, 3)}, B = {rndP(-3, 3), rndP(-3, 3), rndP(-3, 3)};
        if (it % 3 == 0) for (auto* T : {&A, &B}) for (auto& q : *T) q.z = 0;
        if (collinear(A[0], A[1], A[2]) || collinear(B[0], B[1], B[2])) continue;
        bool r = triTriIntersectExact(A, B);
        CHECK(r == triTriIntersectExact(B, A) && r == triTriIntersectExact({A[1], A[2], A[0]}, {B[0], B[2], B[1]}));
        // Muestreo exacto: punto baricéntrico (i,j,k)/6 de A dentro de B => deben cortarse.
        bool sampled = false;
        for (int i = 0; i <= 6 && !sampled; i++) for (int j = 0; i + j <= 6 && !sampled; j++) {
            IPoint3 X = A[0] * i + A[1] * j + A[2] * (6 - i - j);
            sampled = pointInTriangleExact(B[0] * 6, B[1] * 6, B[2] * 6, X);
        }
        if (sampled) CHECK(r);
    }
    // OBB: caso alineado = cajas exactas; rotado: muestreo de puntos (sin falsos "separados").
    for (int it = 0; it < 2000; it++) {
        Box3 a = rndBox(-5, 5), b = rndBox(-5, 5);
        CHECK(obbIntersect(obbFromBox(a), obbFromBox(b)) == boxesTouchOrOverlap(a, b));
    }
    int inter = 0;
    for (int it = 0; it < 1500; it++) {
        OBB o[2];
        for (auto& ob : o) {
            Mat3 M = rodrigues(rndPD(-1, 1) + Point3(0, 0, 1e-3L), rndD(0, 2 * PI3));
            ob.c = rndPD(-3, 3);
            for (int k = 0; k < 3; k++) { ob.u[k] = Point3(M.a[0][k], M.a[1][k], M.a[2][k]); ob.e[k] = rndD(0.2, 2); }
        }
        bool sat = obbIntersect(o[0], o[1]);
        bool found = false;
        for (int x = -4; x <= 4 && !found; x++) for (int y = -4; y <= 4 && !found; y++) for (int z = -4; z <= 4 && !found; z++) {
            Point3 q = o[0].c + o[0].u[0] * (o[0].e[0] * x / 4) + o[0].u[1] * (o[0].e[1] * y / 4) + o[0].u[2] * (o[0].e[2] * z / 4);
            found = pointInOBB(o[1], q);
        }
        if (found) CHECK(sat);
        inter += sat;
    }
    CHECK(inter > 100);
    // Rayo contra malla (cubo).
    vector<IPoint3> cv = cubeV(2);
    vector<Point3> cvd;
    for (auto& q : cv) cvd.pb(Point3(q));
    vector<Face> f = {{0, 2, 3}, {0, 3, 1}, {4, 5, 7}, {4, 7, 6}, {0, 1, 5}, {0, 5, 4}, {2, 6, 7}, {2, 7, 3}, {0, 4, 6}, {0, 6, 2}, {1, 3, 7}, {1, 7, 5}};
    auto hit = rayMesh(Point3(1, 1, -5), Point3(0, 0, 1), cvd, f);
    CHECK(hit && near(hit->first, 5) && !rayMesh(Point3(5, 5, -5), Point3(0, 0, 1), cvd, f));
}

// ---------------- Problemas reales (casos de ejemplo de los enunciados) ----------------
// ABC343 E (7x7x7): fijar el primer cubo en el origen y probar desplazamientos de los otros.
bool solve343E(ll V1, ll V2, ll V3, array<ll, 9>& out) {
    auto cube = [](ll a, ll b, ll c) { return Box3{{a, b, c}, {a + 7, b + 7, c + 7}}; };
    Box3 c1 = cube(0, 0, 0);
    for (ll a2 = 0; a2 <= 7; a2++) for (ll b2 = 0; b2 <= 7; b2++) for (ll d2 = 0; d2 <= 7; d2++)
        for (ll a3 = -7; a3 <= 7; a3++) for (ll b3 = -7; b3 <= 7; b3++) for (ll d3 = -7; d3 <= 7; d3++) {
            auto e = exactlyCovered3(c1, cube(a2, b2, d2), cube(a3, b3, d3));
            if (e[0] == V1 && e[1] == V2 && e[2] == V3) { out = {0, 0, 0, a2, b2, d2, a3, b3, d3}; return true; }
        }
    return false;
}
// ABC312 E: con coordenadas <= 100 la solución real usa una rejilla 100^3 de ids; aquí se
//   valida el predicado boxContact == BC_FACE con los ejemplos en O(N^2).
vector<ll> solve312E(const vector<Box3>& b) {
    vector<ll> r(b.size(), 0);
    for (size_t i = 0; i < b.size(); i++) for (size_t j = 0; j < b.size(); j++) if (i != j) r[i] += boxContact(b[i], b[j]) == BC_FACE;
    return r;
}
// ABC144 D (Water Bottle): sección 2D del prisma a x a x b con x de agua.
ld solve144D(ld a, ld b, ld x) {
    ld t = x >= a * a * b / 2 ? atan2l(2 * (a * a * b - x), a * a * a) : atan2l(a * b * b, 2 * x);
    return toDeg(t);
}
void testProblemas() {
    array<ll, 9> o;
    CHECK(solve343E(840, 84, 7, o));
    {
        Box3 c[3];
        for (int i = 0; i < 3; i++) c[i] = Box3{{o[3 * i], o[3 * i + 1], o[3 * i + 2]}, {o[3 * i] + 7, o[3 * i + 1] + 7, o[3 * i + 2] + 7}};
        auto e = exactlyCovered3(c[0], c[1], c[2]);
        CHECK(e[0] == 840 && e[1] == 84 && e[2] == 7);
    }
    CHECK(!solve343E(343, 34, 3, o));
    CHECK(solve312E({{{0, 0, 0}, {1, 1, 1}}, {{0, 0, 1}, {1, 1, 2}}, {{1, 1, 1}, {2, 2, 2}}, {{3, 3, 3}, {4, 4, 4}}}) == vector<ll>({1, 1, 0, 0}));
    CHECK(solve312E({{{0, 0, 10}, {10, 10, 20}}, {{3, 4, 1}, {15, 6, 10}}, {{0, 9, 6}, {1, 20, 10}}}) == vector<ll>({2, 1, 1}));
    vector<Box3> g;
    for (int m = 0; m < 8; m++) { IPoint3 lo(m & 1, m >> 1 & 1, m >> 2 & 1); g.pb({lo, lo + IPoint3(1, 1, 1)}); }
    CHECK(solve312E(g) == vector<ll>(8, 3));
    CHECK(overlapPositive(Box3{{0, 0, 0}, {4, 5, 6}}, Box3{{2, 3, 4}, {5, 6, 7}}) && !overlapPositive(Box3{{0, 0, 0}, {2, 2, 2}}, Box3{{0, 0, 2}, {2, 2, 4}}));
    CHECK(near(solve144D(2, 2, 4), 45, 1e-9) && near(solve144D(12, 21, 10), 89.7834636934L, 1e-9) && near(solve144D(3, 1, 8), 4.2363947991L, 1e-9));
    // Gym 104248 G: fórmula cerrada contra minimización numérica por búsqueda en rejilla.
    for (int it = 0; it < 30; it++) {
        Point3 A = rndPD(0.5, 3) * 1, B = rndPD(-3, 3), C = rndPD(-3, 3);
        if (fabsl(triple(A, B, C)) < 1) continue;
        ld al = rndD(0.1, 1), be = rndD(0.1, 1), ga = rndD(0.1, 1);
        Point3 P = A * al + B * be + C * ga;
        ld D = fabsl(triple(A, B, C)), best = 1e30;
        // s y t libres; u despejado de al/s + be/t + ga/u = 1.
        ld lo1 = al * 1.01, hi1 = al * 12, lo2 = be * 1.01, hi2 = be * 12;
        for (int rep = 0; rep < 4; rep++) {
            ld bs = 0, bt = 0, bv = 1e30;
            for (int i = 0; i <= 200; i++) for (int j = 0; j <= 200; j++) {
                ld sv = lo1 + (hi1 - lo1) * i / 200, tv = lo2 + (hi2 - lo2) * j / 200, rest = 1 - al / sv - be / tv;
                if (rest <= 0) continue;
                ld V = sv * tv * (ga / rest) * D / 6;
                if (V < bv) { bv = V; bs = sv; bt = tv; }
            }
            best = min(best, bv);
            ld w1 = (hi1 - lo1) / 20, w2 = (hi2 - lo2) / 20;
            lo1 = max(al * 1.0001L, bs - w1); hi1 = bs + w1; lo2 = max(be * 1.0001L, bt - w2); hi2 = bt + w2;
        }
        CHECK(near(minTetraThroughPoint(A, B, C, P), best, 1e-6));
    }
}

signed main() {
    auto t0 = chrono::steady_clock::now();
    testBasico(); testTrucos(); testRotaciones(); testCajas(); testRectas(); testPlanos();
    testTriangulosTetra(); testEsferas(); testMallas(); testHull(); testClosestPair(); testTriTriObb(); testProblemas();
    auto ms = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t0).count();
    cout << "geometria-3d: " << checks << " comprobaciones OK (" << ms << " ms)" << endl;
}
