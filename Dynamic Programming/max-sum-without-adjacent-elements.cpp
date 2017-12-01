int Solution::adjacent(vector<vector<int> > &grd) {
    int sollu = max(grd[0][0], grd[1][0]);
    int slsuz = 0, cur, size = grd[0].size();
    for(int i=1 ; i<size ; ++i){
        cur = max(slsuz, sollu);
        sollu = slsuz + max(grd[0][i], grd[1][i]);
        slsuz = cur;
    }
    return max(sollu, slsuz);
}
