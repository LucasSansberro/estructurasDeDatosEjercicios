#include <stdio.h>

int matrizDePrueba[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

void mostrarMatriz(int matriz[][3], int const filas, int const columnas) {
    for (int i = 0; i < filas; ++i) {
        printf("\n");
        for (int j = 0; j < columnas; ++j) {
            printf("%d \t", matriz[i][j]);
        }
    }
}

void cargarMatriz(int matriz[][3], int const ordenDeMatriz) {
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

int sumatoriaDeSegundaFila(int matriz[][3], int const columnasTotales) {
    int sumatoria = 0;
    for (int columnaActual = 0; columnaActual < columnasTotales; ++columnaActual) {
        sumatoria += matriz[1][columnaActual];
    }
    return sumatoria;
}

int mayorNumSegundaFila(int matriz[][3], int const columnasTotales) {
    int numeroMasAlto = 0;
    for (int columnaActual = 0; columnaActual < columnasTotales; ++columnaActual) {
        if (matriz[1][columnaActual] > numeroMasAlto) {
            numeroMasAlto = matriz[1][columnaActual];
        }
    }
    return numeroMasAlto;
}

int promedioDeMultiplosDe5(int matriz[][3], int const filasTotales, int const columnasTotales) {
    int divisor = 0, sumador = 0;
    for (int filaActual = 0; filaActual < filasTotales; ++filaActual) {
        printf("\n");
        for (int columnaActual = 0; columnaActual < columnasTotales; ++columnaActual) {
            if (matriz[filaActual][columnaActual] % 5 == 0) {
                divisor += 1;
                sumador += matriz[filaActual][columnaActual];
            }
        }
    }
    if (divisor > 0) {
        return sumador / divisor;
    }
    return 0;
}

int sumatoriaDeDiagonal(int matriz[][3], int const ordenDeMatriz) {
    int sumador = 0;
    for (int posicion = 0; posicion < ordenDeMatriz; ++posicion) {
        sumador += matriz[posicion][posicion];
    }
    return sumador;
}

void elementoMinimo(int matriz[][3], int const filasTotales, int const columnasTotales) {
    for (int filaActual = 0; filaActual < filasTotales; ++filaActual) {
        int numeroMinimo = matriz[filaActual][0];
        for (int columnaActual = 0; columnaActual < columnasTotales; ++columnaActual) {
            if (numeroMinimo > matriz[filaActual][columnaActual]) {
                numeroMinimo = matriz[filaActual][columnaActual];
            }
            if (columnaActual == columnasTotales - 1) {
                printf("%d \t", numeroMinimo);
            }
        }
    }
}

void mostrarDiagonalSecundaria(int matriz[][3], int const ordenDeMatriz) {
    for (int filaActual = 0; filaActual < ordenDeMatriz; ++filaActual) {
        for (int columnaActual = 0; columnaActual < ordenDeMatriz; ++columnaActual) {
            if (filaActual + columnaActual == ordenDeMatriz - 1) {
                printf("%d \t", matriz[columnaActual][filaActual]);
            }
        }
    }
}

void elementosBajoDiagonalPrincipal(int matriz[][3], int const ordenDeMatriz) {
    for (int posicion = 0; posicion < ordenDeMatriz - 1; ++posicion) {
        printf("%d \t", matriz[posicion + 1][posicion]);
    }
}

int main() {
    //mostrarMatriz(matrizDePrueba,3,3);
    //printf("%d", sumatoriaDeSegundaFila(matrizDePrueba, 3));
    //printf("%d", mayorNumSegundaFila(matrizDePrueba,3));
    //printf("%d",promedioDeMultiplosDe5(matrizDePrueba,3,3));
    //printf("%d",sumatoriaDeDiagonal(matrizDePrueba,3));
    //elementoMinimo(matrizDePrueba, 3, 3);
    //mostrarDiagonalSecundaria(matrizDePrueba, 3);
    //elementosBajoDiagonalPrincipal(matrizDePrueba,3);
    //comprobarSimetria(matrizDePrueba, 3);

    return 0;
}
