// q is always an even number.
inline string go_next(string q){
    int ind=0, size=q.size(), base=0, curry=0;
    if(q[0]=='1')   curry=base=1, --size;
    string res(size, '0');
    
    for(int i=base ; i<q.size() ; ++i){
        res[ind++] += (curry*10 + q[i]-48) / 2;
        curry = q[i]%2;
    }

    return res;
}

int Solution::power(string A) {
    if(A == "1")    return 0;
    
    while(!(A.back()%2))   A = go_next(A);
    if(A == "1")    return 1;
    
    return 0;
}