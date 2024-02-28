#include <stdio.h>

int sumcif(int n){

    if(n){
        int s=n%10+sumcif(n/10);
        return s;
    }
    else return 0;
}

int main() {


    int n;
    scanf("%d",&n);
    printf("%d",sumcif(n));

    return 0;
}
/*
7
1 1 1 1 0 1 0
1 1 1 1 0 0 0
1 1 1 0 0 1 1
1 1 0 1 1 0 0
0 0 0 1 1 0 0
1 0 1 0 0 1 1
0 0 1 0 0 1 1
5 3
*/