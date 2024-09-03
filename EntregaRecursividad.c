#include <stdbool.h>
#include <stdio.h>

int contador = 0;

int calcularPotencia(int const num1, int const num2) {
    if (num2 == 0) {
        return 1;
    }
    return num1 * calcularPotencia(num1, num2 - 1);
}

bool esPrimo(int const numero, int const divisor) {
    if (divisor == 1) {
        return true;
    }
    if (numero % divisor == 0) {
        return false;
    }
    return esPrimo(numero, divisor - 1);
}

void calcularCuantosPrimos(int const numero) {
    if (numero <= 1) {
        return;
    }

    calcularCuantosPrimos(numero - 1);

    if (esPrimo(numero, numero - 1)) {
        printf("%d es primo\n", numero);
        contador++;
    }
}


int main() {
    int base, exponente;
    printf("Ingrese un número base: ");
    scanf("%d", &base);
    printf("ingrese el número exponente: ");
    scanf("%d", &exponente);

    int const numeroPotenciado = calcularPotencia(2, 3);
    printf("%d elevado a %d da como resultado: %d \n",base, exponente, numeroPotenciado);

    int numero;

    printf("Ingrese un número: ");
    scanf("%d", &numero);

    calcularCuantosPrimos(numero);
    printf("En total hay %d números primos\n", contador);

    return 0;
}
