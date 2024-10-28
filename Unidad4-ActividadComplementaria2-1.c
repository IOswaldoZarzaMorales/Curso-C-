#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5 // Definimos cuántas personas (nodos) tendrá nuestra red social

// Estructura que representa a cada persona en la red social
typedef struct Nodo {
    char nombre[20];          // Nombre de la persona
    int amigos[MAX];          // Lista de amigos (conexiones) de la persona
    int numAmigos;            // Cantidad de amigos actuales
} Nodo;

// Esta función inicializa un nodo (persona) en la red social
void inicializarNodo(Nodo *persona, char nombre[]) {
    strcpy(persona->nombre, nombre);  // Asignamos el nombre a la persona
    persona->numAmigos = 0;           // Empezamos con 0 amigos
    for (int i = 0; i < MAX; i++) {
        persona->amigos[i] = 0;       // Ponemos todas las conexiones en 0 (sin amigos)
    }
}

// Función para añadir un amigo (conexión) entre dos personas, solo en un sentido
void agregarAmigo(Nodo *red, int personaIndex, int amigoIndex) {
    // Comprobamos que la persona no tenga ya el máximo de amigos
    if (red[personaIndex].numAmigos < MAX) {
        red[personaIndex].amigos[amigoIndex] = 1;  // Marcamos a amigoIndex como amigo
        red[personaIndex].numAmigos++;             // Aumentamos el contador de amigos
    } else {
        printf("No se pueden agregar más amigos para %s\n", red[personaIndex].nombre);
    }
}

// Función que muestra los amigos de cada persona
void mostrarRed(Nodo *red) {
    for (int i = 0; i < MAX; i++) {
        printf("Amigos de %s: ", red[i].nombre);
        int tieneAmigos = 0; // Variable para ver si la persona tiene amigos o no
        for (int j = 0; j < MAX; j++) {
            if (red[i].amigos[j] == 1) { // Checamos si hay conexión con otro nodo
                printf("%s ", red[j].nombre);
                tieneAmigos = 1;
            }
        }
        if (!tieneAmigos) {
            printf("No tiene amigos");
        }
        printf("\n");
    }
}

int main() {
    Nodo red[MAX]; // Creamos el array de personas en la red social

    // Inicializamos los nombres de cada persona en la red
    inicializarNodo(&red[0], "Ana");
    inicializarNodo(&red[1], "Luis");
    inicializarNodo(&red[2], "Carlos");
    inicializarNodo(&red[3], "Maria");
    inicializarNodo(&red[4], "Pedro");

    // Establecemos conexiones de amistad entre personas
    agregarAmigo(red, 0, 1);  // Ana es amiga de Luis
    agregarAmigo(red, 0, 2);  // Ana también es amiga de Carlos
    agregarAmigo(red, 1, 0);  // Luis también es amigo de Ana
    agregarAmigo(red, 2, 3);  // Carlos es amigo de Maria
    agregarAmigo(red, 3, 4);  // Maria es amiga de Pedro
    agregarAmigo(red, 3, 3);  // Maria se "sigue a sí misma" o se revisa su propio perfil

    // Mostramos los amigos de cada persona en la red social
    mostrarRed(red);

    return 0;
}
