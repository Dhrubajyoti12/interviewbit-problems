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

bool check(tn* p, tn* q){
    if(!(p and q))  return !p and !q;
    
    return  p->val == q->val     and
        check(p->right, q->left) and
        check(p->left,  q->right);
}
 
int Solution::isSymmetric(TreeNode* root) {
    return check(root, root);
}
