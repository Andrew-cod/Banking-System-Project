#include <stdio.h>
#include <stdlib.h>
//structura pentru un nod
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* sortList(struct ListNode* head){
    struct ListNode *p=NULL,*prev=NULL,*aux=NULL;
    int sortat=1;
    p=head;
    //implementarea la bubblesort pentru liste
    //pana cand nu este sortat adica la o parcurgere nu am avut un element la stanga mai mare ca urmatorul lui 
    do{ 
        p=head;
        prev=NULL;
        sortat=1;
        aux=head;
        //printf("da\n");
        while(p!=NULL){
                //daca urmatorul lui p este null ne oprim din cauza ca algoritmul compara pe p cu urmatorul lui 
                if(p->next==NULL)break;
                //in caz ca valoarea la urmatorul este mai mare ii schimbam cu locul deoarece sortarea se face crescator
                if(p->val>p->next->val){
                    sortat=0;//ca si cum dam flagul in jos deoarece am gasit 2 elemente care nu stau in oridine cerscatoare
                    if(p==head){
                        //in cazul in care chiar primul element este pozitionat incorect si trebuie schimbat avem caz aparate
                        head=p->next;
                        p->next=head->next;
                        head->next=p;
                        //schimbam cu locul 1 si al 2 apoi trecem mai departe ca sa nu stam iar pe cazul acesta
                        prev=p;
                        p=p->next;
                    }else
                    {
                    prev->next=p->next;//trecem precedentul peste nodul actual 
                    p->next=p->next->next;
                    prev->next->next=p;//nodul mai mare arata catre nodul mai mic
                    prev=prev->next;
                    }
                }else{
                    //in caz ca totul este in regula si nodurile sunt pozitionate corect mergem mai departe 
                    prev=p;
                    p=p->next;
                }       
        }
        
    }while(sortat==0);//in caz ca sortat este 1 ciclul while se opreste in caz ca nu inseamna ca am gasit elemente care ereau pozitionate incorect si mai verificam inca o data
    return aux;
}




int main(){

    struct ListNode *head=NULL,*p=NULL,*prev=NULL;
    //crearea unei liste simplu inaltuite
    for(int i=0;i<10;i++){
        p=(struct ListNode*)malloc(sizeof(struct ListNode));
        scanf("%d ",&p->val);
        p->next=head;
        head=p;
    }
    p=head;
    //prindarea listei inainte de sortarer
    while(head!=NULL){
        printf("%d ",head->val);
        head=head->next;
    }
    printf("\n");
    head=p;
    //apelarea functiei
    head=sortList(head);
    //printf("gata");
    //printarea listei sortate
    while(head!=NULL){
        printf("%d ",head->val);

        head=head->next;
        }

    return 0;
}