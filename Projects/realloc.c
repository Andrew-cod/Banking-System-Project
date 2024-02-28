#include <stdio.h>
#include <stdlib.h>



int main(){
    int n,nr=0, *t=NULL,*p=NULL;
    do{
        scanf("%d",&n);
        nr++;
        p=realloc(t,nr*sizeof(int));
        if(p!=NULL)t=p;
        else printf("a esuat");
        p[nr-1]=n;
    }while(n!=0);
    for(int i=0;i<nr;i++){
        printf("%d ",t[i]);
    }




    return 0;
}