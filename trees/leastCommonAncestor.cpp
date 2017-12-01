#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *rite;
    TreeNode(int x) : val(x), left(NULL), rite(NULL) {}
};

using tn = TreeNode;

tn *root;

bool findpath(tn const *root, int val, string &path){
    if(!root)   return false;
    if(root->val == val)     return true;
    // check left
    path.push_back('l');
    if(findpath(root->left, val, path))    return true;   
    path.pop_back();

    // check right
    path.push_back('r');
    if(findpath(root->rite, val, path))   return true;
    path.pop_back();
    
    return false;
}

void init_tree(){
	// root
	root = new tn(3);
	// second row
	root->left = new tn(5);
	root->rite = new tn(1);
	// third row
	root->left->left = new tn(6);
	root->left->rite = new tn(2);
	root->rite->left = new tn(0);
	root->rite->rite = new tn(8);
	// fourth row
	root->left->rite->left = new tn(7);
	root->left->rite->rite = new tn(4);
}


int main(void){
	init_tree();

	string p; int q; while(cin >> q) {p=""; cout<<"fp: "<<findpath(root, q, p)<<" "<<p<<endl;}	
	return 0;
}