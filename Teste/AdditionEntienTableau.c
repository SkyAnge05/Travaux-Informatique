#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 10

int main()
{
int T[MAX];
int n;
int i;
int somme;


do
{
   printf("Choisissez le nombre d'itération que vous voulez faire : ");
   scanf("%d", &n);
   printf("\n");

}while (n > MAX);

printf("Entrer %d valeur : ", MAX);
for(i=0; i< n-1; i++)
{
    scanf("%d", T[i]);
    printf("T%d", i);
    somme += T[i];
}
for(i=0; i< n-1; i++)
{



}
//printf("BON !");
}