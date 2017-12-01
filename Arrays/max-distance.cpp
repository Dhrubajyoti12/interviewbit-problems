#define pb push_back
#define fi first
#define se second
int Solution::maximumGap(const vector<int> &A) {
    vector< pair<int,int> > seyler;
    int size = A.size(), minzie, res;
    
    for(int i=0 ; i<size ; ++i)  seyler.pb(make_pair(A[i],i));
    sort(seyler.begin(), seyler.end());
    
    minzie=seyler[0].se, res = -1, size = seyler.size(); // size artik BASKASI
    for(int cur,i=0 ; i<size ; ++i){
        cur = seyler[i].se;
        minzie = min(minzie, cur);
        res = max(res, cur-minzie);
    }
    
    return res;
    
}
// A : [3 5 4 2]


// 2  3  4  5
// 3  0  2  1
