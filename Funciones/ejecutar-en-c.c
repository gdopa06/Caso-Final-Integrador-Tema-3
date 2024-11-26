#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ejecutar-en-c.h"

#define BUF_SIZE 4000

void load_script(const char* filename, int show_script) {
    char script[BUF_SIZE + 1];
    FILE* f = NULL;

    f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Error de apertura de %s\n", filename);
        return;
    }

    size_t n;
    while ((n = fread(script, 1, BUF_SIZE, f)) > 0) {
        script[n] = '\0';
        if (show_script) {
            printf("\033[34m\033[47m%s\033[0m\n", script);
        }
    }

    if (ferror(f)) {
        fprintf(stderr, "Error durante la lectura del archivo\n");
    }

    fclose(f);
}

void prompt_and_load_script() {
    char filename[500];
    printf("Archivo: ");
    scanf("%499s", filename);
    load_script(filename, 1);
}
