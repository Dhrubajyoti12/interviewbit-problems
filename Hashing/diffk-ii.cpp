#define fi first
#define se second
int Solution::diffPossible(const vector<int> &vec, int B) {
    unordered_map<int, int> mapzie;
    int size = vec.size();
    for(int i=0 ; i<size ; ++i){
        auto get = mapzie.find(vec[i]);
        if(get != mapzie.end())     get->se++;
        else    mapzie.emplace(vec[i],1);
    }
    
    for(int i=0,cur ; i<size ; ++i){
        cur = vec[i];
        auto get = mapzie.find(cur);
        get->se--;
        auto gpr = mapzie.find(cur+B);
        
        if(gpr!=mapzie.end() and gpr->se > 0)    return 1;
        get->se++;
    }
    
    return 0;
}
