// Tema: 01_Estructuras/Colas_monotonas
// Base: Template/simple.cpp (int = long long).
// Adaptación: Texto explicativo original convertido a comentarios C++ (1 líneas).
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

#ifndef NOTEBOOK_GENERADO_9D11FCF36ABF34CE
#define NOTEBOOK_GENERADO_9D11FCF36ABF34CE
#include "../../_base/template-simple.hpp"

// > Funciona como una queue<> que además permite hallar el elemento mínimo en O(1). Para mantener el máximo: cambiar > por <.

template<typename T>
struct mnque {
    deque<T> dq, mn;

    void push(T x) {
        dq.pb(x);
        while (mn.size() && mn.back() > x) mn.pop_back(); // o < para max
        mn.pb(x);
    }

    void pop() {
        if (dq.front() == mn.front()) mn.pop_front();
        dq.pop_front();
    }

    T min() { return mn.front(); }
};

mnque<int> q;
#endif
