#include <stdio.h>

int climbStairs(int n){
    int a=1 ,b=1,c;
    for(int i=1;i<n;i++){
        c=a+b;
        b=a;
        a=c;
    }
    return b;
}

int main(){

    printf("%d",climbStairs(4));

    return 0;
}