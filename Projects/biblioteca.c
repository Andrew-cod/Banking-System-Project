#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num(a,b) (a>b)?a:b

typedef struct {
    char nume[30],titlu[30],domeniu[30],autor[30];
    int anulAparitiei,nrPag;
}Carte;

void adaugaCarte(Carte *c,int *n){
  (*n)++;//mai avem o carte 
  printf("Introduceti titlul:\n");
  scanf("%s",(c+*n)->titlu);
  printf("Introduceti autorul:\n");
  scanf("%s",(c+*n)->autor);
  printf("Introduceti anul aparitiei:\n");
  scanf("%d",&(c+*n)->anulAparitiei);
  printf("Introduceti numarul de pagini:\n");
  scanf("%d",&(c+*n)->nrPag);
  printf("Introduceti domeniul:\n");
  scanf("%s",(c+*n)->domeniu);
}

void afisDom(Carte *c,int n,char dom[30]){
    int i;
    for(i=0;i<=n;i++){
        if(strcmp(dom,(c+i)->domeniu)==0){
              printf("titlul: %30s\n",(c+i)->titlu);
              printf("autorul:%30s\n",(c+i)->autor);
              printf("anul aparitiei:%30d\n",(c+i)->anulAparitiei);
              printf("numarul de pagini:%30d\n",(c+i)->nrPag);
              printf("domeniul:%30s\n",(c+i)->domeniu);
        }
    }
}


void afisTitlu(Carte *c,int n,char titlu[30]){
    int i;
    for(i=0;i<=n;i++){
        if(strcmp(titlu,(c+i)->titlu)==0){
              printf("titlul: %30s\n",(c+i)->titlu);
              printf("autorul:%30s\n",(c+i)->autor);
              printf("anul aparitiei:%30d\n",(c+i)->anulAparitiei);
              printf("numarul de pagini:%30d\n",(c+i)->nrPag);
              printf("domeniul:%30s\n",(c+i)->domeniu);
              printf("\n");
        }
    }
}

void afisAnulAparitiei(Carte *c,int n,int anulAparitiei){
    int i;
    for(i=0;i<=n;i++){
        if(anulAparitiei==(c+i)->anulAparitiei){
              printf("titlul: %30s\n",(c+i)->titlu);
              printf("autorul:%30s\n",(c+i)->autor);
              printf("anul aparitiei:%30d\n",(c+i)->anulAparitiei);
              printf("numarul de pagini:%30d\n",(c+i)->nrPag);
              printf("domeniul:%30s\n",(c+i)->domeniu);
              printf("\n");
        }
    }
}

void stergeCarte(Carte *c,int *n,char t[30]){
    int i,j;
    int k=0;
    for(i=0;i<=*n-k;i++){
        if(strcmp((c+i)->titlu,t)==0){
            k++;
            for(j=i;j<*n-k;j++){
                *(c+j)=*(c+j+1);
            }

        }
    }
    *n=*n-k;
}


int main(){
    Carte C[100];
    int ok=1;
    int n=-1,opt;
    do{
        //Afiseaza meniu



        //mesaj introduceti optiune 
        printf("\nIntroduceti optiunea\n");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            //transmitem pointerul la functii
            adaugaCarte(C,&n);
            break;
        case 2:
            //transmitem pointerul la functii
            printf("Introduceti domeniul:\n");
            char dome[30];
            scanf("%s",dome);
            afisDom(C,n,dome);
            break;
        case 3:
            printf("\nIntroduceti titlul:\n");
            char titlu[30];
            scanf("%s",titlu);
            afisTitlu(C,n,titlu);
            break;
        case 4:
            printf("\nIntroduceti anulaparietiei:\n");
            int anapar;
            scanf("%d",&anapar);
            afisAnulAparitiei(C,n,anapar);
            break;
        case 5:
            printf("\nIntroduceti titlu:\n");
            char ttlu[30];
            scanf("%s",ttlu);
            stergeCarte(C,&n,ttlu);
            break;
        case 7:
            printf("Iesire");
            ok=0;
            break;
        default:
            printf("Ati introdus o optiune invalida");
            ok=0;
            break;
        }
    }while(ok);

    return 0;
}