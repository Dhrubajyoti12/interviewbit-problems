int Solution::diffPossible(vector<int> &A, int K) {
    int res=0, size=A.size();
    for(int sol=0,sag=1 ; sag<size ; ++sol){
        sag = max(sag,sol+1);
        while(A[sag]-A[sol]<K and sag<size)                                                     sag++;
        while(A[sag]-A[sol] == K){
            ++res, ++sag;
        }
    }
        
    return res>0;
}