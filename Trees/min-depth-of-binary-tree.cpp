/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define REALLY_REALLY_HUGE_NUMBER 1000000001

using tn = TreeNode;
int gen_min(tn* root, int curdep){
    if(!(root->left) and !(root->right)) return curdep;
   
    int sol=REALLY_REALLY_HUGE_NUMBER, sag=REALLY_REALLY_HUGE_NUMBER;
    if(root->left)  sol=gen_min(root->left,  curdep + 1);
    if(root->right) sag=gen_min(root->right, curdep + 1);
   
    return min(sol, sag);
}

int Solution::minDepth(TreeNode* root) {
    //input checkzie, donzie hueuheuhe;
    if(!root)   return 0;
    
    return gen_min(root, 1);
}
