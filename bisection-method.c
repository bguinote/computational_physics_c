#include <stdio.h>
#include <math.h>

/* Função */
double f(double x)
{
    return log(cos(2 * x - 0.2) + 1.1);
}

int main()
{
    double a, b, c, fa, fb, fc, e;
    int passos = 1;
    for (;;) {
        printf("\nInsira dois palpites iniciais:\n");
        scanf("%lf%lf", &a, &b);
        printf("Digite o erro toleravel:\n");
        scanf("%lf", &e);

        fa = f(a);
        fb = f(b);

        /* Verificando se as suposições fornecidas incluem a raiz ou não. */
        if (fa * fb > 0.0)
        {
            printf("Suposicoes iniciais incorretas.\n");
        }
        /* Implementando metodo da bissecção */
        printf("\nPassos:\t\ta\t\tb\t\tc\t\tf(c)\n");
        do
        {
            c = (a + b) / 2;
            fc = f(c);

            printf("%d\t\t%f\t%f\t%f\t%f\n", passos, a, b, c, fc);

            if (fa * fc < 0)
            {
                b = c;
                fb = fc;
            } else
            {
                a = c;
                fa = fc;
            }
            passos = passos + 1;
        } while (fabs(fc) > e);
        printf("\nA raiz eh: %f", c);
    }
    return (0);
}