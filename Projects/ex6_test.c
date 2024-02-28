#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void prim_c(char **s,int n){
    char *p;
    p=(char*)malloc(n);//+control
    for(int i=0;i<n;i++){
        p[i]=s[i][0];
    }
    p[n]='\0';

    int flag=1;
    do{
        flag=1;
        for(int i=1;i<n;i++){
            if(p[i-1]<p[i]){
                char aux=p[i-1];
                p[i-1]=p[i];
                p[i]=aux;
            }
        }

    }while(flag==0);
    printf("%s\n",p);
}


void lung_min(char **s,int n){
    int min=9999999;
    for(int i=0;i<n;i++){
        if(strlen(s[i])<min)min=strlen(s[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        if(strlen(s[i])==min){
            printf("%s\n",s[i]);
        }
    }
}
int valid(char *s)
{
    if( s[0]>='A' && s[0]<='Z'  ){
    for(int i=1;i<strlen(s);i++){
        if( !(s[i]>='a' && s[i]<='z') )return 0;
    }
    }else return 0;
    return 1;
}

void print_des(char **s, int n)
{   
    char aux[50];
    int flag=1;
    do{
        flag=1;
        for(int i=1;i<n;i++){
            if(strcmp(s[i-1],s[i])<0){
                flag=0;
                strcpy(aux,s[i]);
                strcpy(s[i],s[i-1] );
                strcpy(s[i-1],aux );
            }
        }
    }while(flag==0);

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", s[i]);
    }
    printf("\n");
}

int main()
{

    int n = 0, opt;
    char **s;
    char cop[50];
    printf("n:");
    scanf("%d", &n);

    s = (char **)malloc(sizeof(char *) * n); //+control

    for (int i = 0; i < n - 1; i++)
    {
        do
        {
            printf("Nume %d: ", i + 1);
            scanf("%s", cop);
        } while (valid(cop) == 0);
        s[i] = (char *)malloc(strlen(cop) + 1); //+control
        strcpy(s[i], cop);
    }
    s[n - 1] = (char *)malloc(4); //+control
    strcpy(s[n - 1], "Leu");

    do
    {
        printf("\n0. Ieșire\n1. Afișarea animalelor în ordine invers alfabetică.\n2. Să se afișeze animalul/animalele care au lungimea cea mai mică.\n3. Să se copieze într-un vector primul caracter d\n\n");
        printf("Optiunea:");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            exit(0);
            break;
        case 1:
            print_des(s, n);
            break;
        case 2:
            lung_min(s,n);
            break;
        case 3:
            prim_c(s,n);
        default:
            break;
        }

    } while (1);
}