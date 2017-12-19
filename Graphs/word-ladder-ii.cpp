#include <bits/stdc++.h>
using namespace std;

#define UNKNOWN -1
using vvs = vector< vector<string> >;
using vs = vector<string>;

struct e{
	string w; // word
	int d; //distance
	vector<e*> parents;
	e(string _w, int _d): w(_w), d(_d) {}

};

bool neighbor(const string &q, const string &p){
	int diff=0, size=q.size();
	for(int i=0 ; i<size ; ++i){
		if(q[i] != p[i]) 	++diff;
	}

	return diff == 1;
}

void collect_paths(vvs &res, vs &buffer, const e* start , const e* end){
	// base case
	if(start == end){
		vs temp = buffer;
		reverse(temp.begin(), temp.end());
		res.push_back(temp);
		return;
	}

	for(const e* parent : end->parents){
		buffer.push_back(parent->w);
		collect_paths(res, buffer, start, parent);
		buffer.pop_back();
	}
}
/*
    --> qwe --> nbr 
end 	 	       --> start
	--> asd --> idr
*/
// add Solution::
vvs findLadders(string start, string end, vector<string> &dict){
	// fill the map
	unordered_map<string, e*> mark;
	for(const string &word : dict){
		if(mark.find(word) == mark.end()){
			mark[word] = new e{word, UNKNOWN}; 
		}
	}

	queue<e*> Q;
	e* cur = mark[start];
	cur->d = 0;
	Q.push(cur);

	while(Q.size()){
		e* fro = Q.front(); 	Q.pop(); //<<--- notice
		for(auto it = mark.begin() ; it!=mark.end() ; ++it){
			e* cur = it->second;//mark[word];
			if(neighbor(fro->w, it->first)){
				// not visited
				if(cur->d == UNKNOWN){
					cur->d = fro->d+1;
					cur->parents.push_back(fro);
					Q.push(cur);
				}
				// visited, but theres another shortest path
				else if(cur->d == fro->d + 1){
					cur->parents.push_back(fro);
				}
			}
		}
	}

	vvs res; 	
	vs buffer; 	buffer.push_back(mark[end]->w);
	collect_paths(res, buffer, mark[start] , mark[end]);
	return res;
}

void printVvs(const vvs &sols){
	for(const vs &path : sols){
		for(const string &word : path) 	cout<<word<<" ";
		cout<<endl;
	}
	cout <<endl;
}

int main(){
	vs dict = {"baba", "abba", "aaba", "bbbb", "abaa", "abab",
			   "aaab", "abba", "abba", "abba", "bbba", "aaab",
			   "abaa", "baba", "baaa", "bbaa", "babb"};
	string start = "bbaa", end = "babb";
	vvs out = findLadders(start, end, dict);
	printVvs(out);

	return 0;
}