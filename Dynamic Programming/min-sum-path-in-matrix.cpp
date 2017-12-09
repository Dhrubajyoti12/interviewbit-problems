inline bool lejit(int i, int j, int I, int J){
    return i<I and i>-1
      and  j<J and j>-1;
}

int Solution::minPathSum(vector<vector<int> > &mat) {
    int I = mat.size();
    int J = mat[0].size();
    for(int i=0 ; i<I ; ++i){
        for(int adj, j=0 ; j<J ; ++j){
            // determine adjacent.
            if(!lejit(i-1, j, I, J) and !lejit(i, j-1, I, J))   adj = 0;
            else if(!lejit(i-1, j, I, J))   adj = mat[i][j-1];
            else if(!lejit(i, j-1, I, J))   adj = mat[i-1][j];
            else                            adj = min(mat[i-1][j], mat[i][j-1]);
            mat[i][j] += adj;
        }
    }
    return mat[I-1][J-1];
}
