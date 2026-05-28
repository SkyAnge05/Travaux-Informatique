#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>
#include <locale.h>

#define MaxTab 10


//Protypage de la fonction  
void bonjour();
void afficher_menu();  
void aleatoire(int *tab);
//---------------------------

//2#ifndef RUN_TESTS
int main() {  
setlocale(LC_ALL,"french");//Rajoute les accents
srand(time(NULL));// sert au nombre aléatoire de rand()

int choix;    
int a= 2;  
int *ptr; 
ptr = &a;

int tab[MaxTab];
do{
afficher_menu();
scanf(" %d", &choix);
printf("\n"); 
switch (choix)  
{  
    case 1 :  
    bonjour();//Appele de la fonction  
        break;  
        
    case 2 :  
    printf("ladresse de a est %p\n", (void*)ptr);  
        break; 
        
    case 3 :  
    aleatoire(tab);
        break;
  
    case 4:  
    return EXIT_SUCCESS;  
        break; 
        
    default : 
    printf("Choix invalide, veuillez réessayer") ;   
} 
}while(choix != 4);

return 0;
}  
//Affichage du menu  
void afficher_menu()  
{  
    printf("\n╔════════════════════════════════════════╗\n");  
    printf("║      Veuillez inserer une reponse      ║\n");  
    printf("║ 1 - Dire bonjour                       ║\n");  
    printf("║ 2 - Afficher l'adresse de a            ║\n"); 
    printf("║ 3 - Afficher  le tableau tab           ║\n");  
    printf("║ 4 - Sortir du programme                ║\n");  
    printf("╠════════════════════════════════════════╣\n");  
    printf("║ >>> Votre choix: ");  
}  

//Création de la fonction  
void bonjour()  
{  
printf("bonjour a toi, tu as fait le bon choix :)");  
}  

void aleatoire(int *tab)
{
printf("Les éléments du tableau i sont : \n");
for (int i = 0; i < MaxTab; i++)
{
tab[i] = (rand()%10) +1;
}
printf("\n");
for (int i = 0; i < MaxTab; i++)
{
printf("l'élément %d du tableau est : %d \n", i, tab[i]);
}
printf("\n");
}
