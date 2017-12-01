inline bool one_more(vector<string> &vec, int ind){
    if(!vec.size())     return false;
    char cur = vec[0][ind];
    for(int i=0 ; i<vec.size() ; ++i)
        if(ind==vec[i].size() or vec[i][ind]!=cur)
            return false;
    
    return true;
} 

string Solution::longestCommonPrefix(vector<string> &vec) {
    string res="";
    int ind=0;
    
    while(one_more(vec,ind)){
        res += vec[0][ind];
        ind++;
    }    
    return res;
}
