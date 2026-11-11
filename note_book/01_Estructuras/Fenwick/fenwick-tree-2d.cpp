// Tema: 01_Estructuras/Fenwick
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_C38F0CC4470A5532
#define NOTEBOOK_GENERADO_C38F0CC4470A5532
#include "../../_base/template-simple.hpp"
using ll = long long;
using vl = vector<long long>;
struct BIT2D { // 1-indexed
    vector<vl> bit;
    ll n, m;
 
    BIT2D(ll n, ll m) : bit(n+1, vl(m+1)), n(n), m(m) {}
 
    ll lsb(ll i) { return i & -i; }
 
    void add(int row, int col, ll x) {
        for (int i = row;i<=n;i+=lsb(i))
            for (int j = col;j<=m;j+=lsb(j))
                bit[i][j] += x;
    }
 
    ll sum(int row, int col) {
        ll res = 0;
        for (int i = row;i>0;i-=lsb(i))
            for (int j = col;j>0;j-=lsb(j))
                res += bit[i][j];
        return res;
    }
 
    ll sum(int x1, int y1, int x2, int y2) {
        return sum(x2,y2) - sum(x1-1,y2) - sum(x2,y1-1) + sum(x1-1,y1-1);
    }
 
    void set(int x, int y, ll val) {
        add(x,y,val-sum(x,y,x,y));
    }
};
#endif
