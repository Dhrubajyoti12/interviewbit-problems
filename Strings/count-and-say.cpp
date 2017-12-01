const string BASE = "1";

inline string gen_next(string q){
    q += "#";
    string next;
    char cur = q[0];
    int count=0;
    for(int i=0 ; i<q.size() ; ++i){
        if(cur == q[i])     ++count;
        else{
            next += to_string(count);
            next += cur;
            cur=q[i], count=1;
        }
    }
    return next;
}

string Solution::countAndSay(int A) {
    string res = BASE;
    if(A<2)     return res;
    while(A-- > 1)  res = gen_next(res);
    return res;
    
}
