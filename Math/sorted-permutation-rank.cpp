#define pb push_back


int Solution::findRank(string q) {
    int tut[256] = {0};     tut[0]=-1;
    for(int i=0 ; i<q.length() ; ++i)   ++tut[  q[i]  ];
    for(int i=1 ; i<256 ; ++i)          tut[i] += tut[i-1];

    vector<int> fact;   fact.pb(1);
    for(int i=1 ; i<=q.length() ; ++i)   fact.pb( (fact[i-1]*i)% 1000003);
    
    unsigned long long int res=0;
    for(int i=0,curInd ; i<q.length() ; ++i){
        curInd = q[i];
        res = (res + tut[curInd]*fact[q.length()-1-i])  % 1000003;
        for(int j=curInd ; j<256 ; ++j)     --tut[j];
    }
    res = (res + 1 )  % 1000003;

    return (int)res;
}