int Solution::singleNumber(const vector<int> &A) {
    int res=0, count;
    for(int i=0 ; i<32 ; ++i){
        count=0;
        for(auto it=A.cbegin() ; it!=A.cend() ; ++it)
            if((*it)&(1<<i))    ++count;
        if(count%3 == 1)  res |= 1<<i;
    }
    
    return res;
}

