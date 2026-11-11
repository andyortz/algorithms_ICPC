// Tema: 06_Matematicas/Teoria_de_numeros/Funciones_multiplicativas
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_205A4A31D84ED0E7
#define NOTEBOOK_GENERADO_205A4A31D84ED0E7
#include "../../../_base/template-simple.hpp"
using ll = long long;
using vl = vector<long long>;
// Given an array and q queries of count pairs gcd(a_i,a_j)==k
// i < j, a_i < 1e5, q < 1e5, n < 1e5
// Complexity O(n * log n + q)
// Tested: https://www.hackerrank.com/contests/ab-yeh-kar-ke-dikhao-returns/challenges/gcd-pairs

const int mxN = 1e5 + 10;
vl mo(mxN);
void init() { // Call init() first !!!
    mo[1] = 1;
    for (int i = 1;i<mxN;i++) 
        for (int j = i+i;j<mxN;j+=i) mo[j]-=mo[i];
}

vl cnt(mxN), dcnt(mxN), ans(mxN);
void test_case() {
    ll n,q; cin >> n >> q;
    for (int i=0;i<n;i++) {
        ll x;cin >> x;
        cnt[x]++; // cnt[x] = quantity of X's in array
    }
    for (int i = 1;i<mxN;i++) 
        for (int j = i;j<mxN;j+=i) 
            dcnt[i] += cnt[j];
    // dcnt[x] = quantity of a_i divisible by x
    for (int k = 1;k<mxN;k++) {
        for (int d = 1; d <= mxN/k; d++) {
            ll totalCnt = d*k < mxN ? dcnt[d*k] : 0;
            ans[k] += mo[d] * totalCnt * totalCnt;
        }
        ans[k] += cnt[k]; // substracting j>=i
        ans[k] /= 2;
    }

    while (q--) {
        ll k; cin >> k;
        if (k < mxN) cout << ans[k] << "\n";
        else cout << 0 << "\n";
    }
}
#endif
