vector<int> Solution::maxset(vector<int> &nums) {
    //baciniz yok
    long long int maxSum=0, sonoLe=0, sonoIn=0, curSm=0, curLe=0, curIn=0;
    for(int i=0 ; i<nums.size() ; ++i){
        if(nums[i] < 0){
            if( (maxSum < curSm) or //(bu satir) or (alt satir) ise
            ((maxSum == curSm) and (sonoLe < curLe))){
                maxSum = curSm;
                sonoLe = curLe;
                sonoIn = curIn;
            }
            curLe=0, curIn=i+1, curSm=0;
        }
        // num[i] positive 
        else curSm += nums[i], ++curLe;
    }
    // saigo wa positive case ?!@#%$%
    if( (maxSum < curSm) or //(bu satir) or (alt satir) ise
            ((maxSum == curSm) and (sonoLe < curLe))){
                maxSum = curSm;
                sonoLe = curLe;
                sonoIn = curIn;
    }
    
    vector<int> res;
    for(int i=sonoIn ; i<sonoIn+sonoLe ; ++i)   res.push_back(nums[i]);
    
    return res;
}
