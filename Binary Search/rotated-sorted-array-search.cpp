int pivotto(const vector<int> &q){
    int hi=q.size()-1, lo=0;
    int mid;
    while(lo<=hi){
        mid = (hi+lo)/2;
//printf("hi:%d lo:%d mid:%d q[mid]%d\n",hi, lo, mid,q[mid]);
        if(mid<hi and q[mid]>q[mid+1])  return mid+1;
        if(mid>lo and q[mid]<q[mid-1])  return mid;
        
        if(q[mid]>q[0])     lo=mid+1;
        else                hi=mid-1;
    
    }
    return mid;
}


int arabul(const vector<int> &q, int target, int shft){
    int hi=q.size()-1, lo=0, size = hi+1;
    int ze_sayi,mid;
    while(lo<=hi){
        mid = (lo+hi)/2;
        ze_sayi = q[(mid+shft)%size];
        if(ze_sayi == target)   return (mid+shft)%size;
        if(ze_sayi > target)    hi=mid-1;
        else                    lo=mid+1;
    }
    return -1;
    
}
int Solution::search(const vector<int> &A, int B) {
    int shft = pivotto(A);
    if(shft==A.size()-1 and A[shft]>A[0])     shft=0;
    
    return arabul(A,B,shft);
}
