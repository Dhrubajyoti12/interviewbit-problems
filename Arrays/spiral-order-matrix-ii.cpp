// #include <iomanip>

// void printv(vector<vector<int> > Q){
//     for(int i=0 ; i<Q.size() ; ++i){
//         for(int j=0 ; j<Q.size() ; ++j)     cout<<std::setfill(' ') << std::setw(2)<<Q[i][j];
//         cout<<endl;
//     }
//     cout<<endl;
// }
vector<vector<int> > Solution::generateMatrix(int n) {
    vector< vector<int> > res(n, vector<int>(n,0));
    bool mark[n][n];    
    for(int i=0 ; i<n ; ++i)
        for(int j=0 ; j<n ; ++j)
            mark[i][j]=0;
    
    int dirI[4]={0,1,0,-1}, dirJ[4]={1,0,-1,0}, ind=0, i=0, j=0, newI, newJ;
    for(int cur=1 ; cur<=n*n ; ++cur){
        mark[i][j] = 1,         res[i][j] = cur;
        newI = i+dirI[ind],     newJ = j+dirJ[ind];
        if(mark[newI][newJ] or newI==n or newJ==n or newI<0 or newJ<0){
            ind = (ind+1)%4;
            newI = i+dirI[ind],     newJ = j+dirJ[ind];
        }
        i = newI,    j = newJ;
    }
    //printv(res);
    return res;
}
