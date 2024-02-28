#include <stdio.h>
#include <stdlib.h>
//asta ar fi un comentariu pentru idee test si atat 
struct tree{
    int val;
    struct tree *left;
    struct tree *right;
};

int deep(struct tree *p){
    if(p->left==NULL && p->right==NULL)return 0;
        else{
            if(p->left!=NULL && p->right==NULL)return 1+deep(p->left);
            else
            if(p->left==NULL && p->right!=NULL)return 1+deep(p->right);
            else
            {
                return (deep(p->left)>deep(p->right))?1+deep(p->left):1+deep(p->right);
            }
        }
}

void parcurge_postordine(struct tree *p){
    if(p!=NULL){
        parcurge_postordine(p->left);
        parcurge_postordine(p->right);
        printf("%d ",p->val);
    }
}

void parcurge_inordine(struct tree *p){
    if(p!=NULL){
        parcurge_inordine(p->left);
        printf("%d ",p->val);
        parcurge_inordine(p->right);
    }
}

void parcurge_preordine(struct tree *p){
    if(p!=NULL){
        printf("%d ",p->val);
        parcurge_preordine(p->left);
        parcurge_preordine(p->right);
    }
}

struct tree* create_tree(){

    static int ok=0;
    static struct tree *p=NULL;
        int x;
        struct tree *root=(struct tree*)malloc(sizeof(struct tree));
            root->left=NULL;
            root->right=NULL;
        if(ok==0)p=root;

        ok++;
        printf("val:");
        scanf("%d",&root->val);
        

    

            printf("does %d have left?",root->val);
            scanf("%d",&x);
            if(x==1){
                root->left=create_tree();
            }else root->left=NULL;
       
            printf("does %d have right?",root->val);
            scanf("%d",&x);
            if(x==1){
                root->right=create_tree();
            }else root->right=NULL;
        
        

        return root;
    

    




}

int main(){

    int n;
    char opt;
    struct tree *p=create_tree();

    printf("\n");
    printf("\n");
    printf("Preordine: ");
    parcurge_preordine(p);
    printf("\nInordine: ");
    parcurge_inordine(p);
    printf("\nPostordine: ");
    parcurge_postordine(p);


    printf("\nInaltimea arboorelui:%d\n",deep(p));






    return 0;
}