string Solution::intToRoman(int A) {
    string res;
    int bolen = 1000, ind=2;
    //               0  1  2  3  4  5  6  7  8  9
    int onlar[10] = {0, 1, 2, 3, 1, 0, 1, 2, 3, 1};
    //                           bi geriden
    string tablo = "##MDCLXVI";
    
    while(bolen){
        int cur = A/bolen;
        A %= bolen;
        //cout << ind << " "<< cur<<endl;
        if(cur<5){
            for(int i=0 ; i<onlar[cur] ; ++i)   res+=tablo[ind];
            if(cur%5==4)    res+=tablo[ind-1];
        }else if(cur<9){
            res += tablo[ind-1];
            for(int i=0 ; i<onlar[cur] ; ++i)   res+=tablo[ind];
        }else{
            res += tablo[ind];
            res += tablo[ind-2];
        }
        bolen/=10, ind+=2;
    }
    return res;
}

//mcmlxxxiv
/*
I - 1
V - 5
X - 10
L - 50
C - 100
D - 500
M - 1000


*/