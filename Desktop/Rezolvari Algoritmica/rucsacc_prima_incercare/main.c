/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct ruc{
    int w;
    int p;
    float w_p;
};


/*
6 10
3 7
3 4
1 2
1 9
2 4
1 5
 */
int main()
{
    int n,g;
    scanf("%d %d",&n,&g);
    struct ruc *t=(struct ruc*)malloc(sizeof(struct ruc)*n);
    if(t==NULL)return 1;

    for(int i=0;i<n;i++){
        scanf("%d %d",&t[i].w,&t[i].p);
        t[i].w_p=(float)t[i].w/t[i].p;
    }

    int ok=1;
    do{
        ok=1;
        for(int i=0;i<n-1;i++){
            if(t[i].w_p<t[i+1].w_p){
                ok=0;
                float aux=t[i].w_p;
                t[i].w_p=t[i+1].w_p;
                t[i+1].w_p=aux;
            }
        }

    }while(!ok);

    for(int i=0;i<n;i++){
        
    }


    int i=n-1;
    int p_total=0;
    while(g>0 && i>=0){
        if(t[i].w<=g){
            p_total=t[i].p;
            g=g-t[i].w;
        }
        i--;
    }
    printf("%d",p_total);

    return 0;
}
