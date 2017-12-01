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
using vi = vector<int>;
using matrix = vector< vi >;

bool leaf(tn* node){
    return !(node->left) and !(node->right);
}

void solve(tn* root, vi &path, matrix &res, int target){
    if(!root)   return;
    target -= root->val;
    
    path.pb(root->val);{ // kill urself if you forget to pop
        // record ze solushonn
        if(leaf(root) and !target)  res.pb(path);
        solve(root->right, path, res, target);
        solve(root->left , path, res, target);
    }
    path.pop_back();//i no forgetz. neither does pepperidge farm.
    
}
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    matrix res;     vi path;
    if(!root)   return res;
    solve(root, path, res, sum);
    return res;
}
