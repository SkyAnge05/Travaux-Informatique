#include <stdio.h>
#include "Calc.h"

// Fonction de saisie utilisant des pointeurs
void saisie(int *R, float *L, float *C) {
    printf("Entrez la valeur de R (résistance en ohms) : ");
    scanf("%d", R);

    printf("Entrez la valeur de L (inductance en Henry) : ");
    scanf("%f", L);

    printf("Entrez la valeur de C (capacité en Farad) : ");
    scanf("%f", C);
}