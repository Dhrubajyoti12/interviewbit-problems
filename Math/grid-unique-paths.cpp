int fact(int q){
    return (q<2)?1:q*fact(q-1);
}

int Solution::uniquePaths(int A, int B) {
    int n = A + B - 2, k = min(A-1, B-1) ;
    unsigned long long int res=1;//ABI YAPMAYIN YA
    
    for (unsigned long long d = 1; d <= k; ++d) {
        res *= n--;
        res /= d;
    }
    
    return res;

}
