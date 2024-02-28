#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};

int main(){

    struct node *p,*buffer, u, *head;
    p=&u;
    head=&u;
    u.val=0;
    u.next=NULL;
    int i=1;

    while(i<=10){
        buffer=(struct node*)malloc(sizeof(struct node));
        buffer->next=p;
        p=buffer;
        p->val=i;
        i++;
    }
    head=p;
    struct node *prev=NULL;
    p=head;
    buffer=NULL;
    while(p!=NULL){
        if(p->val==0){
            if(buffer==NULL){
                buffer=p;
                p=p->next;
                free(buffer);
                head=p;
                break;
            }
            if(p->next==NULL){
                //eroare nu merge din cauza din cauza ca daca pun free(p)
                buffer->next=NULL;
                buffer=p;
                free(buffer);
                
                break;

            }
            buffer->next=p->next;
            free(p);
            break;
        }else{
        buffer=p;
        p=p->next;
        }
    }
    

    p=head;
    while(p!=NULL){
        printf("%d " , p->val);
        p=p->next;
    }
    printf("\n");
    p=head;
    while(p!=NULL){
        buffer=p;
        p=p->next;
        buffer->next=prev;
        prev=buffer;
    }
    head=prev;
    p=prev;

    while(p!=NULL){
        printf("%d " , p->val);
        p=p->next;
    }

    while(head!=NULL){
        p=head;
        head=head->next;
        free(p);
        
    }




    return 0;
}