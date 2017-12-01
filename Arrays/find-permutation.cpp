#define pb push_back

vector<int> Solution::findPerm(const string A, int B) {
    int kck=1, byk=B;
    vector<int> res;
    for(int i=0 ; i<A.size() ; ++i){
        if(A[i]=='D')   res.pb(byk--);
        else            res.pb(kck++);
    }//su an kck==byk beklyorum. sanirim beynim var/
    res.pb(kck);
    return res;
}
