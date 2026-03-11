#include <stdio.h>
#include <stdlib.h>

int main() {
int nombre;
printf("Entrez un nombre entier : ");
scanf("%d", &nombre);

printf("L'adresse de \"nombre\" est 0x%x.\n", &nombre);//le caractère d'échappement \ est utilisé pour afficher les guillemets dans la chaîne de caractères.
printf("la valeur de \"nombre\" est %d.\n", nombre);
return 0;
}
