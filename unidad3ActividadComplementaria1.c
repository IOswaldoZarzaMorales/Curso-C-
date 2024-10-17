#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    char value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isEmpty(Node* root) {
    return root == NULL;
}

Node* insert(Node* root, char value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value == '*' || value == '+' || value == '^') {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

void printInOrder(Node* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    printf("%c ", root->value);
    printInOrder(root->right);
}

int main() {
    Node* root = NULL;

    root = createNode('*');
    root->left = createNode('1');
    root->right = createNode('+');
    root->right->left = createNode('^');
    root->right->right = createNode('2');
    root->right->left->left = createNode('3');
    root->right->left->right = createNode('4');

    printf("Recorrido In-Order: ");
    printInOrder(root);
    printf("\n");

    if (isEmpty(root)) {
        printf("El árbol está vacío.\n");
    } else {
        printf("El árbol no está vacío.\n");
    }

    deleteTree(root);

    return 0;
}
