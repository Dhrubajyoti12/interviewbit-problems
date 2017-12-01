#define pb push_back
using vi = vector<int>;

// needs to be called with non-negative n.
string genKey(int n){
    if(!~n)   return "";
    string blw = genKey(n-1);
    return blw + (char)n + blw;
}

vector<int> Solution::grayCode(int n) {
    string key = genKey(n-1);
    vi res;
    int cur=0;  res.pb(cur);  
    for(auto it = key.cbegin() ; it!=key.cend() ; ++it){
        cur ^= 1<<*it;
        res.pb(cur);
    }
    //for(int i=0 ; i<key.size() ; ++i) printf("%c ",key[i]+48);printf("\n");
    return res;
}
