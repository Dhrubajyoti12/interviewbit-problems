vector<vector<int> > Solution::diagonal(vector<vector<int> > &matrix) {
    int n = matrix.size();
    vector< vector<int> > res;    
    
    for(int t=0,i,j ; t<n ; ++t){
        i=0, j=t;
        vector<int> diag;
        for(int s=0 ; s<=t ; ++s){
            diag.push_back(matrix[i+s][j-s]);
        }
        res.push_back(diag);
    }   
        
    for(int t=1,j,i ; t<n ; ++t){
        i=t, j=n-1;
        vector<int> diag;
        for(int s=0 ; s<n-t ; ++s){
            diag.push_back(matrix[i+s][j-s]);
        }
        res.push_back(diag);
    }
    
    return res;
}
