int halp_me_nigga(int big, int sma){
    if(sma==0)    return big;
    return halp_me_nigga (sma, big%sma);
}
int Solution::gcd(int A, int B) {
    if(!A and !B)   return 0;
    return halp_me_nigga(max(A,B), min(A,B));
}