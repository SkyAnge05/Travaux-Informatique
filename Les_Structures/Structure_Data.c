/* Transmission d'une structure à une fonction. */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/* Déclaration et définition d'une structure stockant les données. */
struct data{
    float montant;
    char fnom[30];
    char lnom[30];
} rec;

/* Prototype de la fonction. Cette fonction ne renvoie pas de valeur, 
   et son argument est une structure de type data. */
void print_rec(struct data x);

int main()
{
setlocale(LC_ALL, "fr_FR.UTF-8");

    /* Lecture des données au clavier. */
    printf("Entrez les nom et prénom du donateur,\n");
    printf("séparés par un blanc : ");
    scanf("%30s %30s", rec.fnom, rec.lnom);

    printf("\nEntrez le montant du don : ");
    scanf("%f", &rec.montant);

    /* Appel de la fonction. */
    print_rec(rec);
    exit(EXIT_SUCCESS);
}

void print_rec(struct data x)
{
    printf("\nLe donateur %s %s a donné %.2f Euros\n", x.fnom, x.lnom, x.montant);
}
