#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct telefon{
    float pret;
    char model[30];
};

void afis(struct telefon *t,int n){
    for(int i=0;i<=n;i++){
        printf("\nMODEL:%s\nPRET:%.2f",(t+i)->model,(t+i)->pret);
    }

}

int valid(char *a){
    if(strlen(a)>=3)
    if(toupper(a[0])==a[0] && toupper(a[1])==a[1] && a[2]=='-')return 1;
    return 0;
}

void adaug(struct telefon *t,int *n){
    
        (*n)++;
        char nume[29];

        printf("Introduceti modelul telefonului\n");
        do{
            scanf("%s",nume);
        }while(!valid(nume));

        printf("Introduceti pretul telefonului\n");
        scanf("%f",&(t+*n)->pret);

        //t->model=(char*)malloc(strlen(nume)+1);
        //if(t->model==NULL){printf("T->model este NULL");exit(1);}
        strcpy((t+*n)->model,nume);
    

}

int main(){

    int n=-1,ok=1,opt=-1,nr=5;
    struct telefon *t,*p;
    t=(struct telefon*)malloc(nr*sizeof(struct telefon));
    if(t==NULL){printf("T este NULL");exit(1);}
    do{
    //Printarea meniului inainte 
    printf("\n0_Iesire\n1_Adauga un telefon nou\n2_Afiseaza telefoanele\n3_Sorteaza telefoanele in ordine crescatoare dupa pretul lor\n\n");
    scanf("%d",&opt);

    switch (opt)
    {
    case 0:
        ok=0;
        break;
    case 1:
        adaug(t,&n);
        break;
    case 2:
        afis(t,n);
        break;
    default:
        break;
    }
    if(n==nr-3){p=(struct telefon*)realloc(t,(nr+10)*sizeof(struct telefon));nr=nr+10;if(p!=NULL)t=p;else exit(1);}
    
    printf("%d",n);
    }while(ok);

    return 0;
}