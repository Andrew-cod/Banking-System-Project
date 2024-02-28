#include <stdio.h>
//Varianta pur Backtracking merge corect dar nu este buna in timp

/*
int uniquePaths(int n, int m){
    if(n==1 || m==1)return 1;
    else return uniquePaths(n-1,m)+uniquePaths(n,m-1);
}

*/
int a,b;
unsigned long int t[105][105]={0};
int uniquePaths(int n, int m){
    if(n==1 || m==1)t[n][m]=1;
    else{
        if( t[n-1][m]!=0 && t[n][m-1]!=0){
            t[n][m]=t[n-1][m]+t[n][m-1];
        }else{
            if( t[n-1][m]!=0 ) t[n][m]=t[n-1][m]+uniquePaths(n,m-1);else
            if( t[n][m-1]!=0 ) t[n][m]=t[n][m-1]+uniquePaths(n-1,m);else
            t[n][m]=uniquePaths(n-1,m)+uniquePaths(n,m-1);
        }
        
        

    }
    printf("\n");
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++)printf("%2d ",t[i][j]);
       printf("\n"); 
    }
        printf("\n---------\n");
    return t[n][m];
}


int main(){

    
    scanf("%d%d",&a,&b);
    printf("%d",uniquePaths(a,b));



    return 0;
}


