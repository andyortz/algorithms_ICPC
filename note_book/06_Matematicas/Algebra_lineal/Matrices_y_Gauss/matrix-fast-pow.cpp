// Tema: 06_Matematicas/Algebra_lineal/Matrices_y_Gauss
// Base: Template/simple.cpp (int = long long).
// Adaptación: Bucles y atajos auxiliares expandidos a C++ explícito o macros de simple.cpp.
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_B1A6F8F9E7C62E37
#define NOTEBOOK_GENERADO_B1A6F8F9E7C62E37
#include "../../../_base/template-simple.hpp"
using ll = long long;
// kth term of linear recurrence 
// of size m a_i = sum(a_(i-j)*p_j)
// f(x) = x^m - sum(x^(m-j)*p_j)
// g(x^k) = g(x^k MOD f)
typedef vector<vector<ll> > Matrix;
Matrix ones(int n) {
  Matrix r(n,vector<ll>(n));
  for (int i=(0), nb_fin_1=(n); i<nb_fin_1; ++i)r[i][i]=1;
  return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
  int n=sz(a),m=sz(b[0]),z=sz(a[0]);
  Matrix r(n,vector<ll>(m));
  for (int i=(0), nb_fin_3=(n); i<nb_fin_3; ++i)for (int j=(0), nb_fin_5=(m); j<nb_fin_5; ++j)for (int k=(0), nb_fin_7=(z); k<nb_fin_7; ++k)
    r[i][j]+=a[i][k]*b[k][j],r[i][j]%=MOD;
  return r;
}
Matrix be(Matrix b, ll e) {
  Matrix r=ones(sz(b));
  while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
  return r;
}
#endif
