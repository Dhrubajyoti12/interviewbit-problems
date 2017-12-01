#define MOD 10000003

int Solution::seats(string row) {
    vector<int> ppl;
    
    int rowsize = row.size();
    for(int i=0 ; i<rowsize ; ++i){
   		if(row[i] == 'x')     ppl.push_back(i);
    }
    int ps = ppl.size(); // number of people
	int med = ps>>1; // median
	
	unsigned long long int res = 0;
	// move everyone on the left of the median
	for(int c=med-1 ; c>-1 ; --c){
		res = (res + ppl[c+1] - ppl[c] - 1 )%MOD;
		ppl[c] = ppl[c+1] - 1;
	}
	// move everyone on the right of the median
	for(int c=med+1 ; c<ps ; ++c){
		res = (res + ppl[c] - ppl[c-1] - 1 )%MOD;
		ppl[c] = ppl[c-1] + 1;
	}
	return res;
}