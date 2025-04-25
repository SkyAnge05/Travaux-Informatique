#include "Calc.h"
#include <math.h>
int affichage()
{
    int R;
    int L;
    int C;
    printf("Rentrer les veleurs de R ");
    scanf("%d",&R);
    printf("\nRentrer les veleurs de L en mH ");
    scanf("%d",&L);
    printf("\nRentrer les veleurs de  C en µF ");
    scanf("%d",&C);
}



float Calc(int R, int L, int C)
{
float calcul;
float res;

calcul = 1/(2*3.14159*(sqrt(L*pow(10, -3)*(C*pow(10, -6)))));
res=calcul;

return res;
}
