#include <stdio.h>



void moveZeroes(int* nums, int numsSize){
    int j=0,nr=0;
    for( int i=0;i<numsSize;i++ ){
        if(nums[i]!=0){
            nums[j]=nums[i];
            j++;
        }else
        {
            nr++;
        }
        }
    for(int i=nr;i>0;i--){
        nums[numsSize-1]=0;
        numsSize--;
    }
        //for(int i=0;i<numsSize;i++)printf("%d ",nums[i]);

}


int main(){
    int t[]={1,0,1,0,5,0,7,8},n=8;
    moveZeroes(t,n);
    for(int i=0;i<n;i++)printf("%d ",t[i]);



    return 0;
}