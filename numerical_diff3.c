#include <stdio.h>
#include <math.h>

// definir fatorial 
// definir função


int main()
{
    FILE* arq;
    double i;
    double x, y, yantes;
    arq = fopen("valores3.txt", "w");
    for (x = 0; x <= 100; x += 1)
    {
        y = yantes = 1;

        for (i = 1; i <= 100; i++)
        {
            yantes = -yantes * x / i;
            y = y + yantes;

        }
        printf("valor de x: %lf, valor de y: %g \n", x, y); //%g escreve em exponencial
        fprintf(arq, "%lf %g \n", x, y);
    }
    fclose(arq);
    return 0;
}