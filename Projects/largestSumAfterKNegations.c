#include <stdio.h>

int largestSumAfterKNegations(int* nums, int numsSize, int k){
    int ord=0,aux,ok;

    //sortarea
    while(ord==0){
        ord=1;
        for(int i=1;i<numsSize;i++){
            if( nums[i]<nums[i-1] ) {
                ord=0;
                aux=nums[i];
                nums[i]=nums[i-1];
                nums[i-1]=aux;
            }
        } 
    }

    int nr=k; 
    //negarea
    for(int i=0;i<k;i++){
                if(nums[i]<0){
                    if(numsSize-1==i){if(nr%2==1)nums[i]=0-nums[i];break;}
                    if(nums[i+1]<=0){
                        //il facem pozitiv pe asta si trecem la urmatorul care este negativ
                        nums[i]=0-nums[i];
                        nr--;
                    }

                    else{
                        //acesta este negativ iarasi urmtorul este pozitiv
                        //printf("%d ",nr);
                        if(nr%2==0){
                            nums[i]=0-nums[i];
                            if( 0-nums[i]+nums[i+1] > nums[i]+0-nums[i+1] )
                            nums[i]=0-nums[i];
                            else
                            nums[i+1]=0-nums[i+1];
                        }else 
                        nums[i]=0-nums[i];
                        k=-1;
                        nr=0;
                    }
                }
                else{
                    if(nums[i]==0){
                        k=-1;
                        break;
                        nr=0;
                    }
                    
                    if(k%2==1)nums[i]=0-nums[i];
                    k=-1;
                    nr=0;




                }   
    }

    /*for(int i=0;i<numsSize;i++){
        printf("%d ",nums[i]);
    }*/

    int sum=0;
    for(int i=0;i<numsSize;i++){
        sum=sum+nums[i];
    }
    return sum;
}


int main(){
    int t[10]={8,-7,-3,-9,1,9,-6,-9,3},n=9,k=8;
    printf("%d ",largestSumAfterKNegations(t,n,k));
}