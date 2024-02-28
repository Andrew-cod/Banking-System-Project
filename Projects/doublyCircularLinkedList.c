#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
    struct node* prev;
};

int main(){
    struct node *head,*p,*curr,*tail;

    head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    head->prev=NULL;
    head->val=0;
    tail=head;//din cazuza ca avem numai una si ea este si capul si coada
    p=head;
    for(int i=1;i<=10;i++){
        
        p=(struct node*)malloc(sizeof(struct node));
        p->val=i;
        p->next=head;
        head->prev=p;
        p->prev=NULL;
        head=p;

    }

    tail->next=head;
    head->prev=tail;



    //trecem peste lista circulara si ne oprim la un nod cu valoarea doria si daca nu este asfel de nod este ciclu infinit
    p=tail;
    while(p!=NULL){
        printf("%d ",p->val);
        if(p->val==8)break;
        p=p->prev;
    }

    return 0;
}