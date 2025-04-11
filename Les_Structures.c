#include <stdio.h>
#include <stdlib.h>
int main(){
struct produits
{
    int numero;
    int quantite;
    float prix;/* data */
};

struct produits article1, article2;
article1.numero = 101;// affecte la valeur 101 au champ numeros de la structure article1

//valeur qui sera affecté au champ prix
scanf("%e", &article1.prix);

//Afficher la valeur du champ pris a la structure art1
printf("\n%e", article1.prix);

//incrémenter la valeur du champ numeros de la structure article1
article1.prix++;



}


