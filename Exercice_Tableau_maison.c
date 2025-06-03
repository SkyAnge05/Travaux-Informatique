#include <stdio.h>
#include <stdlib.h>

int main(){
int i;

int tab[5] = {3, 56, 21, 34, 6};

for(i=0; i<5; i++){/*affichage des éléments*/
printf("tab[%d] = %d\n", i, tab[i]);

}
return 0;
}