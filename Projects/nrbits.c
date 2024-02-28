#include <stdio.h>

int nrbits(int n){
    int nr=0;
    if(n==0)return 0;
    else {
        return nrbits(n>>1)+(n&1);
    }
}


int main()
{
    printf("%d",nrbits(64));

    return 0;
}