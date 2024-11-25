# Caso-Final-Integrador-Tema-3 - Gonzalo Müller

<details>
  <summary> LINK DEL REPOSITORIO </summary>

### Link al repositorio: https://github.com/Muller3014/Caso-Final-Integrador-Tema-3.git

</details>



<details>
  <summary> ENUNCIADO </summary>

## Carga de Scripts en Tiny-Lisp

Este proyecto implementa funciones para cargar scripts desde archivos de texto en la memoria y aplicarles coloración sintáctica. Además, maneja errores comunes como archivos inexistentes, problemas de apertura o errores de lectura.

### Funciones Implementadas:

<code>void load_script(const char* filename, bool show_script = false)</code>

### Descripción:
Carga el contenido de un archivo especificado y, opcionalmente, muestra su contenido en la consola.

### Parámetros:

<code>filename</code>: Nombre del archivo a cargar.

<code>show_script</code>: Si es true, muestra el contenido del archivo en la consola.

### Manejo de Errores:
Archivo inexistente.

Problemas de apertura del archivo.

Errores de lectura del archivo.

<code>void load_script()</code>

### Descripción:
Solicita al usuario el nombre de un archivo, llama a load_script(const char* filename, bool show_script = false) y maneja cualquier error de manera apropiada.

</details>


</details>

<details>
  <summary>EJERCICIOS</summary>

## Código en la carpeta <code>Funciones</code>

```
#include "ejecutar.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

struct ColorConsole {
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox {
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox; // suponemos que ya está inicializado

void load_script(const char* filename, bool show_script) {
    string script;
    FILE* f = nullptr;
    try {
        f = fopen(filename, "rb");
        if (!f) {
            cerr << "Error de apertura de " << filename << endl;
            return;
        }

        int c;
        char buf[4001];
        while ((c = fread(buf, 1, 4000, f)) > 0) {
            buf[c] = 0;
            script.append(buf);
        }
        fclose(f);
        f = nullptr;

        if (show_script) {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }
        consoleBox->new_text();
        consoleBox->set_text(script);
    } catch (...) {
        cerr << "Error durante la lectura del archivo" << endl;
        if (f) fclose(f);
    }
}

void load_script() {
    char filename[500];
    printf("Archivo: ");
    scanf("%499s", filename);
    load_script(filename, true);
}
```
## Código en <code>Main</code>
```
#include "Funciones/ejecutar.h"

int main() {
    load_script();
    return 0;
}
```
Solamente se declara la funcion <code>load_script()</code>
</details>
