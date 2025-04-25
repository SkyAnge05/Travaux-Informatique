#include <math.h>
#include "Calc.h"

// Fonction de calcul utilisant des pointeurs
void Calc(float *L, float *C, float *resultat) {
    *resultat = 1 / (2 * M_PI * sqrt((*L) * (*C)));
}