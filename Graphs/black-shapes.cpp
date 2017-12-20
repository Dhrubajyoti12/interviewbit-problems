#define NMOVES 4
using vs = vector<string>;

bool **mark;
int N, M; // N rows, M cols

//moves
int i_diff[4] = { 0,  0, +1, -1};
int j_diff[4] = {+1, -1,  0,  0};

// doesnt check mark
bool legit(const vs &grid, const int i, const int j){
	return i>=0 and j>=0
		and i<N and j<M
		and grid[i][j] == 'X'; 
}

void solve(const vs &grid, const int i , const int j){

	mark[i][j] = true;
	for(int m=0  ; m<NMOVES ; ++m){
		int ni = i + i_diff[m];
		int nj = j + j_diff[m];
		if(legit(grid, ni, nj) and !mark[ni][nj])
			solve(grid, ni, nj);
	}
}

// add Solution::
int Solution::black(vector<string> &grid) {
	if(!grid.size())	return 0;
	// init N and M
	N = grid.size(), M = grid[0].size();

	// init mark
	mark = new bool*[N];
	for(int i=0 ; i<N ; ++i){
		mark[i] = new bool[M];
		for(int j=0 ; j<M ; ++j)
			mark[i][j] = false;
	}

	// count objects
	int res = 0;
	for(int i=0 ; i<N ; ++i){
		for(int j=0 ; j<M ; ++j){
			if(grid[i][j]=='X' and !mark[i][j]){
				++res;
				solve(grid, i, j);
			}
		}
	}
	return res;
}
