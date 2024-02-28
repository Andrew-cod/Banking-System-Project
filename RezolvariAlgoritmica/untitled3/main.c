#include <stdio.h>

void p(int**t,int n){
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d",t[i][j]);
        }
        printf("\n");
    }
}

int verifica(int **tn,int n,int **tm,int m,int i,int j){
    if(m+i<=n && m+j<=n){
        int x=0,y=0;
        int flag=1;
        for(i,x=0;x<m;i++,x++){
            for(j,y=0;y<m;j++,y++){
                if(tn[i][j]!=tm[x][y])flag=0;
            }
        }
        return flag;
    }
    return 0;
}

void cauta(int **tn,int n,int **tm,int m){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(tn[i][j]==tm[0][0]){
                printf("a gasit ceva\n");
                if(verifica(tn,n,tm,m,i,j)==1)
                    printf("(%d,%d)\n",i,j);
                else
                    printf("nu este egala la coordonatele\n");
            }
        }
    }
}



int main() {
    int n,m,i,j;
    int tn[50][50],tm[50][50];
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&tn[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            scanf("%d",&tm[i][j]);
        }
    }
    p(tn,n);
    cauta(tn,n,tm,m);
        return 0;
}
