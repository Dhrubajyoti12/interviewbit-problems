using tn = TreeNode;
using mrk = unsigned long long int;
#define PUJLA 10000000000000001
#define NOPUJ 20000000000000002
#define pb push_back
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::inorderTraversal(TreeNode* root){
    stack<tn*> S;
    stack<mrk> Y;// puj ka nopuj
    vector<int> res;
    
    S.push(root);
    Y.push(PUJLA);
    while(S.size()){
        tn* cur = S.top();  S.pop();
        mrk cma = Y.top();  Y.pop();//current mark
        //rite'i markliyoruz
        if(cma == PUJLA){
            if(cur->right)   Y.push(PUJLA), S.push(cur->right);
            S.push(cur);    Y.push(NOPUJ);
            if(cur->left)    Y.push(PUJLA), S.push(cur->left);
            
        }
        if(cma == NOPUJ)     res.pb(cur->val);
    }
    return res;
}