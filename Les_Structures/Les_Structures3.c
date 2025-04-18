#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct temps {
    unsigned heures;
    unsigned minutes;
    double secondes;
};

int main(void) {
    setlocale(LC_ALL, " ");

    struct temps t1;
    struct temps t2;

    printf("Première mesure (hh:mm:ss) : ");
    if (scanf("%u:%u:%lf", &t1.heures, &t1.minutes, &t1.secondes) != 3) {
        printf("Mauvaise saisie haha\n");
        return EXIT_FAILURE;
    }

    printf("Deuxième mesure (hh:mm:ss) : ");
    if (scanf("%u:%u:%lf", &t2.heures, &t2.minutes, &t2.secondes) != 3) {
        printf("Mauvaise saisie haha\n");
        return EXIT_FAILURE;
    }

    // Conversion des heures et minutes en secondes
    double total_secondes_t1 = t1.secondes + t1.minutes * 60 + t1.heures * 3600;
    double total_secondes_t2 = t2.secondes + t2.minutes * 60 + t2.heures * 3600;

    // Calcul de la différence en secondes
    printf("Il y a %.3f seconde(s) de différence.\n", total_secondes_t2 - total_secondes_t1);

    return 0;
}