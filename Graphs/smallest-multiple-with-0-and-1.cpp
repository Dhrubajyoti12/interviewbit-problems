struct e{
	string str;
	int mod;
	e(string _str, int _mod): str(_str), mod(_mod) {}
};

string Solution::multiple(int N) {
    if(N == 1)  return "1";
	
	queue<string> Q;

	Q.push(e{"1", 1});  mark[1] = 1;    
    bool mark[N] = {0};
	while(Q.size()){
		e fro = Q.front(); 	Q.pop(); // <----- notice
		int m = fro.mod;
		str s = fro.str;
		
		if(!m)	return s; // we found, zi number.
		
		if(!mark[(10*m)%N]) {
			Q.push(e{str + '0', (m*10)%N});
			mark[(10*m)%N] = true;
		}
		if(!mark[(10*m + 1)%N]) {
			Q.push(e{str + '1', (10*m + 1)%N});
			mark[(10*m + 1)%N] = true;
		}
	}

	return "NNNNNIIIIOOOOOOOOOO, HOWSTHISEVENPOSSIBLE"; 
}
