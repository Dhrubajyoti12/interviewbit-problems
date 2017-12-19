/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using vvi = vector< vector<int> >;
using vi = vector<int>;
using tn = TreeNode;

struct e{
    int depth;
    tn* node;
};

int getDepth(tn *root){
    if(!root)   return 0;
    int left = getDepth(root->left);
    int rite = getDepth(root->right);
    return max(left, rite) + 1;
}
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    if(!A)  return vvi();
    
    int d = getDepth(A);
    vvi res(d, vi());
    
    queue<e> Q;
    Q.push(e{0, A});
    while(Q.size()){
        e top = Q.front();    Q.pop(); //<<<notice
        res[top.depth].push_back(top.node->val);
        
        if(top.node->left)    Q.push(e{top.depth + 1, top.node->left});
        if(top.node->right)    Q.push(e{top.depth + 1, top.node->right});
        
    }
    
    return res;
}
