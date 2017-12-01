#define pb push_back

void Solution::sortColors(vector<int> &A) {
    int fi=0,se=0,th=0;
    for(int i=0 ; i<A.size() ; ++i){
        if(A[i]==0)     fi++;
        if(A[i]==1)     se++;
        if(A[i]==2)     th++;
    }
    for(int i=0 ; i<fi ; ++i)   A[i] = 0;
    for(int i=0 ; i<se ; ++i)   A[i+fi] = 1;
    for(int i=0 ; i<th ; ++i)   A[i+fi+se] = 2;
}
