// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int maxx(int q, int p){
    if(q>p)     return q;
    return p;
}

int abss(int q){
    if(q<0) q=-q;
    return q;
}

int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int res=0, xdiff, ydiff;
    for(int i=0 ; i<X.size()-1 ; ++i){
        xdiff = abss(X[i+1]-X[i]);
        ydiff = abss(Y[i+1]-Y[i]);
        res += maxx(xdiff, ydiff);
    }
    return res;
}
