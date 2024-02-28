#include <stdio.h>

void afis(int t[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",t[i]);
    }
    printf("\n");
}

void swap(int *a,int *b){
    int aux=*a;
    *a=*b;
    *b=aux;
}

void radix(int t[],int l,int r,int b){
    if(b>=0 && l<r){
        int s=l;
        int j=r;

        //aranjeaza conform bitului b
        while(s<=j){
            while( ((t[s]>>b) & 1) ==0 && s<=r) {
                s++;
            }


            while( ((t[j]>>b) & 1) ==1 && j>=0) {
                j--;
            }
            if(s<j)
                swap(&t[s],&t[j]);
            s++;
            j--;
        }

            s=l;
            while(((t[s]>>b) & 1) ==0 && s<=r)s++;

            radix(t, s, r, b - 1);
            radix(t, l, s - 1, b - 1);


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
    radix(t,0,n-1,31);

    for(int i=0;i<n;i++){
        printf("%d ",t[i]);
    }
    return 0;
}

