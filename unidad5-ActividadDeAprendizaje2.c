#include <stdio.h>
#include <stdlib.h>

// Definición del nodo del árbol
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Función para crear un nuevo nodo
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Función para insertar un elemento en el árbol
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Función para buscar un elemento en el árbol
int search(struct Node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == value) {
        return 1;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

// Función para mostrar los elementos del árbol (inorden)
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int option, value;

    do {
        printf("\n--- Menú ---\n");
        printf("1. Insertar elemento\n");
        printf("2. Buscar elemento\n");
        printf("3. Mostrar elementos (inorden)\n");
        printf("4. Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Ingresa el valor a insertar: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Elemento insertado correctamente.\n");
                break;

            case 2:
                printf("Ingresa el valor a buscar: ");
                scanf("%d", &value);
                if (search(root, value)) {
                    printf("Elemento encontrado en el árbol.\n");
                } else {
                    printf("Elemento no encontrado.\n");
                }
                break;

            case 3:
                printf("Elementos en el árbol (inorden): ");
                inOrder(root);
                printf("\n");
                break;

            case 4:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción no válida. Intenta de nuevo.\n");
        }
    } while (option != 4);

    return 0;
}
