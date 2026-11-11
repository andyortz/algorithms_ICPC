// Tema: 06_Matematicas/Teoria_de_numeros/Primos_y_factorizacion
// Base: Template/simple.cpp (int = long long).
// Adaptación: Apunte o implementación comentada; conservado para consulta.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

// APUNTE ORIGINAL: no es una unidad C++ compilable.
// ll fermatFactors(ll n) {
//     ll a = ceil(sqrt(n)) ;
//     if(a * a == n){
//         return a;
//     }
//     ll b;
//     while(true) {
//         ll b1 = a * a - n ;
//         b = (ll)sqrt(b1) ;
         
//         if(b * b == b1)
//             break;
//         else
//             a += 1;
//     }
//     return min(a - b, a + b);
// }
