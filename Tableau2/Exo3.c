#include <stdio.h>
#include <stdlib.h>

int main()
{

  int i;
  int n;

  printf("Introduisez le nombre diteration que vous voulez faire : ");
  scanf("%d",&n);

    int tableau[n];

  for(i=1; i<n; i++)
  {
     printf("\nIntruduiser les valeurs %d du tableau : ",i);
     scanf("%d",&tableau[i]);
  }

printf("Parfait !");

printf("\n---------------------------");
printf("\nJuste pour tester si le tableau ce fait bien");

for(i=1; i<n; i++)
{
    printf("\nLa valeur %d du tableau est %d",i , tableau[i]);
}


printf("\n---------------------------");


for(i=1; i<n; i++)
{
    if (i%2 != 0)
    {
       printf("\nLa valeur %d du tableau est %d",i , tableau[i]);
    }
}

return 0;
}       