int Solution::canJump(vector<int> &stairs) {
	int maxj, size;
	size = stairs.size();  maxj = 0;

	for(int i=0 ; i<size and maxj>=i; ++i){
		maxj = max(maxj, i+stairs[i]);
	}
	return maxj >= size;

}