int searchInsert(int* nums, int numsSize, int target){
    int l=0,r=numsSize-1,m;
    while(l<r){
        m=(l+r)/2;
        if(nums[m]>target){
            r=m;
        }else{
            l=m+1;
        }
        printf("l=%d m=%d r=%d\n",l,m,r);
    }
    return r;
}