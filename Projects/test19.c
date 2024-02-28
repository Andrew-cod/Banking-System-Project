#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct melodie {

    char numart[30];
    char nummelod[30];
    int secunde;

};

void invrs(struct melodie *t,int n){
    struct melodie aux;
    for(int i=0;i<n;i++){
        for(int j=i;j<=n;j++){
            if(strcmp((t+i)->nummelod,(t+j)->nummelod)<0){
                aux=*(t+i);
                *(t+i)=*(t+j);
                *(t+j)=aux;
            }
        }
    }
    for(int i=0;i<=n;i++){
        printf("\n\nArtist:%s\n",(t+i)->numart);
        printf("Melodie:%s\n",(t+i)->nummelod);
        printf("Durata:%d\n\n",(t+i)->secunde);
    }
}

void afis_secunde(struct melodie *t,int n){
    int secunde1;
    printf("Inroduceti secundele dorite:\n");
    scanf("%d",&secunde1);

    for(int i=0;i<=n;i++){
        if((t+i)->secunde<secunde1){
        printf("\n\nArtist:%s\n",(t+i)->numart);
        printf("Melodie:%s\n",(t+i)->nummelod);
        printf("Durata:%d\n\n",(t+i)->secunde);
        }
    }
}

void afis_artist(struct melodie *t,int n){
    char artist1[30];
    printf("Inroduceti artistul dorit:\n");
    scanf("%s",artist1);

    for(int i=0;i<=n;i++){
        if(strcmp((t+i)->numart,artist1)==0){
        printf("\n\nArtist:%s\n",(t+i)->numart);
        printf("Melodie:%s\n",(t+i)->nummelod);
        printf("Durata:%d\n\n",(t+i)->secunde);
        }
    }
}


int valid(char *a){
    int ok=1;
    for(int i=0;i<strlen(a);i++){
        if(isdigit(a[i]) || isalpha(a[i]))ok=1;else return 0;
    }
    return ok;
}

void adauga(struct melodie *t,int *n){
    char numartist[30], nummelodie[30];
    int secunde;
    printf("Introduceti numele artistului:\n");
    do{
    scanf("%s",numartist);
    }while(!valid(numartist));
    printf("Introduceti numele melodiei:\n");
    scanf("%s",nummelodie);
    printf("Intoduceti durata in secunde:\n");
    scanf("%d",&secunde);
    (*n)++;
    (t+*n)->secunde=secunde;
    strcpy((t+*n)->numart,numartist);
    strcpy((t+*n)->nummelod,nummelodie);
}


int main(){

    struct melodie t[1000];
    int ok=1,opt,n=-1;
    do{
        printf("\n\n0-Iesire\n1-Adauga o melodie\n2-Afisarea melodiilor in oridine invers alfabetica\n3-Afisarea melodii care nu depasesc o durata introdusa de utilizatorde la tastatura\n4-Afisarea tuturor melodiilor a unui artist introdus\n\n");
        scanf("%d",&opt);

        switch (opt)
        {
        case 0:
            ok=0;
            break;
        case 1:
            adauga(t,&n);
            break;
        case 2:
            invrs(t,n);
            break;
        case 3:
            afis_secunde(t,n);
            break;
        case 4:
            afis_artist(t,n);
            break;
        default:
            break;
        }



    }while(ok);


    return 0;
}