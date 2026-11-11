// Tema: 01_Estructuras/Segment_Tree/Dos_dimensiones
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_19AC389005584702
#define NOTEBOOK_GENERADO_19AC389005584702
#include "../../../_base/template-simple.hpp"
using ll = long long;
// Tested: https://www.spoj.com/problems/MATSUM/

struct Node { ll x = 0; };
 
Node e() { return Node(); } // Identity element, op(x,e()) = x
 
// Binary Operation, Associative. (a+b)+c = a+(b+c)
Node op(const Node &a, const Node &b) { 
    Node c;
    c.x = a.x + b.x;
    return c;
}
 
struct segtree2d {
    int n, m;
    vector<vector<Node>> t; 
 
    void init(int n, int m) {
        this->n = n;
        this->m = m;
        t.assign(n*2, vector<Node>(m*2, e()));
    }

    void init(int n, int m, vector<vector<Node>> &nums) {
        init(n, m);
        
        for (int i = 0;i<n;i++) { // build leaf segtrees
            for (int j=0;j<m;j++) t[i+n][j+m] = nums[i][j];
            for (int j=m-1;j>0;j--) t[i+n][j] = op(t[i+n][j*2], t[i+n][j*2+1]);
        }

        for (int i = n-1;i>0;i--) { // build non leaf segtrees
            for (int j=0;j<2*m;j++) t[i][j] = op(t[i*2][j], t[i*2+1][j]);
        }
    }

    Node query_y(int x, int l, int r) {
        l += m, r += m+1;
        Node resl = e(), resr = e();
        for (; l < r; l>>=1, r>>=1) {
            if (l&1) resl = op(resl, t[x][l++]);
            if (r&1) resr = op(t[x][--r], resr);
        }
        return op(resl, resr);
    }

    Node query(int x1, int y1, int x2, int y2) {
        ll l = x1+n, r = x2+n+1;
        Node resl = e(), resr = e();
        for (; l < r; l>>=1, r>>=1) {
            if (l&1) resl = op(resl, query_y(l++, y1, y2));
            if (r&1) resr = op(query_y(--r,y1,y2), resr);
        }
        return op(resl,resr);
    }

    void update(int x, int y, const Node &v) {
        x += n, y += m;
        t[x][y] = v; // fix leaf segtrees
        for (int j = y; j>>=1; ) {
            t[x][j] = op(t[x][j*2], t[x][j*2+1]);
        }

        for (; x >>= 1; ) { // fix non leaf segtree
            t[x][y] = op(t[x*2][y], t[x*2+1][y]);
            for (int j = y; j>>=1; ) {
                t[x][j] = op(t[x*2][j], t[x*2+1][j]);
            }
        }
    };

    Node get(int x, int y) { return t[x+n][y+m]; }
};
#endif
