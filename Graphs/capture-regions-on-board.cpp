

#define N_MOVES 4

using vvc = vector< vector<char> >;
using vvi = vector< vector<int> >;
using vi = vector<int>;

int I, J;
vvi mark;

const int dY[N_MOVES] = {+1, 0, -1, 0};
const int dI[N_MOVES] = {0, +1, 0, -1};

bool edge(const int i, const int j){
	return i==0 or j==0
		or i==I-1 or j==J-1;
}

// doesnt check mark.
bool legit(const vvc &grid, const int i, const int j){
	return i>=0 and j>=0
		and i<I and j<J
		and grid[i][j] == 'O';
}

void flip(vvc &grid, const int i, const int j){
	mark[i][j] = 2;
	for(int m=0 ; m<N_MOVES ; ++m){
		int nexti = i+dI[m];
		int nextj = j+dY[m];
		if(legit(grid, nexti, nextj) and mark[nexti][nextj]!=2){
			flip(grid, nexti, nextj);
		}
	}

	grid[i][j] = 'X';
}

bool capture(const vvc &grid, const int i, const int j){
	mark[i][j] = 1;
	bool gucci = true;
	for(int m=0 ; m<N_MOVES ; ++m){
		int nexti = i+dI[m];
		int nextj = j+dY[m];
		if(legit(grid, nexti, nextj) and !mark[nexti][nextj]){
			gucci &= capture(grid, nexti, nextj);
		}
	}
	// not edge and neither is every other branch.
	return !edge(i, j) and gucci;	
}


void Solution::solve(vector<vector<char> > &grid) {
	if(!(grid.size())) 	return;

	I = grid.size(), J = grid[0].size();
	mark = vvi(I, vi(J, 0));
	for(int i=0 ; i<I ; ++i){
		for(int j=0 ; j<J ; ++j){
			if(!mark[i][j] and grid[i][j]=='O' and capture(grid, i, j)){
				flip(grid, i, j);		
			}
		}
	}
}
