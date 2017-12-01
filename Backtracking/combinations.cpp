#define pb push_back
using vvi = vector<vector<int> >;

vvi *res;
vector<int> *cur;

void _init(){
    res = new vvi();
    cur = new vector<int>();
}

void solve(int start, int end, int kalan){
    if(!kalan)  res->pb(*cur);
    for(int i=start ; i<=end ; ++i){
        cur->pb(i);
        solve(i+1, end, kalan-1);
        cur->pop_back();
    }
}

vector<vector<int> > Solution::combine(int n, int k) {
    vvi naber;
    if(n<0 or k<0 or k>n)  return naber;
    _init();
    solve(1,n,k);
    return *res;
}
