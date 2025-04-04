/*
Date : 2025-04-04
Auteur : Nelen Nathan
*/
#include <stdio.h>
#define TAILLE 100

void sommeEtProduit(int *tab, int taille, int *somme, int *produit) {
    *somme = 0;
    *produit = 1;
    int i;

    for (i = 0; i < taille; i++) {
        *somme += tab[i];
        *produit *= tab[i];
    }
}

int main() {
    int tableau[TAILLE];
    int somme, produit;
    int i;
    int qtt;

    printf("combien d'element voulez vous utiliser : ");
    scanf("%d", &qtt);
    printf("Entrez %d entiers :\n", qtt);
    for (i = 0; i < qtt; i++) {
        printf("Element %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }


    sommeEtProduit(tableau, qtt, &somme, &produit);


    printf("\nSomme des elements : %d\n", somme);
    printf("Produit des elements : %d\n", produit);

    return 0;
}
