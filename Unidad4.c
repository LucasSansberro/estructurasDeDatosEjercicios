#include <stdio.h>

void introducirYformatearPalabra() {
    int contador = 0;
    char caracter, primeraLetraDePalabra, ultimaLetra, primeraLetraDeOracion;

    printf("Por favor, ingrese una oración terminada en punto \n");
    caracter = getchar();
    primeraLetraDePalabra = caracter;
    primeraLetraDeOracion = caracter;
    putchar(caracter);

    while (caracter != '.') {
        ultimaLetra = caracter;
        caracter = getchar();
        putchar(caracter);

        if (caracter == ' ') {

            if(( primeraLetraDePalabra == 'a' || primeraLetraDePalabra ==  'A') && (ultimaLetra == 's' || ultimaLetra == 'S')) {
                contador++;
            }

            putchar(' ');
            putchar(' ');
            caracter = getchar();

            while (caracter == ' ') {
                caracter = getchar();
            }

            primeraLetraDePalabra = caracter;
            putchar(primeraLetraDeOracion);
        }
    }

    if(( primeraLetraDePalabra == 'a' || primeraLetraDePalabra ==  'A') && (ultimaLetra == 's' || ultimaLetra == 'S')) {
        contador++;
    }
    printf("\nHay %d palabra/s que comienza/n con A y termina/n con S", contador);
}



int main() {
    introducirYformatearPalabra();
    return 0;
}
