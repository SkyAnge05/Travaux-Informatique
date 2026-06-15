#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Définition 
#define MAX_ENTIER 10


//Prototypage des fonction

void moyenne(int *deb, int *fin);

int main(){
srand(time(NULL));
int tableau[MAX_ENTIER];
int i;
int choix;



int *deb = &tableau[0];
/*2
deb est une adresse
*deb est la valeur contenue à cette adresse
*/

int *fin = &tableau[9];
 /*Remplisage du tableau*/
 for(i=0; i< MAX_ENTIER; i++)
 {
    tableau[i] = 1 + rand() % 20;

 }


/*---------------------Teste-------------------------*/
printf("Le début du tableau : %d", tableau[0]);
printf("\nLa fin du tableau : %d", tableau[9]);
/*---------------------Teste-------------------------*/


printf("\nrentre ton choix : ");
scanf("%d", &choix);

switch (choix)
{
case 1 :
moyenne(deb, fin);
break;

case 2 :
for(i=0; i< MAX_ENTIER; i++)
 {
tableau[i] = 1+ rand() %20 ;

 }

break;


default:

return EXIT_SUCCESS;
break;

}

return 0;

}



/*2
deb est une adresse
*deb est la valeur contenue à cette adresse
*/

⁼ 
void moyenne(int *deb, int *fin)
{
    printf("%d\n", *deb);   // valeur du premier élément
    printf("%d\n", *fin);   // valeur du dernier élément
}
