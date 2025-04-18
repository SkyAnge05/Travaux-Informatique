#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (void){

    struct personne{
        char nom[40];
        char prenom[20];
        int age;
    };
        //déclaraion de locale
       char reponse[3];
    
        setlocale(LC_ALL,"");
    
        struct personne p;
    
        printf("Rentre ton nom ou te vais t'appuyer : ");
        scanf("%s", p.nom);
    
        printf("\033[H\033[J"); // ANSI escape codes pour effacer l'écran
    
        printf("Rentre ton prénom ou sinon je vais te regarder sous la douche  : ");
        scanf("%s", p.prenom);
    
        printf("\033[H\033[J"); // ANSI escape codes pour effacer l'écran
    
        printf("T'a quel âge petite fée : ");
        scanf("%d", &p.age); // ne pas oublier le & !
    
        printf("\033[H\033[J"); // ANSI escape codes pour effacer l'écran
    
        printf("Voici les specs de ce type là :\n");
    
        printf("nom=%s\n", p.nom);
        printf("prenom=%s\n", p.prenom);
        printf("age = %d\n", p.age);
    
        printf("Tu sais quoi ?");
        
        scanf(" %c", &reponse[0]);
    
        printf("\033[H\033[J"); // ANSI escape codes pour effacer l'écran// Notez l'espace avant %c
    
    
        printf("Va niquer tes morts %s %s du haut de tes %d pommes !", p.prenom, p.nom, p.age);
    
        return 0;
    }