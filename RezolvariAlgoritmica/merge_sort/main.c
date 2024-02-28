#include <stdio.h>
#include <stdlib.h>

void afis(int *t,int n){
    for(int i=0;i<n;i++){
        printf("%d ",t[i]);
    }
    printf("\n");
}
void merge(int *t,int l,int r,int mid){


    int t_left[mid-l+1];
    int t_right[r-mid];


    for(int k=0;k<mid-l+1;k++){
        t_left[k]=t[k+l];
    }

    for(int k=0;k<r-mid;k++){
        t_right[k]=t[mid+1+k];
    }

    int i=0,j=0;int k=l;
    while(i<mid-l+1 && j<r-mid){
        if(t_left[i]<t_right[j]){
            t[k++]=t_left[i++];
        }else {
            t[k++] = t_right[j++];
        }
    }

    while(i<mid-l+1){
        t[k++]=t_left[i++];
    }

    while(j<r-mid){
        t[k++]=t_right[j++];
    }





}

void mergesort(int *t,int l,int r){
    if(l<r){
        int mid=l + (r - l) / 2;
        mergesort(t,l,mid);
        mergesort(t,mid+1,r);

        merge(t,l,r,mid);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int *t=calloc(n,sizeof(int));
    if(t==NULL)return 1;
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    afis(t,n);
    mergesort(t,0,n-1);
    afis(t,n);

    return 0;
}
