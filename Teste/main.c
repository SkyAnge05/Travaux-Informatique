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

NeModifiePas(x);
printf("\n%d", x); /* Affiche la valeur de x modifiée dans la fonction, mais cela n'affecte pas x dans main */
Modifie(p);
printf("\n%d", *p); /* Affiche la valeur de x modifiée dans la fonction */

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
