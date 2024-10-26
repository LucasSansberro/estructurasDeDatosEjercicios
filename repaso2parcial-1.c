#include <stdio.h>
#include <stdlib.h>

typedef struct arbol {
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

typedef struct tiponodo {
    int dato;

    struct tiponodo *siguiente;
} nodo;

#define CANT 4
/*1
 *a) Buscar el mayor elemento del árbol divisor de la raíz
b) Cantidad de nodos hojas impares.*/
/*2
 *Desarrollar una función que permita mostrar la sumatoria de números
mayores al primer elemento ingresado en la pila. Si no hubiera ningún
número mostrar una leyenda.*/
/*3
Desarrollar una función que permita mostrar el promedio de los tres primeros
números ingresados a la cola. Si no hubiese tres números, mostrar una leyenda y
no calcular el promedio.
*/

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

void crear(treenode **hoja) {
    int numero;

    printf("ingrese numero\n");
    scanf("%d", &numero);
    while (numero != -1) {
        insertar(&(*hoja), numero);
        printf("ingrese numero\n");
        scanf("%d", &numero);
    }
}


void mostrar(treenode *hoja, int primerElemento, int *mayorDivisor, int *contadorHojasImpares) {
    if (hoja != NULL) {
        if (primerElemento % hoja->dato == 0) {
            *mayorDivisor = hoja->dato;
        }
        if (hoja->izq == NULL && hoja->der == NULL && hoja->dato % 2 != 0) {
            *contadorHojasImpares += 1;
        }
        mostrar(hoja->izq, primerElemento, mayorDivisor, contadorHojasImpares);
        printf("%d \n", hoja->dato);
        mostrar(hoja->der, primerElemento, mayorDivisor, contadorHojasImpares);
    }
    return;
}

void ejercicioArboles() {
    int primerElemento, mayorDivisor = 0, contadorHojasImpares = 0;
    treenode *arbol = NULL;
    printf("Arboles\n");

    crear(&arbol);
    printf("**************\n");
    printf("mostrar arbol\n");
    printf("***************\n");

    primerElemento = arbol->dato;
    mostrar(arbol, primerElemento, &mayorDivisor, &contadorHojasImpares);
    printf("El mayor divisor de la raíz es: %d \n", mayorDivisor);
    printf("Hay %d nodos hojas impares", contadorHojasImpares);
}

void mostrarPila(nodo aux, int primerNumeroIngresado, int *sumatoria) {
    if (aux.dato > primerNumeroIngresado) {
        *sumatoria += aux.dato;
    }
    printf("%d \n", aux.dato);
}

nodo *crear_nodo(int dato) {
    nodo *u;
    u = (nodo *) malloc(sizeof(nodo));
    u->dato = dato;

    u->siguiente = NULL;

    return u;
}

void apilar(nodo **p, nodo *u, int *primerNumeroIngresado) {
    printf("apilar_nodo\n");
    if (*p == NULL) {
        *primerNumeroIngresado = u->dato;
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

void ejercicioPilas() {
    int i, num, sumatoria = 0, primerNumeroIngresado;
    nodo *p = NULL;

    for (i = 0; i < CANT; i++) {
        printf("Ingrese un numero \n");
        scanf("%d", &num);
        apilar(&p, crear_nodo(num), &primerNumeroIngresado);
    }

    printf("Primer número ingresado: %d", primerNumeroIngresado);
    printf("\nVamos a desapilar todo\n");
    while (p != NULL) {
        mostrarPila(desapilar(&p), primerNumeroIngresado, &sumatoria);
    }
    if (sumatoria > 0) {
        printf("La sumatoría de los números mayores al primer ingresado es %d", sumatoria);
    } else {
        printf("No se han ingresado números mayores al primer ingresado");
    }
}

void mostrarCola(nodo aux, int *contador, int *sumatoria) {
    if (*contador < 3) {
        *contador += 1;
        *sumatoria += aux.dato;
    }
    printf("%d \n", aux.dato);
}

nodo *crear_nodoCola(int dato) {
    nodo *u;
    u = (nodo *) malloc(sizeof(nodo));

    u->dato = dato;

    u->siguiente = NULL;

    return u;
}

void acolar(nodo **p, nodo **u, nodo *q) {
    printf("acolar_nodo\n");
    if (*p == NULL)
        *p = *u = q; /*porque hay uno solo*/
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

ejercicioColas() {
    int i, num, contador = 0, sumatoria = 0;
    nodo *p = NULL;
    nodo *u = NULL;

    for (i = 0; i < CANT; i++) {
        printf("Ingrese un numero ");
        scanf("%d", &num);
        acolar(&p, &u, crear_nodoCola(num));
    }

    printf("\nVamos a desacolar todo\n");
    while (p != NULL) {
        mostrarCola(desacolar(&p), &contador, &sumatoria);
    }

    if (contador == 3) {
        printf("El promedio es %d", sumatoria / 3);
    } else {
        printf("No se han ingresado tres números. No se ha podido hacer el promedio");
    }
}

int main() {
    //ejercicioArboles();
    //ejercicioPilas();
    //ejercicioColas();
    return 0;
}
