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

int Solution::kthsmallest(TreeNode* root, int k) {
    tn *top, *dummy=root;
    stack<tn*> S;   S.push(dummy);
    
    while(dummy->left){
        dummy = dummy->left;
        S.push(dummy);
    }
    dummy = top = NULL;
    while(k--){
        top = S.top();  S.pop();
        dummy =  top;
        if(dummy->right){
            dummy = dummy->right;
            S.push(dummy);
            while(dummy->left){
                dummy = dummy->left;    
                S.push(dummy);
            }
                
        }
        
    }
    
    return top->val;
    
}
