#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int valid(char *s){
    int ok=1;
    if(strlen(s)<3)return 0;
   for(int i=0;i<strlen(s);i++){
        if(i==0 && (s[i]!=toupper(s[i]) || isalpha(s[i])==0))ok=0;
        if(i!=0){
            if(s[i]!=tolower(s[i]) || isalpha(s[i])==0)ok=0;
        }
   }
   return ok;
}

void afis(char **t,int n){
    printf("\n");
    for(int i=0;i<n;i++)
        printf("%s\n",t[i]);
        printf("\n");
}

void afis_invers(char **t,int n){
    int sort=0;
    char *aux;
    do{
        sort=1;
        for(int i=1;i<n;i++){
            if(strcmp(t[i],t[i-1])>0){

                sort=0;//daca am gasit asa caz insemana ca nu mai este sortat
                aux=(char*)malloc((strlen(t[i-1])+1)*sizeof(char));                 //alocam memorie ca pentru t[i-1];
                strcpy(aux,t[i-1]);                                                 //copiem t[i-1] in aux         
                t[i-1]=(char*)realloc(t[i-1], sizeof(char)*(strlen(t[i])+1));       //realocam memorie in t[i-1] pentru t[i] 
                strcpy(t[i-1],t[i]);                                                //copiem t[i] in t[i-1]
                t[i]=(char*)realloc(t[i], sizeof(char)*(strlen(aux)+1));            //alocam memorie pentru 
                strcpy(t[i],aux);                                                   //copiem aux in t[i]
                free(aux);                                                          //eliberam memoria folosita de aux
            }
        }
        printf("%d",sort);
        afis(t,n);
    }while(sort!=1);                                                                //pana cand este sortat adica pana nu avem caz in care sort de vine 0
    
    afis(t,n);
}

void lung_binar(char **t,int n){

}

void prim_carac(char **t,int n){
    char *p=(char*)malloc((n+1)*sizeof(char));
    for(int i=0;i<n;i++){
        strncat(p,&t[i][0],1);
    }
    printf("%s",p);
}

int main(){
    char **t ;int n, ok,opt;
    char s[150];
    scanf("%d",&n);
    t=(char**)malloc(sizeof(char*));                                                //alocam memorie pentru poenterii ce vor memora denumirele tarilor

    for(int i=0;i<n;i++){
        //citim pana cand nu este valid numele tarii dupa conditie
        do{ 
            scanf("%s",s);
            if(valid(s)==0)printf("Again:\n");
        }while(valid(s)==0);
        t[i]=(char *)malloc((strlen(s)+1)*sizeof(char));                            //alocam memorie dinamica pentru denumirea citita static
        strcpy(t[i],s);                                                             //copiem 
    }

    do{
    printf("\nmeniu afisat frumos\nIntorduceti optiunea:\n");
    scanf("%d",&opt);
    switch (opt)
    {
    case 0:
        ok=1;
        break;
    case 1:
        afis_invers(t,n);
        break;
    case 2:
        prim_carac(t,n);
        break;
    case 3:
        lung_binar(t,n);
    default:
        break;
    }






    }while(ok==0);
    




    return 0;
}