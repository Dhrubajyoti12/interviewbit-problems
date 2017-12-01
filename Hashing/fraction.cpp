#define mp mak_pair

using pii = pair<int, int>;
using aq = long long int;
struct ALLAHBELANIZIVERSIN {
    size_t operator()(const std::pair<int, int>& p) const {
        return p.first ^ p.second;
    }
};

string coz(aq ust, aq alt){
    unordered_map<pii, int, ALLAHBELANIZIVERSIN> gordukmu;
    string ret;
    
    ret+=to_string(ust/alt);
    if(!(ust%alt))  return ret;
    ret+='.';
    ust%=alt;
    
    int bolum,kalan,index=0, pbas=-1;
    while(ust) {
        ust=ust*10;
        bolum = ust/alt;
        kalan = ust%alt;
        ust%=alt;
        
        if(gordukmu.find(pii{bolum, kalan}) != gordukmu.end()) {
            pbas = gordukmu[pii{bolum,kalan}];
            aq yeri = ret.find('.');
            ret.insert(ret.begin()+yeri+1+pbas,1, '(');
            ret.push_back(')');
            break;
        }
        else{
            gordukmu.emplace(pii{bolum,kalan}, index++);
            ret += to_string(bolum);
        }
    }
    
    return ret;
}

string Solution::fractionToDecimal(int ust, int alt) {
    aq _ust=ust, _alt=alt;
    if(!_ust)   return "0";
    bool neg=0;
    if(_ust<0)  _ust=-_ust, neg=!neg;
    if(_alt<0)  _alt=-_alt, neg=!neg;
    string res = (neg) ? "-" : "";
    res += coz(_ust, _alt);
    return res;
}