#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{   
    setlocale(LC_ALL, "fr_FR.UTF-8");
    int x = 12;

int *px;
px = &x;

/* Affichage de la valeur de x */
printf("La valeur de x est : %d\n", x);

printf("\n Affectation d'une nouvelle valeur à x via le pointeur px sans écrire x\n");
printf(" \n grace à \"*px = 50;\"\n");
*px = 50; /* Affectation d'une nouvelle valeur à x via le pointeur px * sans écrire x */

/* Affichage de la nouvelle valeur de x */
printf("\nAffichage de la nouvelle valeur de x via le pointeur px : %d\n", x);

return 0;
}
