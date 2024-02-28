#include <stdlib.h>
#include <stdio.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };

int isPalindrome(struct ListNode* head){

    if(head->next==NULL)return 1;
    else{
        struct ListNode *tail=head,*p;

        tail=head;
        
        while(tail->next->next!=NULL)tail=tail->next;
        if(tail->next->val==head->val){
            if(head->next==tail->next)return 1;
            
            tail->next=NULL;
            head=head->next;
            
            return isPalindrome(head);
        }else 
        {
            tail=NULL;
        return 0;
        }
    
    


    }
}

int main(){
    struct ListNode *head=NULL,*p=NULL;
    //crearea unei liste simplu inaltuite
    int nr;
    scanf("%d",&nr);
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

    //printarea apelului de functie middleNode care returneaza pointerul la un nod si noi afisam campul val
    printf("%d",isPalindrome(head));

    return 0;
}