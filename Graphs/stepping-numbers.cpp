#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void gen(vi &res, int num, const int lo, const int hi) {
	// base;
	if(num > hi) 	return;

	// add num to solution vector
	if(num >= lo) 	res.push_back(num);

	int d = num%10;

	if(d != 0) 	gen(res, 10*num+d-1, lo, hi);
	if(d != 9) 	gen(res, 10*num+d+1, lo, hi);

}

void solve(vi &res, const int lo, const int hi) {
	for(int i=1 ; i<10 ; ++i)
		gen(res, i, lo, hi);
}

// Solution::
vector<int> stepnum(int lo, int hi) {
	vi res;
	// edge case
	if(lo == 0) 	res.push_back(0);
	solve(res, lo, hi);
	return res;
}

int main(){


	return 0;
}