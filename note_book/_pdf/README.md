# Generador del PDF del notebook

Genera [`notebook-carta-3-columnas.pdf`](../notebook-carta-3-columnas.pdf): tamaño **carta (279,4 × 215,9 mm) en horizontal**, 3 columnas (formato KACTL), código a 7 pt, margen superior de 18 mm para el anillado y estilo para impresora en blanco y negro. Tiene 71 páginas, con índice y número de página en cada entrada.

- **Contenido:** código C++ y Python con resaltado de sintaxis. Los apuntes `.tex` se convierten a tablas y fórmulas (KaTeX) y los `.md` a texto con formato.
- **Orden:** las carpetas numeradas (`00_`, `01_`, …) son los capítulos, las subcarpetas son las secciones y cada archivo es una entrada (`§capítulo.sección.archivo`).
- **Índice:** se calcula en dos pasadas. Se genera el PDF, se busca en qué página quedó cada marca `§` y se vuelve a generar con los números reales. El script avisa si alguna marca no aparece.
- **Limpieza (solo en el PDF):** se quitan las guardas `#ifndef NOTEBOOK_GENERADO_…`, los bloques `push_macro`/`pop_macro`, el `#include` de `_base/template-simple.hpp` (la plantilla se imprime una vez, en §0) y las líneas de metadatos `// Tema:`, `// Base:`, `// Adaptación:`. Las líneas `// Requisito:` propias de cada archivo se conservan; las genéricas que se repiten en decenas de archivos se omiten. Las «cajas» de comentarios hechas con `****` se acortan. Con `"quitarLineasVacias": true` tampoco se imprimen las líneas vacías, los separadores `// ====` ni los comentarios vacíos. Los archivos fuente no se modifican.

## Uso

```powershell
cd note_book/_pdf
npm install          # una vez: puppeteer-core, highlight.js, marked, katex, pdfjs-dist
node generar.mjs     # ~30 s
```

En VS Code: **Terminal → Ejecutar tarea… → PDF: generar notebook (2 y 3 columnas)**.

Usa el **Microsoft Edge** (o Chrome) instalado; no descarga ningún navegador. Si no lo encuentra, definir `CHROME_PATH` con la ruta del ejecutable. El navegador se lanza en modo headless con un perfil temporal y el script se conecta por su puerto de depuración, así que funciona aunque Edge se reinicie solo (por ejemplo, con una actualización pendiente).

## Configuración (`config.json`)

| Clave | Uso |
| --- | --- |
| `titulo`, `subtitulo` | portada y pie de página |
| `salida` | ruta del PDF; `{columnas}` se reemplaza por el número de columnas |
| `papel` | `A4` o `Letter` |
| `orientacion` | `horizontal` (por defecto) o `vertical` |
| `columnas` | un número o una lista: `[2, 3]` genera un PDF por cada valor |
| `tamCodigo`, `tamTexto` | tamaño de letra del código y del texto |
| `margenes` | márgenes de la hoja; `top` es más ancho (18 mm) para el anillado |
| `blancoYNegro` | `true`: todo negro, palabras clave en negrita, comentarios en gris oscuro cursiva y encabezados sin fondo (para impresora monocroma) |
| `extensiones` | tipos de archivo incluidos |
| `excluir` | rutas (relativas a `note_book`) que no se imprimen |
| `quitarLineasQueEmpiezanCon` | líneas de metadatos que se omiten en el PDF |

Las carpetas que empiezan con `_` (`_base`, `_pruebas`, `_pdf`) y los archivos sueltos en la raíz (`README.md`, `CATALOGO.md`) nunca se incluyen.

## Para reducir páginas

El notebook ocupa **71 páginas** (carta, 3 columnas, código a 7 pt). Muchas competencias limitan el material impreso; en ICPC suele ser **25 páginas**, pero hay que confirmarlo en las reglas de cada competencia. Para una versión de competencia:

1. Agregar a `excluir` lo que no se va a usar: un archivo (`"10_Python/estructuras.py"`) o una carpeta completa (`"09_Utilidades/Interactivos"`).
2. Bajar `tamCodigo` (6.5pt sigue siendo legible) o usar `"papel": "Letter"`.
3. Copiar `config.json` con otro nombre y otra `salida`, y generar con `node generar.mjs competencia.json`, para tener dos versiones (completa y de competencia).
