/*1) Calcular y mostrar el promedio de los números ingresados a la lista.
Luego, si el valor del nodo es menor que el promedio de la lista, eliminar dicho nodo.
Ejemplo:
Lista original:
3 -> 8 -> -2 -> 5 -> 4 -> 3 -> 7
El promedio es de 4
Lista después de eliminar: 
8 -> 5 -> 4 -> 7

2) Si un nodo tiene valor par, insertar adelante del mismo un nodo con valor 0.

Lista después de insertar (continúa del ejemplo anterior):*/

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
        printf("%d \t", registro->num);
        mostrar(registro->sig);
    }
}

int calcularPromedio(nodo *registro, int contador, int sumatoria) {
    if (registro->sig != NULL) {
        contador++;
        sumatoria += registro->num;
        calcularPromedio(registro->sig, contador, sumatoria);
    } else {
        return sumatoria / contador;
    }
}

nodo *insertar1(nodo *p) {
    if (p -> num % 2 == 0)
    {
        nodo *aux = malloc(sizeof(nodo));
        aux->num = 0;
        aux->sig = p -> sig;
        p-> sig = aux;
    }
    return p;
}

void insertar2(nodo *p) {
    nodo *aux;
    while (p->sig != NULL) {
        if (p -> sig -> num % 2 == 0)
        {
            aux = (nodo *) malloc(sizeof(nodo));
            aux->num = 0;
            aux->sig = p->sig-> sig;
            p->sig->sig = aux;
            p = p->sig->sig;
        }
        else {
            p = p->sig;
        }
    }
}

nodo *eliminar1(nodo *p, int numPromedio) {
    nodo *aux;
    while (p -> num < numPromedio)
    {
        aux = p->sig;
        free(p);
        p = aux;
    }
    return p;
}

void eliminar2(nodo *p, int numPromedio) {
    nodo *aux;
    while (p->sig != NULL && p->sig->sig != NULL) {
        if (p->sig -> num < numPromedio)
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
    int contador = 0, sumatoria = 0, promedio;

    crear(primero);
    printf("Lista original: \n");
    mostrar(primero);

    promedio = calcularPromedio(primero, contador, sumatoria);
    printf("\nEl promedio es %d \n", promedio);

    primero = eliminar1(primero, promedio);
    eliminar2(primero,promedio);
    printf("Lista tras las eliminaciones: \n");
    mostrar(primero);

    primero = insertar1(primero);
    printf("\nLista tras insertar1: \n");
    mostrar(primero);
    insertar2(primero -> sig);
    printf("\nLista tras insertar2: \n");
    mostrar(primero);
    return 0;
}
