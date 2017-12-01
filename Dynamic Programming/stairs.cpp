int Solution::climbStairs(int A) {
    vector<int> stairs(A+1);
    
    stairs[1] = stairs[0] = 1;
    for(int i=2 ; i<=A ; ++i){
        stairs[i] = stairs[i-1] + stairs[i-2];
    }
    
    return stairs[A];
}
