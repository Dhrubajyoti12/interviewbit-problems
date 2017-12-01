#define pb push_back

vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> S;
    vector<int> res;
    int size = A.size();
    for(int i=0 ; i<size ; ++i){
        while(S.size() and S.top()>=A[i])   S.pop();
        
        if(!S.size())    res.pb(-1);
        else             res.pb(S.top());
        
        S.push(A[i]);
    }
    return res;
}

//Input : A : [4, 10, 13, 9, 9, 9, 8]
//            -1  4   10  4