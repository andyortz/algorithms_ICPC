// Requisito de selección: Para max_right/min_left usar tamaño potencia de dos y predicado monótono que cumpla g(e()).
// Tema: 01_Estructuras/Segment_Tree/Lazy
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: Operaciones de bits/ensamblador: revisar ancho de palabra (32/64 bits) y el caso cero; preservar tipos explícitos cuando el algoritmo lo exige.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_7509BAECEC5E60D1
#define NOTEBOOK_GENERADO_7509BAECEC5E60D1
#include "../../../_base/template-simple.hpp"
using ll = long long;
/*
Lazy Iterative Seg Tree.

This example is for https://cses.fi/problemset/task/1735/
*/
struct Node { ll x; };

const ll SET = 1;
const ll ADD = 2;
struct Func { ll type, val; }; // applied Function

Node e() { return { 0 }; }; // op(x, e()) = x

Func id() { return {ADD, 0}; } // mapping(x, id()) = x

Node op(Node &a, Node &b) { // associative property
    return {a.x + b.x};
}

Node mapping(Node node, ll sz, const Func &lazy) {
    if (lazy.type == SET) node.x = lazy.val * sz;
    else node.x += lazy.val * sz;
    return node;
}

Func comp(Func prev, const Func &actual) {
    if (actual.type==SET) return actual;
    if (prev.type == SET) return {SET, prev.val + actual.val};
    return {ADD, prev.val + actual.val };
}

struct lazyseg {
    ll n, h;
    vector<Node> t;
    vector<Func> lz;
    vector<int> sz; // if sz of node needed
    lazyseg(ll n) : n(n), t(2*n,e()), lz(n, id()), sz(2*n,1) {
        h = 32-__builtin_clz(n);
        for (int i = n-1;i>0;i--) sz[i] = sz[i*2]+sz[i*2+1];
    }

    void all_apply(ll x, const Func & f) {
        t[x] = mapping(t[x], sz[x], f);
        if (x<n) lz[x] = comp(lz[x], f);
    }

    void push(ll x) {
        all_apply(x*2, lz[x]);
        all_apply(x*2+1, lz[x]);
        lz[x] =id();
    }

    void build(ll x) {
        t[x] = op(t[x*2], t[x*2+1]);
    }

    bool ok(ll x, ll i) {
        return ((x>>i)<<i)!=x;
    }

    void update(ll p, Node v) {
        p += n;
        for (int i =h;i>0;i--) push(p>>i);
        t[p] = v;
        for (int i =1;i<=h;i++) build(p>>i);
    }

    Node query(ll l, ll r) {
        if (l>r) return e();
        l += n, r += n+1;
        for (int i=h;i>0;i--) {
            if (ok(l,i)) push(l>>i);
            if (ok(r,i)) push((r-1)>>i);
        }
        Node ansl = e(), ansr = e();
        for (;l<r;l>>=1,r>>=1) {
            if (l&1) ansl = op(ansl, t[l++]);
            if (r&1) ansr = op(t[--r], ansr);
        }
        return op(ansl, ansr);
    }

    void apply(ll l, ll r, const Func &f) {
        if (l>r) return;
        l += n, r += n+1;
        for (int i =h;i>0;i--) {
            if (ok(l,i)) push(l>>i);
            if (ok(r,i)) push((r-1)>>i);
        }
        {
            int l2 = l, r2 = r;
            for (;l<r;l>>=1,r>>=1) {
                if (l&1) all_apply(l++, f);
                if (r&1) all_apply(--r,f);
            }
            l = l2, r= r2;
        }
        for (int i =1;i<=h;i++) {
            if (ok(l,i)) build(l>>i);
            if (ok(r,i)) build((r-1)>>i);
        }
    };
    
    // Maximum r that satisfy g(op(t[l], t[l+1], ..., t[r-1])) = True
    // if there's no g() that returns true, then r = l
    template <class G> int max_right(int l, G g) {
        if (l == n) return n;
        l += n;
        for (int i = h; i >= 1; i--) push(l >> i);
        Node sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, t[l]))) {
                while (l < n) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, t[l]))) {
                        sm = op(sm, t[l]);
                        l++;
                    }
                }
                return l - n;
            }
            sm = op(sm, t[l]);
            l++;
        } while ((l & -l) != l);
        return n;
    }

    // If g is monotone, this is the minimum l that satisfies 
    // g(op(a[l], a[l + 1], ..., a[r - 1])) = true.
    template <class G> int min_left(int r, G g) {
        if (r == 0) return 0;
        ll size = n;
        r += size;
        for (int i = h; i >= 1; i--) push((r - 1) >> i);
        Node sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(t[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(t[r], sm))) {
                        sm = op(t[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(t[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};
#endif
