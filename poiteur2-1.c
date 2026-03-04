#include <stdio.h>
#include <stdlib.h>

int main() {
int nombre;
printf("Entrez un nombre entier : ");
scanf("%d", &nombre);
printf("L'adresse de \"nombre\" est 0x%x.\n", &nombre);
printf("la valeur de \"nombre\" est %d.\n", nombre);
return 0;
}