void Solution::setZeroes(vector<vector<int> > &mat) {
    int h=mat.size(), w=mat[0].size();
    if(!h or !w)  return;
    
    for(int i=0,hepyek; i<h ; ++i){
        hepyek = 1;//all ones
        for(int j=0 ; j<w ; ++j)    hepyek &= mat[i][j];
        
        if(!hepyek)//set the whole row to zeroes if !hepyek.
            for(int j=0 ; j<w ; ++j)
                mat[i][j] = min(mat[i][j], -mat[i][j]);
    }
    
    for(int i=0,hepyek; i<w ; ++i){
        hepyek = 1;//all ones
        for(int j=0 ; j<h ; ++j)    hepyek &= mat[j][i];
        
        if(!hepyek)//set the whole row to zeroes if !hepyek.
            for(int j=0 ; j<h ; ++j)
                mat[j][i] = min(mat[j][i], -mat[j][i]);
    }
    
    //turn all -1s to 0s
    for(int i=0 ; i<h ; ++i)
        for(int j=0 ; j<w ; ++j)
            mat[i][j] = max(0, mat[i][j]);     
}
