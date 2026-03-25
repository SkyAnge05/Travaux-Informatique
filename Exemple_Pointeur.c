/* Comment passer d'un tableau à une fonction. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int tab[MAX], count;

int largest(int x[], int y);

int main()
{
    /* Lecture des MAX valeurs à partir du clavier. */
    
    for (count = 0; count < MAX; count++)
    {
        printf("Entrez une valeur entière : ");
        scanf("%d", &tab[count]);
    }
    
    /* Appel de la fonction et affichage de la valeur renvoyée. */
    
    printf("\n\nLa valeur la plus grande est %d\n", 
            largest(tab, MAX));
    exit(EXIT_SUCCESS);
}

/* La fonction largest() renvoie la valeur la plus grande */
/* d'un tableau d'entiers. */

int largest(int x[], int y)
{
    int count, biggest = x[0];
    
    for (count = 1; count < y; count++)
    {
        if (x[count] > biggest)
            biggest = x[count];
    }
    
    return biggest;
}