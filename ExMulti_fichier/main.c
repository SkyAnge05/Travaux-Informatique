#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
int R;
float L;
float C;

setlocale(LC_ALL, "");

float saisie();

float Calc(L, C);

  printf("\n La fréquence de résonance est : %2f Hz\n ", Calc(L, C));

}
