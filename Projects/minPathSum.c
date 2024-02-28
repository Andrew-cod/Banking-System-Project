#include <stdio.h>
#include <stdlib.h>

int print(int **t,int n,int m){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)printf("%d ",t[i][j]);
    printf("\n");
    }
}

int minn(int a,int b){
    return (a<b)?a:b;
}


int minPathSum(int** t, int gridSize, int *gridColSize){
    int i=0,j=0;
    for(int j=1;j<gridSize;j++)t[0][j]=t[0][j]+t[0][j-1];
    //print(t,3,3);
    for(i=1;i<*gridColSize;i++){
        for(j=0;j<gridSize;j++){
            if(j==0)t[i][j]=t[i][j]+t[i-1][j];
            t[i][j]=t[i][j]+minn(t[i][j-1],t[i-1][j]);
            //printf("%d ",t[i][j]);
        }
       // printf("\n");
    }
    
    return t[i-1][j-1];
}


int main(){
    int n=0,m=0,**t=NULL;
    scanf("%d %d",&m,&n);
    t=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)t[i]=(int*)malloc(sizeof(m*sizeof(int)));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)scanf("%d",&t[i][j]);
    }
    print(t,m,n);
printf("\n%d\n",minPathSum(t,m,&n));


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)printf("%d ",t[i][j]);
    printf("\n");
    }





    return 0;
}