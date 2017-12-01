int Solution::threeSumClosest(vector<int> &vec, int target) {
    sort(vec.begin(), vec.end());
    
    int res = vec[0]+vec[1]+vec[2];
    int mindis = abs(res - target), size=vec.size();
    for(int cursum,curdis, left, rite, i=0 ; i<size-2 ; ++i){
        left=i+1, rite=size-1;
        while(left<rite){
            cursum = vec[left] + vec[rite] + vec[i];
            curdis = abs(cursum - target);

            if(curdis < mindis)  res=cursum, mindis=curdis;
            //if(!curdis)     break;
            if(cursum>target)         --rite;
            else /*if(cursum<target)*/++left;
        }
    }
    return res;
}
