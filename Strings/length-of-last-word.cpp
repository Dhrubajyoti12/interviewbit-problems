int Solution::lengthOfLastWord(const string &A) {
    int res=0, i=A.size()-1;
    // find the end of last word.
    while(A[i] == ' ')  --i;//A[-1] is null
    while(i>-1 and A[i]!=' ')   ++res, --i;
    
    return res;
}
// 'abc aq   '