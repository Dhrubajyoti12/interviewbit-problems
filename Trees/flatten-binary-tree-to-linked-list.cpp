/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using tn = TreeNode;

tn* lastof(tn* root){
    if(!root)   return NULL;
    while(root->right)  root = root->right;
    return root;
}

tn* flatz(tn* root){
    if(!(root->left) and !(root->right))   return root;

    if(root->right)         flatz(root->right);
    if(root->left){
        root->left = flatz(root->left);
        lastof(root->left)->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
    
    return root;
}


TreeNode* Solution::flatten(TreeNode* root){
    return flatz(root);
    
}