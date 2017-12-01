vector<int> Solution::plusOne(vector<int> &num) {
    reverse(num.begin(), num.end());
    num[0]++;   num.push_back(0);

    for(int i=0 ; i<num.size()-1 ; ++i){
        num[i+1]+=num[i]/10;
        num[i]=num[i]%10;
    }
    
    vector<int> res;
    int index=num.size()-1;
    while(!num[index])  --index;
    for(int i=index ; i>-1 ; --i)   res.push_back(num[i]);
    
    return res;
}
