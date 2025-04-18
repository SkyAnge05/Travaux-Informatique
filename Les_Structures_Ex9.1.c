#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct panneau{

    int hauteur;
    int largeur;
    int epaisseur;
    int code;
    

}p;

int main (){
 void saisie();
 void affichage();

setLocale(LC_ALL, "");

}
void saisie(){
  
    printf("\nDéfinisser la hauter de votre planche: ");
    scanf("%d", &p1.hauteur );

    printf(":\nDéfinisser la largeur de votre de planche : ");
    scanf("%d", p1.largeur);

    printf("\nDéfinisser l'épaisseur de votre planche de bois : ");
    scanf("%d", &p1.epaisseur);

}

void affichage(){

    printf("\n Voici les dimmension de votre planche de ........\n");
    printf("\n\n La hauteur est de : %d ", p1.hauteur);
    printf("\n\n La largeur est de : %d ", p1.largeur);
    printf("\n\n La l'épaisseur est de : %d ", p1.epaisseur);

    int volume;
    volume= 1000*(p1.hauteur*p1.largeur*p1.epaisseur);

    
    printf("En tout, le volume de votre planche est de : %d  mètre cube ", volume);






}