#include <stdio.h>
#include <math.h>                         /* math functions */

FILE* regressao_linear, * dados_2;

void leitura()
{
    dados_2 = fopen("dadosreg2.txt", "r");

    double x[100], y[100];
    for (int i = 0;i < 100;i++) {
        fscanf(dados_2, "%lf %lf", &x[i], &y[i]);
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
    dados_2 = fopen("dadosreg2.txt", "r");
    sumx = sumx2 = sumxy = sumy = sumy2 = 0;
    for (i = 0;i < 100;i++) {
        fscanf(dados_2, "%lf %lf", &x[i], &y[i]);
        sumx += log(x[i]);
        sumx2 += sqr(log(x[i]));
        sumxy += log(x[i]) * log(y[i]);
        sumy += log(y[i]);
        sumy2 += sqr(log(y[i]));
        //printf("%lg \t %lg \t %lg \t %lg \n", sumx, sumx2, sumxy, sumy2);
    }
    denominador = (i * sumx2 - sqr(sumx));
    m = (i * sumxy - sumx * sumy) / denominador;
    b = (sumy * sumx2 - sumx * sumxy) / denominador;
    r = (sumxy / i - (sumx / i * sumy) / i) / sqrt((sumx2 / i - sqr(sumx / i)) * (sumy2 / i - sqr(sumy / i)));



    printf("m = %g b = %g r = %g \n", m, b, r);
    fprintf(regressao_linear, "m = %g b = %g r = %g \n", m, b, r);
    fclose(regressao_linear);

    return 0;
}