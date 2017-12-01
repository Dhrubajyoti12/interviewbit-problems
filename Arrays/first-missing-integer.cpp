void swp(vector<int> &A, int p, int q){
    int dummy =A[p];
    A[p]=A[q];
    A[q]=dummy;
    
}

int Solution::firstMissingPositive(vector<int> &A){
    if(!A.size())   return 1;
    int res=1, rightMost=A.size()-1;
    for(int i=0 ; i<=rightMost ; ++i){
        while(A[i]<=0 and rightMost>-1)      {A[i]=0; swp(A,i,rightMost--);}
    }// now rightMost is the effective length.
    
    //or(int i=0 ; i<A.size() ; ++i)     cout<<A[i];
    //cout<<endl;
    if(!A[0]) return 1;
    rightMost++;
    
    //cout<<rightMost<<endl;
    for(int i=0 ; i<rightMost ; ++i){
        int cur = A[i];
        if(cur<0) cur=-cur;
        if(cur-1<rightMost and A[cur-1]>0)  A[cur-1]=-A[cur-1];
    }
    //    for(int i=0 ; i<A.size() ; ++i)     cout<<A[i];

    for(int i=0 ; i<rightMost ; ++i){
        if(A[i]>0)  return i+1;
    }
    
    return rightMost+1;
}