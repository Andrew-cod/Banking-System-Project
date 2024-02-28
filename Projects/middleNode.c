#include <stdlib.h>
#include <stdio.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *mid=head;
    //avem un contor nr si daca a fost cresccut de 2 ori adica a fost la nr par si iar a ajuns la nr par atunci trecem si pe middle la urmatorul deoarece head a trecut de 2 ori
    int nr=0;
    while(head!=NULL){
        if(nr%2==1)mid=mid->next;
        nr++;
        head=head->next;
    }
    return mid;

}

int main(){
    struct ListNode *head=NULL,*p=NULL;
    //crearea unei liste simplu inaltuite

    for(int i=0;i<2;i++){
        p=(struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d ",&p->val);
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
    printf("%d",middleNode(head)->val);

    return 0;
}