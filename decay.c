#include <stdio.h>
#include "mtwister.c"
#include<stdio.h>
#include<math.h>
#include<conio.h>
#define _USE_MATH_DEFINES


int main() {

    FILE* decaimentoBi, * decaimentoPo;
    double R, B, P, Po = 0, Bi = 1000, pBi = 1.0 / 172.8, pPo = 1.0 / 4800.0;  //Bi = quantidade de Bismuto inicial
    int t, j, k;
    MTRand r = seedRand(1337);

    decaimentoBi = fopen("decaimento_Bi.txt", "w");
    decaimentoPo = fopen("decaimento_Po.txt", "w");

    for (t = 0; t <= 10000; t++) {
        B = 0;
        P = 0;
        for (j = 0; j < Bi; j++) {

            R = genRand(&r);

            if (pBi > R) {
                B = B + 1;
            }
        }
        for (k = 0; k < Po; k++) {
            R = genRand(&r);

            if (pPo > R) {
                P = P + 1;
            }
        }
        Bi = Bi - B;
        Po = Po + B - P;
        fprintf(decaimentoBi, "%d %lf\n", t, Bi);
        fprintf(decaimentoPo, "%d %lf\n", t, Po);
    }
    fclose(decaimentoBi);
    fclose(decaimentoPo);
    return 0;
}
