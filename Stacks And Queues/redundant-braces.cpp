int op(char q){
    return
        q == '+' or
        q == '-' or
        q == '*' or
        q == '/';
}

int Solution::braces(string A) {
    stack<char> S;
    int ind=0, size=A.size(), flag;
    
    for(int i=0,cur ; i<size ; ++i){
        cur = A[i];
        if(cur != ')' )  S.push(cur);
        if(cur == ')'){
            flag = 0;
            while(S.top()!='('){
                if(op(S.top()))     flag=1;
                S.pop();
            }
            if(!flag)   return 1;
            S.pop();//pop (
        }
    }

    
    return 0;
}
