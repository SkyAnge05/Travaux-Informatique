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

/*"typedef" permet d'écrire Panne au lieu de struct Panne*/
    typedef struct {
        int score;
    }Panne;

 Panne panne[MAX_PANNES];

//*--------------------------Prototypage des fonctions------------------------------*
void diagnostique(int symptomes[]);
void afficher_historique();
void calculeur_de_score(int symptomes[], Panne panne[], int matrice[MAX_SYMPTOMES][MAX_PANNES]);

//*---------Matrice de score qui fait correspondre les symptômes aux pannes----------*
// matrice[symptome][panne] = points ajoutés
// 11 symptomes x 11 pannes
int matrice[MAX_SYMPTOMES][MAX_PANNES] = {
    /* S'allume pas  */ {2, 2, 0, 0, 0, 1, 0, 0, 1, 1, 2},
    /* Odeur brulé   */ {0, 0, 2, 0, 1, 0, 0, 2, 1, 1, 2},
    /* Bruit anormal */ {0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 2},
    /* Ecran noir    */ {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2},
    /* LED allumée   */ {0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 2},
    /* Chaud         */ {0, 0, 1, 2, 0, 0, 0, 0, 1, 1, 2},
    /* Plante        */ {0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 2},
    /* Pas tension   */ {2, 1, 0, 0, 0, 1, 0, 0, 1, 1, 2},
    /* Batterie gonf */ {0, 0, 1, 0, 0, 2, 0, 0, 1, 1, 2},
    /* Chargeur HS   */ {1, 0, 0, 0, 0, 2, 0, 0, 1, 1, 2},
    /* (reserve)     */ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
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

//*--------------------fonction pour n'accepter que oui ou non-----------------------*
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

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-DIAGNOSTIQUE-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//*--------------------Fonction pour poser les questions et stocker les réponses-----------------------*
void diagnostique(int symptomes[]) {
    for (int i = 0; i < MAX_SYMPTOMES; i++) {
        symptomes[i] = 0; // Initialiser tous les symptômes à 0
    }   
     
    printf("----------Diagnostique---------- \n");
    printf("Oui tapper 1, non taper 0 \n\n");

    printf("1. il s'allume ? \n");
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
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*Panne panne[]-*-HISTORIQUE-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void afficher_historique() {
    printf("----------Historique---------- \n");
    printf("Historique des diagnostics : \n");
    // Afficher l'historique des diagnostics ici (à implémenter)
    printf("Aucun diagnostic enregistré pour le moment.\n\n");
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-SCORE-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
void calculeur_de_score(int symptomes[], Panne panne[],int matrice[MAX_SYMPTOMES][MAX_PANNES]) {
/* Remettre tout a 0 */
for (int i = 0; i< MAX_PANNES; i++)
{
    panne[i].score = 0; // Chaque score du tableau score
}
//Après ça tout est remis à 0

    for(int s = 0; s < MAX_SYMPTOMES; s++)
    {
        if(symptomes[s] == 1)
        {
            for(int p = 0; p < MAX_PANNES; p++)
            {   
            panne[p].score += matrice[s][p];
            }

        }
    }
}
