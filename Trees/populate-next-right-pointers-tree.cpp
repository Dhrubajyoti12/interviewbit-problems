/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
//kalmamis bu gozde yas, gonulde kaygi.
using tn = TreeLinkNode;
// pnin sagina gecip en soldaki alt seyi alicaz.
tn* go_fetch_next(tn* p){
    tn* getzie = p->next;
    while(getzie){
        if(getzie->left)    return getzie->left;
        if(getzie->right)   return getzie->right;
        getzie = getzie->next;
    }
    return NULL;
}


void Solution::connect(TreeLinkNode* root) {
    if(!root)   return;
    
    root->next = NULL;
    tn *ust = root, *alt;
    while(ust){
        alt = ust;
        while(alt){
            if(alt->left){
                // has both childs
                if(alt->right)  alt->left->next = alt->right;
                // get the thingy.
                else            alt->left->next = go_fetch_next(alt);
            }
            if(alt->right)
                alt->right->next = go_fetch_next(alt);
            alt = alt->next;
        }
        /*!*/if(ust->left)      ust = ust->left;
        else if(ust->right)     ust = ust->right;
        else /*nxt line en sol*/ust = ust->next;
    }
    
}
