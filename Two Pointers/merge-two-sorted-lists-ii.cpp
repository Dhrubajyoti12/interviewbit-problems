#define pb push_back

void Solution::merge(vector<int> &LEFT, vector<int> &RITE) {
    int sol=0, sag=0;
    vector<int> dummy;
    while(sol<LEFT.size() or sag<RITE.size()){
        if( sol==LEFT.size() or (sag<RITE.size() and RITE[sag]<=LEFT[sol]))
            dummy.pb(RITE[sag++]);
        else    dummy.pb(LEFT[sol++]);
    }
    LEFT = dummy;
}
