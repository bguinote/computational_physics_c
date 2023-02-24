#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h> 

FILE* integracaonumerica_trapezio;

double funcao(double x)
{
    return x * sin(x);
}

int main() {
    integracaonumerica_trapezio = fopen("int_trapezio.txt", "w");
    double x, h, integral, erro, a = M_PI / 2, b = M_PI, I = 0, k;
    integral = M_PI - 1;
    for (int i = 10; i <= 1e9; i *= 10) {
        h = (b - a) / i;
        for (k = a; k < b - h; k = k + h) {
            I += (h / 2) * (funcao(k) + funcao(k + h));
        }
        erro = log10(fabs((I - integral) / integral));

        printf("%g %g \n", h, erro);
        fprintf(integracaonumerica_trapezio, "%g %g \n", h, erro);
        I = 0;
    }
    fclose(integracaonumerica_trapezio);
    return 0;
}







