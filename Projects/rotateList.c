#include <stdlib.h>
#include <stdio.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* rotateRight(struct ListNode* head, int k){
    int len=0;//lungimea listei sau mai bine spus cate noduri are 
    struct ListNode *p=head;
    if(p==NULL)return NULL;
    while(p->next!=NULL){
        len++;
        p=p->next;
    }
    len++;
    k = k % len;//daca retim de n ori tot la aceiasi ajungem

    p->next=head;//o facem circulara 
    p=head;
    for(int i=1;i<len-k;i++){
        p=p->next;
    }
    head=p->next;
    p->next=NULL;
    return head;
    


}


int main(){
    struct ListNode *head=NULL,*p=NULL;
    //crearea unei liste simplu inaltuite
    int nr=0,k=0;
    scanf("%d %d",&nr,&k);
    for(int i=0;i<nr;i++){
        p=(struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d",&p->val);
        p->next=head;
        head=p;
    }
    //pritarea listei pentru claritate
    p=head;
    while(p!=NULL){
        printf("%d ",p->val);

        p=p->next;
    }
    printf("\n");
    head=rotateRight(head,k);
    p=head;
    while(p!=NULL){
        printf("%d ",p->val);

        p=p->next;
    }
    printf("\n");

    

    return 0;
}