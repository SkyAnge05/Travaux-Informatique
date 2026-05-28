#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// On définit RUN_TESTS pour ignorer la fonction main() de prepaexams.c
#define RUN_TESTS
// On inclut directement le fichier source pour avoir accès à ses fonctions
#include "prepaexams.c"

void test_aleatoire_valeurs_limites() {
    int tab[MaxTab];
    
    // Appel de la fonction à tester
    aleatoire(tab);
    
    // Vérification : les valeurs doivent être strictement comprises entre 1 et 10 inclus.
    // L'instruction assert fera planter le programme avec un message d'erreur si la condition est fausse.
    for (int i = 0; i < MaxTab; i++) {
        assert(tab[i] >= 1 && tab[i] <= 10);
    }
    
    printf("test_aleatoire_valeurs_limites : SUCCÈS\n");
}

int main() {
    printf("--- Lancement des tests unitaires ---\n");
    
    test_aleatoire_valeurs_limites();
    
    printf("Tous les tests ont réussi !\n");
    return EXIT_SUCCESS;
}