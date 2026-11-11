// Tema: 07_Geometria/Convex_Hull
// Base: Template/simple.cpp (int = long long).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_0D0AC7F2617F930E
#define NOTEBOOK_GENERADO_0D0AC7F2617F930E
#include "../../_base/template-simple.hpp"

struct pt {
    int x, y;
    pt(int a = 0, int b = 0) {x = a, y = b;}
    int operator == (pt const &o) const {
        return x == o.x && y == o.y;
    }
    pt operator - (pt const &o) {return {x - o.x, y - o.y};}
};
int dist(pt &a, pt &b) {
    int x = a.x - b.x, y = a.y - b.y;
    return x*x + y*y;
}
int orientation(pt &a, pt &b, pt &c) {
    int v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v<0) return -1;
    return v? 1: 0; // 0 colineal, 1 b esta a la derecha de a, c
}
int cw(pt &a, pt &b, pt &c, int colli = 0) {
    int o = orientation(a, b, c); 
    return o<0 || (colli && !o);
}
int collinear(pt &a, pt &b, pt &c) {return !orientation(a, b, c);}
void convexhull(vector<pt> &v, int inclu) {
    pt p0 = *min_element(v.begin(), v.end(), [](pt a, pt b){
            return make_pair(a.y, a.x)<make_pair(b.y, b.x);
            });
    sort(v.begin(), v.end(), [&p0](pt &a, pt &b){
                int o = orientation(p0, a, b); 
                if (!o) return dist(p0, a)<dist(p0, b);
                return o<0;
            });
    if (inclu) {
        int i = v.size()-1; 
        while (i > -1 && collinear(p0, v[i], v.back())) i--;
        reverse(v.begin() + 1 + i, v.end());
    }

    vector<pt> st; 
    for (int i= 0; i<v.size(); i++) {
        while (st.size()>1 && !cw(st[st.size()-2], st.back(), v[i], inclu)) st.pop_back();
        st.push_back(v[i]);
    }

    if (!inclu && st.size() == 2 && st[0] == st[1]) st.pop_back();
    v = st;
    // devuelve los puntos sobre el mismo vector, en lado de reloj;
}
/*
	para calcular si 2 segmentos intersectan, hacer convex hull y caso especial es puntos colineales
*/
#endif
