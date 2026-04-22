#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
Un grossiste en composants informatiques vends  quatres types de produits 

Chaques produit possède une références (ce qui est un nombre entier), un prix en euros
et des quantités disponibles
*/
struct produit
{
 int carte_mere;/*code 1*/
 int processeur;/*code 2*/
 int RAM;/*code 3*/
 int carte_graphique;/*code 4*/
}p;
 /* p pour produit */


int main()
{
set_Locale(LC_ALL, "fr_FR");





}