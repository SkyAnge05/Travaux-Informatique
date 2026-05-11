    /*Cours d'informatique 2*/
    /*Date 20/04/2026*/
    /*Réalisé par Peeters Xavier et Nelen Nathan*/

    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>

    #define MAX_SYMPTOMES 11
    

int lire_oui_non() {
    int x;
    do {
        scanf("%d", &x);  // Lit un nombre
        if (x != 0 && x != 1) {
            printf("Entrée invalide. Tapez 1 (oui) ou 0 (non): ");
        }
    } while (x != 0 && x != 1);  // Boucle tant que ce n'est pas 1 ou 0
    return x;
}

    int main ()
    {
    setlocale(LC_ALL, "");
    int symptomes[MAX_SYMPTOMES];
    int choix;

    

    
do {
printf("-----------------Menu------------------- \n");
printf("1. Diagnostique\n");
printf("2. Historique\n");
printf("3. Quitter \n\n");
printf("Choix : ");
scanf("%d", &choix);

if (choix == 1) {
    for (int i = 0; i < MAX_SYMPTOMES; i++) {
        symptomes[i] = 0; // Initialiser tous les symptômes à 0
    }   
     
    printf("----------Dyagnostique---------- \n");
    printf("oui tapper 1, non taper 0 \n");

    printf("1. S'allume \n");
    symptomes[0] = lire_oui_non();

    printf("2. Odeur de brulé \n");
    symptomes[1] = lire_oui_non();

    printf("3. Bruit anormal \n");
    symptomes[2] = lire_oui_non();

    printf("4. Ecran noir \n");
    symptomes[3] = lire_oui_non();

    printf("5. Led allumée ? \n");
    symptomes[4] = lire_oui_non();

    printf("6. Chaud ? \n");
    symptomes[5] = lire_oui_non();

    printf("7. Est ce qu'il plante ? \n");
    symptomes[6] = lire_oui_non();

    printf("8. Est ce qu'il y a de la tension ? \n");
    symptomes[7] = lire_oui_non();

    printf("9. Est ce que la batterie est gonflée ? \n");
    symptomes[8] = lire_oui_non();

    printf("10. Est ce que le chargeur fonctionne ? \n");
    symptomes[9] = lire_oui_non();
    }

} while (choix != 3); 

   
    printf("\nAu revoir !\n");
    
    return 0;
}

    /*
    1. Lister les pannes possible :  :
    
    -s'allume
    -odeur de brulé
    -bruit anormal 
    -écran noir
    -led allumée ?
    -Chaud ?
    -est ce qu'il plante ?
    -est ce qu'il y a de la tension ?
    -est ce que la batterie est gonflée ?
    -est ce que le chargeur fonctionne ?

    2. les pannes possibles
    -alimentation HS
    -fusible grillé
    -court-circuit
    -surchaufe
    -composant défectueux
    -batterie HS
    -mauvais contacte
    -carte mère endommagée

    3. Vericifation conseillée :
    -redémarrer l'ordinateur
    -vérifier les connexions
    -mesuré la tesion de la batterie 
    */