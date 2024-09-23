/*Crear y mostrar una lista donde cada nodo tiene dos números enteros (termina con -1).

Insertar el consecutivo de cada nodo si la suma de sus elementos es mayor a 10.
Eliminar aquelos nodos donde ambos números son pares.
Generar una lista con la suma de los elementos de cada nodo.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int num1;
    int num2;
    struct lista *sig;
} nodo;

void crear(nodo *registro) {
    printf("Ingrese el primer número: ");
    scanf("%d", &registro->num1);
    if (registro->num1 == -1) {
        registro->sig = NULL;
    } else {
        printf("Ingrese el segundo número: ");
        scanf("%d", &registro->num2);
        printf("Creación de siguiente nodo\n\n");
        registro->sig = (nodo *) malloc(sizeof(nodo));
        crear(registro->sig);
    }
}

void insertar2(nodo *p) {
    while (p->sig != NULL) {
        if (p->num1 + p->num2 > 10) {
            printf("Hola, entraste a insertar \n");
            nodo *aux = (nodo *) malloc(sizeof(nodo));
            aux->num1 = p->num1 + 1;
            aux->num2 = p->num2 + 1;
            aux->sig = p->sig;
            p->sig = aux;
            p = p->sig->sig;
        } else {
            p = p->sig;
        }
    }
}

void eliminar2(nodo *p) {
    while (p->sig != NULL && p->sig->sig != NULL) {
        if (p->sig->num1 % 2 == 0 && p->sig->num2 % 2 == 0) {
            nodo *aux = p->sig->sig;
            free(p->sig);
            p->sig = aux;
        } else {
            p = p->sig;
        }
    }
}

nodo *eliminar1(nodo *p) {
    nodo *aux;
    while (p->num1 % 2 == 0 && p->num2 % 2 == 0)
    {
        aux = p->sig;
        free(p);
        p = aux;
    }
    return p;
}

void mostrar(nodo *registro) {
    if (registro->sig != NULL) {
        printf("Número 1: %d\n", registro->num1);
        printf("Número 2: %d\n", registro->num2);
        printf("Siguiente nodo \n\n");
        mostrar(registro->sig);
    }
}

int main() {
    //Ejercicio 1
    /*nodo *primero = (nodo *) malloc(sizeof(nodo));
    crear(primero);
    printf("Pasamos a inserción \n");
    insertar2(primero);
    printf("Pasamos a eliminación \n");
    eliminar1(primero);
    eliminar2(primero);
    printf("Pasamos a mostrar \n");
    mostrar(primero);*/

    return 0;
}
