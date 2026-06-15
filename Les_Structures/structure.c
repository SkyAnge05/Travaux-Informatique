#include <stdio.h>
#include <stdlib.h>

int main()
{

struct produits{

int numero;
int quantite;
float prix;

};

struct produits article1, article2;

article1.numero = 101;
article1.quantite = 10;


//valeur qui sera affecté au champs prix
printf("Entrer le prix de l'article 1 : ");
scanf("%e", &article1.prix);

//Afficher la valeur du champs prix de la structure article1
printf("Le prix de l'article 1 est : %.2f \n", article1.prix);

//incrémentation de 1 la valeur du champs prix de la structure article 1
article1.prix++;

//afficher la nouvelle valeur du champs prix de la structure article1
printf("Le nouveau prix de l'article 1 est : %2f \n", article1.prix);




 return 0;   
}