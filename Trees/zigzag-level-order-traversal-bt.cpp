/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define pb push_back
using tn = TreeNode;


vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    vector< vector<int> > res;
    if(!root)   return res;
    
    int cde = 0; //current depth
    queue<int> W;           W.push(0);
    queue<tn*> Q;           Q.push(root);
    vector<int> buffer;
    
    while(Q.size()){
        int qde = W.front();    W.pop();//depth of the node that is in front of the Q
        tn* nod = Q.front();    Q.pop();
        if(qde != cde){
            if(cde%2)   reverse(buffer.begin(), buffer.end());
            res.pb(buffer);
            buffer.clear();
            cde = qde;
        }
        buffer.pb(nod->val);
        if(nod->left)    Q.push(nod->left),    W.push(qde+1);     
        if(nod->right)   Q.push(nod->right),   W.push(qde+1);
    }
    if(cde%2)   reverse(buffer.begin(), buffer.end());
    res.pb(buffer);
    
    return res;
}
