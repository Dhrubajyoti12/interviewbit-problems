#define MOD (1000000007)

int Solution::nTriang(vector<int> &E) {
    sort(E.begin(), E.end());
    int left=0, rite=0, size=E.size();
    long long int res=0;  
    for(int i=0,k=0 ; i<size-2;  k=0, ++i){
        for(int j=i+1 ; j<size-1 ; ++j){
            while(E[i]+E[j]>E[k] and k<size)   ++k;
            res = (res + k - j - 1)%MOD;
        }
    }
    return res;   
}