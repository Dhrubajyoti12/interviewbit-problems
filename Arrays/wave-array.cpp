vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<int> res;
    for(int i=1 ; i<A.size(); i+=2){
        res.push_back(A[i]);
        res.push_back(A[i-1]);
    }
    if(A.size()%2)  res.push_back(A[A.size()-1]);
    return res;
}
