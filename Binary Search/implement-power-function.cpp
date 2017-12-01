typedef unsigned long long int lanet;

lanet help(lanet base, lanet pwr, lanet d){
    if(!pwr)    return 1;
    lanet res = help((base*base)%d, pwr/2, d);
    if(pwr%2)     res = (res*base)%d;
    return res;
}

int Solution::pow(int x, int n, int d) {
    if(!x and !n)       return 0;
    if(x<0 and n%2)     return d - help(-x,n,d);
    return help(x,n,d);
    
}
