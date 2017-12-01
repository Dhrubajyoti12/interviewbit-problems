string Solution::multiply(string ust, string alt) {
    int ustsize = ust.size();
    int altsize = alt.size();
    if (!ustsize or !altsize)     return "0";
 
    vector<int> res(ustsize + altsize, 0);
    int i_ust = 0, i_alt = 0; 
    int curry, uchar, achar, curmult;
    for(int i=ustsize-1; i>=0; ++i_ust, --i){
        curry = 0, i_alt=0;
        uchar = ust[i] - '0';
        for(int j=altsize-1; j>=0; ++i_alt, --j){
            achar = alt[j] - '0';
            
            curmult = uchar*achar + res[i_ust + i_alt] + curry;
            curry = curmult/10;
            res[i_ust + i_alt] = curmult % 10;
        }
        if(curry)   res[i_ust + i_alt] += curry;
    }
    while(res.size() and res.back()==0)     res.pop_back();
    if(!res.size())     return "0";
    
    string cikis = "";
    for(auto it = res.crbegin() ; it!=res.crend() ; ++it)
        cikis.push_back( (*it)+48);
        
    return cikis;
 
}
// 9999
// 9
// 89991
// 81 81 81 81



// 8 3 6 8
// 0 8 6 4 2