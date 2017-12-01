int Solution::maxSubArray(const vector<int> &A) {
    if(!A.size())   return -1000000000;
    
    int kuyruk=A[0], res=A[0];
    for(int i=1 ; i<A.size() ; ++i){
        kuyruk = kuyruk>0?kuyruk:0;
        kuyruk += A[i];
        res = res>kuyruk?res:kuyruk;
    }
    
    return res;
    
}
