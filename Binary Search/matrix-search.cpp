int Solution::searchMatrix(vector<vector<int> > &A, int target) {
    long long int h=A.size(), w=A[0].size();
    long long int left=0, rite=h*w-1, mid;
    
    while(left<=rite){
        mid = left + (rite-left)/2;
        
        if(A[mid/w][mid%w] == target)   return 1;
        if(A[mid/w][mid%w] < target)    left=mid+1;
        else/* mid no yatsu > target*/  rite=mid-1;
    }
    
    return 0;
}
