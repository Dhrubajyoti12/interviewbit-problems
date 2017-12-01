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

bool findpath(tn const *root, int val, string &path){
    if(!root)   return false;
    if(root->val == val)     return true;
    // check left
    path.push_back('l');
    if(findpath(root->left, val, path))    return true;   
    path.pop_back();

    // check right
    path.push_back('r');
    if(findpath(root->right, val, path))   return true;
    path.pop_back();
    
    return false;
}
int Solution::lca(TreeNode* root, int val1, int val2) {
    string p1, p2;
    if( !(findpath(root, val1, p1) and findpath(root, val2, p2)) )  return -1;
    tn* it = root;  int ind=0, len = min(p1.size(), p2.size());
    while(ind < len and (p1[ind] == p2[ind]) ){
        if(p1[ind] == 'l')  it = it->left;
        else                it = it->right;
        ind++;
    }
    return it->val;
}
