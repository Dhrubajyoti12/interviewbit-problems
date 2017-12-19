#include <bits/stdc++.h>
using namespace std;

#define NOT_VISITED -1
using vvi = vector< vector<int> >;
using vi = vector<int>;

int N, M;
vvi MARK;

struct e{
	int i,j;
	e(int _i, int _j): i(_i), j(_j) {}
};

bool legit(int i, int j){
	return  i>0 and j>0
		and i<=N and j<=M
		and MARK[i][j] == NOT_VISITED;
}

void initMark(){
	MARK = vvi(N + 1, vi(M + 1));
	for(int i=0 ; i<=N ; ++i) {
		for(int j=0 ; j<=M ; ++j)
			MARK[i][j] = NOT_VISITED;
	}
}

// add Solution::
int knight(int n, int m, int is, int js, int ie, int je) {
	N = n, M = m; // init the global variables.
	initMark();

	queue<e> Q;	
	Q.push(e{is, js}); 	MARK[is][js]=0;// <<<--- notice
	
	while(Q.size()){
		e fro = Q.front(); 	Q.pop(); // <<<--- notice
		int i = fro.i, j = fro.j;
		
		// up & left block
		if(legit(i-2, j-1)) {
			MARK[i-2][j-1] = MARK[i][j]+1;
			Q.push(e{i-2,j-1});
		}
		if(legit(i-1, j-2)) {
			MARK[i-1][j-2] = MARK[i][j]+1;
			Q.push(e{i-1, j-2});
		}

		// up & right block
		if(legit(i-2, j+1)) {
			MARK[i-2][j+1] = MARK[i][j]+1;
			Q.push(e{i-2,j+1});
		}
		if(legit(i-1, j+2)) {
			MARK[i-1][j+2] = MARK[i][j]+1;
			Q.push(e{i-1, j+2});
		}

		// down & right block
		if(legit(i+2, j+1)) {
			MARK[i+2][j+1] = MARK[i][j]+1;
			Q.push(e{i+2,j+1});
		}
		if(legit(i+1, j+2)) {
			MARK[i+1][j+2] = MARK[i][j]+1;
			Q.push(e{i+1, j+2});
		}

		// down & left block
		if(legit(i+2, j-1)) {
			MARK[i+2][j-1] = MARK[i][j]+1;
			Q.push(e{i+2,j-1});
		}
		if(legit(i+1, j-2)) {
			MARK[i+1][j-2] = MARK[i][j]+1;
			Q.push(e{i+1, j-2});
		}
	}

	return MARK[ie][je];
}

int main() {

	return 0;	
}