#include <stdio.h>
#include <stdlib.h>

/*
5. Diseñar una función que, dado un árbol binario de búsqueda, calcule la cantidad de
nodos hojas divisores de la raíz.
6. Diseñar una función que, dado un árbol binario de búsqueda, calcule la sumatoria de
aquellos nodos pares con un solo hijo.
7. Diseñar una función que, dado un árbol binario de búsqueda, calcule la cantidad de
nodos impares con dos hijos.*/

typedef struct arbol {
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

void crear(treenode **hoja);

void insertar(treenode **hoja, int elem);

void mostrar(treenode *hoja, int *contadorNodos);

void crear(treenode **hoja) {
    int numero;

    printf("Ingrese numero\n");
    scanf("%d", &numero);
    while (numero != -1) {
        insertar(&(*hoja), numero);
        printf("ingrese numero\n");
        scanf("%d", &numero);
    }
}

void insertar(treenode **hoja, int elem) {
    int numero = elem;
    if (elem == -1)
        return;
    if (*hoja == NULL) {
        (*hoja) = (treenode *) malloc(sizeof(treenode));
        (*hoja)->dato = elem;
        (*hoja)->der = NULL;
        (*hoja)->izq = NULL;
    } else {
        if (numero > (*hoja)->dato) {
            insertar(&(*hoja)->der, elem);
        } else {
            insertar(&(*hoja)->izq, elem);
        }
    }
    return;
}

void mostrar(treenode *hoja, int *contadorNodos) {
    if (hoja != NULL) {
        *contadorNodos += 1;
        mostrar(hoja->izq, contadorNodos);
        printf("%d ", hoja->dato);
        mostrar(hoja->der, contadorNodos);
    }
    return;
}

void preOrden(treenode *hoja, int *contadorNodos) {
    if (hoja != NULL) {
        printf("%d ", hoja->dato);
        mostrar(hoja->izq, contadorNodos);
        mostrar(hoja->der, contadorNodos);
    }
    return;
}

void postOrden(treenode *hoja, int *contadorNodos) {
    if (hoja != NULL) {
        mostrar(hoja->izq, contadorNodos);
        mostrar(hoja->der, contadorNodos);
        printf("%d ", hoja->dato);
    }
    return;
}

void buscarNumero(treenode *hoja, int numeroBuscado) {
    if (hoja != NULL) {
        if (hoja->dato == numeroBuscado) {
            printf("\nSe ha encontrado el número ingresado");
            return;
        }
        buscarNumero(hoja->izq, numeroBuscado);
        buscarNumero(hoja->der, numeroBuscado);
    }
}

int main() {
    int numeroABuscar, contadorNodos = 0;
    printf("Arboles\n");
    treenode *arbol = NULL;

    crear(&arbol);
    //printf("¿Qué número quiere saber si está en el árbol?");
    //scanf("%d", &numeroABuscar);
    printf("**************\n");
    printf("Mostrar arbol\n");
    printf("***************\n");


    mostrar(arbol, &contadorNodos);
    //buscarNumero(arbol, numeroABuscar);
    //printf("Hay %d nodo/s\n", contadorNodos);
    return 0;
}
