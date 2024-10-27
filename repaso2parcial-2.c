#include <stdio.h>
#include <stdlib.h>
#define CANT 4


typedef struct tiponodo {
    int dato;

    struct tiponodo *siguiente;
} nodo;

typedef struct arbol {
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

/*Cantidad de los elementos pares con un hijo.
b) Mínimo elemento impar del árbol.*/

/*Escribir la función necesaria para calcular la cantidad de elementos múltiplos del
último número ingresado a la pila. Si no hubiera ningún número mostrar una
leyenda.*/
/*Escribir una función para calcular el máximo elemento de la cola y en qué posición
está.*/

void insertar(treenode **hoja, int elem) {
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


void mostrar(treenode *hoja, int *contadorNodosParesConHijos, int *minimoElementoImpar) {
    if (hoja != NULL) {
        if (hoja->dato % 2 == 0 && ((hoja->izq == NULL && hoja->der != NULL) || (
                                        hoja->izq != NULL && hoja->der == NULL))) {
            *contadorNodosParesConHijos += 1;
        }
        if (hoja->dato % 2 != 0 && *minimoElementoImpar > hoja->dato) {
            *minimoElementoImpar = hoja->dato;
        }
        mostrar(hoja->izq, contadorNodosParesConHijos, minimoElementoImpar);
        printf("%d ", hoja->dato);
        mostrar(hoja->der, contadorNodosParesConHijos, minimoElementoImpar);
    }
    return;
}

void ejercicioArboles() {
    int contadorNodosParesConHijos = 0, minimoElementoImpar;
    printf("arboles\n");
    treenode *arbol = NULL;

    crear(&arbol);
    printf("**************\n");
    printf("mostrar arbol\n");
    printf("***************\n");
    minimoElementoImpar = arbol->dato;
    mostrar(arbol, &contadorNodosParesConHijos, &minimoElementoImpar);
    printf("\nHay %d nodo/s par/es con un solo hijo \n", contadorNodosParesConHijos);
    if (minimoElementoImpar % 2 == 0) {
        printf("No hay elementos impares");
    } else {
        printf("El mínimo elemento impar es %d", minimoElementoImpar);
    }
}

void mostrarPilas(nodo aux, int ultimoNum, int *contadorMultiplos) {
    if (aux.dato % ultimoNum == 0) {
        *contadorMultiplos += 1;
    }
    printf("%d \n", aux.dato);
}

nodo *crear_nodoPilas(int dato) {
    nodo *u;
    u = (nodo *) malloc(sizeof(nodo));
    u->dato = dato;

    u->siguiente = NULL;

    return u;
}

void apilar(nodo **p, nodo *u) {
    printf("apilar_nodo\n");


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
    int i, num, ultimoNum, contadorMultiplos = 0;
    nodo *p = NULL;


    for (i = 0; i < CANT; i++) {
        printf("Ingrese un numero \n");
        scanf("%d", &num);
        apilar(&p, crear_nodoPilas(num));
    }

    ultimoNum = p->dato;
    printf("\nVamos a desapilar todo\n");
    while (p != NULL) {
        mostrarPilas(desapilar(&p), ultimoNum, &contadorMultiplos);
    }
    printf("La cantidad de multiplos del último num ingresado es %d", contadorMultiplos);
}

void mostrarQueue(nodo aux, int *maximoNumero, int *contadorMaximo, int *contador) {
    *contador += 1;
    if (aux.dato > *maximoNumero) {
        *maximoNumero = aux.dato;
        *contadorMaximo = *contador;
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

int main() {
    //ejercicioArboles()
    //ejercicioPilas();
    int i, num, contadorMaximo = 0, maximoNumero = 0, contador = 0;
    nodo *p = NULL;
    nodo *u = NULL;

    for (i = 0; i < CANT; i++) {
        printf("Ingrese un numero");
        scanf("%d", &num);
        acolar(&p, &u, crear_nodo(num));
    }


    printf("\nVamos a desacolar todo\n");
    while (p != NULL) {
        mostrarQueue(desacolar(&p), &maximoNumero, &contadorMaximo, &contador);
    }
    printf("El número máximo es %d y está en la posición %d", maximoNumero, contadorMaximo);
    return 0;
}
