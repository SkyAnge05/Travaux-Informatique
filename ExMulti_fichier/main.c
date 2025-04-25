#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Calc.h"

int main() {
    setlocale(LC_ALL, "");

    int R;
    float L, C, resultat;

    // Appel de la fonction de saisie
    saisie(&R, &L, &C);

    // Calcul de la fréquence de résonance
    Calc(&L, &C, &resultat);

    // Affichage des résultats
    affichage(&R, &L, &C);
    printf("\nLa fréquence de résonance est : %.2f Hz\n", resultat);

    return 0;
}