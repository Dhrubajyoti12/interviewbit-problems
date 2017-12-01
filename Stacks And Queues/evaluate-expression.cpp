string table[4] = {"+", "-", "*", "/"};

inline char getOp(string q){
    if(q == "+")    return '+';
    if(q == "-")    return '-';
    if(q == "/")    return '/';
    if(q == "*")    return '*';
    // q aint no operation maine.
    return 0;
}
inline int eval(int q1, int q2, int op){
    if(op == '+')   return q1+q2;
    if(op == '-')   return q1-q2;
    if(op == '*')   return q1*q2;
    if(op == '/')   return q1/q2;
    
    return -21436;
}

int Solution::evalRPN(vector<string> &A) {
    stack<int> S;
    
    for(int i=0, cur ; i<A.size() ; ++i){
        cur = getOp(A[i]);
        if(!cur)    S.push(stoi(A[i]));
        else{
            int ust = S.top(); S.pop();
            int alt = S.top(); S.pop();
            int evl = eval(alt, ust, cur);
            S.push(evl);
        }
    }
    
    return S.top();
}
