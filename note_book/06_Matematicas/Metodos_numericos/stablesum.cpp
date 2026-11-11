// Tema: 06_Matematicas/Metodos_numericos
// Base: Template/simple.cpp (int = long long).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_CF6D98B97D795853
#define NOTEBOOK_GENERADO_CF6D98B97D795853
#include "../../_base/template-simple.hpp"

struct stableSum {
  int cnt = 0;
  vector<double> v, prefs{0};
  void operator += (double a) {
    assert(a >= 0);
    int s = ++cnt;
    while(s % 2 == 0) {
      a += v.back();
      v.pop_back(), pref.pop_back();
      s /= 2;
    }
    v.pb(a);
    pref.pb(pref.back() + a);
  }
  double val() {return pref.back();}
};
#endif
