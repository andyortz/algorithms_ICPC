// Selección: Una clase para SA, LCP y LCS; corregidos accesos fuera de rango al comparar bloques y prefijos. Reservar $ como centinela y # como separador de LCS.
// Tema: 08_Strings/Suffix_Array_y_LCP
// Base: Template/simple.cpp (int = long long).
// Adaptación: La longitud m de la segunda cadena pasa a ser parámetro explícito de lcs(m).
// Adaptación: Alias de tipos ausentes declarados localmente: pii.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_075F89FC6291A506
#define NOTEBOOK_GENERADO_075F89FC6291A506
#include "../../_base/template-simple.hpp"
using pii = pair<int, int>;
const int MAXL = 300;

struct suffixArray {
    string s;
    int n, MX;
    vector<int> ra, tra, sa, tsa, lcp;

    suffixArray(string &_s) {
        s = _s+"$";
        n = s.size();
        MX = max(MAXL, n)+2;
        ra = tra = sa = tsa = lcp = vector<int>(n);
        build();
    }

    void radix_sort(int k) {
        vector<int> cnt(MX, 0);
        for (int i = 0; i < n; i++) 
            cnt[(i+k < n) ? ra[i+k]+1 : 1]++;
        for (int i = 1; i < MX; i++) 
            cnt[i] += cnt[i-1];
        for (int i = 0; i < n; i++) 
            tsa[cnt[(sa[i]+k < n) ? ra[sa[i]+k] : 0]++] = sa[i];
        sa = tsa;
    }

    void build() {
        for (int i = 0; i < n; i++) 
            ra[i] = static_cast<unsigned char>(s[i]), sa[i] = i;
        for (int k = 1, r; k < n; k <<= 1) {
            radix_sort(k);
            radix_sort(0);
            tra[sa[0]] = r = 0;
            for (int i = 1; i < n; i++) {
                if (ra[sa[i]] != ra[sa[i-1]] || (sa[i]+k < n ? ra[sa[i]+k] : -1) != (sa[i-1]+k < n ? ra[sa[i-1]+k] : -1)) ++r;
                tra[sa[i]] = r;
            }
            ra = tra;
            if (ra[sa[n-1]] == n-1) break;
        }
    }

    int& operator [] (int i) { return sa[i]; }

    void build_lcp() {
        lcp[0] = 0;
        for (int i = 0, k = 0; i < n; i++) {
            if (!ra[i]) continue;
            while (i+k < n && sa[ra[i]-1]+k < n && s[i+k] == s[sa[ra[i]-1]+k]) k++;
            lcp[ra[i]] = k;
            if (k) k--;
        }
    }
    // Longest Common Substring: construir el suffixArray s = s1 + "#" + s2 + "$" y m = s2.size()
    pii lcs(int m) {
        int mx = -1, ind = -1;
        for (int i = 1; i < n; i++) {
            if (((sa[i] < n-m-1) != (sa[i-1] < n-m-1)) && mx < lcp[i]) {
                mx = lcp[i]; ind = i;
            }
        }
        return {mx, ind};
    }
};
#endif
