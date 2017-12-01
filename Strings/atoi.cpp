typedef long long int lli;

// q is non negative;
lli help(string q){
    lli res = 0;
    for(char c : q){
        res = 10*res + (c-'0');
       // cout<<res<<endl;
        if(res>INT_MAX)     return res;
    }
    return res;
}

// positive = 0 for negatives, 1 for positives
int convert(string q, int positive){
    lli res = help(q);
    //cout<<"res: "<<res<<endl;
    if(positive)    return min((lli)INT_MAX, res);
    /*else*/ 
    return max((lli)INT_MIN, -res);
    
}

int Solution::atoi(const string &A) {
    if(!A.size())   return 0;
    int ind = 0, sign=1; string dummy;
    
    if(A[0]=='-')       sign=0, ++ind;
    if(A[0]=='+')       ++ind;
    
    while('0'<=A[ind] and A[ind]<='9')  dummy += A[ind++];
    //cout<<dummy<<endl;
    return convert(dummy, sign);
}
