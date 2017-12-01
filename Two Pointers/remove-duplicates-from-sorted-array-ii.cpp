int Solution::removeDuplicates(vector<int> &A) {
    int cur=A[0], oku=0, yaz=0;
    int size=A.size(), dbl=0;
    while(oku < size){
        // we get a new number
        if(A[oku]!=cur) dbl=1, cur=A[oku], A[yaz++]=cur;
        // A[oku]==cur and dbl<2
        else if(dbl<2)  A[yaz++]=cur, ++dbl;    
        
        ++oku;
    }
    //while(A.size() > yaz)   A.pop_back();
    return yaz;
}
