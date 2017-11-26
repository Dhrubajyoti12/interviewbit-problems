#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> sol, sag;
int K;

void get_inpt(){
	int dumi;
	//k
	cin >> K;
	// vector 1
	cin >> dumi;
	while(dumi != -1) 	sol.push_back(dumi), cin >> dumi;
	// vector 2
	cin >> dumi;
	while(dumi != -1) 	sag.push_back(dumi), cin >> dumi;
}

void solve(){
	priority_queue<int> pq;

	for(auto i : sol){
		for(auto j : sag) 	pq.push(i+j);
	}

	while(K--){
		cout << pq.top();
		pq.pop();
	}
}

int main(void){
	get_inpt();
	solve();
	return 0;
}