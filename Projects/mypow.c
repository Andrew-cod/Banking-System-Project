#include <stdio.h>


double myPow(double x,long  int n){
    if(x==0)return 0;
    if(n==0)return 1;
    if(n==1)return x;
    else {
        double cop;
        if(n>0){
            if(n%2==0){
                cop=myPow(x,n/2);
                return cop*cop;
            }
                    else {
                        cop=myPow(x,n/2);
                        return cop*cop*x;
                    }
        }
        else {
            n=0-n;
            if(n%2==0){
                cop=myPow(x,n/2);
                return 1/(cop*cop);
                }
                    else {
                        cop=myPow(x,n/2);
                        return 1/( cop*cop*x);
                        }
        }

    }
}



int main(){
    printf("%f",myPow(2,-2));


    return 0;
}