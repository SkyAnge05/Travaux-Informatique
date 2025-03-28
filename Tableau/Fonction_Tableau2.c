/*
Nathan Nelen
14/03/2025
Programmme d'initialisation de tableau
*/

#include <stdlib.h>
#include <stdio.h>

#define TAILLE 10

int main(){
    void init_tab (int tableau[], int n, int valeur_init);
    void affichage (int taille_tableau, int tableau[]);
    int tableauDeBase[TAILLE];
    
    init_tab (tableauDeBase, TAILLE, 5);
    
    affichage (TAILLE, tableauDeBase);
    
    return 0;
    }
    
    void init_tab (int tableau[], int taille_tableau, int valeur_init){
    int i;
    
    for (i = 0; i < taille_tableau; i++){
    tableau [i] = valeur_init;
    }
    }
    
    void affichage (int taille_tableau, int tableau[]){
    for (int i = 0; i < taille_tableau; i++){
    printf ("Element %d : %d \n", i+1, tableau[i]);
    }
    }
    
    