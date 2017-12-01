#define fi first
#define se second

pair<int,int> lenLas(string A, int i){
    int res=0;
    // find the end of last word.
    while(A[i] == ' ')  --i;//A[-1] is null
    while(i>-1 and A[i]!=' ')   ++res, --i;
    return make_pair(res,i+1);
}

void Solution::reverseWords(string &A) {
    string res;
    int son = A.length()-1;
    
    pair<int,int> ri = lenLas(A, son);
    for(int i=0 ; i<ri.fi ; ++i)    res+=A[ri.se+i];
    son = ri.se-1;
    
    while(son>-1){     //length&ind
        pair<int,int> li = lenLas(A, son);
        res +=" ";
        for(int i=0 ; i<li.fi ; ++i)    res+=A[li.se+i];
        son = li.se-1;
    }
    A=res;
}