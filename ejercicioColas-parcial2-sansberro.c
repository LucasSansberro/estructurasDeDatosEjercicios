#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 6

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

void mostrar(nodo aux, int numeroIngresadoPorElUsuario, int *contador, int *posicionMaximo, int *numeroMaximo) {
    *contador += 1;
    if (aux.dato % numeroIngresadoPorElUsuario == 0 && aux.dato > *numeroMaximo) {
        *posicionMaximo = *contador;
        *numeroMaximo = aux.dato;
    }
    printf("%d \n", aux.dato);
}

void acolar(nodo **p, nodo **u, nodo *q) {
    printf("acolar_nodo\n");
    if (*p == NULL)
        *p = *u = q;
    else {
        (*u)->siguiente = q;
        (*u) = q;
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
    int i, num, numeroIngresadoPorElUsuario, contador = 0, posicionMaximo = 0, numeroMaximo = 0;
    nodo *p = NULL;
    nodo *u = NULL;

    for (i = 0; i < CANT; i++) {
        printf("Ingrese un numero");
        scanf("%d", &num);
        acolar(&p, &u, crear_nodo(num));
    }
    printf("Ingrese un numero. Se buscará en la cola el máximo número que sea multiplo de este");
    scanf("%d", &numeroIngresadoPorElUsuario);

    printf("\nVamos a desacolar todo\n");
    while (p != NULL) {
        mostrar(desacolar(&p), numeroIngresadoPorElUsuario, &contador, &posicionMaximo, &numeroMaximo);
    }
    if (posicionMaximo != 0) {
        printf("El número máximo múltiplo del ingresado es %d y es el elemento número %d de la cola", numeroMaximo,
               posicionMaximo);
    } else {
        printf("No se ha encontrado un número multiplo de aquel ingresado");
    }
    return 0;
}
