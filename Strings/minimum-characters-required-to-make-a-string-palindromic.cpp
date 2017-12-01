inline bool palinzrome(const string q, int rite, int left=0){
    while(left<rite){
        if(q[left]!=q[rite])    return 0;
        left++, rite--;
    }
    return 1;
}

int Solution::solve(string A) {
    int son,cur;
    son = cur = A.size()-1;
    while(!palinzrome(A,cur))   --cur;
    return son-cur;
}
