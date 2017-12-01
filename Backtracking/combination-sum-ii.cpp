#include <set>

using vi = vector<int>;

void solve(vi &set, vi &cur, std::set< vi > &sol_set, int ind, int target){
    if(target < 0)  return;
    if(!target)     {sol_set.insert(cur);return;}
    
    for(int i=ind ; i<set.size() ; ++i){
        cur.push_back(set[i]);
        solve(set, cur, sol_set, i+1, target-set[i]);
        cur.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &set, int target) {
    vi cur;     std::set<vi> sol_set;
    sort(set.begin(), set.end());
    solve(set, cur, sol_set, 0, target);
    //push everything into a vector vi.
    vector< vi > res;
    for(auto ihi: sol_set)  res.push_back(ihi);
    
    return res;
}
