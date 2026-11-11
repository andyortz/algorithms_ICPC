// Requisito de selección: Inicializar todos los valores con update antes de sumar en rangos: el neutro INT64_MAX no admite incrementos positivos.
// Tema: 01_Estructuras/Segment_Tree/Lazy
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_AF657BEC3E8B2BA2
#define NOTEBOOK_GENERADO_AF657BEC3E8B2BA2
#include "../../../_base/template-simple.hpp"
using ll = long long;
// TODO: Make this iterative
struct Node { // Structure
    ll mn;
    ll size = 1;

    Node(ll mn):mn(mn) {
    }
};

struct Func { // Applied function
    ll a = 0;
};

Node e() { // op(x, e()) = x
    Node a(INT64_MAX); // neutral element
    return a;
};

Func id() { // mapping(x, id()) = x
    Func l = {0}; // identify func
    return l;
}

Node op(Node &a, Node &b) { // associative property
    Node c = e();           // binary operation
    c.size = a.size + b.size;
    c.mn = min(a.mn, b.mn);
    return c;
}

Node mapping(Node node, Func &lazy) {
    node.mn += lazy.a; // appling function
    return node;
}

Func composicion(Func &prev, Func &actual) {
    prev.a = prev.a + actual.a; // composing funcs
    return prev;
}

struct lazytree {
    int n;
    vector<Node> nodes;
    vector<Func> lazy;

    void init(int nn) {
        n = nn;
        int size = 1;
        while (size < n) {
            size *= 2;
        }
        ll m = size *2;
        nodes.assign(m, e());
        lazy.assign(m, id());
    }

    void push(int i, int sl, int sr) {
        nodes[i] = mapping(nodes[i], lazy[i]);
        if (sl != sr) {
            lazy[i * 2 + 1] = composicion(lazy[i*2+1],lazy[i]);
            lazy[i * 2 + 2] = composicion(lazy[i*2+2],lazy[i]);
        }
        lazy[i] = id();
    }

    void apply(int i, int sl, int sr, int l, int r, Func f) {
        push(i, sl, sr);
        if (l <= sl && sr <= r) {
            lazy[i] = f;
            push(i,sl,sr);
        } else if (sr < l || r < sl) {
        } else {
            int mid = (sl + sr) >> 1;
            apply(i * 2 + 1, sl, mid, l, r, f);
            apply(i * 2 + 2, mid + 1, sr, l, r, f);
            nodes[i] = op(nodes[i*2+1],nodes[i*2+2]);
        }
    }

    void apply(int l, int r, Func f) {
        apply(0, 0, n - 1, l, r, f);
    }

    void update(int i, Node node) {
        update(0, 0, n-1, i, node);
    }

    void update(int i, int sl, int sr, int pos, Node node) {
        // push SIEMPRE (también en el hijo que no contiene pos): si no, el padre se recalcula
        // con el valor viejo de ese hijo y se pierde su lazy pendiente.
        push(i,sl,sr);
        if (sl <= pos && pos <= sr) {
            if (sl == sr) {
                nodes[i] = node;
            } else {
                int mid = (sl + sr) >> 1;
                update(i * 2 + 1, sl, mid, pos, node);
                update(i * 2 + 2, mid + 1, sr, pos, node);
                nodes[i] = op(nodes[i*2+1], nodes[i*2+2]);
            }
        }
    }

    Node query(int i, int sl, int sr, int l, int r) {
        push(i,sl,sr);
        if (l <= sl && sr <= r) {
            return nodes[i];
        } else if (sr < l || r < sl) {
            return e();
        } else {
            int mid = (sl + sr) >> 1;
            auto a = query(i * 2 + 1, sl, mid, l, r);
            auto b = query(i * 2 + 2, mid + 1, sr, l, r);
            return  op(a,b);
        }
    }

    Node query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};
#endif
