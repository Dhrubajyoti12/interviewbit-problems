// void runCircle(vector<int> &arr, int startInd){
//     int curInd = startInd, size = arr.size();
//     int target = arr[startInd] , startVal = arr[startInd];

//     while(target!=curInd and arr[target]>0){
//         arr[curInd] = -arr[target%size];
//         curInd = target;
//         target = arr[curInd%size];
//     }
    
//     arr[curInd] = -startVal;
// }

// 0 dan n-1'e  

// arr[index]%n eski
// arr[index]/n yeni

// (Arr[Arr[i]] % n)*n.
union lmix{
    int value;
    struct{
        unsigned short lo;
        unsigned short hi;
    }part;
};

void Solution::arrange(vector<int> &arr) {
    lmix cur, tmp;
    const int N = arr.size();
    for(int i=0 ; i<N ; ++i){
        cur.value = arr[i];
        tmp.value = arr[arr[i]];
        cur.part.hi = tmp.part.lo;
        arr[i] = cur.value;
    }
    
    for(int i=0 ; i<N ; ++i){
        cur.value = arr[i];
        cur.value = cur.part.hi;
        arr[i] = cur.value;
    }
    
}

// void Solution::arrange(vector<int> &arr) {
//     int n = arr.size();
//     for(int i=0 ; i<arr.size() ; ++i){
//         arr[i] += (arr[arr[i]]%n)*n;
//     }
    
//     for(int i=0 ; i<arr.size() ; ++i){
//         arr[i] /= n;
//     }
// }
