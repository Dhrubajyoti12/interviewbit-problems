//q will never be 1
bool prime(int q){
    for(int i=2 ; i*i<=q ; ++i){
        if(q%i==0)  return 0;
    }
    return 1;
}

vector<int> Solution::primesum(int A) {
    vector<int> res;
    for(int i=3 ; i<A ; i+=2){
        if(prime(i) and prime(A-i)){
            res.push_back(i);
            res.push_back(A-i);
            return res;
        }
        
    }
    return res;
}
