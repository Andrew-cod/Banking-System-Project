#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_binary(int n){
    uint32_t mask= 1<<31;
    for(int i=0;i<32;i++){
        printf("%d", (n&mask)?1:0);
        mask = mask>>1;
    }
    printf("\n");
}

uint32_t reverseBits(uint32_t n) {
    uint32_t rev=0;
    uint32_t mask=1;
    uint32_t all_1=1;
    for(int i=0;i<31;i++){    

        if(mask&n)rev=rev+1;
            rev=rev<<1;
            mask=mask<<1;
    }
    if(1<<31&n)rev++;
    
    return rev;
}

int main(){
    print_binary(reverseBits(0b01111111111111111111111111111101));


    return 0;
}