// Tema: 08_Strings/KMP
// Base: Template/simple.cpp (int = long long).
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_1AB5E71063F949C7
#define NOTEBOOK_GENERADO_1AB5E71063F949C7
#include "../../_base/template-simple.hpp"

// Very useful for some DP's with strings
// aut[i][j], you are in 'i' position, and choose character 'j', the next position.

const int MAXN = 1e5 + 5, alpha = 26;
const char L = 'A';
int aut[MAXN][alpha]; // aut[i][j] = a donde vuelvo si estoy en i y pongo una j

void build(string &s) {
    int lps = 0;
    aut[0][s[0]-L] = 1;
    int n = s.size();
    for (int i = 1; i < n+1; i++) {
        for (int j = 0; j < alpha; j++) aut[i][j] = aut[lps][j];
        if (i < n) {
            aut[i][s[i]-L] = i + 1;
            lps = aut[lps][s[i]-L];
        }
    }
}
#endif
