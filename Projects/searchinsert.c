#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    int l=0,r=numsSize,m;
    while(l<r){
        m=(l+r)/2;
        if(nums[m]>=target){
            r=m;
        }else{
            l=m+1;
        }
    }
    return r;
}


int main(){

    int t[100],n,target;
    scanf("%d %d",&n,&target);
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    printf("%d",searchInsert(t,n,target));

    return 0;
}