#define MOD (1000000007)

int Solution::cntBits(vector<int> &A){
    unsigned long long int size=A.size(),res=0,dif=0;
    for(int bit=0 ; bit<32 ; ++bit, dif=0){
        for(int i=0 ; i<size ; ++i)
            if(A[i]&(1<<bit)) ++dif;
        res = (res + dif*(size-dif)*2)%MOD;
    }
    //cout<<MOD<<endl;
    return (int)res;
}
// 101
// 011
// 001