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
stack<tn*> *S; 

BSTIterator::BSTIterator(TreeNode *root) {
    S = new stack<tn*>();
    tn * dummy = root;
    while(dummy){
        S->push(dummy);
        dummy = dummy->left;
    }
    
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return S->size() > 0;
}

/** @return the next smallest number */
int BSTIterator::next() {
    int res = S->top()->val;
    
    // push the next min;
    tn* min = S->top();  S->pop();
    if(min->right){
        min = min->right;
        while(min){
            S->push(min);
            min = min->left;
        }
    }
    
    return res;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
