//3 gram beyin edin, overflow olabilecekhererdepatliyosunaqretardi.
typedef long long int lanet;
lanet halp(lanet ust, lanet alt){
    //cout<<ust<<" "<<alt<<endl;
    if(!alt)    return INT_MAX;
    lanet shft_cnt=0, res=0;
    while(ust>alt and alt>0)  alt <<= 1, ++shft_cnt;
    for(int i=0 ; i<=shft_cnt ; ++i){
        res <<= 1;
        if(ust>=alt)     ust-=alt, ++res;
        alt >>= 1;
    }
    //if(res>INT_MAX)     return INT_MAX;
    return res;
}

int Solution::divide(int _ust, int _alt) {
    lanet ust = _ust, alt = _alt;
    int sign = 1;
    if(ust<0)   ust = -ust, sign = !sign;
    if(alt<0)   alt = -alt, sign = !sign;
    lanet res = halp(ust, alt);
    if(!sign) res = -res;
    if(res>INT_MAX or res<INT_MIN)  return INT_MAX;
    return (int)res;
}

// 0101
// 0110
// 011