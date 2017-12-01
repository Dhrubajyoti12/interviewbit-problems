int Solution::numSetBits(unsigned int A) {
    int res=0;
    while(A){
        if(A&1)     ++res;
        A>>=1;
    }
    return res;
}
