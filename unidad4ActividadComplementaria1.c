#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar un nodo (día)
typedef struct Dia {
    int numeroDia;
    struct Dia* siguienteDia;
} Dia;

// Estructura para representar un nodo (mes)
typedef struct Mes {
    char nombreMes[15];
    struct Dia* listaDias;
    struct Mes* siguienteMes;
} Mes;

// Estructura para la cabeza del grafo
typedef struct Grafo {
    Mes* listaMeses;
} Grafo;

// Función para inicializar el grafo
void Init(Grafo* grafo) {
    grafo->listaMeses = NULL;
}

// Función para crear un nuevo nodo de tipo Mes
Mes* crearNodoMes(char* nombreMes) {
    Mes* nuevoMes = (Mes*)malloc(sizeof(Mes));
    strcpy(nuevoMes->nombreMes, nombreMes);
    nuevoMes->listaDias = NULL;
    nuevoMes->siguienteMes = NULL;
    return nuevoMes;
}

// Función para crear un nuevo nodo de tipo Día
Dia* crearNodoDia(int numeroDia) {
    Dia* nuevoDia = (Dia*)malloc(sizeof(Dia));
    nuevoDia->numeroDia = numeroDia;
    nuevoDia->siguienteDia = NULL;
    return nuevoDia;
}

// Función para añadir un mes al grafo
void addNodo(Grafo* grafo, char* nombreMes) {
    Mes* nuevoMes = crearNodoMes(nombreMes);
    
    // Si la lista de meses está vacía, lo añade como primer mes
    if (grafo->listaMeses == NULL) {
        grafo->listaMeses = nuevoMes;
    } else {
        // Si no, lo añade al final de la lista de meses
        Mes* temp = grafo->listaMeses;
        while (temp->siguienteMes != NULL) {
            temp = temp->siguienteMes;
        }
        temp->siguienteMes = nuevoMes;
    }
}

// Función para añadir días a un mes (enlazar nodos día con el mes)
void addEdge(Mes* mes, int numeroDia) {
    Dia* nuevoDia = crearNodoDia(numeroDia);
    
    // Si la lista de días del mes está vacía, lo añade como primer día
    if (mes->listaDias == NULL) {
        mes->listaDias = nuevoDia;
    } else {
        // Si no, lo añade al final de la lista de días
        Dia* temp = mes->listaDias;
        while (temp->siguienteDia != NULL) {
            temp = temp->siguienteDia;
        }
        temp->siguienteDia = nuevoDia;
    }
}

// Función para buscar un mes en el grafo
Mes* buscarMes(Grafo* grafo, char* nombreMes) {
    Mes* temp = grafo->listaMeses;
    while (temp != NULL) {
        if (strcmp(temp->nombreMes, nombreMes) == 0) {
            return temp;
        }
        temp = temp->siguienteMes;
    }
    return NULL; // Si no encuentra el mes
}

// Función para imprimir los meses y sus días
void imprimirGrafo(Grafo* grafo) {
    Mes* tempMes = grafo->listaMeses;
    while (tempMes != NULL) {
        printf("%s:\n", tempMes->nombreMes);
        Dia* tempDia = tempMes->listaDias;
        while (tempDia != NULL) {
            printf("  Día: %d\n", tempDia->numeroDia);
            tempDia = tempDia->siguienteDia;
        }
        tempMes = tempMes->siguienteMes;
    }
}

int main() {
    Grafo grafo;
    Init(&grafo);
    
    // Añadir los 6 primeros meses
    addNodo(&grafo, "Enero");
    addNodo(&grafo, "Febrero");
    addNodo(&grafo, "Marzo");
    addNodo(&grafo, "Abril");
    addNodo(&grafo, "Mayo");
    addNodo(&grafo, "Junio");
    
    // Añadir días a cada mes
    Mes* mes = buscarMes(&grafo, "Enero");
    for (int i = 1; i <= 31; i++) {
        addEdge(mes, i);
    }
    
    mes = buscarMes(&grafo, "Febrero");
    for (int i = 1; i <= 28; i++) {
        addEdge(mes, i);
    }
    
    mes = buscarMes(&grafo, "Marzo");
    for (int i = 1; i <= 31; i++) {
        addEdge(mes, i);
    }
    
    mes = buscarMes(&grafo, "Abril");
    for (int i = 1; i <= 30; i++) {
        addEdge(mes, i);
    }
    
    mes = buscarMes(&grafo, "Mayo");
    for (int i = 1; i <= 31; i++) {
        addEdge(mes, i);
    }
    
    mes = buscarMes(&grafo, "Junio");
    for (int i = 1; i <= 30; i++) {
        addEdge(mes, i);
    }

    // Imprimir el grafo
    imprimirGrafo(&grafo);

    return 0;
}
