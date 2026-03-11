#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;


    char tabcouleur1[4] = "BLEU";


    char tabcouleur2[] = {'R','O','u','G','E'};

    printf("\n\nAffichage de la chaine de caractere");
   for(i = 0; i < 4; i++)
    {
        printf("\n couleur[%d]= %c", i, tabcouleur1[i]);
    }

    printf("\n\n");


    for(i = 0; i < 5; i++)
    {

        printf("\n couleur2[%d] = %c", i, tabcouleur2[i]);
    }

   return 0;
}
