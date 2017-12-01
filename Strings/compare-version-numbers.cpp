using lanet = unsigned long long int;

int Solution::compareVersion(string A, string B) {
    lanet aNok = 0, bNok = 0;
    
    for (int a=0,b=0; a<A.size() or b<B.size(); ++a, ++b){
        
        // iki nokta arasindaki sayiyi aNok ve bNok'a at.
        while (a < A.size() && A[a] != '.')
            aNok = aNok * 10 + (A[a++] - '0');
        while (b < B.length() && B[b] != '.')
            bNok = bNok * 10 + (B[b++] - '0');
 
        // tiplere bak.
        if (aNok > bNok)    return 1;
        if (bNok > aNok)    return -1;
        
        // A'da da B'de de noktadayiz, esitiz, devam et.
        aNok = bNok = 0;
    }
    return 0;
}
