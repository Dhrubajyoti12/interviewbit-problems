#include <bits/stdc++.h>
using namespace std;

#define NMOVES 4
using vs = vector<string>;

int N, M; // N rows, M cols

// moves
int i_diff[4] = { 0,  0, +1, -1};
int j_diff[4] = {+1, -1,  0,  0};

bool legit(const vs &grid, const int i, const int j){
	return i>=0 and j>=0
		and i<N and j<M;
}

bool find(const vs &grid, const string &word, 
		  const int depth, const int i, const int j){
	// base case: WE FOUND AN UNMATCHING CHAR
	if(word[depth] != grid[i][j])	return false;
	// base case: WE GOT IT
	if(depth == word.size()-1) 	return true;

	bool found = false;
	for(int m=0 ; m<NMOVES ; ++m){
		int ni = i + i_diff[m];
		int nj = j + j_diff[m];
		if(legit(grid, ni, nj)){
			found = found or find(grid, word, depth+1, ni, nj);
		}
	}
	return found;
}

// add Solution::
int exist(vector<string> &grid, string word) {
	// corner case
	if(!grid.size()) 	return 0;
	// init N and M for an easy lyfe.
	N = grid.size(), M = grid[0].size();

	for(int i=0 ; i<N ; ++i){
		for(int j=0 ; j<M ; ++j){
			if(find(grid, word, 0, i, j))
				return 1;
		}
	}

	return 0;
}

int main(){
	string word;
	vs board = {"ABCE", "SFCS", "ADEE"};
	while(1){
		cin >> word;
		cout << exist(board, word) << "\t\t";
	}
	return 0;
}