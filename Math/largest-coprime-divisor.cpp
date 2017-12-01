int _gcd(int big, int sma){
    if(!sma)    return big;
    return _gcd(sma, big%sma);
}
int gcd(int q, int p){
    if(!q and !p)   return 0;
    return _gcd(max(q,p), min(q,p));
}

int Solution::cpFact(int A, int B) {
    int step = B;
    while(gcd(A,step)!=1){
        A/=gcd(A,step);
    }
    return A;
}
