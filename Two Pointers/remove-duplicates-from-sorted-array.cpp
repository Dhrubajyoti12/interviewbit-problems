int Solution::removeDuplicates(vector<int> &A) {
    if(!A.size())   return 0;
    
    int size=A.size(), cur=A[0], oku, yaz;
    for(oku=0,yaz=0 ; oku<size ;){
        cur = A[oku];
        A[yaz++] = cur;
        while(A[oku]==cur and oku<size)  ++oku;
    }
    while(A.size()>yaz)     A.pop_back();
    
    return A.size();
}