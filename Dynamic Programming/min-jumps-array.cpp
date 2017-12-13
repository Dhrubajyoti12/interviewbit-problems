int Solution::jump(vector<int> &A) {
	int size = A.size();
	int maxj=0;
	vector<unsigned int> sol(size, -1);
	sol[0] = 0;
	for(int i=0 ; i<size and maxj>=i ; ++i){
		if(i+A[i] > maxj){
			while(i+A[i] > maxj and maxj<size-1){
				sol[++maxj] = sol[i]+1;
			}	
		}
	}
	return sol[size-1];
}