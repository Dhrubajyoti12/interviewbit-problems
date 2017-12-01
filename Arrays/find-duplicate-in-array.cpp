int Solution::repeatedNumber(const vector<int> &A) {
    int size=A.size()-1; 
    int seal=0, sonSize, bSayisi;
    while(seal*seal < size) ++seal;
    
    sonSize = seal;
    if(size%seal)   sonSize=size%seal;
    bSayisi = size/seal;
    if(bSayisi*seal != size)    ++bSayisi;
    
    
    int bucket[bSayisi];
    for(int i=0; i<bSayisi; bucket[i++]=0);
    
    for(int i=0 ; i<A.size() ; ++i)
        bucket[(A[i]-1)/seal]++;
    
    //cout<<size<<endl<<seal<<endl<<sonSize<<endl<<bSayisi<<endl;
    //for(int i=0  ; i<bSayisi ; ++i)     cout<<i<<":"<<bucket[i]<<endl;
    
    //b[0]==2;    bsize 1 sonsize 1 bsayisi 1 seal 1 
    int KULPIRIT=1, seySize=seal;
    for(int i=0 ; i<bSayisi ; ++i)
        if(bucket[i]>seal or (i==bSayisi-1 and bucket[i]>sonSize) )
            KULPIRIT = i;
    if(KULPIRIT == bSayisi-1)     seySize = sonSize;
    
    //cout<<"KULPIRIT: "<<KULPIRIT<<endl;
    
    int mark[seySize]; for(int i=0; i<seySize; mark[i++]=0); // = {}
    
    for(int i=0 ; i<A.size(); ++i){
        if ( (KULPIRIT*seal  <= A[i]-1) and (A[i]-1 < KULPIRIT*seal + seal) ) {
            if(mark[A[i]-KULPIRIT*seal-1])  return A[i];
            else mark[A[i]-KULPIRIT*seal-1]++;
        }
        
    }
    return -1;
}
