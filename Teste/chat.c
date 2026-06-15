#include <stdio.h>
#include <string.h>
  #include <locale.h>

#define MAX_SYMPTOMES 10
#define MAX_HISTORIQUE 5

int lire_oui_non() {
    int x;
    do {
        scanf("%d", &x);
        if (x != 0 && x != 1) {
            printf("Nique ta mEre enculE j'ai dit soit 1 soit 0. Tapez 1 (oui) ou 0 (non): ");
        }
    } while (x != 0 && x != 1);
    return x;
}

int main() {
    setlocale(LC_ALL, "");
    int choix;
    int symptomes[MAX_SYMPTOMES];

    char historiquePanne[MAX_HISTORIQUE][100];
    char historiqueUrgence[MAX_HISTORIQUE][20];
    int nbHist = 0;

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Nouveau diagnostic\n");
        printf("2. Voir historique\n");
        printf("3. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        if (choix == 1) {
            for (int i = 0; i < MAX_SYMPTOMES; i++) {
                symptomes[i] = 0;
            }

            printf("cls"); // Efface l'écran pour une nouvelle saisie
            printf("\n--- Diagnostic ---\n");

            printf("Appareil ne s'allume pas ? (1=oui,0=non): ");
            symptomes[0] = lire_oui_non();

            printf("Pas de LED ? (1=oui,0=non): ");
            symptomes[1] = lire_oui_non();

            printf("Odeur de brule ? (1=oui,0=non): ");
            symptomes[2] = lire_oui_non();

            printf("Bruit anormal ? (1=oui,0=non): ");
            symptomes[3] = lire_oui_non();

            printf("Fusible grille ? (1=oui,0=non): ");
            symptomes[4] = lire_oui_non();

            printf("Surchauffe ? (1=oui,0=non): ");
            symptomes[5] = lire_oui_non();

            printf("Ecran noir ? (1=oui,0=non): ");
            symptomes[6] = lire_oui_non();

            printf("Redemarrage aleatoire ? (1=oui,0=non): ");
            symptomes[7] = lire_oui_non();

            printf("Pas de tension ? (1=oui,0=non): ");
            symptomes[8] = lire_oui_non();

            printf("Composant gonfle ? (1=oui,0=non): ");
            symptomes[9] = lire_oui_non();
            

            char panne[100] = "Inconnue";
            char urgence[20] = "Faible";
            int score = 0;

            if (symptomes[0] && symptomes[1] && symptomes[8]) {
                strcpy(panne, "Alimentation HS");
                strcpy(urgence, "Elevee");
                score = 80;
            } else if (symptomes[4]) {
                strcpy(panne, "Fusible grille");
                strcpy(urgence, "Moyenne");
                score = 70;
            } else if (symptomes[2]) {
                strcpy(panne, "Court-circuit");
                strcpy(urgence, "Elevee");
                score = 90;
            } else if (symptomes[5]) {
                strcpy(panne, "Surchauffe");
                strcpy(urgence, "Moyenne");
                score = 60;
            } else if (symptomes[9]) {
                strcpy(panne, "Condensateur defectueux");
                strcpy(urgence, "Moyenne");
                score = 75;
            } else if (symptomes[7]) {
                strcpy(panne, "Instabilite alimentation");
                strcpy(urgence, "Moyenne");
                score = 65;
            } else if (symptomes[6]) {
                strcpy(panne, "Probleme affichage");
                strcpy(urgence, "Faible");
                score = 50;
            } else {
                strcpy(panne, "Panne inconnue");
                strcpy(urgence, "Faible");
                score = 20;
            }

            printf("\n===== RESULTAT =====\n");
            printf("Panne probable : %s\n", panne);
            printf("Niveau d'urgence : %s\n", urgence);
            printf("Score de confiance : %d%%\n", score);

            printf("\nVerifications conseillees :\n");
            printf("- Verifier alimentation\n");
            printf("- Tester fusible\n");
            printf("- Mesurer tension\n");
            printf("- Inspecter composants\n");

            if (nbHist < MAX_HISTORIQUE) {
                strcpy(historiquePanne[nbHist], panne);
                strcpy(historiqueUrgence[nbHist], urgence);
                nbHist++;
            } else {
                for (int i = 0; i < MAX_HISTORIQUE - 1; i++) {
                    strcpy(historiquePanne[i], historiquePanne[i + 1]);
                    strcpy(historiqueUrgence[i], historiqueUrgence[i + 1]);
                }
                strcpy(historiquePanne[MAX_HISTORIQUE - 1], panne);
                strcpy(historiqueUrgence[MAX_HISTORIQUE - 1], urgence);
            }

        } else if (choix == 2) {
            printf("\n===== HISTORIQUE =====\n");
            if (nbHist == 0) {
                printf("Aucun diagnostic.\n");
            } else {
                for (int i = 0; i < nbHist; i++) {
                    printf("%d. Panne: %s | Urgence: %s\n", i + 1, historiquePanne[i], historiqueUrgence[i]);
                }
            }
        }

    }while (choix != 3); 

    printf("\nAu revoir !\n");
    return 0;
}