/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

typedef enum
{
    iesire,
    caz1 = 4,
    caz2,
    caz3
} meniu;

typedef struct ceva
{
    int a;
    int b 
    int s = a + b;
}

int 
functie(int *a)
{
    return *a;
}

int main()
{
    meniu men;
    men = caz3;
    printf("%d", men);
    int a[] = {1, 5, 3};
    int *v;
    v = a + 1;
    printf("%d", functie(v));

    return 0;
}
