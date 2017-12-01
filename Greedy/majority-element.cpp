int Solution::majorityElement(const vector<int> &A) {
	int count=0, value;
	for(auto a : A){
		if(value == a) 	++count;
		else if(!count)	count=1, value=a;
		else 			--count;
	}
	return value;
}
