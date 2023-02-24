#include <stdio.h>
#include <math.h>

/* Função */
double f(double x)
{
    return log(cos(2 * x - 0.2) + 1.1);
}

double df(double x)
{
    return -(20 * sin(2 * x - (1 / 5)) / (10 * cos(2 * x - (1 / 5) + 11)));
}
int main()
{
    FILE* newton;
    newton = fopen("newton.txt", "w");
    int it, maxit = 10;
    double g, x0, x1, erro = 0.00001;
    for (;;)
    {
        printf("\nInsira um valor para x0:\n");
        scanf("%lf", &x0);
        if (x0 == 0) {
            break;
        }
        for (it = 1; it <= maxit; it++)
        {
            g = f(x0) / df(x0);
            x1 = x0 - g;
            printf("Interacao: %3d, x = %lf   f(x) = %lf\n", it, x1, f(x1));
            if (fabs(f(x1)) < erro)
            {

                printf("na %3d interacao, raiz = %lf f(x)=%lf)\n", it, x1, f(x1));
                break;

            }
            x0 = x1;
        }
        fprintf(newton, "%f %f\n", x1, f(x1));
        // printf(" error\n");

    }

    return 0;
}