#include<stdio.h>
#include <math.h>

FILE* dadosmatriz;

void leitura()
{
    double x[10][10], y[10];
    dadosmatriz = fopen("matrizdados.txt", "r");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            fscanf(dadosmatriz, "%lf\n", &x[i][j]);
            printf("%lf\n", x[i][j]);
        }
        fscanf(dadosmatriz, "%lf\n", &y[i]);
        printf("%lf\n", y[i]);
    }
}

int main()
{
    int i, j, k, m, n = 10;
    double A[10][10], c, x[10], sum = 0.0;
    dadosmatriz = fopen("matrizdados.txt", "r");

    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            fscanf(dadosmatriz, "%lf", &A[i][j]);
        }
        fscanf(dadosmatriz, "%lf", &x[j]);
    }
    x[n] = A[n][n + 1] / A[n][n];


    for (i = n - 1; i > 1; i--)
    {
        sum = 0.0;
        for (j = i + 1; j < n; j++)
        {
            sum = sum + A[i][j] * x[j];
        }
    }
    x[i] = (A[i][n + 1] - sum) / A[i][i];

    printf("\nA solucao eh: \n");
    for (i = 0; i < n; i++)
    {
        printf("\nx%d = %lf \t", i, x[i]);
    }
    return 0;
}