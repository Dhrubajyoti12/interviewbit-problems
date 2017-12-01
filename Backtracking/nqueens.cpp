#define pb push_back

int **mark, N, *row;

vector< vector<string> > *cevab;


void _init(int A){
    cevab = new vector<vector<string> >(); 
    N = A;
    mark = new int*[A];
    row = new int[A];
    for(int i=0 ; i<A ; ++i){
        mark[i] = new int[A];
    }
    
    for(int i=0 ; i<A ; ++i)    row[i]=0;
    for(int i=0 ; i<A ; ++i)
        for(int j=0 ; j<A ; ++j)
            mark[i][j]=0;
    // cevaB, veremedi ins.
}

void mapToCevaB(){
//printf("##BOOOOO##\n");
    vector<string> cozum;
    for(int i=0 ; i<N ; ++i){
        string satir="";
        for(int j=0 ; j<N ; ++j){
            if(mark[i][j])   satir+='Q';
            else            satir+='.';
        }
        cozum.pb(satir);
    }
    cevab->pb(cozum);
}

bool bos(const int row, const int col){
    int i=row, j=col;
    while(i<N and j>-1){
        if(mark[i][j])   return 0;
        ++i, --j;
    }
    
    i=row, j=col;
    while(i>-1 and j>-1){
        if(mark[i][j])   return 0;
        --i, --j;
    }
    
    return 1;
}

void solve(int col) {
    if(col == N)    {mapToCevaB();return ;}
    for(int i=0 ; i<N ; ++i){
        if(!row[i] and bos(i,col)){
            row[i]=1;   mark[i][col]=1;
//printf("koyduk:%d %d\n",i,col);
            solve(col+1);
//printf("kldrdk:%d %d\n",i,col);
            row[i]=0;   mark[i][col]=0;
        }
    }
}


vector<vector<string> > Solution::solveNQueens(int A) {
    if(A<1 or A==2 or A==3)     return vector<vector<string> >();
    _init(A);
    solve(0);
    return *cevab;
}
