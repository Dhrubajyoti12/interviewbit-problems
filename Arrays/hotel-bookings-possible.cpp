#include <iostream>
#include <queue>

using namespace std;

using pii = pair<int, int>;

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
	vector< pii > durumlar;
	durumlar.reserve(2*arrive.size());
		
	for(int arr : arrive)	reserve.push_back(make_pair(arr, +1));
	for(int dep : depart)	reserve.push_back(make_pair(dep, -1));

	sort(durumlar.begin(), durumlar.end());
	
	int cur = 0; // currently occupied rooms.
	for(auto event : durumlar){
		cur += event.second;
		if(cur > K) 	return false;
	}

	return 1;
}



int main(){


	return 0;
}