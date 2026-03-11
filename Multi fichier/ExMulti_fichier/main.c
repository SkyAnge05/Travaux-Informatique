#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Calc.h"

int main() {
    setlocale(LC_ALL, "");

    int R;
    float L, C;

    // Appel de la fonction de saisie
    saisie(&R, &L, &C);

    printf("\nValeurs saisies : R = %d, L = %.2f, C = %.2f\n", R, L, C);

    return 0;
}