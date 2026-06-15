/* Transmission d'une structure à une fonction. */
#include <stdio.h>
#include <stdlib.h>

/* Déclaration et définition d'une structure stockant les données. */
struct data {
    float montant;
    char fnom[30];
    char lnom[30];
}rec;

/*Prototype de la fonction. Cette fonction ne renvoie pas de
valeur, et son argument est une structure de type date */

void print_rec(struct data x);

int main()
{
/*lecture des données au clavier*/
    printf("Entrez le nom et prénom du donateur, \n ");
    printf("séparés par un blanc :   ");
    scanf("%30s %30s", rec.fnom, rec.lnom);

    printf("\n Entrez le montant du don :  ");
    scanf("%f", &rec.montant);

    /*Appel de la fonction*/

    print_rec(rec);
    exit(EXIT_SUCCESS);

}

void print_rec(struct data x)
{

    printf("\n Le donateur  %s %s à donné %.2f Euros. \n", x.fnom, x.lnom,
        x.montant);

}