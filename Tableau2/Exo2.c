#include <stdio.h>
#include <stdlib.h>

int main()
{
  int tableau[5];
  int i;

     for(i=0; i<5; i++)
  {
     printf("\nIntruduiser les valeurs %d du tableau\n",i);
     scanf("%d",&tableau[i]);
  }
printf("Parfait !");

for(i=0; i<5; i++)
{
    printf("\nLa valeur %d du tableau est %d",i , tableau[i]);

}
return 0;
}
