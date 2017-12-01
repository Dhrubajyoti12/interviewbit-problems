inline void cevir(vector<vector<int> > &A, int i, int j){
    int n=A.size(), i_next=j, j_next=n-i-1;
    int carry = A[i][j], dummy;
    for(int q=0 ; q<4 ; ++q){
        dummy = A[i_next][j_next];
        A[i_next][j_next] = carry;
        carry = dummy;
        i=i_next, j=j_next;
        i_next=j, j_next=n-1-i;
    }
}

//i,j -->  j,n-1-i 
//0,0 -->  0,5 -->  5,5 --> 5,0 --> 0,0

void Solution::rotate(vector<vector<int> > &A) {
    if(!A.size())   return;
    int n=A.size();
    for(int i=0 ; i<n/2 ; ++i)
        for(int j=i ; j<n-1-i ; ++j)
            cevir(A,i,j);
}
