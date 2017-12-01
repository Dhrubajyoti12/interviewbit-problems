void Solution::nextPermutation(vector<int> &nums) {
    // 0case. allah belanizi versin ya
    if(!nums.size())    return;
    int head = nums.size()-2;
    while(head>-1 and nums[head]>=nums[head+1]) --head;
    
    // last permutation
    if(head==-1)    {reverse(nums.begin(), nums.end()); return;}
    
    
    int lup = nums[head+1], lupInd;
    for(int i=head+1 ; i<nums.size() ; ++i){
        if(nums[i]>nums[head] and nums[i]<=lup)    lup=nums[i], lupInd=i;
    }
    //cout<<lup<<endl;
    
    //swap shit
    int dummy = nums[head];
    nums[head] = nums[lupInd];
    nums[lupInd] = dummy;
    
    // gerekeniyap.
    for(int i=head+1, j=nums.size()-1 ; i<j ; ++i,--j){
        dummy = nums[i];
        nums[i] = nums[j];
        nums[j] = dummy;
    }
}
