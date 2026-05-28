´´´c  
#include <stdio.h>  
#include <stdlib.h>  
//Protypage de la fonction  
void bonjour();
int main() {  
int choix;  
int a= 2;  
int *ptr;  
ptr = &a;  
printf("Veuillez inserez une réponse\n");  
printf("1 pour dire bonjour via la fonction bonjour\n");  
printf("2 pour afficher l'adresse de la valeur a");  
printf("");  
scanf("%d", &choix);  
switch (choix)  
{  
case 1 :  
bonjour();//Appele de la fonction  
break;  
  
case 2 :  
printf("%p", ptr);  
break;  
  
case 3:  
return EXIT_SUCCESS;  
break;  
}  

}  
//Créat:ion de la fonction  
void bonjour()  
{  
printf("bonjour a toi, tu as fait le bon choix :)");  
}  
  