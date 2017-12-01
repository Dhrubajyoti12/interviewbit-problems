// q>0
int rev(int q){
    long long int newRes=0;
    while(q){
        newRes = newRes*10 + q%10;
        q/=10;
        if(newRes>INT_MAX)  return 0;
    }
    
    return newRes;
}
int Solution::reverse(int A) {
    int res;
    if(A<0)     res=-rev(-A);
    else        res=rev(A);
    return res;
}
