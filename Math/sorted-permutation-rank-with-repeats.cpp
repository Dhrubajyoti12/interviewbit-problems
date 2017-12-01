#define MOD 1000003
typedef unsigned long long int ulli;
ulli mdl(ulli sunumdaki){
    return sunumdaki%MOD;
}
unsigned long long int fact(unsigned long long int q){
    if(q<2) return 1;
    return mdl(q*fact(q-1));
}

ulli kuvvet(ulli base, int p){
    if(!p)  return 1;
    ulli res = kuvvet( mdl(base*base), p/2 );
    if(p%2)     res= mdl(base*res);
    return res;
}

int Solution::findRank(string s){
    ulli res=1;
    int len = s.length()-1,  mark[52]={0};
    string alfabe = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for(int i=0 ; i<s.length() ; ++i){
        if(s[i]<'a')    mark[s[i]-'A']++;
        else            mark[s[i]-'a'+26]++;
    }

    for(int i=0 ; i<s.length() ; ++i){
        char cur = s[i];
        ulli denom=1, ltc=0;//less than current
        
        for(int j=0 ; alfabe[j]<cur ; ++j)      ltc += mark[j];
        for(int j=0 ; j<52 ; ++j)       denom = mdl(denom*fact(mark[j]));
        
        if(cur<'a')     mark[cur-'A']--;
        else            mark[cur-'a'+26]--;
        
        res = mdl(res + (ltc*mdl(fact(len--))*kuvvet(denom,MOD-2)));///denom));//
        
     //   cout<<ltc<<" "<<denom<<" "<<fact(len+1)<<" "<<res<<endl;
        
    }
    return res;
}