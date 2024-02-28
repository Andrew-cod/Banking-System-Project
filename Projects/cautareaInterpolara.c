#include <stdio.h>

int cautareaBinaraInterpolara(int *t,int n,int x){
    int s=0,d=n-1;
    int m;
    if(x>=t[s] && x<=t[d]){
            do{
                m=s+(x-t[s])*(d-s)/(t[d]-t[s]);
                if(x>t[m])s=m+1;
                else
                d=m-1;
                printf("\nm=%d",m);
            }while(s<d && x>=t[s] && x<=t[d] && x!=t[m]);
    }else return -1;
    return m;
}

int main(){
    int t[100],n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    scanf("%d",&x);
    printf("\n%d",cautareaBinaraInterpolara(t,n,x));
    return 0;
}