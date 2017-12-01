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
bool check(tn* root, int target){
    if(!(root->left) and !(root->right))    return target == root->val;
   
    bool sol=false, sag=false;
    if(root->left)  sol=check(root->left,  target - root->val);
    if(root->right) sag=check(root->right, target - root->val);
   
    return sol or sag;
}
int Solution::hasPathSum(TreeNode* root, int target) {
    if(!root)   return 0;
    return check(root, target);
    
}
