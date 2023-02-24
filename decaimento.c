#include <stdio.h>
#include "mtwister.c"
#include<stdio.h>
#include<math.h>
#include<conio.h>


FILE* arq1, * arq2;


int main() {

    arq1 = fopen("decaimento_Bi.txt", "w");
    arq2 = fopen("decaimento_Po.txt", "w");

    MTRand r = seedRand(1337);
    double R, R2, p = 1, Bi = 1000, Po = 0, cteBi = 1.0 / 172.8, ctePo = 1.0 / 4800.0;  //Bi = quantidade de Bismuto inicial
    int i, n, t;                   //Po = quantidade de Polonio inicial //cteBi e ctePo = constante de decaimento

    for (t = 0; t < 10000; t++) {
        R = genRand(&r);
        if (p > R) {
            Bi = Bi - cteBi * Bi;
            Po = Po + (cteBi * Bi) - (Po * ctePo);
            fprintf(arq1, "Bi: %lf\n", Bi);
            fprintf(arq2, "Po: %lf\n", Po);
        }

    }
}