typedef unsigned long long int lanet;
//pozitif aliyoruz.
int help(lanet x){
    // x == 1 or 0
    if (x<2)    return x;
 
    int start = 0, end = x, ans;   
    while (start <= end){        
        int mid = start + (end - start) / 2;
        if (mid*mid==x)     return mid;
        if (mid*mid < x){
            start = mid + 1;
            ans = mid;
        } 
        else    end=mid - 1;        
    }
    return ans;
}

int Solution::sqrt(int A) {
    lanet b = A;
    if(b<0)     return help(-b);
    else        return help(b);
}
