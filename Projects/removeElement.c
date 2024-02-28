#include <stdio.h>
// nu a mers aceastea de si pare buna insa a mers ideea ca 
// daca este bun numarul il punem cu un contor nou pe pozitia de la incput de vector daca nu punem
int removeElement(int* nums, int numsSize, int val){
    int j,aux,nr=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==val){
            j=i;
            
            while(nums[j]==val && j<numsSize-1){
                j++;
            }
            aux=nums[i];
            nums[i]=nums[j];
            nums[j]=aux;
            
        }else nr++;

    }
    return nr;
}

int main(){
    int t[]={1,2,3,3,5},n=5;
    removeElement(t,n,1);
    for(int i=0;i<removeElement(t,n,3);i++){
        printf("%d ",t[i]);
    }




}