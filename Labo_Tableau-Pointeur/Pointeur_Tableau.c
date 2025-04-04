#include <stdio.h>
#include <stdlib.h>

int main(){

    int T[10] = {-3, 4, 0, -7, 3, 8, 0, -1, 4, -9};
    int POS[10];
    int I, J; /*Indice se courant dans T et POS*/

    for (J = 0, I = 0; I < 10; I++) {
        if (*(T + I) > 0) {
            *(POS + J) = *(T + I);
            J++;
        }
    }

    // Affichage des valeurs positives extraites
    printf("Valeurs positives extraites :\n");
    for (I = 0; I < J; I++) {
        printf("%d ", *(POS + I));
    }
    printf("\n");

    return 0;
}


