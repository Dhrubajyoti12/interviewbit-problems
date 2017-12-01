#define pb push_back

vector<int> Solution::intersect(const vector<int> &Q, const vector<int> &P) {
    int q=0, p=0;
    vector<int> res;
    while(q<Q.size() and p<P.size()){
        /* */if(Q[q]>P[p])      p++;
        else if(Q[q]<P[p])      q++;  
        else /*(Q[q] == P[p])*/ res.pb(Q[q]), q++, p++;    
    }
    
    return res;
}
