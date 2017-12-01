#define pb push_back
using vvi = vector< vector<int> >;

vector<int> *seq;
int size, *mark;

vvi *res;


void _init(int _size){
    size = _size;
    mark = new int[size];
    for(int i=0 ; i<size ; ++i)     mark[i]=0;
    res = new vvi();
    seq = new vector<int>();
}

void solve(vector<int> &vec, int kalan){
    if(!kalan){res->pb(*seq);  return;}
    
    for(int i=0 ; i<size ; ++i){
        if(!mark[i]){
            mark[i]=1;  seq->pb(vec[i]);
            solve(vec, kalan-1);
            mark[i]=0;  seq->pop_back();
        }
    }
}



vector<vector<int> > Solution::permute(vector<int> &A) {
    _init(A.size());
    solve(A, size);
    return *res;
}
