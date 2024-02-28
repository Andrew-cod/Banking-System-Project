#include <stdio.h>
#include <stdlib.h>
struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int nr;
    struct ListNode *p=head,*delete=head;
    while(p!=NULL){
        nr++;
        if(nr>n+1)delete=delete->next;
        p=p->next;
    }
    if(delete!=NULL)p=delete->next;
    if(delete!=NULL)delete->next=delete->next->next;

}


int main(){
struct ListNode *p=NULL,*head=NULL;
int n;
scanf("%d",&n);
head=(struct ListNode*)malloc(sizeof(struct ListNode));
scanf("%d",&head->val);
head->next=NULL;
for(int i=1;i<n;i++){
    p=(struct ListNode*)malloc(sizeof(struct ListNode));
    scanf("%d",&p->val);
    p->next=head;
    head=p;
}
removeNthFromEnd(head,1);

while(head!=NULL){
    printf("%d ",head->val);
    head=head->next;
}






}