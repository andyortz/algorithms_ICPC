// Tema: 01_Estructuras/Descomposicion_SQRT
// Base: Template/simple.cpp (int = long long).
// Adaptación: Apunte o implementación comentada; conservado para consulta.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

// APUNTE ORIGINAL: no es una unidad C++ compilable.
square decomposition. 
dividir array en sqrt(n) bloques => por lo tanto si tenemos n = 1e5 -> sqrt(n) = 300. Por lo tanto es posible tener mas o menos 3e7 -> (es pesado). 
Operaciones => actualizaciones O(1), no entrara log(...) -> es muy caro 
(suele ser trampa: brute force mas optimizado - inteligente)
algoritmo MO: avanzada de square decomposition. 
1. agrupar consultas adyacentes maximo sqrt(q)
2. ordenar por end
3. tenemos 3 operaciones que se deben hacer: add, remove, query. *** la mayoria o es dificil ponerle un update a la estructura -> debe ser bien pensado. 
