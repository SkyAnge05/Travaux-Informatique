#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Prototypes des fonctions
float LogNeperien(float x, int n);
float Encodage_de_N_et_X(int Choix);
void Affichage_du_resultat(float x, int n);

int main(){
    // Appelle de la fonction Encodage de N et de X pour la valeur X qui vaut 1.
    float x = Encodage_de_N_et_X(1);
    // Appelle de la fonction Encodage de N et de X pour la valeur N qui vaut 2/autres.
    float n = Encodage_de_N_et_X(2);

    float LnX = LogNeperien(x, n);

    Affichage_du_resultat(x, n);

    return 0;
}

float Encodage_de_N_et_X(int Choix)
{
    float x;

    if(Choix == 1){
        printf("\nChoisissez une valeur de x parmi la liste ci-dessous :  ");
        printf("\n\n -10");
        printf("\n\n 0,01");
        printf("\n\n 0,5");
        printf("\n\n 2");
        printf("\n\n 120\n");
        scanf("%f", &x);
    } else {
        printf("Ensuite, choisissez une valeur pour n parmi la liste ci-dessous : ");
        printf("\n\n 3");
        printf("\n\n 4");
        printf("\n\n 7");
        printf("\n\n 14");
        printf("\n\n 20\n");
        scanf("%d", &x); // Utilisation de la variable x en tant que int
    }

    return (x);
}

float LogNeperien(float x, int n)
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

void Affichage_du_resultat(float x, int n){
    printf("ln(x) : %f \n", LogNeperien(x, n));
}
