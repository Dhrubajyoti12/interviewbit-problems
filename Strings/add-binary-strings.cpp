string halp(string kisa, string uzun){
    while(kisa.size() < uzun.size())    kisa += "0";
    int size = kisa.size();
    for(int i=0 ; i<size ; ++i)
        if(kisa[i]=='1')    ++uzun[i];
    

    for(int i=0 ; i<size-1 ; ++i){
        int nex = (uzun[i]-48)/2;
        int cur = (uzun[i]-48)%2;
        uzun[i] = (char)(cur+48);
        uzun[i+1] += nex;
    }
    int nex = (uzun[size-1]-48)/2;
    int cur = (uzun[size-1]-48)%2;
    
    if(nex){
        uzun[size-1] = (char)(cur+48);
        uzun += "1";
    }
    reverse(uzun.begin(), uzun.end());
    return uzun;
}

string Solution::addBinary(string p, string q) {
    reverse(p.begin(), p.end()); reverse(q.begin(), q.end());
    if(p.size() < q.size())     return halp(p, q);
    return halp(q,p); 
}