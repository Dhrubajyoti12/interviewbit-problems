int Solution::solve(vector<int> &A) {
    std::sort(A.begin(), A.end());
    int greater[A.size()], streak=1;
    for(int i=0 ; i<A.size() ; ++i)     greater[i]=0;
    for(int i=A.size()-2 ; i>-1 ; --i){
        if(A[i]<A[i+1])     greater[i] = greater[i+1]+streak, streak=1;
        else                ++streak, greater[i] = greater[i+1];
    }
    for(int i=0 ; i<A.size() ; ++i){
        if(greater[i]==A[i])    return 1;
    }
    return -1;
}
