int Solution::maxProfit(const vector<int> &A) {
	if(!A.size()) 	return 0;
	int size = A.size();
	int big = A[size-1], res = 0;
	for(int i=size-2 ; i>-1 ; --i){
		big = max(big, A[i]);
		res = max(res, big-A[i]);
	}
	return big - sml;
}
