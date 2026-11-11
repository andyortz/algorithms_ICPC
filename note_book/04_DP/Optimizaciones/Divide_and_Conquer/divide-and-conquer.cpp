// Requisito de selección: El comentario anuncia mínimo, pero el cuerpo usa max y centinela -1. Ajustar objetivo, centinela, tam y función de coste juntos.
// Tema: 04_DP/Optimizaciones/Divide_and_Conquer
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_407A92DF5899C93E
#define NOTEBOOK_GENERADO_407A92DF5899C93E
#include "../../../_base/template-simple.hpp"
using ll = long long;
/*
DP[i][j] = min( DP[i-1][k] + C[k][j] )
K[i][j] <= K[i][j+1]
*/
ll lastDP[tam], DP[tam];
int C[tam][tam]; // Cambiar a una funcion de costo si pre-procesar ocupa mucha memoria
void DC(int b, int e, int KL, int KR) {
  int mid = (b + e) / 2;
  pair<ll, int> best = make_pair(-1, KL);
  for (int k = KL; k < min(mid, KR+1); k++)
    best = max( best, make_pair(lastDP[k] + C[k+1][mid], k) );
  DP[mid] = best.first;
  int K = best.second;
  if (b <= mid-1)
    DC(b, mid-1, KL, K);
  if (mid+1 <= e)
    DC(mid+1, e, K, KR);
}
#endif
