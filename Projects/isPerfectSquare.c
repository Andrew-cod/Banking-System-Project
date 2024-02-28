#include <stdio.h>

int isPerfectSquare(int num){
    int i=2;;
    while(i*i<num){
        i++;
    }
    if(i*i==num)return 1;else return 0;
}

int main(){
    
    printf("%d ",isPerfectSquare(36));

    return 0;
}