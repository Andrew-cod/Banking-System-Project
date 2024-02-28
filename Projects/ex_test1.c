#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define pp(a) (a)++

void swap(float *a, float *b)
{
    float aux = *a;
    *a = *b;
    *b = aux;
}

void sort_bubble(float *t, int n)
{
    int flag = 0;
    do
    {
        flag = 0;
        for (int i = 1; i < n; i++)
        {
            if (t[i - 1] < t[i])
            {
                flag = 1;
                swap(&t[i - 1], &t[i]);
            }
        }
    } while (flag == 1);
}

void repet(float *t, int n)
{

    sort_bubble(t, n);

    float *t_rep = NULL;

    t_rep = (float *)malloc(sizeof(float) * (n / 2 + 1));
    if (t_rep == NULL)
    {
        printf("Alocarea dinamica a esuat\n");
        exit(1);
    }

    float aux = t[0];
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (t[i] == aux)
        {
            t_rep[j] = t[i];
            j++;
            while (t[i] == aux)
            {
                pp(i);
            }
        }

        aux = t[i];
    }

    printf("\n");
    for (int i = 0; i < j; i++)
    {
        printf("%f ", t_rep[i]);
    }
    printf("\n");
    free(t_rep);
}

void print_desc(float *t, int n)
{
    sort_bubble(t, n);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%f\n", t[i]);
}

int main(){
    int n, opt;
    float *t, s = 0;

    do{
        printf("n:");
        scanf("%d", &n);
    }while(n<5);
    t = (float *)malloc(sizeof(float) * (n + 1));
    for (int i = 0; i < n; i++)
    {   
        do{
        scanf("%f", &t[i]);
        }while(t[i]<0);
        s = s + t[i];
        
    }
    t[n] = s / n; /// setarea ultimul element pe media aritmetica
    n++;          // am mai adaugat un ultim element

    if (t == NULL)
    {
        printf("alocare de memorie esuata");
        exit(1);
    }

    do
    {
        printf("\n0-Iesire\n1-Afisarea elementelor in ordine descrescatoare\n2-Sa se copieze toate elementele multimii se se repeta de mai multe ori intr-o multime noua apoi sa se afiseze suma lor");
        printf("\nOptinunea :");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            exit(0);
            break;
        case 1:
            print_desc(t, n);
            break;
        case 2:
            repet(t, n);
            break;
        default:
            printf("\n!!! Ati ales optiune inexistenta !!!\n");
            break;
        }
    } while (1);
    free(t);
    return 0;
}