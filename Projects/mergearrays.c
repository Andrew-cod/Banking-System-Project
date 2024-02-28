#include <Stdio.h>

void merge(int *new,int *t,int nr_t,int *a, int nr_a){
    int nr_k=nr_a+nr_t;
    int i=0,j=0;
    for(int k=0;k<=nr_k;k++){
        if( (i<nr_t)&&(j>=nr_a) ||t[i]<a[j]){
            new[k]=t[i];
            i++;
        }else{
            new[k]=a[j];
            j++;
        }
    }
 
}


int main(){
    int t[100000];
    int t_length=0;

    scanf("%d",&t_length);
    for(int i=0;i<t_length;i++){
        scanf("%d",&t[i]);
    }

    int a[100000];
    int a_length=0;

    scanf("%d",&a_length);
    for(int i=0;i<a_length;i++){
        scanf("%d",&a[i]);
    }

    int new[a_length+t_length];
    merge(new,t,t_length,a,a_length);
    printf("\n");
    for(int i=0;i<a_length+t_length;i++){
        printf("%d ",new[i]);
    }


    return 0;
}