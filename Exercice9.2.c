#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
Un grossiste en composants informatiques vends  quatres types de produits 

Chaques produit possède une références (ce qui est un nombre entier), un prix en euros
et des quantités disponibles
*/

/*Déclaration d'une structure stokante */
struct produit
{
 int ref;
 char produits[20];
 float prix;
 int quantités;
};
//struct produit p1;

struct produit produit_saisie();


int main() {
set_Locale(LC_ALL, "fr_FR");


struct produit p;
p = produit_saisie();




}

struct produit produit_saisie()
{
printf("Bonjour et bienvenue le programme de gestion de stock de composants informatique \n");

struct produit p1;
printf("Veuillez rentre la référence de produit que vous souhaitez ajouter au panier parmis les choix: ");
printf("\n 1: Processeur");


}