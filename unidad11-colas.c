#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*1) La productoria de los números múltiplos de 7.
2) El promedio de aquellos números divisores del último número ingresado a la cola
3) Sumatoria de aquellos números divisores de primer elemento ingresado a la cola.
4) El número máximo y su posición en la cola.
5) El número mínimo y su posición en la cola.*/

#define CANT 3

typedef struct tiponodo {
    int dato;

    struct tiponodo *siguiente;
} nodo;

void mostrar(nodo aux, int *productoria) {
    printf("%d \n", aux.dato);
    if (aux.dato % 7 == 0) {
        *productoria *= aux.dato;
    }
}

nodo *crear_nodo(int dato) {
    nodo *u;
    u = (nodo *) malloc(sizeof(nodo));

    u->dato = dato;
    u->siguiente = NULL;

    return u;
}

void acolar(nodo **p, nodo **u, nodo *q, int *numeroMaximo, int *contador, int *posicionMaximo) {
    printf("Acolar_nodo\n");
    *contador += 1;

    if (*p == NULL)
        *p = *u = q;
    else {
        (*u)->siguiente = q;
        (*u) = q;
    }
    if ((*u)->dato > *numeroMaximo) {
        *numeroMaximo = (*u)->dato;
        *posicionMaximo = *contador;
    }
    printf("%02d p=%X u=%X\n", q->dato, *p, *u);
}

nodo desacolar(nodo **inicio) {
    nodo *aux;
    nodo datos;

    datos = **inicio;

    aux = *inicio;

    *inicio = (*inicio)->siguiente;
    free(aux);

    return datos;
}

int main() {
    int i, num, productoria = 1, numeroMaximo = 0, contador = 0, posicionMaximo = 0;
    nodo *p = NULL;
    nodo *u = NULL;

    for (i = 0; i < CANT; i++) {
        printf("Ingrese un numero");
        scanf("%d", &num);
        acolar(&p, &u, crear_nodo(num), &numeroMaximo, &contador, &posicionMaximo);
    }

    printf("\nVamos a desacolar todo\n");
    printf("\nEl último número ingresado a la fila es %d\n", u->dato);
    while (p != NULL) {
        mostrar(desacolar(&p), &productoria);
    }

    printf("\nLa productoria de los múltiplos de 7 es %d\n", productoria);
    printf("\nEl número más alto es %d y su posición es %d\n", numeroMaximo, posicionMaximo);
    return 0;
}
