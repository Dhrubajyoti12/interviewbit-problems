/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// nkarecozum :(
// AMA GECTI EHUEUHEHU
using tn = TreeNode;

int depth(tn* root){
    if(!root)   return 0;
    return max(depth(root->left), depth(root->right)) + 1;
}

bool balans(tn* root){
    if(!root)   return true;
    return balans(root->right)   and 
           balans(root->left)    and 
    abs(depth(root->right) - depth(root->left)) < 2;
}

int Solution::isBalanced(TreeNode* root) {
    return balans(root);
}
