#include <stdio.h>
#include <stdbool.h>

#define NUM_ARCHIVOS 5
#define NUM_CARPETAS 3
#define TOTAL_COMBINACIONES 243

void imprimirCombinacion(int combinacion[]) {
    for (int i = 0; i < NUM_CARPETAS; ++i) {
        printf("C%d", i + 1);
        for (int j = 0; j < NUM_ARCHIVOS; ++j) {
            if (combinacion[j] == i + 1) {
                printf("%d", j + 1);
            }
        }
        if (i != NUM_CARPETAS - 1) {
            printf(" / ");
        }
    }
    printf("\n");
}


bool combinacionRepetida(int combinaciones[][NUM_ARCHIVOS], int nuevaCombinacion[]) {
    for (int i = 0; i < TOTAL_COMBINACIONES; ++i) {
        bool igual = true;
        for (int j = 0; j < NUM_ARCHIVOS; ++j) {
            if (combinaciones[i][j] != nuevaCombinacion[j]) {
                igual = false;
                break;
            }
        }
        if (igual) {
            return true;
        }
    }
    return false;
}


void generarCombinaciones(int combinaciones[][NUM_ARCHIVOS], int combinacion[], int nivel) {
    if (nivel == NUM_ARCHIVOS) {
        if (!combinacionRepetida(combinaciones, combinacion)) {
            imprimirCombinacion(combinacion);
            for (int i = 0; i < NUM_ARCHIVOS; ++i) {
                combinaciones[TOTAL_COMBINACIONES - 1][i] = combinacion[i];
            }
        }
        return;
    }

    for (int i = 1; i <= NUM_CARPETAS; ++i) {
        combinacion[nivel] = i;
        generarCombinaciones(combinaciones, combinacion, nivel + 1);
    }
}

int main() {
    int combinaciones[TOTAL_COMBINACIONES][NUM_ARCHIVOS];
    int combinacionActual[NUM_ARCHIVOS] = {0};

    generarCombinaciones(combinaciones, combinacionActual, 0);

    return 0;
}
