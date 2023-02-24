#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h> 

FILE* derivadanumerica;

double funcao(double x)
{
    return sin(x);
}

double derivada_segunda;

double derivadacomputacional(double h) /* Aproxima a segunda derivada de funcao(x) em x=pi/4.0 */
{
    return (funcao((M_PI / 4) + h) - 2 * funcao(M_PI / 4) + funcao((M_PI / 4) - h)) / pow(h, 2);
}

int main()
{
    derivadanumerica = fopen("erroderivada.txt", "w");
    double h;
    derivada_segunda = -sin(M_PI / 4);/*segunda derivada de funcao(x) em x=pi/4.0 */
    for (h = 0.1; h >= 1e-10; h *= 0.1)
    {
        printf("%g\t%g\n", log10(h), log10(fabs((derivadacomputacional(h) - derivada_segunda) / (derivada_segunda))));
        fprintf(derivadanumerica, "%g\t%g\n", log10(h), log10(fabs((derivadacomputacional(h) - derivada_segunda) / (derivada_segunda))));
    }
    printf("%f\n", M_PI);
    fclose(derivadanumerica);
    return 0;
}