#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node{
    int val;
    struct node *left, *right;
};

typedef struct node node;

node* creeazaNode(int val){
    node *temp=(node*)malloc(sizeof(node));
    temp->val=val;
    temp->left=temp->right=NULL;
    return temp;
}

node* adaugaNode(node* root, int temp){
    if(root==NULL)return creeazaNode(temp);
    if(temp<root->val){
        root->left=adaugaNode(root->left,temp);
    }
    if(temp>=root->val){
        root->right=adaugaNode(root->right,temp);
    }
    return root;
}

void afisTree(node *root){
    if(root==NULL)return;
    printf("%d, ",root->val);
    afisTree(root->left);
    afisTree(root->right);
}

int max(int a, int b){
    return (a>b)?a:b;
}

int height(node *root){
    if(root==NULL)return -1;
    return max(height(root->left),height(root->right))+1;
}

int balansatAVL(node* root){
    if(root==NULL)return 1;
    return balansatAVL(root->right) && balansatAVL(root->left) && (abs(height(root->left)-height(root->right))<=1);
}

node* min(node* a,node* b){
    if(a!=NULL && b!=NULL)
        return (a->val<b->val)?a:b;
    if(a==NULL)return b;
    if(b==NULL)return a;
    return creeazaNode(INT_MAX);
}

node* findMinNode(node *root){
    if(root!=NULL)
        return min(root,min(findMinNode(root->left),findMinNode(root->right)));
    return creeazaNode(INT_MAX);
}

int ord(node* root, int minim, int maxim){
    if(root==NULL)return 1;
    if(root->val<=maxim && root->val>=minim)
        return ord(root->right, root->val, maxim) && ord(root->left,minim,root->val);

    return 0;
}

int ordonatTree(node* root){
    return ord(root,-INT_MAX+1,INT_MAX);
}

node* stergeNode(node *root, node* nod){
    if(nod!=NULL){
        node temp;
        if(nod->left==NULL && nod->right==NULL){
            free(nod);
        }
        else
        if(nod->left==NULL){
            temp=*(nod->right);
            free(nod->right);
            *nod=temp;
        }
        else
        if(nod->right==NULL){
            temp=*(nod->left);
            free(nod->left);
            *nod=temp;
        }
        else
        {
            node* mi=findMinNode(nod->right);
            temp= *mi;
            free(mi);
            nod->val=temp.val;
           printf("minval %d   nod val %d",mi->val,nod->val);
        }
    }
    return root;
}

int main()
{
    node *root;
    int n,temp;
    scanf("%d",&temp);
    while(temp!=0){

        root=adaugaNode(root,temp);
        scanf("%d, ",&temp);
    }
    afisTree(root);
    printf("\n");
    //root=stergeNode(root,root);
    afisTree(root);
    printf("\nInaltimea: %d",height(root));
    printf("\nBalansat AVL: %d",balansatAVL(root));
    printf("\nOrdonat: %d",ordonatTree(root));


    return 0;
}
/*

: 12, -7,
45, 32, 2, 22, 1, 2, 3, 4, 9, 90, 89, 225, 0

*/
