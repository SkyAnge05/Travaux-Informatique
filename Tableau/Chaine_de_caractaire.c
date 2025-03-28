#include <stdio.h>
#include <stdlib.h>

int main(){
int i, T;

    char maChaine[] = "Bonjour les bac 1";

    T = sizeof(maChaine)/sizeof(maChaine[0]);


    printf("\n La taille du tableau est : %d \n", T);


}