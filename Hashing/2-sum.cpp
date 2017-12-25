vector<int> Solution::twoSum(const vector<int> &arr, int target) {
    unordered_map<int, int> hmap;  
    int size = arr.size();
    for(int i=0 ; i<size ; ++i) {
        unordered_map<int, int>::iterator get = hmap.find(target - arr[i]);
        // return the vector if we found 2 numbers
        if(get != hmap.end())   return vector<int>{get->second, i+1};
        
        // add the element if its not a duplicate
        if(hmap.find(arr[i]) == hmap.end())     hmap[arr[i]] = i+1;   
    }
    return vector<int>{};
}
