    /*Cours d'informatique 2*/
    /*Date 20/04/2026*/
    /*Réalisé par Peeters Xavier et Nelen Nathan*/
//*--------------------------Inclusion des bibliothèques------------------------------*
    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>
//*--------------------------Définition des constantes------------------------------*
    #define MAX_SYMPTOMES 11
    #define MAX_PANNES 11
    #define MAX_VERIFS 9
    #define MAX_SOLUTIONS 10
//*---------Matrice de score qui fait correspondre les symptômes aux pannes----------*
int matrice[MAX_SYMPTOMES][MAX_PANNES] = 
{
    {2, 2, 0, 0, 0, 1, 0, 0, 0, 0},  // 1. S'allume pas
    {0, 0, 2, 0, 1, 0, 0, 2, 0, 0},  // 2. Odeur brulé
    {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},  // 3. Bruit anormal
    {1, 0, 0, 0, 0, 0, 1, 1, 2, 0},  // 4. Ecran noir
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},  // 5. LED allumée
    {0, 0, 1, 2, 0, 0, 0, 0, 0, 0},  // 6. Chaud
    {0, 0, 0, 1, 1, 0, 0, 1, 0, 2},  // 7. Plante
    {2, 1, 0, 0, 0, 1, 0, 0, 0, 0},  // 8. Pas de tension
    {0, 0, 1, 0, 0, 2, 0, 0, 0, 0},  // 9. Batterie gonflée
    {1, 0, 0, 0, 0, 2, 0, 0, 0, 0},  // 10. Chargeur HS
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}   // 11. (réservé)
};

    int main ()
    {
    setlocale(LC_ALL, "french"); // pour les accents de la langue française
    int symptomes[MAX_SYMPTOMES]; // tableau pour stocker les réponses des symptômes
    int choix; // sert pour le menu
    int score_panne[MAX_PANNES];// Tabk-leau de 10 score, un par pannes

    /* un type const pour ne jamais modifié les chaines de caractères*/
    /* char* char pointeur pour pointer vers une chaîne de caractères */
    const char* noms_pannes[MAX_PANNES] = 
    {
    "Alimentation HS",          // 0
    "Fusible grille",           // 1
    "Court-circuit",            // 2
    "Surchauffe",               // 3
    "Composant defectueux",     // 4
    "Batterie HS",              // 5
    "Mauvais contact",          // 6
    "Carte mere endommagee",    // 7
    "Ecran defectueux",         // 8
    "Probleme logiciel",        // 9
    "Présence d'humidité"       // 10
};

    
    const char* noms_verifs[MAX_VERIFS] = 
    {
    "Redémarrer l'ordinateur",
    "Vérifier les ports/connexions",
    "Mesurer la tension de la batterie",
    "Vérifier le fusible",
    "Vérifier l'alimentation",
    "Nettoyer les ventilateurs",
    "Tester avec un autre chargeur",
    "Vérifier les condensateurs",
    "Vérifier les ampli entrée de charge"
    };

    const char* solutions[MAX_SOLUTIONS] = 
    {
    "Remplacer le bloc d'alimentation ou le câble d'alimentation défectueux",
    "Identifier la cause du claquage, puis remplacer le fusible",
    "Localiser le point de court-circuit, isoler ou remplacer le composant ou câble fautif",
    "Nettoyer les grilles de ventilation, remplacer le ventilateur défaillant",
    "Diagnostiquer le composant en cause, remplacer par un composant identique",
    "Tester la tension en charge avec un multimètre ; si inférieure au seuil minimal, remplacer la batterie",
    "Nettoyer les connecteurs à l'alcool isopropylique, re-sertir ou resoler les connexions défectueuses",
    "Inspecter visuellement les pistes et soudures, réparer les pistes rompues ou remplacer la carte si irréparable"
    };
//*--------------------------Teste------------------------------*

    for (int i = 0; i < MAX_PANNES; i++) {
        printf("%d. %s\n", i + 1, noms_pannes[i]);
    }
    printf("\n\n");

    for (int i = 0; i < MAX_VERIFS; i++) {
        printf("%d. %s\n", i + 1, noms_verifs[i]);
    }

    for (int i=0; i< MAX_SOLUTIONS ; i++) {
        printf("%d. %s\n", i+1, solutions[i]);
    }
//*--------------------------Teste------------------------------*

//*--------------------Début du programme-----------------------*
    printf("\n\nBienvenue dans le programme de diagnostique de panne\n\n");

    do {
        printf("-----------------Menu------------------- \n");
        printf("1. Diagnostique\n");
        printf("2. Historique\n");
        printf("3. Quitter \n\n");
        printf("Choix : ");
        scanf("%d", &choix);
        printf("\n");

        if (choix == 1) {
            diagnostique(symptomes);
        }
        else if (choix == 2) {
            afficher_historique();
        }
        else if (choix == 3) {
            printf("Au revoir !\n");
        }
        else {
            printf("Choix invalide. Veuillez réessayer.\n\n");
        }
    } while (choix != 3);
    
    return EXIT_SUCCESS;
}

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

void diagnostique(int symptomes[]) {
    for (int i = 0; i < MAX_SYMPTOMES; i++) {
        symptomes[i] = 0; // Initialiser tous les symptômes à 0
    }   
     
    printf("----------Diagnostique---------- \n");
    printf("Oui tapper 1, non taper 0 \n\n");

    printf("1. S'allume \n");
    symptomes[0] = lire_oui_non();

    printf("2. Une odeur de brulé ? \n");
    symptomes[1] = lire_oui_non();

    printf("3. Un bruit anormal ? \n");
    symptomes[2] = lire_oui_non();

    printf("4. Un écran noir ?     \n");
    symptomes[3] = lire_oui_non();

    printf("5. La led est allumée ? \n");
    symptomes[4] = lire_oui_non();

    printf("6. Est-il Chaud ? \n");
    symptomes[5] = lire_oui_non();

    printf("7. Est ce qu'il crash souvent ? \n");
    symptomes[6] = lire_oui_non();

    printf("8. Est ce qu'il y a de la tension lors du branchement ? \n");
    symptomes[7] = lire_oui_non();

    printf("9. Est ce que la batterie est gonflée ? \n");
    symptomes[8] = lire_oui_non();

    printf("10. Est ce que le chargeur fonctionne ? \n");
    symptomes[9] = lire_oui_non();

    printf("11. Est ce qu'il y a de l'humidité ? \n");
    symptomes[10] = lire_oui_non();

    printf("\nDiagnostique terminé.\n\n");
}

void afficher_historique() {
    printf("Historique des diagnostics : \n");
    // Afficher l'historique des diagnostics ici (à implémenter)
    printf("Aucun diagnostic enregistré pour le moment.\n\n");
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