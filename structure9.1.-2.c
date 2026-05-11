#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct panneau{

    int hauteur;
    int largeur;
    int epaisseur;
    int code;
};
//struct panneau p1;

struct panneau saisie();
void affichage(struct panneau pAff);

int main() {
    setlocale(LC_ALL, "fr_FR");


    struct panneau p;
    p = saisie();
    affichage(p);

    return 0;
}

struct panneau saisie(){

    struct panneau p1;
    printf("Bonjour, bienvenue dans le programme de calcul de volume de planche de bois\n");
    printf("Veuillez entrer les dimensions de votre planche de bois\n");
    printf("\nDéfinissez la hauteur de votre planche: ");
    scanf("%d", &p1.hauteur );

    printf("\nDéfinissez la largeur de votre planche : ");
    scanf("%d", &p1.largeur);

    printf("\nDéfinissez l'épaisseur de votre planche de bois : ");
    scanf("%d", &p1.epaisseur);

    return p1;
}

void affichage(struct panneau pAff){

    printf("\nVoici les dimensions de votre planche :\n");
    printf("\n\n La hauteur est de : %d ", pAff.hauteur);
    printf("\n\n La largeur est de : %d ", pAff.largeur);
    printf("\n\n L'épaisseur est de : %d ", pAff.epaisseur);

    int volume;
    volume= 1000*(pAff.hauteur*pAff.largeur*pAff.epaisseur);


    printf("En tout, le volume de votre planche est de : %d  mètre cube ", volume);

}
