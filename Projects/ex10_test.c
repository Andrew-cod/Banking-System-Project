// 4:00
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct
{
    float pret;
    char cod[5];
    char nume[20];

} bautura;

int valid(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')))
            return 0;
    }
    return 1;
}

void adaug(bautura *t, int *n)
{
    char s[20];
    do
    {
        printf("Nume %d:", *n + 1);
        scanf("%s", s);
    } while (!valid(s));
    strcpy((t + *n)->nume, s);
    printf("Pret:");
    scanf("%f", &(t + *n)->pret);
    (t + *n)->cod[0] = s[0];
    (t + *n)->cod[1] = s[strlen(s) - 1];
    int c;
    c = floor((t + *n)->pret);
    while (c >= 10)
        c = c / 10;
    (t + *n)->cod[2] = (char)(c + '0');
    (t + *n)->cod[3]='\0';
    *n = *n + 1;
}


void afis(bautura *t,int n){

    for (int i=0;i<n;i++){
        printf("Bautura %d:\n",n+1);
        printf("Nume:%s\n",(t+i)->nume);
        printf("Pret:%2.2f\n",(t+i)->pret);
        printf("Cod:%s\n\n",(t+i)->cod);
    }

}

void scump(bautura *t,int n){
    int k;
    printf("Dati lungimea cuvantului:");
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        if(strlen((t+i)->nume)>k){
            (t+i)->pret = (t+i)->pret*1.2;
        }
    }
    afis(t,n);
}


void ult(bautura *t,int n){
    char s[n];
    for(int i=0;i<n;i++){
        s[i]=(t+i)->cod[2];
    }
    s[n]='\0';

    int flag=1;
    do{
        flag=1;
        for(int i=1;i<n;i++){
            if(s[i-1]>s[i]){
                flag=0;
                char aux=s[i-1];
                s[i-1]=s[i];
                s[i]=aux;
            }
        }

    }while(flag==0);
    printf("%s",s);
}


int main()
{
    int n = 0;
    int opt = 0;
    bautura t[1000];

    do
    {
        printf("\n0. Ieșire\n1. Adăugarea unei băuturi în meniu.\n2. Afișarea băuturilor din meniu.\n3. Să se copieze ultimul caracter din codul băuturii într-un vector de caractere,apoi să se afișeze vectorul în ordine crescătoare.\n4. Să se aplice o scumpire de 20% tuturor băuturilor a căror lungime a numeluieste mai mare decât un număr precizat de utilizator de la tastatură, apoi să seafișeze toate băuturile.\n\nOptiune:\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            exit(0);
            break;
        case 1:
            adaug(t, &n);
            break;
        case 2:
            afis(t,n);
            break;
        case 3:
            ult(t,n);
            break;
        case 4:
            scump(t,n);
            break;
        }

    } while (1);

    return 0;
}