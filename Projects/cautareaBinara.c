#include <stdio.h>

int cautareaBinaraPerformata(int *t,int n,int x){

    int s=0,d=n-1;
    int m=(s+d)/2;
    do{
        m=(s+d)/2;
        if(x>t[m])s=m+1;
        else
        d=m;
        printf("\nm=%d",m);
    }while(s<d);
    return d;
}

int main(){
    int t[100],n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    scanf("%d",&x);
    printf("\n%d",cautareaBinaraPerformata(t,n,x));




    return 0;
}