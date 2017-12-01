int Solution::lengthOfLongestSubstring(string K) {
    int res=0, cle=0, size=K.size();// curlen
    unordered_map<char, int> table;
    queue<char> Q;
    
    for(int i=0 ; i<size ; ++i){
        char cur = K[i];
        unordered_map<char, int>::iterator get = table.find(cur);
        
        // yeni char
        if(get == table.end())  ++cle, table.emplace(cur, i), Q.push(cur);
        else{
            res = max(res, cle);//update max if necessary.
            while(Q.front() != cur){
                table.erase(Q.front());   Q.pop();
            }
            cle = i - table[cur]; 
            Q.pop(); //table.erase(cur); asagida geri ekliyo
            table[cur] = i;     Q.push(cur);
        }
    }
    return max(res, cle);
}