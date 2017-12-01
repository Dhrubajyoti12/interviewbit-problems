#define MOD 1000000007
using aq = long long int;

int Solution::nchoc(int K, vector<int> &boxes) {
    priority_queue<int> heap;
    for(auto box : boxes)   heap.push(box);
    
    aq res = 0;
    while(K--){
        aq top = heap.top();
        res = (res + top)% MOD;  
        heap.pop();
        heap.push(top/2);
    }
    return res;
    
}
