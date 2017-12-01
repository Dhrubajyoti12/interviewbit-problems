int Solution::singleNumber(const vector<int> &A) {
    int nexor=0;
    for(int i=0 ; i<A.size() ; ++i) nexor ^= A[i];
    return nexor;
}
