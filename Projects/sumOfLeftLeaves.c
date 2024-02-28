#include <stdio.h>

 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

int sumOfLeftLeaves(struct TreeNode* root){

}

int main(){
    TreeNode t,t1,t2,t3,t4;
    t.val=3;
    t1.val=9;
    t2.val=20;
    t3.val=15;
    t4.val=7;

    t.left=&t1;
    t2.left=&t3;
    t2.right=&t4;

    sumOfLeftLeaves(t);





    return 0;
}