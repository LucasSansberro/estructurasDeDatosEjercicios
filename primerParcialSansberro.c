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
        printf("%d\n", registro->num);
        mostrar(registro->sig);
    }
}

nodo *insertar1(nodo *p) {
    nodo *aux = (nodo *) malloc(sizeof(nodo));
    aux->num = p->num;
    aux->sig = p->sig;
    p->sig = aux;

    return p;
}

void insertar2(nodo *p) {
    nodo *aux;
    while (p->sig != NULL) {
        aux = (nodo *) malloc(sizeof(nodo));
        aux->num = p->sig->num;
        aux->sig = p->sig;
        p->sig = aux;

        p = p->sig->sig;
    }
}

nodo *eliminar1(nodo *p, int primerNum, int promedioNum) {
    nodo *aux;
    while (p->num % primerNum == 0 || p->num > promedioNum) {
        aux = p->sig;
        free(p);
        p = aux;
    }
    return p;
}

void eliminar2(nodo *p, int primerNum, int promedioNum) {
    nodo *aux;
    while (p->sig != NULL && p->sig->sig != NULL) {
        if (p->sig->num % primerNum == 0 || p->sig->num > promedioNum) {
            aux = p->sig->sig;
            free(p->sig);
            p->sig = aux;
        } else {
            p = p->sig;
        }
    }
}

int calcularPromedioDePares(nodo *registro, int contador, int sumatoria) {
    if (registro->sig != NULL) {
        if (registro->num % 2 == 0) {
            contador++;
            sumatoria += registro->num;
        }
        calcularPromedioDePares(registro->sig, contador, sumatoria);
    } else {
        printf("\nSumatoria %d y contador %d ", sumatoria, contador);
        return sumatoria / contador;
    }
}

int main() {
    nodo *primero = (nodo *) malloc(sizeof(nodo));
    int promedio, primerNumero;
    crear(primero);
    printf("\nLista ingresada\n");
    mostrar(primero);

    promedio = calcularPromedioDePares(primero, 0, 0);
    printf("\nEl promedio es %d", promedio);
    primerNumero = primero->num;
    printf("\nEl primer número es %d\n", primerNumero);

    primero = eliminar1(primero, primerNumero, promedio);
    eliminar2(primero, primerNumero, promedio);
    printf("\nLista post-eliminación\n");
    mostrar(primero);

    insertar1(primero);
    insertar2(primero->sig);
    printf("\nLista post-insert\n");
    mostrar(primero);

    return 0;
}
