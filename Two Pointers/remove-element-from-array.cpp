int Solution::removeElement(vector<int> &A, int toxic) {
    
    int sol=0, size=A.size();
    int yapistiran;// right pt.
    
    while(A[sol]!=toxic and sol<size)     ++sol;
    // hala yok
    if(sol == size)     return size;
    yapistiran = sol+1;
    while(yapistiran<size){
        if(A[yapistiran]!=toxic)    A[sol++] = A[yapistiran];
        ++yapistiran;
    }
    // 3grambeyinnotfound.
    while(yapistiran>sol)  --yapistiran, A.pop_back();
    //cout<<size-sol<<endl;
    return A.size();;
}