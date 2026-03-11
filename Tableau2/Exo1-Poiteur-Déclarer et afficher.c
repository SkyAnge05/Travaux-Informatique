#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

//srand(time(NULL));
int main()
{
    setlocale(LC_ALL, "fr_FR.UTF-8");
/* Création d'une variable et d'un pointeur */
int a = 25;
int *P;
/* Faire pointer la variable p vers a */
P = &a;
/*  Affichage de la valeur de a */
printf("Affichage de la valeur de a : ");
printf("%d", a);

/* Affichage de l'adresse de a */
printf("\n\n Affichage de l'adresse de a : ");
printf("\n 0x%x", &a);

/*  Affichage de la valeur de p*/
printf("\n\nAffichage de la valeur de p : ");
printf("\n 0x%x", P);

/* Affichage de la valeur pointée par p */
printf("\n\nAffichage de la valeur pointée par p : ");
printf("\n %d", *P);

    return 0;
}