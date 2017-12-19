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
int I[8] = {-2, -1, -2, -1, +2, +1, +2, +1};
int J[8] = {-1, -2, +1, +2, +1, +2, -1, -2};
// add Solution::
int knight(int n, int m, int is, int js, int ie, int je) {
	N = n, M = m; // init the global variables.
	initMark();

	queue<e> Q;	
	Q.push(e{is, js}); 	MARK[is][js]=0;// <<<--- notice
	
	while(Q.size()){
		e fro = Q.front(); 	Q.pop(); // <<<--- notice
		int i = fro.i, j = fro.j;
		for(int m=0 ; m<8 ; ++m){
			if(legit(i+I[m], j+J[m])){
				Q.push(e{i+I[m], j+J[m]});
				MARK[i+I[m]][j+J[m]] = MARK[i][j] + 1;
			}
		}
	}

	return MARK[ie][je];
}

int main() {

	return 0;	
}