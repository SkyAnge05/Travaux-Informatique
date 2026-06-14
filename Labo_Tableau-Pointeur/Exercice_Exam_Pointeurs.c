#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 10

void AfficheTableau(int *debut, int *fin) {
    int *p;

    for (p = debut; p <= fin; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

double moyenne(int *debut, int *fin) {
    int *p;
    double somme = 0.0;
    double moyenneCalcul;
    int nbElements;

    nbElements = (int)(fin - debut + 1);

    for (p = debut; p <= fin; p++) {
        somme += *p;
    }

    moyenneCalcul = somme / nbElements;

    for (p = debut; p <= fin; p++) {
        *p = (int)(*p * moyenneCalcul);
    }

    return moyenneCalcul;
}

int main(void) {
    int tableau[TAILLE];
    int *p;
    double moyenneRetournee;

    srand((unsigned int)time(NULL));

    for (p = tableau; p < tableau + TAILLE; p++) {
        *p = rand() % 100;
    }

    printf("Tableau avant appel de moyenne :\n");
    AfficheTableau(tableau, tableau + TAILLE - 1);

    moyenneRetournee = moyenne(tableau, tableau + TAILLE - 1);

    printf("\nTableau apres modification :\n");
    AfficheTableau(tableau, tableau + TAILLE - 1);

    printf("\nMoyenne retournee : %.2f\n", moyenneRetournee);

    return 0;
}
