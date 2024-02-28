//7:19
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct telefon{
    char model[30];
    float diagonala;
    float pret;
};

int valid(char *s){
    int len=strlen(s);
    int flag=0;
    for(int  i=0;i<len;i++){
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')flag=1;
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z')))
            return 0;
    }
    return flag;
}

void print(struct telefon *t,int n){
    printf("\n");
    for(int i=0;i<n;i++){
        printf("\n\n");
        printf("MODEL: %s\n",(t+i)->model);
        printf("Diagonala: %.2f\n",(t+i)->diagonala); 
        printf("Pret:      %.2f\n", (t+i)->pret);
    }
    printf("\n");
}

void swap(struct telefon *a,struct telefon *b){
    struct telefon aux=*a;
    *a=*b;
    *b=aux;
}

void sort(struct telefon *t,int n){
    
}

void print_desc(struct telefon *t,int n){
    int flag = 1;
    do
    {
        flag = 1;
        for (int i = 1; i < n; i++)
        {
            if (((t + i - 1)->pret) < ((t + i)->pret))
            {
                flag = 0;
                swap((t + i - 1), (t + i));
            }
        }
    } while (flag == 0);
    print(t,n);
}

void reducere(struct telefon *t,int n){
    char model[30];
    scanf("%s",model);
    for(int i=0;i<n;i++){
        if(strcmp(model,(t+i)->model)==0){
            (t+i)->pret=(t+i)->pret* (0.8);
        }
    }
}

void adaug(struct telefon *t,int *n){
    
    do{
        printf("MODEL: ");
        scanf("%s",&(t+*n)->model);
    }while(valid((t+*n)->model)==0);
    printf("DIAGONALA: ");
    scanf("%f",&(t+*n)->diagonala);
    (t+*n)->pret=(t+*n)->diagonala*strlen((t+*n)->model);
    *n=*n+1;
}

int main(){
    struct telefon t[1000];
    int n=0,opt;

    do{

        printf("0. Ieșire\n1. Adăugarea unui telefon.\n2. Afișarea telefoanelor în ordine crescătoare după preț.\n3. Să se aplice o reducere de 20% la toate telefoanele care aparțin unei mărci\nspecificate de utilizator de la tastatură.\n4. Să se afișeze câți biți de 1 are reprezentarea binară a fiecărei diagonale\n\nOptiune:\n");
        scanf("%d",&opt);

        switch (opt)
        {
        case 0:
            exit(0);
            break;
        case 1:
            adaug(t,&n);
            break;
        case 2:
            print_desc(t,n);
            break;

        case 3:
            reducere(t,n);
            break;
        default:
            break;
        }


    }while(1);
    return 0;
}
//8:021