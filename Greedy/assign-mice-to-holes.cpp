int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int res = 0;

    int size = A.size();
    for(int i=0 ; i<size ; ++i){
    	res = max(res, abs(A[i] - B[i]));
    }

    return res;
}
