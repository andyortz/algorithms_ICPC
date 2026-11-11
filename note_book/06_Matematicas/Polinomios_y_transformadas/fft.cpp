// Tema: 06_Matematicas/Polinomios_y_transformadas
// Base: Template/simple.cpp (int = long long).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_BEC5675D96AB8706
#define NOTEBOOK_GENERADO_BEC5675D96AB8706
#include "../../_base/template-simple.hpp"

using cd = complex<double>;
const double PI = acos(-1);
/*only works for n <= 2e5 aprox -> 1(s) and n<=1e6 takes 1.5(s) */
void fft(vector<cd> & a, int inv = 0) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (inv ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (inv) 
        for (cd & x : a) x /= n;
}
vi multiply(vi &a, vi &b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end()); 
    int n = 1; 
    while (n<a.size()+b.size()) n<<=1;
    fa.resize(n), fb.resize(n); 
    fft(fa), fft(fb); 
    for (int i =0; i<n;i ++) fa[i]*=fb[i]; 
    fft(fa, 1); 
    vi res(n); 
    for (int i= 0; i<n;i ++) res[i] = round(fa[i].real()); 
    return res;
}
#endif
