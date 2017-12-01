long long int rev(int q){
    long long int res=0;
    while(q){
        res = res*10 + q%10;
        q/=10;
    }
    return res;
}

bool Solution::isPalindrome(int A) {
    return A>=0 and A == rev(A);
}
