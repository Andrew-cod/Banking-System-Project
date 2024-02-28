#include <stdio.h>
#include <stdlib.h>
#define UNU 1

void swap_char(char *a,char *b){
    char aux=*a;
    *a=*b;
    *b=aux;
}

void print_mat(char **mat,int n){
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
}

void colt(char **mat,int n){
    printf("Dati caracterul dorit:");
    char c;
    scanf(" %c",&c);
    mat[0][0]=c;
    mat[0][n-1] = c;
    mat[n-1][0] = c;
    mat[n-1][n-1] = c;
}

void dp_desc(char** mat,int n){

    char *dp=NULL;

    dp=(char*)malloc(sizeof(char)*n);
    if(dp==NULL){
        printf("alocarea dinamica a esuat");
        exit(1);
    }

    for(int i=0;i<n;i++){
        dp[i]=mat[i][i];
    }

    int flag=0;

    do{
        flag=1;
        for(int i=1;i<n;i++){
            if(dp[i-1]<dp[i]){
                flag=0;
                swap_char(&dp[i-1],&dp[i]);
            }
        }
    }while(flag==0);

    for (int i = 0; i < n; i++)
    {
        printf("%c ", dp[i]);
    }
}

int main(){

    char **mat=NULL;
    int n,opt;
    printf("n:");
    scanf("%d",&n);
    mat = (char **)malloc(sizeof(char*)*n);

    if(mat==NULL){
        printf("alocarea dinamica a esuat");
        exit(1);
    }
    printf("mat:\n");
    for(int i=0;i<n;i++){
        mat[i]=(char*)malloc(sizeof(char)*(n));
        if(*(mat+i)==NULL){
            printf("alocarea dinamica a esuat");
            exit(1);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            do{
            scanf(" %c",&mat[i][j]);
            }while(mat[i][j]<'A' && mat[i][j]>'Z');
        }
    }

    for(int i=0;i<n;i++){
        mat[i][0]='A';
    }

    do{
        printf("meniu\n");
        printf("optiunea:");
        scanf("%d",&opt);
        switch (opt)
        {
        case 0:
            exit(0);
            break;
        case 1:
            print_mat(mat,n);
            break;
        case 2:
            dp_desc(mat,n);
            break;
        case 3:
            colt(mat,n);
        default:
            break;
        }

    }while(1);

    


    return 0;
}