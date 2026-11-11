// Tema: 04_DP/LCS_y_distancia_edicion
// Base: Template/simple.cpp (int = long long).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_5C23C93DF58B9E82
#define NOTEBOOK_GENERADO_5C23C93DF58B9E82
#include "../../_base/template-simple.hpp"

const int M_MAX = 20;
const int N_MAX = 20;
int m, n;
string X;
string Y;
int memo[M_MAX + 1][N_MAX + 1];


// Encuetra el Longest Common Subsequence de string X e Y. m y n son sus tamaños
// lcs de abfgh aeeeeiiiiigh =  agh
int lcs (int m, int n) {
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0) memo[i][j] = 0;
      else if (X[i - 1] == Y[j - 1]) memo[i][j] = memo[i - 1][j - 1] + 1;
      else memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
    }
  }
  return memo[m][n];
}
#endif
