//heap sort

#include <stdio.h>

void swap(int *a,int *b){
    int aux=*a;
    *a=*b;
    *b=aux;
}

void afis(int *t,int n){
    for(int i=1;i<=n;i++){
        printf("%d ",t[i]);
    }
    printf("\n");
}

int max(int a,int b){
    return (a>b)?a:b;
}

void verif(int *t,int i,int n){
    if(i<=n/2){
        if( 2*i<=n && 2*i+1<=n){
            if(max(t[i],max(t[2*i],t[2*i+1]))==t[2*i]){
                swap(&t[i],&t[2*i]);
                verif(t,2*i,n);
            }
            else{
                if(max(t[i],max(t[2*i],t[2*i+1]))==t[2*i+1]){
                    swap(&t[i],&t[2*i+1]);
                    verif(t,2*i+1,n);
                }
            }
        }
        else
            if(2*i+1>n){
                if(max(t[i],t[2*i])==t[2*i]){
                    swap(&t[i],&t[2*i]);
                    verif(t,2*i,n);
                }
            }
    }
}

void ansamblu(int *t,int n){
    for(int i=n/2;i>=1;i--){
        verif(t,i,n);
    }
}



void heap(int *t, int n){
    while(n>=2){
        ansamblu(t,n);
        swap(&t[1],&t[n]);
        n--;

    }
}



int main()
{
    int n;
    scanf("%d",&n);
    int t[100]={0};

    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);
    }
    heap(t,n);
    afis(t, n);

    return 0;
}
