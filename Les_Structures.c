#include <stdio.h>
#include <stdlib.h>
/*
int main(){

struct produits
{
    int numero;
    int quantite;
    float prix;
};

struct produits article1, article2;

article1.numero = 101;// affecte la valeur 101 au champ numeros de la structure article1

//valeur qui sera affecté au champ prix
scanf("%e", &article1.prix);

//Afficher la valeur du champ pris a la structure art1
printf("\n %e", article1.prix);

//incrémenter la valeur du champ numeros de la structure article1
article1.prix++;



}
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
Nathan
int main(){

//déclaraion de locale
setlocale(LC_ALL,);
struct produits
{
    int numero;
    int quantite;
    float prix;
};

struct produits article1, article2;

article1.numero = 101;// affecte la valeur 101 au champ numeros de la structure article1
printf("Entrez le prix de l'article : ");
//valeur qui sera affecté au champ prix
scanf("%e", &article1.prix);

//Afficher la valeur du champ pris a la structure art1
printf("\n %e", article1.prix);

//incrémenter la valeur du champ numeros de la structure article1
article1.prix++;
}
*/

/*int main (void){

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
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct temps {
    unsigned heures;
    unsigned minutes;
    double secondes;
};

int main(void) {
    setlocale(LC_ALL, " ");

    struct temps t1;
    struct temps t2;

    printf("Première mesure (hh:mm:ss) : ");
    if (scanf("%u:%u:%lf", &t1.heures, &t1.minutes, &t1.secondes) != 3) {
        printf("Mauvaise saisie haha\n");
        return EXIT_FAILURE;
    }

    printf("Deuxième mesure (hh:mm:ss) : ");
    if (scanf("%u:%u:%lf", &t2.heures, &t2.minutes, &t2.secondes) != 3) {
        printf("Mauvaise saisie haha\n");
        return EXIT_FAILURE;
    }

    // Conversion des heures et minutes en secondes
    double total_secondes_t1 = t1.secondes + t1.minutes * 60 + t1.heures * 3600;
    double total_secondes_t2 = t2.secondes + t2.minutes * 60 + t2.heures * 3600;

    // Calcul de la différence en secondes
    printf("Il y a %.3f seconde(s) de différence.\n", total_secondes_t2 - total_secondes_t1);

    return 0;
}