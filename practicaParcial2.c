#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int num;
    struct lista *sig;
} nodo;

void crear(nodo *registro) {
    scanf("%d", &registro->num);

    if (registro->num == -1)
        registro->sig = NULL;
    else {
        registro->sig = (nodo *) malloc(sizeof(nodo));
        crear(registro->sig);
    }
}

void mostrar(nodo *registro) {
    if (registro->sig != NULL) {
        printf("%d ", registro->num);
        mostrar(registro->sig);
    }
}

int comprobarLongitudDeLista(nodo *registro, int numeroMayor, int contador) {
    if (registro->sig == NULL) {
        return numeroMayor > contador;
    }
    comprobarLongitudDeLista(registro->sig, numeroMayor, contador + 1);
}

nodo *eliminar1(nodo *p) {
    nodo *aux;
    while (1 == 1)
    {
        aux = p->sig;
        free(p);
        p = aux;
    }
    return p;
}

void eliminar2(nodo *p) {
    nodo *aux;
    while (p->sig != NULL && p->sig->sig != NULL) {
        if (1 == 1)
        {
            aux = p->sig->sig;
            free(p->sig);
            p->sig = aux;
        } else {
            p = p->sig;
        }
    }
}

int main() {
    nodo *primero = (nodo *) malloc(sizeof(nodo));
    int num1, num2;
    crear(primero);
    mostrar(primero);

    printf("\nInserte dos números enteros. Se borraran los nodos que se encuentren entre dichos números");
    printf("\nNúmero 1: ");
    scanf("%d", &num1);
    printf("\nNúmero 2: ");
    scanf("%d", &num2);
    int test = comprobarLongitudDeLista(primero, num2, 1);
    if (test == 1) {
        printf("La lista no contiene la cantidad suficiente de elementos como para satisfacer el pedido");
    } else {
        printf("Comenzando eliminación de nodos");
    }
    return 0;
}
