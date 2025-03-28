#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>  // Inclure time.h pour srand(time(NULL))
#define TAILLE 100

// Prototypes des fonctions
float LogNeperien(float x, float n);
float Encodage_de_N_et_X(int Choix);
void Affichage_du_resultat(float x, float n);
void Resultat_Tableau();

int main(){
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires
    // Appelle de la fonction Encodage de N et de X pour la valeur X qui vaut 1.
    float x = Encodage_de_N_et_X(1);
    // Appelle de la fonction Encodage de N et de X pour la valeur N qui vaut 2/autres.
    float n = Encodage_de_N_et_X(2);

    Affichage_du_resultat(x, n);
    Resultat_Tableau();

    return 0;
}

float Encodage_de_N_et_X(int Choix)
{
    float x;
    int valid = 0;

    if(Choix == 1){
        while (!valid) {
            printf("\nChoisissez une valeur de x parmi la liste ci-dessous :  ");
            printf("\n\n -10");
            printf("\n\n 0,01");
            printf("\n\n 0,5");
            printf("\n\n 2");
            printf("\n\n 120\n");
            scanf("%f", &x);
            if (x == -10 || x == 0.01 || x == 0.5 || x == 2 || x == 120) {
                valid = 1;
            } else {
                printf("Valeur invalide. Veuillez réessayer.\n");
            }
        }
    } else {
        while (!valid) {
            printf("\nEnsuite, choisissez une valeur pour n parmi la liste ci-dessous : ");
            printf("\n\n 3");
            printf("\n\n 4");
            printf("\n\n 7");
            printf("\n\n 14");
            printf("\n\n 20\n");
            scanf("%f", &x);
            if (x == 3 || x == 4 || x == 7 || x == 14 || x == 20) {
                valid = 1;
            } else {
                printf("Valeur invalide. Veuillez réessayer.\n");
            }
        }
    }

    return (x);
}

float LogNeperien(float x, float n)
{
    float lnX = 0, exposant, lnProvisoire;
    int i;

    exposant = 1;

    for (i = 1; i <= n; i++){
        lnProvisoire = ((x-1)/(x+1));
        lnProvisoire = pow(lnProvisoire, exposant);
        lnProvisoire *= 1/exposant;
        lnX += lnProvisoire;
        exposant += 2;
    }

    lnX *= 2;

    return(lnX);
}

void Affichage_du_resultat(float x, float n){
    
    printf("ln(x) : %f \n", LogNeperien(x, n));

}
 
void Resultat_Tableau(){
    float tableauEntree[TAILLE];
    float tableauSortie[TAILLE];
    float n = Encodage_de_N_et_X(2);
    int i;

    // Remplir le tableau d'entrée avec des valeurs aléatoires
    for (i = 0; i < TAILLE; i++) {
        tableauEntree[i] = 1 + rand() % 10;  // Génère des nombres aléatoires entre 1 et 10
    }

    // Calculer les valeurs de sortie en utilisant la fonction LogNeperien
    for (i = 0; i < TAILLE; i++) {
        tableauSortie[i] = LogNeperien(tableauEntree[i], n);
    }

    // Afficher les résultats
    for (i = 0; i < TAILLE; i++) {
        printf("Entrée[%d] = %f, Sortie[%d] = %f\n", i, tableauEntree[i], i, tableauSortie[i]);
    }
}