#include <stdio.h>


int main(){

    int n,min=1000000,prev,curr;
    scanf("%d",&n);
    scanf("%d",&prev);
    for(int i=1;i<n;i++){
        scanf("%d",&curr);
        if(curr-prev<min)min=curr-prev;
        prev=curr;
    }
    printf("%d",min);



    return 0;
}