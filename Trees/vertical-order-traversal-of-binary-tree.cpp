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

void gen_min_max(tn* root, int &sol, int &sag, int cur){
    if(!root)   return;

    sol = min(sol, cur);
    sag = max(sag, cur);
    gen_min_max(root->left, sol, sag, cur-1);
    gen_min_max(root->right, sol, sag, cur+1);
}

void fill_res(tn* root, vector< vector<int> > &res, int ind){
    queue<tn*> Q;
    queue<int> W;
    Q.push(root);   W.push(ind);
    
    while(Q.size()){
        tn* curv = Q.front();   Q.pop();
        int curi = W.front();   W.pop();
        res[curi].push_back(curv->val);
        
        if(curv->left)   Q.push(curv->left),   W.push(curi-1);
        if(curv->right)  Q.push(curv->right),  W.push(curi+1);
    }
    
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root){
    if(!root)   return vector<vector<int> >();
    int sol=0, sag=0;
    gen_min_max(root, sol, sag, 0);
    vector< vector<int> > res(sag-sol+1, vector<int>());
    fill_res(root, res, -sol);
    return res;
}