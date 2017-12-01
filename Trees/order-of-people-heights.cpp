struct tn{
    int hgt, fnl, sol;
    tn *rite, *left;
    tn(int final, int height){
        hgt = height;
        fnl = final;
        sol = 0;
        rite = left = NULL;
    }
};

tn* insert(tn *root, tn *cur){
    if(!root) 	return root = cur;
	if(cur->fnl > root->sol){
		cur->fnl -= root->sol + 1;
		root->rite = insert(root->rite, cur); 
	}
	else{
		root->sol++;
		root->left = insert(root->left, cur);
	}
	return root;    
}

void fillzie(tn *root, vector<int> &buffer){
	if(!root)	return;
	fillzie(root->left, buffer);
	buffer.push_back(root->hgt);
	fillzie(root->rite, buffer);
}


vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {
    vector<int> res;
    vector< pair<int , int> > sortie;
    // populate sortie.
    int size = heights.size();
    for(int i=0 ; i<size ; ++i){
        int fi = -heights[i];
        int se = infronts[i];
        sortie.push_back(make_pair(fi, se));
    }
    sort(sortie.begin(), sortie.end());
    // form the tree.
    tn *root = NULL;
    for(int i=0 ; i<size ; ++i)
        root = insert(root, new tn(sortie[i].second, -sortie[i].first));
    // traverse the tree(inorder).
    fillzie(root, res);

    return res;
}