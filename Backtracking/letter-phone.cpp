#define pb push_back
using vesi = vector<string>;
//                   0    1     2      3      4
string TABLE[10] = {"0", "1", "abc", "def", "ghi", 
                    //5      6      7       8      9
                    "jkl", "mno", "pqrs", "tuv", "wxyz"};

void solve(const string &seq, int ind, int size, string &res, vesi &snc){
	// push whatever we have & return;
	if(ind==size){snc.pb(res);return;}
	
	int table_size = TABLE[seq[ind]-48].size();
	for(int i=0 ; i<table_size ; ++i){
		res.pb(TABLE[seq[ind]-48][i]);
		solve(seq, ind+1, size, res, snc);
		res.pop_back();
	}
}
// void write(vesi snc){
// 	for(int i=0 ; i<snc.size() ; ++i)
// 		cout<<snc[i]<<endl;
// }
vector<string> Solution::letterCombinations(string seq) {
    vesi snc;
    string res;
    solve(seq, 0, seq.size(), res, snc);
    //write(snc);
    return snc;
}