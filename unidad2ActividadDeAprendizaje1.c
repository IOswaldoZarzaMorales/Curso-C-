#include <stdio.h>
#include <string.h>

#define MAX 4 // Definimos el tamaño máximo de la pila.

// Definimos la estructura para la pila.
typedef struct {
    char nombres[MAX][20]; // Arreglo para almacenar los nombres con un máximo de 20 caracteres.
    int tope;              // Entero que indica el índice del tope de la pila.
} Pila;

// Función para inicializar la pila, estableciendo el tope en -1 (pila vacía).
void inicializar(Pila *p) {
    p->tope = -1; // Al iniciar, no hay elementos, por eso el tope es -1.
}

// Función que verifica si la pila está vacía.
int esVacia(Pila *p) {
    return p->tope == -1; // Si el tope es -1, significa que no hay elementos.
}

// Función que verifica si la pila está llena.
int esLlena(Pila *p) {
    return p->tope == MAX - 1; // Si el tope es igual al máximo tamaño de la pila, entonces está llena.
}

// Función para insertar un nombre en la pila (operación push).
void push(Pila *p, char nombre[]) {
    if (esLlena(p)) { // Si la pila está llena, no se puede agregar más.
        printf("La pila está llena. No se puede insertar '%s'.\n", nombre);
    } else {
        p->tope++; // Incrementamos el tope para apuntar al nuevo elemento.
        strcpy(p->nombres[p->tope], nombre); // Copiamos el nombre en la posición correspondiente.
        printf("Se insertó '%s' en la pila.\n", nombre);
    }
}

// Función para extraer un nombre de la pila (operación pop).
void pop(Pila *p) {
    if (esVacia(p)) { // Si la pila está vacía, no se puede extraer.
        printf("La pila está vacía. No se puede extraer.\n");
    } else {
        printf("Se extrajo '%s' de la pila.\n", p->nombres[p->tope]); // Mostramos el nombre que se va a eliminar.
        p->tope--; // Decrementamos el tope para "eliminar" el elemento.
    }
}

// Función para mostrar los nombres en la pila.
void mostrarPila(Pila *p) {
    if (esVacia(p)) { // Si la pila está vacía, se indica.
        printf("La pila está vacía.\n");
    } else {
        printf("Contenido de la pila:\n");
        for (int i = p->tope; i >= 0; i--) { // Mostramos los elementos desde el tope hacia abajo.
            printf("%s\n", p->nombres[i]);
        }
    }
}

int main() {
    Pila pila; // Declaramos una variable de tipo Pila.
    inicializar(&pila); // Inicializamos la pila.

    // Realizamos las operaciones solicitadas.
    pop(&pila); // Intentamos extraer un nombre de una pila vacía (debe mostrar un mensaje de error).

    // Insertamos 4 nombres en la pila.
    push(&pila, "Oswaldo");
    push(&pila, "Ivan");
    push(&pila, "Brenilda");
    push(&pila, "Valeria");

    mostrarPila(&pila); // Mostramos los nombres que están en la pila después de insertarlos.

    // Extraemos 2 nombres.
    pop(&pila);
    pop(&pila);

    mostrarPila(&pila); // Mostramos los nombres restantes en la pila después de las extracciones.

    // Intentamos extraer 3 nombres (aunque solo quedan 2 en la pila).
    pop(&pila);
    pop(&pila);
    pop(&pila); // Este pop debería mostrar un mensaje de error porque la pila ya estará vacía.

    return 0;
}

