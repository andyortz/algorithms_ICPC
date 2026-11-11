// Tema: 09_Utilidades/Entrada_salida
// Base: Template/simple.cpp (int = long long).
// Adaptación: Apunte o implementación comentada; conservado para consulta.
// Requisito: En simple.cpp int significa long long: usar %lld para esos valores. Los formatos listados describen los tipos nativos.
// Validación y dependencias: ver CATALOGO.md y _verificacion/resultados.json.

// APUNTE ORIGINAL: no es una unidad C++ compilable.
* Lectura segun el tipo de dato (Se usan las mismas para imprimir):

scanf("%d", &value);   // int
scanf("%ld", &value);  // long y long int
scanf("%c", &value);   // char
scanf("%f", &value);   // float
scanf("%lf", &value);  // double
scanf("%s", &value);   // char*
scanf("%lld", &value); // long long int
scanf("%x", &value);   // int hexadecimal
scanf("%o", &value);   // int octal

* Impresion de punto flotante con d decimales, ejemplo 6 decimales:

printf("%.6lf", value);
