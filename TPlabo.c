/*
 ___________________________________________________________________________________  
|                                                                                   |
|  Cours d'informatique Q2                                                          |
|  Date de début : 20/04/2026                                                       |
|  Date de fin :   12/05/2026                                                       |
|  Réalisé par Peeters Xavier et Nelen Nathan                                       |
|___________________________________________________________________________________|

*/

//*--------------------------Inclusion des bibliothèques------------------------------*
    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>

//*--------------------------Définition des constantes------------------------------*
    #define MAX_SYMPTOMES 11
    #define MAX_PANNES 11
    #define MAX_VERIFS 9
    #define MAX_SOLUTIONS 10
    #define HISTORIQUE_SIZE 5

/*
    STRUCTURE PANNE : Stocke le score de probabilité pour chaque panne diagnostiquée
    "typedef" permet d'utiliser simplement "Panne" au lieu de "struct Panne"
    Le champ "score" accumule les points basés sur les symptômes confirmés
*/
    typedef struct {
        int score;  // Score de probabilité calculé selon les symptômes (plus élevé = plus probable)
    }Panne;

 Panne panne[MAX_PANNES];

 /*
    STRUCTURE FICHE : Enregistre les diagnostiques effectués pour créer un historique
    Permet de conserver une trace des pannes trouvées et de leur gravité
 */
 typedef struct {
    char nom_de_panne[50];      // Nom de la panne diagnostiquée
    int le_score;               // Score obtenu pour cette panne
    int niveau_urgence;         // Niveau d'urgence : 0=faible, 1=moyen, 2=élevé
 }fiche;

 fiche historique[HISTORIQUE_SIZE]; // tableau pour stocker les fiches de l'historique
 int nb_diagnostique = 0;

//*--------------------------Prototypage des fonctions------------------------------*
int lire_oui_non();
void diagnostique(int symptomes[]);
void afficher_historique();
void enregistrer_historique(const char* noms_pannes[]);
void calculeur_de_score(int symptomes[], Panne panne[], int matrice[MAX_SYMPTOMES][MAX_PANNES]);
void afficher_resultat(Panne panne[], const char* noms_pannes[], const char* noms_verifs[], const char * noms_solutions[]);

//*---------Matrice de score qui fait correspondre les symptômes aux pannes----------*
/*
    Cette matrice est la clé du système de diagnostic par score.
    Chaque case [symptome][panne] contient les points à ajouter si ce symptôme est confirmé
    pour cette panne particulière.
    
    Structure : 11 symptômes (lignes) × 11 pannes (colonnes)
    
    Exemple : Si l'utilisateur répond OUI à "il s'allume pas" (symptôme 0),
    alors on ajoute 2 points à la panne 0, 2 points à la panne 1, 0 à la panne 2, etc.
    
    Les valeurs plus hautes (1 ou 2) indiquent une forte corrélation symptôme-panne
    Les valeurs basses (0) indiquent aucune corrélation
*/
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


/*
    FONCTION PRINCIPALE
    Gère le menu interactif et coordonne le flux du programme :
    - Affiche le menu de choix
    - Appelle les fonctions de diagnostique ou historique selon le choix
    - Boucle jusqu'à ce que l'utilisateur choisisse de quitter (option 3)
*/
    int main ()
    {
    // Configuration de la locale pour afficher correctement les accents français
    setlocale(LC_ALL, "french");
    
    // Tableau pour stocker les réponses de l'utilisateur aux questions de symptômes
    // Chaque indice [0-10] contient 0 (non) ou 1 (oui)
    int symptomes[MAX_SYMPTOMES];
    
    // Variable pour stocker le choix du menu (1=Diagnostique, 2=Historique, 3=Quitter)
    int choix;
    //int score_panne[MAX_PANNES];// Tabk-leau de 10 score, un par pannes


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
    "Redémarrer l'ordinateur",              //0
    "Vérifier les ports/connexions",        //1
    "Mesurer la tension de la batterie",    //2
    "Vérifier le fusible",                  //3
    "Vérifier l'alimentation",              //4
    "Nettoyer les ventilateurs",            //5
    "Tester avec un autre chargeur",        //6
    "Vérifier les condensateurs",           //7
    "Vérifier les ampli entrée de charge"   //8
    };


    const char* noms_solutions[MAX_SOLUTIONS] =
    {
    "Remplacer le bloc d'alimentation ou le câble d'alimentation défectueux",                                                                  //0
    "Identifier la cause du claquage, puis remplacer le fusible",                                                                              //1
    "Localiser le point de court-circuit, isoler ou remplacer le composant ou câble fautif",                                                   //2
    "Améliorer la ventilation, nettoyer les dissipateurs thermiques, remplacer la pâte thermique, ou remplacer le composant en surchauffe",    //3
    "Nettoyer les grilles de ventilation, remplacer le ventilateur défaillant",                                                                //4
    "Diagnostiquer le composant en cause, remplacer par un composant identique",                                                               //5
    "Tester la tension en charge avec un multimètre ; si inférieure au seuil minimal, remplacer la batterie",                                  //6
    "Nettoyer les connecteurs à l'alcool isopropylique, re-sertir ou resoler les connexions défectueuses",                                     //7
    "Inspecter visuellement les pistes et soudures, réparer les pistes rompues ou remplacer la carte si irréparable",                           //8
    "Effectuer une réinitialisation matérielle, réinstaller le système d'exploitation, ou remplacer le disque dur si le problème persiste"    //9
    };

