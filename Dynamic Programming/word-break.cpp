/* use trie if dictContains works too slowly*/

#define UNKNOWN -1

vector<int> table;

bool dictContains(const vector<string> &dict, const string &query){
	for(string word : dict){
		if(word == query) 	return true;
	}
	return false;
}

bool _wordBreak(const string &G, const vector<string> &dict, int start){
	if(start == G.length()) 	return 1;
	if(table[start] != UNKNOWN) 	return table[start];
	string sub;
	for(int i=start ; i<G.length() ; ++i){
		sub.push_back(G[i]);
		if(dictContains(dict, sub) and _wordBreak(G, dict, i+1)){
			return table[start] = 1;
		}
	}
	return table[start] = 0;
}

int Solution::wordBreak(string G, vector<string> &dict) {
	table = vector<int>(G.size(), UNKNOWN);
	return _wordBreak(G, dict, 0);
}
