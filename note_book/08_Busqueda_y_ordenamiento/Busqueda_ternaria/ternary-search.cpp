// Selección: Función objetivo recibida como parámetro; máximo inicial válido para valores negativos; precisión configurable.
// Tema: 08_Busqueda_y_ordenamiento/Busqueda_ternaria
// Base: Template/simple.cpp (int = long long).
// Adaptación: Alias de tipos ausentes declarados localmente: ll.
// Requisito: Respetar y configurar límites, módulo, tolerancia e inicialización según el problema; no se inventan parámetros faltantes.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_705D998E52348B50
#define NOTEBOOK_GENERADO_705D998E52348B50
#include "../../_base/template-simple.hpp"
using ll = long long;
//Ternary Search - O(log(n))
//Max version, for minimum version just change signals

template<class Funcion>
int ternary_search(int l, int r, Funcion f){
    while(r - l > 3) {
        ll m1 = (l+r)/2;
        ll m2 = (l+r)/2 + 1;
        ll f1 = f(m1), f2 = f(m2);   
        //if(f1 > f2) l = m1;
        if (f1 < f2) l = m1;
        else r = m2;
    }
    int ans = f(l);
    for(int i = l; i <= r; i++){
        ll tmp = f(i);
        //ans = min(ans, tmp);
        ans = max(ans, tmp);
    }
    return ans;
}

//Faster version - 300 iteratons up to 1e-6 precision 
template<class Funcion>
double ternary_search(double l, double r, Funcion f, double tolerancia = 1e-9){
    // for(int i = 0; i < No; i++){
    for (int iter = 0; iter < 300 && r - l > tolerancia; ++iter){
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        // if (f(m1) > f(m2))
        if (f(m1) < f(m2))
            l = m1;
        else
            r = m2;
    }
    return f(l);  
}
#endif
