using tn = TreeNode;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* root) {
    stack<tn*> S;
    vector<int> res;
    
    S.push(root);
    while(S.size()){
        tn* cur = S.top();  S.pop();
        res.push_back(cur->val);
        if(cur->right)   S.push(cur->right);
        if(cur->left)    S.push(cur->left);
    }
    return res;
}
