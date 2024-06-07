#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int busquedaBinaria(int arr[], int bajo, int alto, int objetivo) {
    while (bajo <= alto) {
        int medio = bajo + (alto - bajo) / 2;
        if (arr[medio] == objetivo) {
            return medio; 
        } else if (arr[medio] < objetivo) {
            bajo = medio + 1; 
        } else {
            alto = medio - 1; 
        }
    }
    return -1; 
}


void generarNumerosAleatorios(int arr[], int cantidad) {
    srand(time(NULL)); 

    for (int i = 0; i < cantidad; ++i) {
        arr[i] = rand() % 1000 + 1; // 
    }
}

void ordenarArreglo(int arr[], int cantidad) {
}

int main() {
    int numeros[100];
    int objetivo = 35;

    
    generarNumerosAleatorios(numeros, 100);

    
    ordenarArreglo(numeros, 100);

   
    int indice = busquedaBinaria(numeros, 0, 99, objetivo);

   
    if (indice != -1) {
        printf("El valor %d se encuentra en la posición %d.\n", objetivo, indice + 1);
    } else {
        printf("El valor %d no se encuentra en el conjunto.\n", objetivo);
    }

    return 0;
}
