#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i=0,j=numsSize-1;int *t=NULL;
    while(i<j){
        if(nums[i]+nums[j]<target){
            i++;
        }
        else
        if(nums[i]+nums[j]>target){
            j--;
        }else{
            t=(int*)malloc(8);
            t[0]=nums[i];
            t[1]=nums[j];
            return t;
        }
    }
    return t;
}


int main(){
    int t[1000],n,target;
    scanf("%d %d",&n,&target);
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    int new_n;
    int *p=twoSum(t,n,target,&new_n);
    printf("%d %d",p[0],p[1]);


    return 0;
}