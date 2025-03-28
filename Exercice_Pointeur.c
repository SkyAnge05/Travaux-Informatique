#include <stdlib.h>
#include <stdio.h>

int echange( int *nombre1, int *nombre2);

int main(){
// Déclaration des variables
int nombre1;
int nombre2;
int temp;
int *ptr_nombre1;
int *ptr_nombre2;
// Déclaration des pointeurs

printf("Rentrez deux valeur entiere : \n");
scanf("%d %d", &nombre1, &nombre2);

ptr_nombre1 = &nombre1;
ptr_nombre2 = &nombre2;

// Suppression de l'échange manuel, car la fonction echange s'en charge

echange(&nombre1, &nombre2);

printf("\nApres echange :");
printf("La valeur du \"nombre 1\" est : %d\n", nombre1);
printf("La valeur du \"nombre 2\" est : %d\n", nombre2);


}
// Définition de la fonction echange
int echange(int *nombre1, int *nombre2){
    int temp = *nombre1;// il prend la valeur de la variable pointée
    *nombre1 = *nombre2;
    *nombre2 = temp;   
   
    

}
