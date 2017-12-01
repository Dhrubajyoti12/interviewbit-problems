

vector<int> Solution::getRow(int n) {
    int c=n, cur=1;
    vector<int> res;
	res.push_back(cur);
	if(!n)  return res;

	for(int i=n,j=1 ; j<=c ; ++j,--i){
		cur*=i;
		cur/=j;
		res.push_back(cur);
	}
	return res;
}

// 1
// 1 2 1 
// 1 3 3 1
