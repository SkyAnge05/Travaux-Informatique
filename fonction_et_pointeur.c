#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{

void NeModifiePas(int x);/*Déclaration de la fonction NeModifiePas */
int Modifie(int *p);/*Déclaration de la fonction Modifie */

int x = 1;
int *p;
p = &x; /* p pointe vers l'adresse de x */

printf("Etat initial : x = %d\n", x);

printf("Appel NeModifiePas(x)\n");
NeModifiePas(x);
printf("Apres NeModifiePas : x = %d\n", x);


printf("Appel Modifie(p)\n");
Modifie(p);
printf("Apres Modifie : x = %d\n", x);

return 0;
}

/*-------------------------Fonctions-----------------------*/

void NeModifiePas(int x)
{

x= x+1; /*le x local est modifié mais la valeur originale de x dans main reste inchangée*/

}




int Modifie(int *p)
{
*p = *p + 1; /* Modifie la valeur pointée par p, c'est-à-dire x dans main */

return *p;
}