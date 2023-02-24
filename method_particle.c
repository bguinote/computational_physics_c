#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "mtwister.c"
#define _USE_MATH_DEFINES


int main() {
    FILE* particula;
    double N = 10000, Nt = 50000, Ni = 10000, t, p, R;
    MTRand r = seedRand(1337);
    particula = fopen("particula_caixa.txt", "w");

    for (t = 0; t < Nt; t++) {
        p = Ni / N;
        R = genRand(&r);
        if (p < R) {
            Ni = Ni + 1;
            fprintf(particula, "\n: %f \t %f\n", t, Ni);
        } else {
            Ni = Ni - 1;
            fprintf(particula, "\n %f \t %f\n", t, Ni);
        }
    }
    fclose(particula);
    return 0;
}


