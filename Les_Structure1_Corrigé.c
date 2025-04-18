#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    // Déclaration de la structure
    struct produits {
        int numero;
        int quantite;
        float prix;
    };

    // Déclaration des variables
    struct produits article1, article2;

    // Initialisation de la locale
    setlocale(LC_ALL, "");

    // Affectation d'une valeur au champ numero
    article1.numero = 101;

    // Saisie de la valeur du champ prix
    printf("Entrez le prix de l'article : ");
    scanf("%f", &article1.prix);

    // Affichage de la valeur du champ prix
    printf("\nPrix initial : %.2f\n", article1.prix);

    // Incrémentation de la valeur du champ prix
    article1.prix++;
    printf("Prix après incrémentation : %.2f\n", article1.prix);

    return 0;
}