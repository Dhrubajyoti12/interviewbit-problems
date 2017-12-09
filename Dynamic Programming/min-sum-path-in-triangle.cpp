int Solution::minimumTotal(vector<vector<int> > &A) {
    int N = A.size();
    vector<int> temp = A[N-1];
    for(int i=N-2 ; i>-1 ; --i){
    	for(int j=0 ; j<i ; ++j){
   			temp[i][j] = min(temp[i][j], temp[i][j+1]) + A[i][j]; 		
    	}
    }
    return temp[0];
}
