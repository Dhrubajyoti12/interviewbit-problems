#define pb push_back
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

vector<Interval> Solution::insert(vector<Interval> &inz, Interval newI) {
    if(!inz.size()){
        vector<Interval> aq;
        aq.pb(newI);
        return aq;
    }
    vector<Interval> mid;
    int i=0, dummy;
    
    while(inz[i].start<newI.start and i<inz.size()) {
        if(inz[i].start > inz[i].end)   // swap if needed
            dummy=inz[i].start, inz[i].start = inz[i].end, inz[i].end=dummy;   
        mid.pb(inz[i++]);
    }
    if(newI.start > newI.end)   // swap if needed
        dummy=newI.start, newI.start = newI.end, newI.end=dummy;
    mid.pb(newI);
    
    while(i<inz.size()) {
        if(inz[i].start > inz[i].end)   // swap if needed
            dummy=inz[i].start, inz[i].start = inz[i].end, inz[i].end=dummy;   
        mid.pb(inz[i++]);
    }

    stack<Interval> s;  s.push(mid[0]);
    for(int i=1 ; i<mid.size() ; ++i){
        Interval top = s.top();
        Interval cur = mid[i];
        if(cur.start<=top.end){
            s.pop(); 
            top.end = max(cur.end, top.end);
            s.push(top);
        }
        else s.push(cur);
    }
    
    vector<Interval> res;
    while(s.size()){
        Interval top = s.top(); s.pop();
        res.pb(top);
    }
    
    reverse(res.begin(), res.end());

    return res;
    
}
