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

void gen_max(tn* root, int &maxd, int cur){
    if(!root)   return;
    maxd = max(maxd, cur);
    gen_max(root->left,  maxd, cur+1);
    gen_max(root->right, maxd, cur+1);
}
int Solution::maxDepth(TreeNode* root) {
    int res=0;
    gen_max(root, res, 1);
    return res;
}
