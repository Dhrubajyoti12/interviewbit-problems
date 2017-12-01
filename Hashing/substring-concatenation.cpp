#define fi first
#define se second

using vs = vector<string>;
using umsi = unordered_map<string, int>;
using vi = vector<int>;

umsi *keyMap, *curMap;
int wle, wsz; //word_length

int _init(const vs &words){
    if(!words.size())   return 1;
    wle = words[0].size();
    wsz = words.size();
    keyMap = new umsi();
    curMap = new umsi();
    
    for(int i=0 ; i<wsz ; i++){
        // if varsa, else yoksa
        if(keyMap->find(words[i]) != keyMap->end()) (*keyMap)[words[i]]++;
        else                                        (*keyMap)[words[i]]=1;
    }
    return 0;
}

inline bool match(){
    if(keyMap->size()!=curMap->size())  return 0;
    for(auto it=keyMap->cbegin() ; it!=keyMap->cend() ; ++it){
        auto found = curMap->find(it->fi);
        if(found == curMap->end()  or
            found->se != it->se)    return 0;
    }
    return 1;
}
vi solve(const string &S, const vs &words){
    vi res;
    int index=0, size = S.size(), start=0;
    while(index<size){
        string dummy = "";
        for(int i=0 ; i<wle & index<size ; ++i)     dummy+=S[index++];
        if(keyMap->find(dummy) == keyMap->end()){
            index = ++start;
            free(curMap);    curMap = new umsi();
        }
        else{
            (*curMap)[dummy]++;
            if((*curMap)[dummy] > (*keyMap)[dummy]){
                index = ++start;
                free(curMap);    curMap = new umsi();
            }
            else if(match()){
                res.push_back(start++);
                free(curMap);    curMap = new umsi();
                index = start;
            }
        }
    }
    return res;
}

vector<int> Solution::findSubstring(string S, const vector<string> &words) {
    
    if(_init(words))    return vector<int>();    
                return solve(S, words);
}
