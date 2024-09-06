#include <stdio.h>

/*5. Escribir un programa efectúe las siguientes operaciones:
a) Declarar un arreglo de 5 posiciones de tipo float. Cargar sus elementos y
mostrarlo.
b) Declarar un puntero a float.
c) Asignar al puntero la dirección del arreglo.
d) Recorrer con el puntero el arreglo, mostrando la dirección y el contenido de cada
posición.*/


int main() {
    float const array[5] = {1.50,2.50,3.50,4.50,5.50};
    float *puntero = array;
    for (int i = 0; i < 4; ++i) {
        puntero++;
        printf("Posición: %p \t",puntero);
        printf("Valor: %.2f \n",*puntero);
    }

    int test = 10;
    int *testPuntero = &test;
    printf("Prueba de posición %p \n", testPuntero);
    printf("Prueba de valor: %d", *testPuntero);

    return 0;
}
