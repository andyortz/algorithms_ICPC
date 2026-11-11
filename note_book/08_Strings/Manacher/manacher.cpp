// Tema: 08_Strings/Manacher
// Base: Template/simple.cpp (int = long long).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_AF7B519735E2EA0D
#define NOTEBOOK_GENERADO_AF7B519735E2EA0D
#include "../../_base/template-simple.hpp"

vi f(string &s) {
    int n = s.size(); 
    vi v(n); 
    int l = 1, r = 1; 
    for (int i=1 ; i<n;i ++) {
        v[i] = max(0ll, min(r-i, v[l+r-i])); 
        while (s[i-v[i]] == s[i+v[i]]) v[i]++; 
        if (i+v[i] > r) l = i-v[i], r = i+v[i]; 
    }
    return v; 
}
vi manacher(string &s, int n) {
    string t = "";
    for (int i= 0; i<n; i++) {
        string aux = i?"$": ""; 
        aux.pb(s[i]); 
        t += aux;
    } 
    t = "#"+t+"@"; 

    vi v = f(t);

    int res = v[0]; 
    for (int i=0 ; i<v.size(); i++) 
        res = max(res, v[i]); 

    int l, r, sum; 
    l = 1, r = 1, sum =0;

    for (int i =0 ; i<v.size(); i++) 
    if (res==v[i]) {
        int lx = i-(res-1), rx = i+(res-1);
        int s = 1+((res-1)/2)*2; // string: aaa
        if (!(i&1)) s = (res/2)*2; // string aa
        if (sum < s) l = lx, r = rx, sum = s;
    }
    for (int i=l; i<=r; i++) 
        if (t[i]!='$') cout<<t[i];
    cout<<endl;

    return v;
}
#endif
