int hadibul(const vector<int> &A, int target, int dir){
    int lo=0, hi=A.size()-1, mid, res=-1;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(A[mid] == target){
            res = mid;
            if(dir)     lo = mid+1;
            else        hi = mid-1;
        }
        else if(A[mid] < target)    lo=mid+1;
        else                        hi=mid-1;
    }
    return res;
}


vector<int> Solution::searchRange(const vector<int> &A, int B) {
   int sol = hadibul(A, B, 0);
   int sag = hadibul(A, B, 1);
   return vector<int>({sol,sag});
}
