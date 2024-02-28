#include <stdio.h>

void swap(int *a,int *b){
    int aux=*a;
    *a=*b;
    *b=aux;
}

void afis(int t[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",t[i]);
    }
    printf("\n");
}

int patition(int t[],int l, int r){
    if(l<r){
        int pivot=t[r];
        int i=l-1;
        for(int j=l;j<r;j++){
            if(t[j]<pivot){
                i++;
                swap(&t[j],&t[i]);
            }
        }
        i++;
        swap(&t[r],&t[i]);
        return i;
    }


}

void  quick(int t[],int l,int r){
    if(l<r){
        int pivot=patition(t,l,r);

            quick(t, l, pivot-1);
            quick(t, pivot + 1, r);
    }
}



int main() {
    int n;
    int t[100]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }

    //printf("%d\n",patition(t,0,n-1));
    quick(t,0,n-1);

    for(int i=0;i<n;i++){
        printf("%d ",t[i]);
    }
    return 0;
}
