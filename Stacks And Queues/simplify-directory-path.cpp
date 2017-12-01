#define pb push_back

vector<string> tokenize(string q){
    int size = q.size(), ind=1;
    string token;
    vector<string> res;
    while(ind<size){
        token = "";
        while(q[ind]!='/' and ind<size){
            token += q[ind++];
        }
        while(q[ind] == '/')    ++ind;
        res.pb(token);
    }
    return res;
}

string Solution::simplifyPath(string A) {
    vector<string> tokens = tokenize(A);
    deque<string> deck;
    
    for(int i=0; i<tokens.size() ; ++i){
        string cur = tokens[i];
        if(cur == ".")      continue;
        if(cur == ".." and deck.size())    deck.pop_back();
        if(cur != "..")                 deck.push_back(cur);
    }
    
    
    // build up the result.
    string res = "/";
    while(deck.size()){
        res += deck.front();     deck.pop_front();
        res += "/";
    }
    if(res.size() > 1)      res.pop_back();
    
    return res;
}