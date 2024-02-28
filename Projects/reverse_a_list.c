#include <stdio.h>

struct node {
    int info;
    struct node *next;
};

int main(){
    struct node n1,n2,n3,n4,n5;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    n5.next=NULL;
    struct node *head=&n1,*p;
    p=head;
    int i=2;
    while(p!=NULL){
        p->info=i*i;
        p=p->next;
        i++;
    }

    p=head;
    struct node *prev=NULL,*buffer;
    while(p!=NULL){
        buffer=p;
        p=p->next;
        buffer->next=prev;
        prev=buffer;
        if(p!=NULL)head=p;
    }


    p=head;
    while(p!=NULL){
        
        printf("%d ",p->info);
        p=p->next;
    }

    return 0;
}