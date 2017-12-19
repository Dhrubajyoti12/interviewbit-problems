#define LIM 46

using namespace std;

using vi = vector<int>;

vi fibs(LIM, 0);

void genFibs(){
	fibs[0] = fibs[1] = 1;
	for(int i=2 ; i<LIM ; ++i){
		fibs[i] = fibs[i-1] + fibs[i-2];
	}
}

int Solution::fibsum(int A) {
	genFibs();
	
	int index=0;
	while(fibs[index] <= A) 	++index;
	--index;

	int res = 0;
	while(A){
		A -= fibs[index];
		res++;
		while(fibs[index] > A) 	--index;
	}

	return res;
}
