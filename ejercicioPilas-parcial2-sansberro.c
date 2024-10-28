#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CANT 3

typedef struct tiponodo {
    int dato;

    struct tiponodo *siguiente;
} nodo;

nodo *crear_nodo(int dato) {
    nodo *u;
    u = (nodo *) malloc(sizeof(nodo));
    u->dato = dato;

    u->siguiente = NULL;

    return u;
}

void mostrarPila(nodo aux, int *contador, int *sumatoria, int primerNumero, int ultimoNum) {
    if (aux.dato > primerNumero && aux.dato < ultimoNum) {
        *contador += 1;
        *sumatoria += aux.dato;
    }
    printf("%d \n", aux.dato);
}

void apilar(nodo **p, nodo *u, int *primerNum) {
    printf("Apilar_nodo\n");
    if (*p == NULL) {
        *primerNum = u->dato;
    }
    u->siguiente = *p;
    printf("%02d p=%X u=%X\n", u->dato, *p, u);
    *p = u;
}

nodo desapilar(nodo **p) {
    nodo *aux;
    nodo datos;

    datos = **p;

    aux = *p;

    *p = (*p)->siguiente;
    free(aux);

    return datos;
}

int main() {
    int i, num, ultimoNum, primerNum, contador = 0, sumatoria = 0;
    nodo *p = NULL;


    for (i = 0; i < CANT; i++) {
        printf("Ingrese un numero \n");
        scanf("%d", &num);
        apilar(&p, crear_nodo(num), &primerNum);
    }
    ultimoNum = p->dato;

    printf("\nVamos a desapilar todo\n");
    while (p != NULL) {
        mostrarPila(desapilar(&p), &contador, &sumatoria, primerNum, ultimoNum);
    }
    if (contador > 0) {
        printf("El promedio de los números mayores al primero y menores al último es %d", sumatoria / contador);
    } else {
        printf("No se han encontrado números mayores al primero y menores al último");
    }
    return 0;
}
