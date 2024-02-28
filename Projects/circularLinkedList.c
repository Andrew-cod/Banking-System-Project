#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

int main(){
    struct node *head=NULL, *tail,*p;
    tail->next=NULL;
    for(int i=0;i<=10;i++){
        p=(struct node*)malloc(sizeof(struct node));
        if(i==0)tail=p;
        p->val=i;
        p->next=head;
        head=p;
    }


    tail->next=head;
    p=head;
    do{
        printf("%d ",p->val);
        p=p->next;
    }while(p!=head);
    



    return 0;
}