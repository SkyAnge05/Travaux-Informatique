#include <stdlib.h>
#include <stdio.h>  

int main()
{
    int addition(int a, int b); // declaration of the function
int x, y, z;

x =3;
y =2;

//z = x + y;
addition(x, y); /* appel de la fonction */ 


  return 0;  
}
int addition(int a, int b) // definition of the function
    {
        int resultat;
        resultat = a + b;

        return resultat;
    }