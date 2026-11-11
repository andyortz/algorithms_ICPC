// Tema: 07_Geometria/Tres_dimensiones
// Base: Template/simple.cpp (int = long long).
// Adaptación: Includes adicionales protegidos de las macros de la plantilla.
// Requisito: Contiene main de ejemplo/prueba: usar su main o el de simple.cpp, nunca ambos.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_E5A95A382982D817
#define NOTEBOOK_GENERADO_E5A95A382982D817
#include "../../_base/template-simple.hpp"
#pragma push_macro("int")
#undef int
#pragma push_macro("fast")
#undef fast
#pragma push_macro("pb")
#undef pb
#pragma push_macro("F")
#undef F
#pragma push_macro("S")
#undef S
#pragma push_macro("all")
#undef all
#pragma push_macro("sortt")
#undef sortt
#pragma push_macro("sortn")
#undef sortn
#pragma push_macro("pi")
#undef pi
#pragma push_macro("vi")
#undef vi
#pragma push_macro("vb")
#undef vb
#pragma push_macro("vpi")
#undef vpi
#pragma push_macro("vs")
#undef vs
#pragma push_macro("endl")
#undef endl
#include <iostream>
#include <cmath>
#pragma pop_macro("endl")
#pragma pop_macro("vs")
#pragma pop_macro("vpi")
#pragma pop_macro("vb")
#pragma pop_macro("vi")
#pragma pop_macro("pi")
#pragma pop_macro("sortn")
#pragma pop_macro("sortt")
#pragma pop_macro("all")
#pragma pop_macro("S")
#pragma pop_macro("F")
#pragma pop_macro("pb")
#pragma pop_macro("fast")
#pragma pop_macro("int")

/*
Converts from rectangular coordinates to latitude/longitude and vice
versa. Uses degrees (not radians).
*/




using namespace std;

struct ll
{
  double r, lat, lon;
};

struct rect
{
  double x, y, z;
};

ll convert(rect& P)
{
  ll Q;
  Q.r = sqrt(P.x*P.x+P.y*P.y+P.z*P.z);
  Q.lat = 180/M_PI*asin(P.z/Q.r);
  Q.lon = 180/M_PI*acos(P.x/sqrt(P.x*P.x+P.y*P.y));
  
  return Q;
}

rect convert(ll& Q)
{
  rect P;
  P.x = Q.r*cos(Q.lon*M_PI/180)*cos(Q.lat*M_PI/180);
  P.y = Q.r*sin(Q.lon*M_PI/180)*cos(Q.lat*M_PI/180);
  P.z = Q.r*sin(Q.lat*M_PI/180);
  
  return P;
}

signed main()
{
  rect A;
  ll B;
  
  A.x = -1.0; A.y = 2.0; A.z = -3.0;
  
  B = convert(A);
  cout << B.r << " " << B.lat << " " << B.lon << endl;
  
  A = convert(B);
  cout << A.x << " " << A.y << " " << A.z << endl;
}
#endif
