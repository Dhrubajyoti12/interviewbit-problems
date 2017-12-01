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

tn* revtree(tn* root){
    if(!root)   return NULL;
    tn* temp = root->left;
    root->left = revtree(root->right);
    root->right = revtree(temp);
    return root;
}

TreeNode* Solution::invertTree(TreeNode* root) {
    return revtree(root);
}
