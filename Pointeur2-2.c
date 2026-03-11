#include <stdio.h>
#include <stdlib.h>

int main() {
    int x=2; /*déclaration d'une variable x*/
    int *p; /*déclaration d'un pointeur p*/

    p=&x; /*p pointe vers x*/
    /*la veleur de p est l'adresse de x, donc 0x%x*/

    scanf("%d", p); /* lectrure de la valeur de x au clavier*/
    printf("\n %d", x); /*affichage de la nouvelle valeur de x*/
/*va a ladresse ou ce trouve la variable x et depose ce que je te mets au clavier*/

    return 0;
}