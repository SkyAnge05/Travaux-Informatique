#include <stdio.h>
#include <stdlib.h>

// Déclaration de la fonction modification
void modification(int *nombre);

int main() {
    int nombre;
    int *ptr_nombre; // Déclaration d'un pointeur de type entier.

    printf("Entrez un entier : ");
    scanf("%d", &nombre);

    printf("L'adresse de \"nombre\" est 0x%p.\n", &nombre);
    printf("La valeur de \"nombre\" est %d.\n", nombre);

    ptr_nombre = &nombre; // ptr_nombre contient l'adresse de nombre.

    *ptr_nombre = 100; // On modifie le contenu de l'adresse mémoire.

    modification(ptr_nombre);

    printf("\nApres la modification :\n");

    printf("L'adresse de \"nombre\" est 0x%p.\n", &nombre);
    printf("La valeur de \"nombre\" est %d.\n", nombre);
    printf("La valeur de \"ptr_nombre\" est 0x%p.\n", ptr_nombre);

    return 0;
}

// Définition de la fonction modification
void modification(int *nombre) {
    *nombre += 10; // Ajoute 10 à la valeur pointée par nombre
    printf("\nDans la fonction : nombre vaut %d\n", *nombre);
}