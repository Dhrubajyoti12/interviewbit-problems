 string int2Str(int q){
    char dgt = q%10 + 48;
    if(q<10)    return (string)""+dgt;
    return int2Str(q/10)+dgt;
}

bool le_comp(const int q, const int p){
    string qsol = int2Str(q) + int2Str(p);
    string psol = int2Str(p) + int2Str(q);
    return qsol.compare(psol)>0;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<int> dummy;
    for(int i=0 ; i<A.size() ; ++i)     dummy.push_back(A[i]);
    
    sort(dummy.begin(), dummy.end(), le_comp);
    string res = "";
    if(dummy[0] == 0)   return "0";
    for(int i=0 ; i<dummy.size() ; ++i)  res += int2Str(dummy[i]);
    return res;
}


