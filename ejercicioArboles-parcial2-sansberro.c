#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct arbol {
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

void insertarNodoArbol(treenode **hoja, int elem) {
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
            insertarNodoArbol(&(*hoja)->der, elem);
        } else {
            insertarNodoArbol(&(*hoja)->izq, elem);
        }
    }
    return;
}

void crearNodoArbol(treenode **hoja) {
    int numero;

    printf("ingrese numero\n");
    scanf("%d", &numero);
    while (numero != -1) {
        insertarNodoArbol(&(*hoja), numero);
        printf("ingrese numero\n");
        scanf("%d", &numero);
    }
}

void mostrarNodoArbol(treenode *hoja, int valorRaiz, int *contadorMayoresALaRaiz, int *sumatoria,int *contadorDivisores, int *sumatoriaDivisores) {
    if (hoja != NULL) {
        if (hoja->dato > valorRaiz) {
            *contadorMayoresALaRaiz += 1;
        }
        if (hoja->izq == NULL && hoja->der == NULL && hoja->dato % 4 == 0) {
            *sumatoria += hoja->dato;
        }
        if (valorRaiz % hoja->dato == 0 && hoja->dato != valorRaiz) {
            *contadorDivisores += 1;
            *sumatoriaDivisores += hoja->dato;
        }
        mostrarNodoArbol(hoja->izq, valorRaiz, contadorMayoresALaRaiz, sumatoria, contadorDivisores,sumatoriaDivisores);
        printf("%d ", hoja->dato);
        mostrarNodoArbol(hoja->der, valorRaiz, contadorMayoresALaRaiz, sumatoria, contadorDivisores,sumatoriaDivisores);
    }
    return;
}


int main() {
    int valorRaiz, contadorMayoresALaRaiz = 0, sumatoria = 0, contadorDivisores = 0, sumatoriaDivisores = 0;
    printf("Árboles\n");
    treenode *arbol = NULL;

    crearNodoArbol(&arbol);
    printf("**************\n");
    printf("Mostrar árbol\n");
    printf("***************\n");

    valorRaiz = arbol->dato;

    mostrarNodoArbol(arbol, valorRaiz, &contadorMayoresALaRaiz, &sumatoria, &contadorDivisores, &sumatoriaDivisores);
    printf("\nHay %d nodo/s con un valor mayor al de la raíz\n", contadorMayoresALaRaiz);
    if (sumatoria > 0) {
        printf("La sumatoria de los nodos hoja múltiplo de 4 es %d\n", sumatoria);
    } else {
        printf("No se han encontrado nodos hoja que sean múltiplo de 4\n");
    }
    if (contadorDivisores != 0) {
        printf("El promedio de los divisores de la raíz es %d\n", sumatoriaDivisores / contadorDivisores);
    } else {
        printf("No se han encontrado elementos divisores de la raíz en el árbol\n");
    }

    return 0;
}
