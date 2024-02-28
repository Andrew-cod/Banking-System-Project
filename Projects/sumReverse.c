#include <stdio.h>
int rev(int n){
    int ogl=0;
    while(n>0){
        ogl=ogl*10+n%10;
        n=n/10;
    }
    return ogl;

}
int sumOfNumberAndReverse(int num){
    for(int i=0;i<num;i++){
        if(i+rev(i)==num)return 1;
    }
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d", sumOfNumberAndReverse(n));




    return 0;
}