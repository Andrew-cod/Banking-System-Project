#include <stdlib.h>
#include <stdio.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    struct ListNode *head1=list1,*head2=list2,*temp=NULL,a,*rez=&a;
            a.next=NULL;
            a.val=0;
            //setam primul node
            if(list1==NULL)return list2;
            if(list2==NULL)return list1;
            if(list1==NULL && list2==NULL)return NULL;

            temp=rez;
        //pana cand ammbii nu sunt null adaugam la rez un nod in dependenta de cine mai poate fi null

        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                rez->next=list1;
                list1=list1->next;
                rez=rez->next;
            }      
            else {
                rez->next=list2;
                list2=list2->next;
                rez=rez->next;
            }
        
            

            
        }
        if(list1!=NULL)rez->next=list1;else rez->next=list2;
        

    return temp->next;
}

int main(){
    struct ListNode *p=NULL,*temp=NULL, *p1=NULL;
    //creem prima lista
    for(int i=10;i>=2;i=i-1){
        temp= (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val=i;
        temp->next=p;
        p=temp;
    }
    //creem a doua lista
    temp=NULL;
    for(int i=20;i>=0;i=i-2){
        temp= (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val=i;
        temp->next=p1;
        p1=temp;
    }   
    //le afisam pe ambele penttru a fi mai vizibil

printf("\n");
    temp=p;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->next;
    }

    printf("\n");
    temp=p1;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->next;
    }
printf("\n");
    temp=mergeTwoLists(p,p1);
printf("\n");

    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->next;
    }
    return 0;
}