#include <stdio.h>
#include <stdlib.h>


typedef struct stiva{
    int val;
    struct stiva *next;
}stiva;

stiva* init(){
    stiva *t=NULL;
    return t;
}

stiva* push(stiva *t,int n){
    stiva *new=(stiva*)malloc(sizeof(stiva));
    if(new==NULL)exit(EXIT_FAILURE);
    new->next=t;
    new->val=n;
    return new;
}

stiva* pop(stiva *t){
    stiva *aux=t->next;
    free(t);
    return aux;
}
int empty(stiva *t){
    if(t==NULL)return 1;
    return 0;
}

int peek(stiva *t){
    if(!empty(t))
        return t->val;
}

int elem(stiva *t){
    int s=0;
    stiva *a=t;
    while(a!=NULL){
        s++;
        a=a->next;
    }
    return s;
}

void print(stiva *t){
    if(!empty(t)){
        print(t->next);
        printf("%d ",t->val);
    }
}






int main() {





    return 0;
}
