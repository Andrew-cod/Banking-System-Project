#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    node *left,*right;
}node;



int main() {
    node *root;
    root=(node*)malloc(sizeof(node));
    root->val=1;
    root->left=(node*)malloc(sizeof(node));
    root->left->val=2

    return 0;
}
