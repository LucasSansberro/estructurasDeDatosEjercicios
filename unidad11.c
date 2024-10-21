#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
1) La cantidad de números múltiplos de 3.
2) El promedio de aquellos números divisores de 4.
3) La sumatoria de aquellos números múltiplos del primer elemento ingresado a la pila.
4) El número máximo y su posición en la pila.
*/

#define CANT 3

typedef struct tiponodo {
    int dato;

    struct tiponodo *siguiente;
} nodo;

void mostrar(nodo aux, int *contadorMultiplos, int *promedioDeDivisoresDe4, int *contadorDivisoresDe4,
             int *sumatoriaDeMultiplosDelPrimerIngresado, int primerValor) {
    if (aux.dato % 3 == 0) {
        *contadorMultiplos += 1;
    }
    if (aux.dato % 4 == 0) {
        *contadorDivisoresDe4 += 1;
        *promedioDeDivisoresDe4 += aux.dato;
    }
    if (aux.dato % primerValor == 0) {
        printf("Hola");
        *sumatoriaDeMultiplosDelPrimerIngresado += aux.dato;
    }
    printf("%d \n", aux.dato);
}

nodo *crear_nodo(int dato) {
    nodo *u = (nodo *) malloc(sizeof(nodo));
    u->dato = dato;
    u->siguiente = NULL;

    return u;
}

void apilar(nodo **p, nodo *u, int *primerValor, int *numeroMaximo, int *contador, int *posicionMaximo) {
    printf("Apilar_nodo\n");
    *contador += 1;
    if (*p == NULL) {
        *primerValor = u->dato;
    }
    if (u->dato > *numeroMaximo) {
        *numeroMaximo = u->dato;
        *posicionMaximo = *contador;
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
    int i, num, contadorMultiplosDe3 = 0, promedioDeDivisoresDe4 = 0, contadorDivisoresDe4 = 0, primerValor = 0,
            sumatoriaDeMultiplosDelPrimerIngresado = 0, numeroMaximo = 0, contador = 0, posicionMaximo = 0;
    nodo *p = NULL;

    for (i = 0; i < CANT; i++) {
        printf("Ingrese un numero \n");
        scanf("%d", &num);
        apilar(&p, crear_nodo(num), &primerValor, &numeroMaximo, &contador, &posicionMaximo);
    }

    printf("\nVamos a desapilar todo\n");
    while (p != NULL) {
        mostrar(desapilar(&p), &contadorMultiplosDe3, &promedioDeDivisoresDe4, &contadorDivisoresDe4,
                &sumatoriaDeMultiplosDelPrimerIngresado, primerValor);
    }
    printf("Contador de multiplos %d \n", contadorMultiplosDe3);
    printf("Suma de todos: %d \nContador: %d\n", promedioDeDivisoresDe4, contadorDivisoresDe4);
    printf("El primer valor ingresado es %d \n", primerValor);
    printf("La sumatoria de los multiplos del primer valor ingresado es %d \n", sumatoriaDeMultiplosDelPrimerIngresado);
    printf("El número máximo es %d y es el elemento número %d en la pila\n", numeroMaximo, posicionMaximo);
    printf("El promedio de divisores de 4 es %d \n", promedioDeDivisoresDe4 / contadorDivisoresDe4);

    return 0;
}
