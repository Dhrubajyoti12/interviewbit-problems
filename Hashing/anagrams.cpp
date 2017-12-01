using vi = vector<int>;
#define pb push_back

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string, vi> zimep;
    vector< vi > ret;
    int size = A.size();
    for(int i=0 ; i<size ; ++i) {
        string dummy = A[i];
        sort(dummy.begin(), dummy.end());
        zimep[dummy].pb(i+1);
    }
    for(auto it=zimep.cbegin() ; it!=zimep.cend() ; ++it )
        ret.pb(it->second);
    
    return ret;
}
