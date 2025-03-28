#include <stdio.h>
#include <stdlib.h>

int main() {
    int nombre;
    int *ptr_nombre; // Déclaration d'un pointeur de type entier.

    printf("Entrez un entier : ");
    scanf("%d", &nombre);

    printf("L'adresse de \"nombre\" est 0x%p.\n", (void *)&nombre);
    printf("La valeur de \"nombre\" est %d.\n", nombre);

    ptr_nombre = &nombre; // ptr_nombre contient l'adresse de nombre.

    *ptr_nombre = 100; // On modifie le contenu de l'adresse mémoire.

    printf("\nAprès la modification :\n");

    printf("L'adresse de \"nombre\" est 0x%p.\n", &nombre);
    printf("La valeur de \"nombre\" est %d.\n", nombre);
    printf("La valeur de \"ptr_nombre\" est 0x%p.\n", ptr_nombre);

    return 0;
}