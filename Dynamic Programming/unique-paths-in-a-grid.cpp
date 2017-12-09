int Solution::uniquePathsWithObstacles(vector<vector<int> > &grid) {
    // init sizes;
    int I = grid.size(); 	
    int J = grid[0].size();
    // init the first row & column.
    vector< vector<int> > sol(I, vector<int>(J,0));
	for(int j=0 ; j<J and !grid[0][j] ; ++j) 	sol[0][j]=1;    
	for(int i=0 ; i<I and !grid[i][0] ; ++i) 	sol[i][0]=1;    

	for(int i=1 ; i<I ; ++i){
		for(int j=1 ; j<J ; ++j){
			if(!grid[i][j]) 	sol[i][j] = sol[i-1][j] + sol[i][j-1];
		}
	}
	return sol[I-1][J-1];
}
