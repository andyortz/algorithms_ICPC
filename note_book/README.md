# Notebook seleccionado

Actualización LIS/LCS: LIS ya era O(N log N). Se añadieron [LCS por LIS y LCS por bloques de 64 bits](04_DP/LCS_y_distancia_edicion/README.md), con complejidades, condiciones de uso y pruebas propias. Los recuentos y validaciones de la selección inicial indicados abajo son históricos y no incluyen estas dos nuevas implementaciones.

Actualización geometría 3D: se añadió la [biblioteca de geometría 3D](07_Geometria/Geometria_3D/README.md) en tres partes (esencial, sólidos y avanzado), con cheat sheet, tabla «¿Qué uso?», problemas analizados y [pruebas propias](_pruebas/geometria-3d.cpp). Requiere GNU G++20 y tampoco está incluida en los recuentos históricos.

261 archivos organizados por tema: **229 implementaciones/programas**, 15 apuntes C++ y 17 recursos de referencia. La primera fase tenía 669 archivos. Se retiraron 408 archivos de la salida (alternativas redundantes, arneses históricos y metadatos).

Se eligió una implementación por algoritmo o contrato: prioridad a `int`, `vi`, `pb`, bucles normales y contenedores estándar compatibles con **Template/simple.cpp**; después, dependencias explícitas y verificaciones disponibles. Se conservan variantes con capacidades distintas: 1D/2D, persistencia/rollback, lazy de suma/asignación/progresión, CHT monótono/dinámico y aritmética real/modular/XOR. El nombre conserva el origen.

- [Catálogo por tema y requisitos](CATALOGO.md).
- [Decisiones y alternativas retiradas](SELECCION.md).
- [Auditoría de integridad](_verificacion/auditoria.json).
- [Diagnósticos de compilación](_verificacion/resultados.json).
- [Pruebas funcionales](_verificacion/pruebas.json).

## Uso con la plantilla

Cada .cpp incluye `_base/template-simple.hpp`, cuyo preámbulo es el de `../Template/simple.cpp` (sin solve/main). Los enteros de la plantilla son long long. Para incluir un fragmento, usa esa cabecera una sola vez y escribe tu solve/main; para copiarlo manualmente, omite los includes de la base y las guardas. Los programas que ya tienen main usan signed main: conserva un único main. La colección es un notebook de fragmentos, no un programa que deba compilar todos los archivos juntos: nombres como Node, init y MOD pueden coincidir entre algoritmos.

Los aliases adicionales están declarados localmente. Las bibliotecas GNU se incluyen con las macros protegidas. Algunos kernels usan uint32_t, uint64_t o __int128 deliberadamente; no sustituyas esos tipos por int.

## Validación y límites

GCC: **173 archivos pasan sintaxis**, **56 requieren integración**, 15 son apuntes. 0 archivos pasan con avisos. Se ejecutaron **17/17 pruebas funcionales** con casos pequeños y, donde corresponde, comparación con fuerza bruta.

Pasar sintaxis no implica que el algoritmo sea correcto en todos los casos ni que enlace sin completar funciones de coste. El catálogo marca límites, variables externas y errores previos conocidos. Los temas únicos incompletos se conservaron para no perderlos; no deben usarse directamente sin atender sus requisitos. No se inventaron dimensiones, módulos o transiciones específicos de problemas.

## Fuentes y reproducción

Los **669 originales** de Alex, Nicolas, extra, pacha y vasito mantienen sus SHA-256. También permanece intacto Template/simple.cpp. Se eliminaron las copias redundantes de `_originales` tras comprobarlas contra las fuentes. El inventario completo y las decisiones siguen en `_revision`, sin duplicar código.

Desde esta carpeta, con Node.js y GNU g++ disponibles:

```powershell
node _herramientas/generar.mjs
node _herramientas/verificar.mjs
node _herramientas/pruebas.mjs
node _herramientas/documentar.mjs
```

El generador aplica automáticamente `_herramientas/seleccion.json`: regenerar **no vuelve a dejar las alternativas descartadas**. Los scripts capturar-* y ajustes-manuales pertenecen a la preparación de la primera fase; no forman parte de estos pasos.
