/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define MOD 1003
using tn = TreeNode;


int Solution::sumNumbers(TreeNode* root) {
    if(!root)   return 0;
    int res=0;
    queue<tn*> Q;
    Q.push(root);
    
    while(Q.size()){
        tn* cur = Q.front();    Q.pop();
        //if our current node is a leaf
        if(!(cur->right) and !(cur->left))  res = (res + (cur->val))%MOD;  
        if(cur->right){
            cur->right->val = (cur->val*10 + cur->right->val)%MOD;
            Q.push(cur->right);
        }
        if(cur->left){
            cur->left->val = (cur->val*10 + cur->left->val)%MOD;
            Q.push(cur->left);
        }
    }
    return res;
}