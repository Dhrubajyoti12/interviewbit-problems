#define pb push_back

vector<vector<int> > getSets(vector<int> &A, int ind, int size){
    if(ind == size)     return vector<vector<int> >(1, vector<int>());
    vector<vector<int> > res = getSets(A, ind+1, size);
    int rsize = res.size();
    for(int i=0 ; i<rsize ; ++i){
        vector<int> dummy(1,A[ind]);
        for(int j=0 ; j<res[i].size() ; ++j)    dummy.pb(res[i][j]);
        res.push_back(dummy);
    }
    return res;
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int> > aq = getSets(A, 0, A.size());
    sort(aq.begin(), aq.end());
    return aq;
}
