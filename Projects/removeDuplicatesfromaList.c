#include <stdlib.h>
#include <stdio.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* deleteDuplicates(struct ListNode* head){

    struct ListNode *p=NULL,*temp=NULL;
    p=head;
    if(p->next!=NULL)temp=p->next;
    
    while(p!=NULL){
        if(temp->val==p->val){
           
            while(temp->val==p->val || temp!=NULL){

                temp=temp->next;
                if(temp==NULL)break;
                }
            p->next=temp;
            
        }
        printf("%d ",p->val);
        p=p->next;
        temp=p->next;

    }
}


int main(){

struct ListNode *head=NULL,*p=NULL,*prev=NULL;

    for(int i=0;i<10;i++){
        p=(struct ListNode*)malloc(sizeof(struct ListNode));
        //scanf("%d ",&p->val);
        p->val=i;
        if(p->val==5)p->val=6;
        p->next=head;
        head=p;
    }
    p=head;
    while(head!=NULL){
        printf("%d ",head->val);

        head=head->next;
    }
    head=p;
    deleteDuplicates(head);
    printf("\n");
    p=head;
    while(head!=NULL){
        printf("%d ",head->val);

        head=head->next;
    }





    return 0;
}