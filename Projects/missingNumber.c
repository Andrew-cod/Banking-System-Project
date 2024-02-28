#include <stdio.h>
//a mers foarte bine 
int missingNumber(int* nums, int numsSize){
    int t=0;
    for(int i=0;i<numsSize;i++)
        t=t+nums[i];
    return (numsSize*(numsSize+1)/2)-t;
}

int main(){

    int t[]={0,1},n=2;
    printf("%d",missingNumber(t,n));


    return 0;
}