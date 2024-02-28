#include <stdio.h>

int min(int a,int b){
    return (a<b)?a:b;
}
int maxArea(int* t, int n){
    int i=0,j=n-1,local=0,global=0;
    while(i!=j){
        local=min(t[i],t[j])*(j-i);
        //printf("%d %d %d\n",i,j,local);
        if(local>global)global=local;
        if(t[i]<t[j]){
            i++;
        }else j--;
    }
    return global;
}

int main(){
    

    int n, t[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    printf("%d",maxArea(t,n));





    return 0;

}