// Tema: 01_Estructuras/Segment_Tree/Lazy
// Base: Template/simple.cpp (int = long long).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_6DAC32657AA2E3DD
#define NOTEBOOK_GENERADO_6DAC32657AA2E3DD
#include "../../../_base/template-simple.hpp"

struct ST {
    struct st {
        int val, lazy;
        st* l;
        st* r;
        st() : val(0), lazy(0), l(nullptr), r(nullptr) {}
        st(int v): val(v), lazy(0), l(nullptr), r(nullptr) {}
    };
    typedef st* pst;

    pst root;
    ST() {root = new st();}

    int get(pst &t) {return t ? t->val : 0;}
    void apply(pst &t, int b, int e, int v) {
        if (!t) return;
        t->val += (e - b) * v;
        t->lazy += v;
    }
    void push(pst &t, int b, int e) {
        if (!t || t->lazy == 0) return;

        int mid = (b + e) >> 1;
        if (!t->l) t->l = new st();
        if (!t->r) t->r = new st();

        apply(t->l, b, mid, t->lazy);
        apply(t->r, mid, e, t->lazy);

        t->lazy = 0;
    }
    void pull(pst &t) {t->val = get(t->l) + get(t->r);}
    void upd(pst &t, int l, int r, int i, int j, int val) {
        if (j <= l || r <= i) return;
        if (!t) t = new st();

        if (i <= l && r <= j) {
            apply(t, l, r, val);
            return;
        }

        push(t, l, r);

        int mid = (l+r)>>1;
        upd(t->l, l, mid, i, j, val);
        upd(t->r, mid, r, i, j, val);

        pull(t);
    }
    int query(pst &t, int l, int r, int i, int j) {
        if (!t || j <= l || r <= i) return 0;
        if (i <= l && r <= j) return t->val;

        push(t, l, r);

        int mid = (l+r)>>1;
        return query(t->l, l, mid, i, j) + query(t->r, mid, r, i, j);
    }
    void upd(int l, int r, int i, int j, int val) {
        upd(root, l, r, i, j, val);
    }
    int query(int l, int r, int i, int j) {
        return query(root, l, r, i, j);
    }
};
#endif
