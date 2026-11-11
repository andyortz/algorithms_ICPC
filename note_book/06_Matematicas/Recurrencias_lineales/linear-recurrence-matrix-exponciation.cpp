// Tema: 06_Matematicas/Recurrencias_lineales
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll, vl.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_7F51BE0D6F62B830
#define NOTEBOOK_GENERADO_7F51BE0D6F62B830
#include "../../_base/template-simple.hpp"
using ll = long long;
using vl = vector<long long>;
// Solves F_n = C_n-1 * F_n-1 + ... + C_0*F_0 + p + q*n + r*n^2
// O((n+3)^3*log(k))
// Also solves (k steps)-min path of a matrix in same complexity
// Tested and for more details see: https://codeforces.com/blog/entry/80195
const int MOD = 1e9 + 7;
const int N = 10 + 3; // 10 is MAX N, 3 is for p,q,r
inline ll add(ll x, ll y) { return (x+y)%MOD; }
inline ll mul(ll x, ll y) { return (x*y)%MOD; }

// const ll inf = ll(1e18) + 5; // for k-min path
struct Mat {
    array<array<ll,N>,N> mt;
    Mat(bool id=false) {
        for (auto &x : mt) fill(all(x),0);
        if (id) for (int i=0;i<N;i++) mt[i][i]=1;
	//for (auto &x : mt) fill(all(x),inf); // For k-min path
        //if (id) for (int i =0;i<N;i++) mt[i][i]=0;
    }
    inline Mat operator * (const Mat &b) {
        Mat ans;
        for (int k=0;k<N;k++)for(int i=0;i<N;i++)for(int j=0;j<N;j++)
            ans.mt[i][j]=add(ans.mt[i][j],mul(mt[i][k],b.mt[k][j]));
            //ans.mt[i][j] = min(ans.mt[i][j],mt[i][k]+b.mt[k][j]); // For K-min Path

        return ans;
    }
    inline Mat pow(ll k) {
        Mat ans(true),p=*this; // Note '*'!!
        while (k) {
            if (k&1) ans = ans*p;
            p=p*p;
            k>>=1;
        }
        return ans;
    }
    string db() { // Optional for debugging
        string ans;
        for (int i =0;i<mt.size();i++)for (int j=0;j<mt.size();j++)
                ans +=to_string(mt[i][j]),ans+=" \n"[j==N-1];
        return "\n"+ans;
    }
};

// Important!!! Remember to set N = MAX_N + 3 
// Solves F_n = C_n-1 * F_n-1 + ... + C_0*F_0 + p + q*n + r*n^2 
// f = {f_0,f_1,f_2,f_3,...,f_n}
// c = {c_0,c_1,c_2,c_3,...,c_n}
ll fun(vl f, vl c, ll p, ll q, ll r, ll k) {
    ll n = c.size();
    if (k < n) return f[k];
    reverse(all(c)),reverse(all(f));
    Mat mt,st;
    for (int i = 0;i<n;i++) mt.mt[0][i]=c[i];
    for (int i = 1;i<n;i++) mt.mt[i][i-1]=1;
    for (int i = 0;i<n;i++) st.mt[i][0]=f[i];
    
    vl extra = {p,q,r}; // To extend here with 1*p,i*q,i*i*r,etc
    for (int i=0;i<extra.size();i++) {
        st.mt[n+i][0]=1; //1,i,i*i,i*i*i
        mt.mt[0][n+i]=extra[i];//p,q,r
        mt.mt[n+i][n]=1; //pascal
        for (int j=1;j<=i;j++) { //pascal
            st.mt[n+i][0]*=n;//1,i*i,i*i*i
            mt.mt[n+i][n+j]=mt.mt[n+i-1][n+j]+mt.mt[n+i-1][n+j-1];
        }
    }
    return (mt.pow(k-(n-1))*st).mt[0][0];
}
#endif
