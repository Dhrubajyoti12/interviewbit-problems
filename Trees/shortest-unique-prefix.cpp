#include <iostream>
#define ALFABE_SIZE 52

using vs = vector<string>;

int getindex(char q){
	if(q>'Z') 	return q-'a'+26;
	return q-'A';
}

class yumi{
  public:
    yumi *next[ALFABE_SIZE];
    int count;
  	yumi(){
  		count = 0;
  		for(int i=0 ; i<ALFABE_SIZE ; ++i)
  			next[i] = NULL;
  	}
};

class trie{
  private:
    yumi* _root;

  	yumi* insert(yumi* root, const string &key, int ind){
  		if(!root) 	root = new yumi();
  		if(ind == key.size() ) 	 return root;
  		root->next[getindex(key[ind])] = 
  		insert(root->next[getindex(key[ind])], key, ind+1);
  		root->count++;
  		return root;
  	}

  	void solve(yumi* root, const string &key, int ind, string &buffer){
  		if( (root->count < 2) ) 	return;
  		buffer.push_back(key[ind]);
  		
  		solve(root->next[getindex(key[ind])], key, ind+1, buffer);
  	}

  public:
  	void insert(const string &key){
  		_root = insert(_root, key, 0);
  	}
  	string solve(const string &key){
  		string res;
  		solve(_root, key, 0, res);
  		return res;
  	}
  	trie() {
  		_root = NULL;
  	}
    
};

vector<string> Solution::prefix(vector<string> &A) {
    vs res;
    trie t;
    
    for(auto s : A)  t.insert(s);
    for(auto s : A)  res.push_back(t.solve(s));
    
    return res;
}
