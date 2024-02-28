#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int valid(char *a){
    if(a[0]==toupper(a[0])){
        for(int i=1;i<strlen(a);i++){
            if(tolower(a[i])!=a[i])return 0;
        }
    }else return 0;
    return 1;
}

void print_prim(char **mat,int n){

    for(int i=0;i<n;i++)printf("%c",mat[i][0]);

}

int main(){
    int n=0;
    char *p=NULL;
    char sir[100];
    char **tab=NULL;
    scanf("%d",&n);
    tab=malloc(n*sizeof(char*));

    for(int j=0;j<n;j++){
        do{
        scanf("%s",sir);
        }while(valid(sir)==0);
        p=malloc((strlen(sir)+1)*sizeof(char));
        strcpy(p,sir);
        tab[j]=p;
    }
    printf("\n");
    print_prim(tab,n);
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%s\n",tab[i]);
    }

    return 0;
}