/*
//--------------------------Teste------------------------------* fais pas attention 

    for (int i = 0; i < MAX_PANNES; i++) {
        printf("%d. %s\n", i + 1, noms_pannes[i]);
    }
    printf("\n\n");

    for (int i = 0; i < MAX_VERIFS; i++) {
        printf("%d. %s\n", i + 1, noms_verifs[i]);
    }

    for (int i=0; i< MAX_SOLUTIONS ; i++) {
        printf("%d. %s\n", i+1, noms_solutions[i]);
    }
//--------------------------Teste-------- ----------------------*
*/

//*--------------------Début du programme-----------------------*
   
printf("\n\nBienvenue dans le programme de diagnostique de panne\n\n");

// Boucle principale qui continue jusqu'à ce que l'utilisateur choisisse de quitter (option 3)
// Le "do...while" garantit que le menu s'affiche au moins une fois
do{
    printf("-----------------Menu------------------- \n");
            printf("1. Diagnostique\n");
            printf("2. Historique\n");
            printf("3. Quitter \n\n");
            printf("Choix : ");
            scanf("%d", &choix);
            printf("\n");
    // Switch pour traiter chaque choix de l'utilisateur
    switch (choix)
    {
    case 1 :
        // Étape 1 : Poser les questions à l'utilisateur et collecter les symptômes
        diagnostique(symptomes);
        
        // Étape 2 : Calculer le score de chaque panne selon les symptômes confirmés
        calculeur_de_score(symptomes,panne,matrice);
        
        // Étape 3 : Afficher la panne la plus probable, son urgence et la solution
        afficher_resultat(panne,noms_pannes,noms_verifs,noms_solutions);
        
        // Étape 4 : Enregistrer ce diagnostique dans l'historique
        enregistrer_historique(noms_pannes);
            
            break;

    case 2 :
        afficher_historique();
            
            break;

    case 3 :
        printf("\n Au revoir \n");
            
            break;

    default :
        printf("Choix invalide");

    } 
} while (choix != 3);
return EXIT_SUCCESS;
   
}


