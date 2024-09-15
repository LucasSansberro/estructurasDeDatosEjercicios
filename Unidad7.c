#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    int info;
    struct lista *sig;
} nodo;

typedef struct persona {
    int dni;
    char nombre[15];
    char tipoCuenta;
    int saldo;
    struct persona *sig;
} Persona;

void mostrar(nodo const *nodoEnLista) {
    if (nodoEnLista->sig != NULL) {
        printf("El contenido del nodo es: %d \n", nodoEnLista->info);
        mostrar(nodoEnLista->sig);
    }
}

void buscarEnListaPorDNI(Persona const *nodoEnLista, int const dniBuscado) {
    if (nodoEnLista->sig != NULL) {
        if (nodoEnLista->dni == dniBuscado) {
            printf("La dirección del nodo buscado es: %p \n", nodoEnLista);
        } else {
            buscarEnListaPorDNI(nodoEnLista->sig, dniBuscado);
        }
    } else {
        printf("No se encontró el DNI específicado");
    }
}

void primerEjercicio() {
    nodo *primer = malloc(sizeof(nodo)),
            *segundo = malloc(sizeof(nodo)),
            *tercero = malloc(sizeof(nodo));

    primer->info = 3;
    primer->sig = segundo;
    segundo->info = 5;
    segundo->sig = tercero;
    tercero->info = 9;
    tercero->sig = NULL;

    mostrar(primer);
    free(primer);
    free(segundo);
    free(tercero);
}

void segundoEjercicio() {
    Persona *personaPrueba = malloc(sizeof(Persona));
    Persona *personaPrueba2 = malloc(sizeof(Persona));

    personaPrueba->dni = 12345678;
    strcpy(personaPrueba->nombre, "Pepe");
    personaPrueba->tipoCuenta = 'A';
    personaPrueba->saldo = 150;
    personaPrueba->sig = personaPrueba2;

    personaPrueba2->dni = 87654321;
    strcpy(personaPrueba2->nombre, "Jorge");
    personaPrueba2->tipoCuenta = 'C';
    personaPrueba2->saldo = 200;
    personaPrueba2->sig = NULL;

    buscarEnListaPorDNI(personaPrueba, 12345678);

    free(personaPrueba);
    free(personaPrueba2);
}



int main() {

    return 0;
}
