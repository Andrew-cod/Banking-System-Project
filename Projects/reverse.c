#include <stdio.h>

int reverse(int cop){
    int ogl=0;
    while(cop!=0){
        ogl=ogl*10+cop%10;
        cop=cop/10;
    }
    return ogl;
}

int main(){
    printf("%d",reverse(-123));



    return 0;
}