inline bool match(const string byk, const string kck, int base){
    for(int i=0 ; i<kck.size() ; ++i)
        if(byk[base+i] != kck[i])   return 0;
    return 1 and kck.size();
}

int Solution::strStr(const string &byk, const string &kck){
    int rightMost = byk.size() - kck.size();
    for(int i=0 ; i<=rightMost ; ++i)
        if(match(byk, kck, i))      return i;
    return -1;
}
