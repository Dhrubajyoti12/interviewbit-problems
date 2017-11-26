int Solution::bulbs(vector<int> &A) {
    int res=0, effect=0, size = A.size();
    for(int cur,i=0 ; i<size ; ++i){
        cur = (effect%2)^A[i];
        if(!cur){
        	effect++;
        	res++;
        }
    }
    return res;    
}