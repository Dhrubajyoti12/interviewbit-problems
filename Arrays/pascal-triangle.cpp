vector<vector<int> > Solution::generate(int N) {
    vector< vector<int> > res;
    vector<int> dummy;
    
    if(!N) return res;
    dummy.push_back(1);     --N;
    res.push_back(dummy);
    if(!N)  return  res;
    
    for(int i=0 ; i<N ; ++i){
        vector<int> bummy;
        bummy.push_back(1);
        for(int j=0 ; j<i ; ++j){
            bummy.push_back(res[i][j]+res[i][j+1]);
        }
        bummy.push_back(1);
        res.push_back(bummy);
    }
    
    
    return res;
}
