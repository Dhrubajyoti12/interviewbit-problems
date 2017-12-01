int tsTo(int povar){
    int res=1;
    for(int i=0 ; i<povar ; ++i)
        res*=26;
    return res;
}
int Solution::titleToNumber(string A) {
    int res=0;
    for(int i=0, j=A.length()-i-1 ; i<A.length() ; --j, ++i)
        res += tsTo(j)*(A[i]-'A'+1);
    return res;
}
