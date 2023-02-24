#include <stdio.h>
#include <math.h>

double fatorial(int n) {
    double fat;
    for (fat = 1; n > 1; n = n - 1) {
        fat = fat * n;
    }
    return fat;
}

double func(double x, double n) {
    return (pow(x, n) / fatorial(n));
}

int main()
{
    FILE* arq;
    double i;
    double x, y;
    arq = fopen("valores2.txt", "w");

    for (x = 0; x <= 100; x += 1) {
        y = 0;
        for (i = 0; i <= 100; i++) {
            y = y + func(x, i);
        }
        printf("valor de x: %lf, valor de y: %g \n", x, 1 / y); //%g escreve em exponencial
        fprintf(arq, "%lf %g \n", x, 1 / y);
    }
    fclose(arq);
    return 0;
}