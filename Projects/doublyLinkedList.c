#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
    struct node *prev;
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

    //parcurgerea de la cap pana la coada 
    //avem o variabila p care la sfarsit va fi NULL asa ca o jetvim pentru parcurege apoi o sa trebuiasca sa ii atribuim ceva 
    p=head;
    while(p!=NULL){

        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");

    //parcurgerea de la coada la cap folosing p->prev pentru a trece la precedentul 
    //am atribuit lui p pe tail deoarece este ca un puct de start
    p=tail;
    while(p!=NULL){
    printf("%d ",p->val);

        p=p->prev;
    }



    return 0;
}