// Fonction de validation pour s'assurer que l'utilisateur entre uniquement 0 ou 1
// Cela simplifie le traitement des données et évite les erreurs de saisie
int lire_oui_non() {
    int x;
    // Boucle de validation qui continue jusqu'à obtenir une réponse valide
    do {
        scanf("%d", &x);
        // Vérifier que l'entrée n'est pas 0 (non) ou 1 (oui)
        if (x != 0 && x != 1) {
            printf("Entrée invalide. Tapez 1 (oui) ou 0 (non): ");
        }
    } while (x != 0 && x != 1);
    // Retourner la valeur validée
    return x;
}
/*
    FONCTION DIAGNOSTIC
    
    Cette fonction pose une série de 11 questions oui/non à l'utilisateur
    pour évaluer les symptômes de l'appareil défaillant.
    
    Les réponses sont stockées dans le tableau symptomes[] :
    - 1 = OUI, le symptôme est présent
    - 0 = NON, le symptôme n'est pas présent
    
    Paramètre : symptomes[] -> tableau qui contiendra les réponses
*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-DIAGNOSTIQUE-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//*--------------------Fonction pour poser les questions et stocker les réponses-----------------------*
void diagnostique(int symptomes[]) {
    // Réinitialiser le tableau des symptômes à 0 (aucun symptôme confirmé au départ)
    // Cette étape garantit que nous partons avec un tableau propre pour chaque diagnostic
    for (int i = 0; i < MAX_SYMPTOMES; i++) {
        symptomes[i] = 0;
    }   
     
    printf("----------Diagnostique---------- \n");
    printf("Oui tapper 1, non taper 0 \n");
    printf("Répondez aux questions suivantes pour évaluer l'appareil défaillant \n\n");

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

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-SCORE-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*
    FONCTION CALCULEUR DE SCORE
    
    Calcule la probabilité de chaque panne en fonction des symptômes confirmés.
    
    Mécanisme :
    1. Réinitialiser tous les scores à zéro
    2. Pour chaque symptôme confirmé (=1) par l'utilisateur
    3. Ajouter les points correspondants de la matrice pour CHAQUE panne
    
    Par exemple, si le symptôme 0 ("ne s'allume pas") est confirmé,
    on ajoute les valeurs de la première ligne de la matrice à chaque panne.
    
    Paramètres :
    - symptomes[] : réponses de l'utilisateur (0 ou 1)
    - panne[] : tableau de structures où stocker les scores calculés
    - matrice[][] : la matrice de correspondance symptôme->panne
*/
void calculeur_de_score(int symptomes[], Panne panne[],int matrice[MAX_SYMPTOMES][MAX_PANNES]) {
/* Remettre tout a 0 */
// Réinitialiser tous les scores à 0 avant de calculer les nouveaux
// Cette étape est cruciale pour éviter que les scores des diagnostiques précédents
// n'affectent le diagnostic actuel
for (int i = 0; i< MAX_PANNES; i++)
{
    panne[i].score = 0;  // Chaque panne commence avec un score vierge
}


    // Parcourir chaque symptôme confirmé par l'utilisateur
for(int s = 0; s < MAX_SYMPTOMES; s++)
    {
        // Vérifier si l'utilisateur a confirmé ce symptôme (valeur 1 = oui)
        if(symptomes[s] == 1)
        {
            // Pour chaque symptôme confirmé, ajouter les points de la matrice à CHAQUE panne
            // La matrice[symptôme][panne] contient les points à ajouter selon la relation symptôme-panne
            for(int p = 0; p < MAX_PANNES; p++) 
            {   
                // Ajouter les points correspondants à cette panne pour ce symptôme
                // Cela accumule les scores de probabilité pour chaque panne
                panne[p].score += matrice[s][p];
            }
        }
    }
    // Après cette boucle, chaque panne[i].score contient son score de probabilité total
    /*Cette fonction parcourt chaque symptôme confirmé (symptomes[s] == 1) et ajoute les points correspondants à chaque panne en utilisant la matrice de score
    Ainsi, à la fin de cette fonction, chaque panne aura un score total basé sur les symptômes confirmés.*/
}
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-AFFICHAGE RESULTAT-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
/*
 * Affiche la panne la plus probable et le niveau d'urgence, ainsi que la vérification à faire
 * Paramètres : panne qui est le tableau avec les score 
 *              const char* noms_pannes[] tableau qui présente les noms des pannes possibles
 *              const char* noms_verifs[] tableau quio présente les noms des vérifs possible
 *              const char* noms_solutions[] tableau qui présente les noms des solutions possibles
 */
