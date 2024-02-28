#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};


d

struct TreeNode* create_tree(){
    static int ok=0;
    static struct TreeNode *p=NULL;
        int x;
        struct TreeNode *root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
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
    struct TreeNode *p=create_tree(),*q=create_tree();
    printf("%d",isSameTree(p,q));






    return 0;
}