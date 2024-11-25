# Caso-Final-Integrador-Tema-3

Carga de Scripts en Tiny-Lisp
Descripción
Este proyecto implementa funciones para cargar scripts desde archivos de texto en la memoria y aplicarles coloración sintáctica. Además, maneja errores comunes como archivos inexistentes, problemas de apertura o errores de lectura.

Funciones Implementadas
void load_script(const char* filename, bool show_script = false)
Descripción: Carga el contenido de un archivo especificado y, opcionalmente, muestra su contenido en la consola.
Parámetros:
filename: Nombre del archivo a cargar.
show_script: Si es true, muestra el contenido del archivo en la consola.
Manejo de Errores:
Archivo inexistente.
Problemas de apertura del archivo.
Errores de lectura del archivo.
void load_script()
Descripción: Solicita al usuario el nombre de un archivo, llama a load_script(const char* filename, bool show_script = false) y maneja cualquier error de manera apropiada.
Código

```
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

void load_script(const char* filename, bool show_script = false) {
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

int main() {
    load_script();
    return 0;
}
```

Compilación y Ejecución
Para compilar y ejecutar el programa en CLion:

Asegúrate de que tu archivo CMakeLists.txt esté configurado correctamente:

cmake_minimum_required(VERSION 3.10)
project(Caso_Final_Integrador_Tema_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Caso_Final_Integrador_Tema_3 main.cpp)
Compila y ejecuta el proyecto desde CLion.

Manejo de Errores
El código maneja los siguientes errores:

Archivo inexistente: Verifica si el archivo se puede abrir.
Error de apertura: Muestra un mensaje de error si no se puede abrir el archivo.
Error de lectura: Muestra un mensaje de error si ocurre un problema durante la lectura.
