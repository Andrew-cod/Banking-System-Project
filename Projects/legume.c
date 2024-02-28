#include <stdio.h>
#include <string.h>
#define citire_s(num) scanf("%s",num)

typedef struct{
char nume[30];
int cantitate;
float pret;
}Leguma;

void citeste(Leguma *l,int *n){
    int c;
    float p;
    char num[30];
    int ok=0;
    printf("Nume:");
    scanf("%s",num);
    //citire_s(num);
    printf("Cantitate:");
    scanf("%d",&c);
    printf("Pret:");
    scanf("%f",&p);

    for(int i=0;i<=*n;i++){
        
        if(strcmp((l+i)->nume,num)==0){
        ok=-1;
        (l+i)->cantitate=(l+i)->cantitate+c;
        (l+i)->pret=p;
        break;
        }
    }
    if(ok==0){
        (*n)++;
        (l+*n)->cantitate=c;
        (l+*n)->pret=p;
        strcpy((l+*n)->nume,num);
    }
}

void afisare(Leguma *l, int n){
    for(int i=0;i<=n;i++){
        printf("Nume:%s\n",(l+i)->nume);
        printf("Cantitate:%d\n",(l+i)->cantitate);
        printf("Pret:%f\n\n",(l+i)->pret);
    }
}

void trans(Leguma *l,int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=strlen((l+i)->nume);j++){
            if((l+i)->nume[j]=='a' || (l+i)->nume[j]=='e' || (l+i)->nume[j]=='i' || (l+i)->nume[j]=='o' || (l+i)->nume[j]=='u'){
                (l+i)->nume[j]=(l+i)->nume[j]-('a'-'A');
            }
        }
    }
}

void ordonare(Leguma *l,int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<=n;j++){
            if(strcmp((l+i)->nume,(l+j)->nume)>0){
                Leguma aux;
                aux=*(l+i);
                *(l+i)=*(l+j);
                *(l+j)=aux;
            }
        }
    }
}

void stergere(Leguma *l,int *n){
    char num[30];
    printf("introduceti numele legumei:\n");
    scanf("%s",num);
    for(int i=0;i<=*n;i++){
        if(strcmp((l+i)->nume,num)==0){
            for(int j=i;j<*n;j++)
                *(l+j)=*(l+j+1);
                (*n)--;
        }
    }
}


int main(){
    Leguma l[100];
    int n=-1,opt,ok=1;

    do{

        printf("printam meniul frumos cu optiuni\n\n");
        printf("Intoroduceti opt\n");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            citeste(l,&n);
            break;
        case 2:
            afisare(l,n);
            break;
        case 3:
            trans(l,n);
            break;
        case 4:
            ordonare(l,n);
            break;
        case 5:
            stergere(l,&n);
            break;
        case 6:
            ok=0;
            break;
        }


    }while(ok);


    return 0;
}