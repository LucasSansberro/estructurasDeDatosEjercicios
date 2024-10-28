#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 6

typedef struct arbol {
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

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


void insertarNodoArbol(treenode **hoja, int elem) {
    int numero = elem;
    if (elem == -1)
        return;
    if (*hoja == NULL) {
        //creo la hoja vacia
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

void mostrarNodoArbol(treenode *hoja, int valorRaiz, int *contadorMayoresALaRaiz, int *sumatoria,
                      int *contadorDivisores, int *sumatoriaDivisores) {
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
        mostrarNodoArbol(hoja->izq, valorRaiz, contadorMayoresALaRaiz, sumatoria, contadorDivisores,
                         sumatoriaDivisores);
        printf("%d ", hoja->dato);
        mostrarNodoArbol(hoja->der, valorRaiz, contadorMayoresALaRaiz, sumatoria, contadorDivisores,
                         sumatoriaDivisores);
    }
    return;
}

void ejercicioArbol() {
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

void ejercicioPilas() {
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
