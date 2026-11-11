// Tema: 01_Estructuras/Treap
// Base: Template/simple.cpp (int = long long).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_B912249D92A30697
#define NOTEBOOK_GENERADO_B912249D92A30697
#include "../../_base/template-simple.hpp"

// Prioridades con mt19937: rand() en MinGW (Windows) solo llega a RAND_MAX = 32767 y repite.
// Tested https://judge.yosupo.jp/problem/ordered_set
mt19937 rngTreap(chrono::steady_clock::now().time_since_epoch().count());
struct item {
    int key, pri, siz;
    item *l, *r;
    item() {}
    item(int key) : key(key), siz(1), pri(rngTreap()), l(0), r(0) {}
};
typedef item* pitem;
int sz(pitem t) {
    return (t?t->siz:0);
}
void up_sz(pitem t) {
    if(t) t->siz = sz(t->l) + 1 + sz(t->r);
}
void split(pitem t, pitem &l, pitem &r, int val) {
    if(!t) r = l = NULL;
    else if(t->key < val) split(t->r, t->r, r, val), l = t;
    else split(t->l, l, t->l, val), r = t;
    up_sz(t);
}
void merge(pitem &t, pitem l, pitem r) {
    if(!l || !r) t=(l?l:r);
    else if(l->pri >= r->pri) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l),t=r;
    up_sz(t);
}
#endif
