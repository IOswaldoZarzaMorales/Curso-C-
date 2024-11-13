#include <stdio.h>
#define MAX 100

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[MAX];
    int size = 0;
    int option;
    int target;
    int result;

    do {
        printf("\n--- Menú de Opciones ---\n");
        printf("1. Insertar elementos\n");
        printf("2. Buscar un elemento\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (size < MAX) {
                    printf("Ingrese un número para insertar: ");
                    scanf("%d", &arr[size]);
                    size++;
                    printf("Elemento insertado correctamente.\n");
                } else {
                    printf("El arreglo está lleno.\n");
                }
                break;

            case 2:
                if (size == 0) {
                    printf("El arreglo está vacío. Inserte elementos primero.\n");
                } else {
                    printf("Ingrese el número que desea buscar: ");
                    scanf("%d", &target);
                    result = linearSearch(arr, size, target);
                    if (result != -1) {
                        printf("Elemento encontrado en el índice %d.\n", result);
                    } else {
                        printf("Elemento no encontrado.\n");
                    }
                }
                break;

            case 3:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (option != 3);

    return 0;
}
