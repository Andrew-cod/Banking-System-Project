#include <stdio.h>
#include <stdlib.h>
 struct ListNode {
     int val;
     struct ListNode *next;
 };

int hasCycle(struct ListNode *head) {
    if(head==NULL)return 0;
    struct ListNode *fast=head,*slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL&& slow->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)return 1;
    }
    return 0;
}
int main(){
    struct ListNode* head=NULL,n1,n2,n3,n4,n5;
    n1.val=1;
    n2.val=2;
    n3.val=3;
    n4.val=4;
    n5.val=5;
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    n5.next=NULL;
    head=&n1;

    
    
    


    printf("%d",hasCycle(head));




    return 0;
}