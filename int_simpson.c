#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h> 

FILE* integracaonumerica_simpson;

double funcao(double x)
{
    return x * sin(x);
}

int main() {
    integracaonumerica_simpson = fopen("int_simpson2.txt", "w");
    double x, h, integralresult, integral, integral1, integral2, erro, a = M_PI / 2, b = M_PI, k;
    integralresult = M_PI - 1;
    for (int i = 10; i <= 1e9; i *= 10) {
        h = (b - a) / i;
        //printf("%g %d\n", h, i);
        //break;
        integral = h / 3.0 * (funcao(a) + funcao(b));
        for (int k = 1; k < i - 1; k += 2) {
            x = a + k * h;
            integral1 += 4 * funcao(x);
            x = x + h;
            integral2 += 2 * funcao(x);
            //integral += (1 / 3) * funcao(x) + (4 / 3) * funcao((x + h) / 2) + (1 / 3) * funcao(x + h);
            integral += ((h / 3.0) * (integral1 + integral2));
        }
        integral += 4.0 * h * (funcao(x)) / 3.0;

        erro = log10(fabs((integral - integralresult) / integralresult));

        printf("%g %g %g %g \n", h, integral, integralresult, erro);
        fprintf(integracaonumerica_simpson, "%g %g %g %g \n", h, integral, integralresult, erro);
        integral = 0;
    }
    fclose(integracaonumerica_simpson);
    return 0;
}