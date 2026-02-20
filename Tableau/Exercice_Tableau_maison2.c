#include <stdio.h>

main()
{
int n, compteur;
float moy, d, somme = 0;
float valeurs[100];

/* saisie de la valeur de n */
printf("\nNombre de valeurs à traiter? ");
scanf("%d", &n);
printf("\n");

/* saisie des valeurs et calcul de leur somme */
for (compteur = 0; compteur < n; ++compteur) {
    printf("i = %d x = ", compteur + 1);
    
    
    scanf("%f", &valeurs[compteur]);
    somme += valeurs[compteur];
}

/* calcul et affichage de la moyenne */
moy = somme / n;
printf("\nLa moyenne est %5.2f\n\n", moy);

/* calcul et affichage des écarts à la moyenne */
for (compteur = 0; compteur < n; ++compteur) {
    d = valeurs[compteur] - moy;
    printf("i = %d x = %5.2f d = %5.2f\n", compteur + 1, valeurs[compteur], d);
}
}