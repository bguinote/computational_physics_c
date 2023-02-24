#include <stdio.h>
#include <math.h>

// definir fatorial 
// definir função


double fatorial(int n)
{
    double fat;

    for (fat = 1; n > 1; n = n - 1) {
        fat = fat * n;
    }

    return fat;
}

double func(double x, double n)
{

    return pow(-1, n) * (pow(x, n) / fatorial(n));
}
int main()
{
    FILE* arq;
    double i;
    double x, y;
    arq = fopen("valores.txt", "w");
    for (x = 0; x <= 100; x += 1)
    {
        y = 0;

        for (i = 0; i <= 100; i++)
        {
            y = y + func(x, i);

        }
        printf("valor de x: %lf, valor de y: %g \n", x, y); //%g escreve em exponencial
        fprintf(arq, "%lf %g \n", x, y);
    }
    fclose(arq);
    return 0;
}