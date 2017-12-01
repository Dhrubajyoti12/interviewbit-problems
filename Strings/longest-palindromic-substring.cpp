inline string tekler(const string &q, int mid){
    int off = 0, size=q.size();
    while(mid-off>-1 and mid+off<size){
        if(q[mid+off] != q[mid-off])    break;
        off++;
    }
    
    string res;
    for(int i=mid-off+1 ; i<mid+off ; ++i)        res+=q[i];
    
    return res;
}

inline string cftler(const string &q, int left, int rite){
    int size = q.size();
    while(left>-1 and rite<size){
        if(q[left]!=q[rite])    break;
        left--, rite++;
    }
    
    string res;
    for(int i=left+1 ; i<rite ; ++i)    res+=q[i];
    
    return res;
}

string Solution::longestPalindrome(string A) {
    string cur_tek, cur_cft, max_pal;
    for(int i=0 ; i<A.size() ; ++i){
        cur_tek = tekler(A, i);
        cur_cft = cftler(A, i, i+1);
        if(cur_tek.size()>max_pal.size())   max_pal = cur_tek;
        if(cur_cft.size()>max_pal.size())   max_pal = cur_cft;
    }
    
    return max_pal;
}
