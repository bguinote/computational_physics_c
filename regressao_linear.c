#include <stdio.h>
#include <math.h>                         /* math functions */

FILE* regressao_linear, * dados;

void leitura()
{
    dados = fopen("dadosreg1.txt", "r");

    double x[100], y[100];
    for (int i = 0;i < 100;i++) {
        fscanf(dados, "%lf %lf", &x[i], &y[i]);
    }
}


double sqr(double x) {
    return x * x;
}

int main() {

    regressao_linear = fopen("regressao_linear.txt", "w");
    int i;
    double m, b, r, denominador, sumx, sumx2, sumxy, sumy, sumy2;
    double x[100], y[100];
    dados = fopen("dadosreg1.txt", "r");
    sumx = sumx2 = sumxy = sumy = sumy2 = 0;
    for (i = 0;i < 100;i++) {
        fscanf(dados, "%lf %lf", &x[i], &y[i]);
        sumx += x[i];
        sumx2 += sqr(x[i]);
        sumxy += x[i] * y[i];
        sumy += y[i];
        sumy2 += sqr(y[i]);
    }
   // printf("%lg \t %lg \t %lg \t %lg \n", sumx, sumx2, sumxy, sumy2);

    denominador = (i * sumx2 - sqr(sumx));
    printf("%d\n", i);
    m = (i * sumxy - sumx * sumy) / denominador;
    b = (sumy * sumx2 - sumx * sumxy) / denominador;
    r = (sumxy / i - sumx / i * sumy / i) / sqrt((sumx2 / i - sqr(sumx / i)) * (sumy2 / i - sqr(sumy / i)));

    printf("m = %g b = %g r = %g \n", m, b, r);
    fprintf(regressao_linear, "m = %g b = %g r = %g \n", m, b, r);
    fclose(regressao_linear);

    return 0;
}