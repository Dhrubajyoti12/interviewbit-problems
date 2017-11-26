#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int canCompleteCircuit(const vector<int> &gasu, const vector<int> &cost) {
    int res = 0, total = 0, size = gasu.size();
    for(int cg=0, i=0 ; i<size ; ++i){// cg for current gas.
    	total += gasu[i] - cost[i];// total may overflow depending on the input
    	cg += gasu[i] - cost[i];	
    	if(cg < 0) 	cg = 0, res = i+1;
    }
    
    if(total < 0) 	return -1;
    return res;
}
