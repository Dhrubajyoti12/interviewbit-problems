vector<int> Solution::repeatedNumber(const vector<int> &nums) {
    long long nrmlDff=0, squareDff=0;
    for(int i=1 ; i<nums.size()+1 ; ++i){
        nrmlDff += nums[i-1] - i;
        squareDff += (long long)nums[i-1]*nums[i-1] - (long long)i*i;
    }
    int nrmlSum = squareDff/nrmlDff;
    int olan = (nrmlSum + nrmlDff) / 2;
    int olmayan = nrmlSum - olan;
    vector<int> naber;
    naber.push_back(olan); naber.push_back(olmayan);
    
    return naber;
}