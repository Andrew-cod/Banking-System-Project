#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define NMAX 1000000
int func(uint16_t A[],int N,uint8_t x){
    int nr=0;
    uint8_t a=255;
    for(int i=0;i<N;i++){
        A[i]=A[i]<<8;
        A[i]=A[i]>>8;
        if((A[i])==x)nr++;
    }
    return nr;
}

int main(){
    uint16_t t[NMAX];
    int n=NMAX;
    uint8_t x;
    x=255;
    for(int i=0;i<=NMAX;i++){
        t[i]= (rand() % (60000 - 1));
    }
   
    printf("%d ",func(t,n,x));
    return 0;
}