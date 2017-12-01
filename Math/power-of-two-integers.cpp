bool Solution::isPower(int A) {
    if(A==1)    return true;
    int long long dummy;
    for(int i=2 ; i<=sqrt(A) ; ++i){
        dummy=i;
        for(int j=2 ; dummy<A ; ++j)   dummy*=i;
        if(dummy == A)  return true;
    }
    return false;
}
