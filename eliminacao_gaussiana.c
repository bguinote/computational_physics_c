#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void imprimirmatriz(double x[10][10], double y[10]) {

    int k = 0;
    int m = 0;
    for (k = 0; k < 10;k++) {

        for (m = 0; m < 10; m++) {

            printf("%lf ", x[k][m]);

        }

        printf("%lf", y[k]);
        printf("\n");
    }
}

int main() {

    double coeficientes[10][10];
    double coeficientesb[10][10];
    double valory[10];
    double valorx[10];
    double valorz[10];
    int i;
    int j;
    int n = 0;
    double l = 0;

    FILE* dadosMatriz;
    dadosMatriz = fopen("dados-eliminacaoGaussiana.txt", "r");
    for (i = 0; i < 10;i++) {

        for (j = 0; j < 10; j++) {

            fscanf(dadosMatriz, "%lf", &coeficientes[i][j]);

        }

        fscanf(dadosMatriz, "%lf", &valory[i]);
        valorx[i] = 0;
    }


    for (i = 0; i < 10;i++) {

        for (j = 0; j < 10; j++) {

            coeficientesb[i][j] = coeficientes[i][j];

        }

        valorz[i] = valory[i];
    }


    while (n < 10) {

        for (i = n + 1; i < 10; i++) {

            l = coeficientesb[i][n];
            for (j = n + 0; j < 10; j++) {

                coeficientesb[i][j] -= coeficientesb[n][j] * (l / coeficientesb[n][n]);

            }

            valorz[i] = valorz[i] - (valorz[n] * (l / coeficientesb[n][n]));
            l = 0;

        }

        n = n + 1;

    }


    // calculando os valores de x utilizando a matriz B

    for (i = 9; i >= 0;i--) {

        valorx[i] = valorz[i];
        for (j = i + 1;j < 10;j++)
        {
            valorx[i] -= coeficientesb[i][j] * valorx[j];
        }
        valorx[i] /= coeficientesb[i][i];

    }

    for (i = 0; i <= 9;i++) {
        printf("%lf\n", valorx[i]);

    }

    // teste valores

    double teste = 0;

    for (i = 0; i < 10;i++) {

        teste = 0;

        for (j = 0; j < 10; j++) {

            teste += coeficientes[i][j] * valorx[j];

        }

        printf("Valor de y calculado: %lf \n", teste);
        printf("Valor de y da matriz: %lf \n", valory[i]);
    }


    fclose(dadosMatriz);
    return 0;
}