int Solution::searchInsert(vector<int> &A, int val) {
    if(!A.size())   return 0;
    
    int sol=0,sag=A.size()-1, mid=0;
    
    while(sol<=sag){
        mid = sol + (sag-sol)/2; //overflow yiyemem; 
        //nazenara, max vector<int> capacity = 2^30-1 yakara
        if(A[mid]==val)     return mid;
        if(A[mid]>val)      sag=mid-1;
        if(A[mid]<val)      sol=mid+1;
    }
    if(A[mid]>val)  return mid; // A[mid-1] < val < A[mid];
    return mid+1;               // A[mid] < val < A[mid]+1;
    
//indices     0  1  2  3  4  5  6  7
//valz        1  3  5  7  9  11 13 15    
}