void afficher_resultat(Panne panne[], const char* noms_pannes[], const char* noms_verifs[], const char* noms_solutions[])
{
int max = 0;
int indice_max = 0;

// Parcourir toutes les pannes pour trouver celle avec le score maximal
// Cela permet de déterminer quelle est la panne la plus probable selon les symptômes
for(int i = 0; i < MAX_PANNES; i++)
{
    // Comparer chaque score de panne avec le score maximum actuellement enregistré
    if(panne[i].score > max)
    {
        // Mettre à jour le score maximal trouvé
        max = panne[i].score;
        // Enregistrer l'indice de cette panne pour pouvoir y accéder plus tard
        // (pour afficher son nom, sa vérification et sa solution)
        indice_max = i;
    }
}
// À la fin de cette boucle, indice_max contient la position de la panne la plus probable
if (max ==0 )  // Si aucun symptôme n'est confirmé, il n'y a pas de panne
    {
    printf("\nAucune panne");
    return;
    }

// Afficher le nom de la panne détectée en utilisant son indice
printf("\nPanne détectée : %s", noms_pannes[indice_max]);

// Classifier le niveau d'urgence en fonction du score total
// Plus le score est élevé, plus la panne est grave
if(max <= 5)
    {
        printf("\nNiveau d'urgence : FAIBLE");
    }
else if (max <= 10)
        {
        printf("\nNiveau d'urgence : MOYEN");
        }
else
        {
            printf("\nNiveau d'urgence : ÉLEVÉ");
        }

int correspondance_verifs[MAX_PANNES] = {4, 3, 7, 5, 0, 2, 1, 7, 0, 0, 1}; // Correspondance entre les pannes et les vérifications à faire
printf("Vérification : %s", noms_verifs[ correspondance_verifs[indice_max] ]);
/*
[0] Alimentation HS  ->  4  ->  noms_verifs[4]
[1] Fusible grille   ->  3  ->  noms_verifs[3]
[2] Court-circuit    ->  7  ->  noms_verifs[7]
[3] Surchauffe       ->  5  ->  noms_verifs[5]
...etc
*/
int correspondance_solutions[MAX_PANNES] = {0, 1, 2, 3, 4, 5, 6, 7, 7, 4, 0}; // Correspondance entre les pannes et les solutions à proposer
printf("\nSolution : %s\n", noms_solutions[correspondance_solutions[indice_max]]);
}


/*
*   
*
*
*/
/*
    FONCTION ENREGISTRER HISTORIQUE
    
    Sauvegarde chaque diagnostique effectué dans un historique.
    L'historique peut contenir jusqu'à HISTORIQUE_SIZE (5) diagnostiques.
    
    Quand l'historique est plein, les anciens diagnostiques sont supprimés
    pour laisser place aux nouveaux (système FIFO simple).
    
    Chaque entrée historique contient :
    - Le nom de la panne
    - Le score obtenu
    - Le niveau d'urgence (0=faible, 1=moyen, 2=élevé)
*/
void enregistrer_historique(const char* noms_pannes[])
{
    int max = 0;
int indice_max = 0;

  for(int i = 0; i < MAX_PANNES; i++)
{
   if(panne[i].score > max)
    {
        max = panne[i].score;
        indice_max = i;
    }
    
}

if (max == 0) return;

if(nb_diagnostique == HISTORIQUE_SIZE)
{
    for(int i = 0; i< HISTORIQUE_SIZE -1; i++)
    {
        historique[i] = historique[i+1];
    }
nb_diagnostique = HISTORIQUE_SIZE -1;
}
int j = 0;
while (noms_pannes[indice_max][j] != '\0') 
{
    historique[nb_diagnostique].nom_de_panne[j] = noms_pannes[indice_max][j];
    j++;
}
historique[nb_diagnostique].nom_de_panne[j] = '\0';
historique[nb_diagnostique].le_score = max;

if (max <= 3)
    historique[nb_diagnostique].niveau_urgence = 0;  // stocker 0
else if (max <= 6)
    historique[nb_diagnostique].niveau_urgence = 1;  // stocker 1
else
    historique[nb_diagnostique].niveau_urgence = 2;  // stocker 2

nb_diagnostique++;

}

// Fonction pour afficher l'historique des diagnostiques enregistrés
// Cette fonction parcourt le tableau historique et affiche tous les diagnostiques sauvegardés
void afficher_historique()
{
    printf("\n----------Historique des diagnostiques---------- \n");
    
    // Vérifier s'il y a au moins un diagnostic enregistré
    if(nb_diagnostique == 0) {
        printf("Aucun diagnostic enregistré pour le moment.\n\n");
        return;
    }else
    {
       // Parcourir et afficher tous les diagnostiques enregistrés
    printf("Nombre de diagnostiques : %d\n\n", nb_diagnostique);
    for(int i = 0; i < nb_diagnostique; i++) {
        printf("%d. %s\n", i+1, historique[i].nom_de_panne);
        printf("   Score : %d  |  Urgence : ", historique[i].le_score);
        
        // Afficher le niveau d'urgence en fonction de sa valeur
        if(historique[i].niveau_urgence == 0)
            printf("FAIBLE\n");
        else if(historique[i].niveau_urgence == 1)
            printf("MOYEN\n");
        else
            printf("ÉLEVÉ\n");
    }
    }
    printf("\n");
}





