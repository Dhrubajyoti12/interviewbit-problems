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

tn* solve(const vector<int> &arr, int left, int rite){
    if(left > rite)  return NULL;
    int mid = (left + rite) / 2;
    tn* root = new tn(arr[mid]);
    root->left = solve(arr, left, mid - 1);
    root->right = solve(arr, mid + 1, rite);
    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return solve(A, 0, A.size()-1);
}
