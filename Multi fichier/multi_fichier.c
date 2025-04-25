/*
Date: 25-04-25
Editeur: Nelen Nathan
*/
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main()
{

int x;

printf("Taper un nombre entier ");
scanf("%d", &x);

printf("\n Le carré de %d est %d.\n", x, carre(x));



}