int Solution::maxArea(vector<int> &sticks){
 	int res = 0, size = sticks.size();
 	
 	int lo = 0, hi = size - 1;
 	while(lo<hi){
 		res = max(res, (hi-lo)*min(sticks[hi], sticks[lo]));
 		if(sticks[hi] < sticks[lo]) 	--hi;
 		else 							++lo;
 	}

 	return res;
}
