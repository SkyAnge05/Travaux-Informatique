#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
int R;
int L;
int C;
setlocale(LC_ALL, "");

affichage();
  printf("\nVoici les valeurs rentr�es R= %d, L= %d, C= %d  \n",R, L, C);

  printf("\nLa fr�quence de r�sonance est :%2f Hz\n ", Calc(R, L, C));







}
