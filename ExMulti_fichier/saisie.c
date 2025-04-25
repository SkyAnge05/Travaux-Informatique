#include "Calc.h"
float saisie()
{
        int *R;
        float *L;
        float *C;

    printf("Rentrer les veleurs de R ");
    scanf("%d",&R);
    printf("\nRentrer les veleurs de L en mH ");
    scanf("%f",&L);
    printf("\nRentrer les veleurs de  C en µF ");
    scanf("%f",&C);

    printf("\nVoici les valeurs rentrées R= %d, L= %d, C= %d  \n",R, L, C);
}

