#include <stdio.h>

int matrizDePrueba[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

int matrizAntisimetrica[3][3] = {
    {0, 1, - 8},
    {-1, 0, 6},
    {8, -6, 0}
};

void mostrarMatriz(int matriz[][10], int const ordenDeMatriz) {
    for (int filaActual = 0; filaActual < ordenDeMatriz; ++filaActual) {
        printf("\n");
        for (int columnaActual = 0; columnaActual < ordenDeMatriz; ++columnaActual) {
            printf("%d \t", matriz[filaActual][columnaActual]);
        }
    }
}

void cargarMatriz(int matriz[][10], int const ordenDeMatriz) {
    for (int i = 0; i < ordenDeMatriz; ++i) {
        printf("\n");
        for (int j = 0; j < ordenDeMatriz; ++j) {
            printf("Introduzca un valor a cargar en la matriz: ");
            int num;
            scanf("%d", &num);
            matriz[i][j] = num;
        }
    }
}

void convertirEnDiagonal(int matriz[][10], int const ordenDeMatriz) {
    for (int filaActual = 0; filaActual < ordenDeMatriz; ++filaActual) {
        printf("\n");
        for (int columnaActual = 0; columnaActual < ordenDeMatriz; ++columnaActual) {
            if (filaActual != columnaActual) {
                matriz[filaActual][columnaActual] = 0;
            }
        }
    }
}

void comprobarAntisimetria(int matriz[][10], int const ordenDeMatriz) {
    for (int filaActual = 0; filaActual < ordenDeMatriz; ++filaActual) {
        for (int columnaActual = 0; columnaActual < ordenDeMatriz; ++columnaActual) {
            if (matriz[filaActual][columnaActual] != matriz[columnaActual][filaActual] * -1) {
                printf("\nLa matriz no es antisimétrica.");
                return;
            }
        }
    }
    printf("\nLa matriz es antisimétrica.");
    return;
}

int main() {
    int matrizACargar[10][10], segundaMatrizACargar[10][10], ordenDeMatriz, segundoOrdenDeMatriz;

    printf("Introduzca el orden de la matriz: ");
    scanf("%d", &ordenDeMatriz);

    cargarMatriz(matrizACargar,ordenDeMatriz);
    printf("La matriz cargada ha sido: \n");
    mostrarMatriz(matrizACargar, ordenDeMatriz);

    convertirEnDiagonal(matrizACargar, ordenDeMatriz);
    printf("La matriz cargada modificada en una matriz diagonal es: \n ");
    mostrarMatriz(matrizACargar, ordenDeMatriz);

    printf("Introduzca el orden de la segunda matriz: ");
    scanf("%d", &segundoOrdenDeMatriz);
    cargarMatriz(segundaMatrizACargar,segundoOrdenDeMatriz);
    printf("La segunda matriz cargada ha sido: \n ");
    mostrarMatriz(segundaMatrizACargar, segundoOrdenDeMatriz);
    comprobarAntisimetria(segundaMatrizACargar, segundoOrdenDeMatriz);

    return 0;
}
