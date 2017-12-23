vector<int> Solution::solve(int q, int p, int t, int K){
    vector<int> res;
    set<int> s;
    
    // initialize the set.
    s.insert({q, p,t });
    while(res.size() < K) {
        // pop the smallest element.
        int next = *(s.begin());
        s.erase(s.begin());
        
        res.push_back(next);
        s.insert({next*q, next*p, next*t});
    }
    
    return res;
}
