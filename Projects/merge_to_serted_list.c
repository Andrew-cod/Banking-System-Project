#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
     int val;
    struct ListNode *next;
 };


int main(){

   struct ListNode *p,*a,*b,*c,*d,*f,*g,*h;
   a= (struct ListNode*)malloc( sizeof(struct ListNode) );
   b= (struct ListNode*)malloc( sizeof(struct ListNode) );
   c= (struct ListNode*)malloc( sizeof(struct ListNode) );
   d= (struct ListNode*)malloc( sizeof(struct ListNode) );
   f= (struct ListNode*)malloc( sizeof(struct ListNode) );
   g= (struct ListNode*)malloc( sizeof(struct ListNode) );
   h= (struct ListNode*)malloc( sizeof(struct ListNode) );

    a->next=b;
    b->next=c;
    c->next=d;
    d->next=f;
    f->next=g;
    g->next=h;
    h->next=NULL;

    int u;
    p=a;
    int i=0;

    while(p!=NULL){
        scanf("%d ",&(p->val));
        p=p->next;
        
    }

    struct ListNode *prev=NULL,*urm;

    p=a;
    while(p!=NULL){
        urm=p->next;
        p->next=prev;
        prev=p;
        p=urm;

    }
    p=prev;
    printf("\n");

    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }
    
    return 0;
}