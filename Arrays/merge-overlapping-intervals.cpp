
#define pb push_back

// struct Interval {
//     int start;
//     int end;
//     Interval() : start(0), end(0) {}
//     Interval(int s, int e) : start(s), end(e) {}
// };
// struct E{
//     int s,e;
// };

bool bakisAt(Interval q, Interval p){
    return q.start  < p.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), bakisAt);
    stack<Interval> feriha;
    
//for(int i=0 ; i<A.size() ; ++i)printf("[%d:%d] ",A[i].start, A[i].end);cout<<endl;
//  [4:4] [5:31] [5:27] [6:25] [6:20] [8:48] 

    feriha.push(A[0]);
    for(int i=1 ; i<A.size() ; ++i){
        Interval top = feriha.top();
        Interval cur = A[i];
        //printf("i=%d top[%d:%d]  cur[%d:%d]\n",i,top->start,top->end,cur.start,cur.end);
        if(cur.start<=top.end){
            feriha.pop(); 
            top.end = max(cur.end, top.end);
            feriha.push(top);
        }
        else feriha.push(cur);
    }
    
    vector<Interval> res;
    while(feriha.size()){
        Interval top = feriha.top(); feriha.pop();
        res.pb(top);
    }
    
    reverse(res.begin(), res.end());

    return res;
}