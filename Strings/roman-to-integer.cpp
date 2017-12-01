int Solution::romanToInt(string A) {
    A+="!";
    int map[255] = {0};  // piresidans.   
    map['M']=1000, map['D']=500, map['C']=100, map['L']=50;
    map['X']=10, map['V']=5, map['I']=1;
    
    string tablo = "MDCLXVI";
    
    int res=0;
    for(int i=0,cur ; i<A.size()-1 ; ++i){
        cur = map[A[i]];
        if(map[A[i+1]]>cur)     cur=-cur;
        res += cur;
    }
    
    return res;
}
