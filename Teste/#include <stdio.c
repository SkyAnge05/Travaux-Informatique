#include <stdio.h>
#include <stdio.h>

int main() {
    int x = 5;
    int *p = &x;

    printf("Valeur de x : %d\n", x);
    printf("Address de x : %p\n", (void*)&x);
    printf("Valeur de p : %p\n", (void*)p);
    printf("Valeur pointe  par p : %d\n", *p);

    return 0;
}