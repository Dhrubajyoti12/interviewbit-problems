#define pb push_back
using vi = vector<int>;
using aq = unsigned long long int;

aq *table, curInd, curFct;

void _init(const int n, int &k){
    --k;
    table = new aq[n+1];
    for(int i=0 ; i<=n ; table[i++]=0);
    table[0]=1;
}

int fact(const int n){
    if(n>12)    return INT_MAX;
    if(table[n])    return table[n];
    return table[n] = n*fact(n-1);
}

string Solution::getPermutation(int n, int k) {
    // init stuff.
    _init(n, k);
    if(n<1 or k>=fact(n))  return "";
    vi numbers;
    string res;
    for(int i=1 ; i<=n ; ++i)   numbers.pb(i);
    
    while(n--){
        curFct = fact(n);
        curInd = k/curFct;
        k %= curFct;
        res += to_string(numbers[curInd]);
        numbers.erase(numbers.begin() + curInd);
    }
    return res;
}
/*
1 2 3 4 
1 2 4 3
1 3 2 4
1 3 
1 4 
1 4





*/

