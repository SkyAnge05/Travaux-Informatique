#include "Calc.h"
#include <math.h>



float Calc(float L, float C)
{
float calcul;

calcul = 1/(2*3.14159*(sqrt(L*C)));
printf("%2f", calcul);

return calcul;
}
