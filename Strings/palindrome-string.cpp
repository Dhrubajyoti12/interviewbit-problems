inline bool valid(char *q){
    if('A'<=*q and *q<='Z') *q += 32;
    
    return ('a'<=*q and *q<='z')or
           ('0'<=*q and *q<='9');
}
int Solution::isPalindrome(string A) {
    string realdeal;
    for(int i=0 ; i<A.length() ; ++i)   
        if(valid(&A[i]))     realdeal += A[i];

    for(int i=0, j=realdeal.size()-1 ; i<j ; ++i,--j)
        if(realdeal[i]!=realdeal[j])     return false;
    return true;
}
