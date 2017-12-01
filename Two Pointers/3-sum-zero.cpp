#define pb push_back

vector<vector<int> > Solution::threeSum(vector<int> &vec) {
    sort(vec.begin(), vec.end());
    int size=vec.size();
    set< vector<int> > le_set;
    vector< vector<int> > res;
    
    for(int i=0,sol,sag ; i<size-2 ; ++i){
        sol=i+1, sag=size-1;
        while(sol<sag){
            /* */if(vec[i]+vec[sol]+vec[sag] < 0)    ++sol;
            else if(vec[i]+vec[sol]+vec[sag] > 0)    --sag;
            else  le_set.insert({vec[i], vec[sol], vec[sag]}), ++sol,--sag;
        }
    }
 
    for(auto it = le_set.begin() ; it!=le_set.end() ; ++it){
        const vector<int> cur = *it;
        res.pb(cur);
    }
    
    return res;
}