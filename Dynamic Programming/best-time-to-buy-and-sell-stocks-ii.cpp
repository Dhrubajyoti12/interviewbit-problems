int Solution::maxProfit(const vector<int> &A){
	int size = A.size();
	int res = 0;
	for(int i=0 ; i<size-1 ; ++i){
		if(A[i] < A[i+1]) 	res += A[i+1] - A[i];
	}
	return res;
}
