#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#define EMPTY '.'

using vvc = vector< vector<char> >;
using vc = vector<char>;


class strUtilz{
  private:
	const string str;
	int i, size;
  public:
  	char delim;

  	// ----------------------- MEMBER FUNCTIONS -----------------------
  	strUtilz(const string &_str, char _dlm=' '): str(_str) {
  		i = 0;
  		size = str.size();
  		delim = _dlm;
  	}

	string next(){
		string res;
		while(str[i] != delim and i<size){
			res.push_back(str[i]);
			++i;
		}
		++i; // escape delim
		return res; 
	}
	// reads an integer from string
	int nextInt(){
		return stoi(next());
	}

	bool done(){
		return i > size;
	}
};	

vvc solved_grid;

vc getAvailable(const vvc &grid, const int i, const int j){
	bool AVAILABLE[10];
	for(bool* a=AVAILABLE; a<AVAILABLE+10 ; ++a) 	*a=true;

	// check the box
	int boxI = i/3*3, boxJ = j/3*3;
	for(int cur, i=0 ; i<3 ; ++i){
		for(int j=0 ; j<3 ; ++j){
			cur = grid[boxI+i][boxJ+j];
			if(cur != EMPTY) 	AVAILABLE[cur - '0']=false;
		}
	}
	// check the row
	for(int cur, col=0 ; col<9 ; ++col){
		cur = grid[i][col]; 
		if(cur != EMPTY) 	AVAILABLE[cur - '0']=false;
	}

	// check the column
	for(int cur, row=0 ; row<9 ; ++row){
		cur = grid[row][j]; 
		if(cur != EMPTY) 	AVAILABLE[cur - '0']=false;
	}

	vc res;
	for(int i=1 ; i<10 ; ++i){
		if(AVAILABLE[i])	 res.push_back(i+'0');
	}
	return res;
}

bool getNextCell(const vvc &grid, int &i, int &j){
	for(int k=i*9+j ; k<81 ; ++k){
		i = k/9,	j = k%9;
		if(grid[i][j] == EMPTY)
			return true;
	}
	return false;
}

bool _solveSudoku(vvc &grid, int i, int j){
	// bosyer bulduque + grid doluysa donduk.
	if(!getNextCell(grid, i, j)){
		solved_grid = grid;
		return true;
	}

	vc candidates = getAvailable(grid, i, j);
	for(char candidate : candidates){
		grid[i][j] = candidate;
		if(_solveSudoku(grid, i, j))
			return true;
		grid[i][j] = EMPTY;
	}
	return false;
}

void solveSudoku(vector<vector<char> > &A) {
	_solveSudoku(A, 0 , 0);
}

void printVector(vc vec){
	for(char i : vec)	cout<<i<<" ";
	cout<<endl;
}

vvc readInput(){
	vvc grid;
	ifstream oku("sudoku.in");
	string INPUT;
	getline(oku, INPUT);
	
	strUtilz parser(INPUT);

	while(!parser.done()){
		vc row;
		string token = parser.next();
		int i = 0;
		while(token[i]==' ' or token[i]=='[')
			++i;
		while(token[i]!=']')	
			row.push_back(token[i++]);

		grid.push_back(row);
	}
	return grid;
}

void printGrid(const vvc &grid){
	string hori = "|-----------------------|";
	for(int i=0 ; i<9 ; ++i){
		if(i%3 == 0) 	cout<<hori<<endl;
		for(int j=0 ; j<9 ; ++j){
			if(j%3 == 0) 	cout<<"| ";
			cout<<grid[i][j]<<" ";
		}
		cout<<"|\n";
	}
	cout<<hori<<endl<<endl;
}

int main(){
	vvc exampleGrid = readInput();
	printGrid(exampleGrid);
	_solveSudoku(exampleGrid, 0, 0);
	printGrid(solved_grid);
	return 0;
}
// 23:20


/*


|-----------------------|
| 5 3 . | . 7 . | . . . |  
| 6 . . | 1 9 5 | . . . |  
| . 9 8 | . . . | . 6 . | 
|-----------------------|
| 8 . . | . 6 . | . . 3 | 
| 4 . . | 8 . 3 | . . 1 | 
| 7 . . | . 2 . | . . 6 |
|-----------------------| 
| . 6 . | . . . | 2 8 . | 
| . . . | 4 1 9 | . . 5 | 
| . . . | . 8 . | . 7 9 |
|-----------------------| 


*/