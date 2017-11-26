#include <iosream>
#include <unordered_map>

using namespace std;

inline bool map_contains(unordered_map<int, int> &chi, int query){
	return chi.find(query) != chi.end();
}

vector<int> dNums(vector<int> &vec, int window_size){
	unordered_map<int, int> chi; // value - quantitiy
	
	int i, size = vec.size();
	for(i=0 ; i<window_size ; ++i) 		chi[veci]++;

	vector<int> res; 	res.pb(chi.size());
	while(i < size){
		chi[ vec[i - window_size] ]--;
		chi[ vec[i] ]++;
		res.pb(chi.size());
	}
	return res;
}



int main(void){



	return 0;
}
